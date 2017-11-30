#include "telnet_sb.h"

void read8(unsigned char** message, int* i){
    int8_t t = 0;
    int j;
    for(j=1; j>=0; j--){
        if(j==0){
            t = (*message)[*i];
        }else{
            t = (*message)[*i]<< 4;
        }
    }
    printf("%d ", (int)(t));
}

void read16(unsigned char** message, int* i){
    int16_t t = 0;
    int j;
    for(j=3; j>=0; j--){
        if(j==0){
            t = (*message)[*i];
        }else{
            t = (*message)[*i]<< 4;
        }
        *i = *i +1;
    }
    printf("%d ", (int)(t));
}

void read32(unsigned char** message, int* i){
    int32_t t = 0;
    int j;
    for(j=7; j>=0; j--){
        if(j==0){
            t = (*message)[*i];
        }else{
            t = (*message)[*i]<< 4;
        }
        *i = *i +1;
    }
    printf("%d ", (int)(t));
}

void read255(unsigned char** message, int* i, int print){
    while((*message)[*i] != 255){
        if(print == 3){
            read8(message, i);
        }else if(print == 0){
            printf("%c", (*message)[*i]);
            *i = *i +1;
        }else if(print == 1){
            printf("%d ", (*message)[*i]);
            *i = *i +1;
        }
    }
}

void checkZeroOne(unsigned char** message, int* i, char* one, char* zero){
    if((*message)[*i] == 1){
        print(one, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 0){
        print(zero, (*message)[*i]);
        *i = *i +1;
    }
}

void bmReason(unsigned char** message, int* i){
    if((*message)[*i] == 1){
        print("bad-choice", (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 2){
        print("too-long", (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 3){
        print("wrong length", (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 4){
        print("other", (*message)[*i]);
        *i = *i +1;
    }
}

void bm(unsigned char** message, int* i){
    if((*message)[*i] == 1){
        print("define", (*message)[*i]);
        *i = *i +1;
        read8(message, i);
        read8(message, i);
        read255(message, i, 0);
    }else if((*message)[*i] == 2){
        print("accept", (*message)[*i]);
        *i = *i +1;
        read8(message, i);
    }else if((*message)[*i] == 3){
        print("refuse", (*message)[*i]);
        *i = *i +1;
        read8(message, i);
        bmReason(message, i);
    }else if((*message)[*i] == 4){
        print("litteral", (*message)[*i]);
        *i = *i +1;
        read8(message, i);
    }else if((*message)[*i] == 5){
        print("please_cancel", (*message)[*i]);
        *i = *i +1;
        read8(message, i);
        bmReason(message, i);
    }
}

void print_sb(unsigned char** message, int* i, int* option){
    switch((*option)){
        case 5:
        case 24:
        case 32:
        case 35:
            checkZeroOne(message, i, "Send", "Is");
            read255(message, i, 0);
            break;
        case 10:
        case 12:
        case 13:
        case 15:
        case 16:
            checkZeroOne(message, i, "DS", "DR");
            read8(message, i);
            break;
        case 11:
        case 14:
            checkZeroOne(message, i, "DS", "DR");
            read255(message, i, 3);
            break;
        case 17:
        case 31:
            read16(message, i);
            read16(message, i);
            break;
        case 19:
            bm(message, i);
            break;
        case 22:
            read255(message, i, 1);
            break;
        case 23:
            read255(message, i, 0);
            break;
        case 27:
            read32(message, i);
        default:
            break;
    }
}
