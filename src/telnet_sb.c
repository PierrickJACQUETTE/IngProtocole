#include "telnet_sb.h"

void read8(unsigned char** message, int* i){
    int8_t t = 0;
    t = (*message)[*i];
    *i = *i +1;
    printf("%d ", (int)(t));
}

void read16(unsigned char** message, int* i){
    int16_t t = 0;
    int j;
    for(j=1; j>=0; j--){
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

void checkZeroOne(unsigned char** message, int* i, char* zero, char* one){
    if((*message)[*i] == 1){
        print(one, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 0){
        print(zero, (*message)[*i]);
        *i = *i +1;
    }
}

void checkZeroUntilTwo(unsigned char** message, int* i, char* zero, char* one, char* two){
    checkZeroOne(message, i, zero, one);
    if((*message)[*i] == 2){
        print(two, (*message)[*i]);
        *i = *i +1;
    }
}

void checkZeroUntilThree(unsigned char** message, int* i, char* zero, char* one, char* two, char* three){
    checkZeroUntilTwo(message, i, zero, one, two);
    if((*message)[*i] == 3){
        print(three, (*message)[*i]);
        *i = *i +1;
    }
}

void checkZeroUntilEight(unsigned char** message, int* i, char* zero, char* one, char* two, char* three, char* four, char* five, char* six, char* seven, char* eight){
    checkZeroUntilThree(message, i, zero, one, two, three);
    if((*message)[*i] == 4){
        print(four, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 5){
        print(five, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 6){
        print(six, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 7){
        print(seven, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 8){
        print(eight, (*message)[*i]);
        *i = *i +1;
    }
}

void checkEightUntilEleven(unsigned char** message, int* i, char* eight, char* nine, char* ten, char* eleven){
	if((*message)[*i] == 8){
        print(eight, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 9){
        print(nine, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 10){
        print(ten, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 11){
        print(eleven, (*message)[*i]);
        *i = *i +1;
    }
}

void check0Until4And8Until11(unsigned char** message, int* i, char* zero, char* one, char* two, char* three, char* four, char* eight, char* nine, char* ten, char* eleven){
    checkZeroUntilThree(message, i, zero, one, two, three);
    if((*message)[*i] == 4){
        print(four, (*message)[*i]);
        *i = *i +1;
    }
    checkEightUntilEleven(message, i, eight, nine, ten, eleven);
}

void checkOneUntilSeven(unsigned char** message, int* i, char* one, char* two, char* three, char* four, char* five, char* six, char* seven){
    if((*message)[*i] == 1){
        print(one, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 2){
        print(two, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 3){
        print(three, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 4){
        print(four, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 5){
        print(five, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 6){
        print(six, (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 7){
        print(seven, (*message)[*i]);
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

void x3Pad(unsigned char** message, int* i){
    if((*message)[*i] == 0){
        print("set", (*message)[*i]);
        *i = *i +1;
        read255(message, i, 3);
    }else if((*message)[*i] == 1){
        print("response set", (*message)[*i]);
        *i = *i +1;
        read255(message, i, 3);
    }else if((*message)[*i] == 2){
        print("is", (*message)[*i]);
        *i = *i +1;
        read255(message, i, 3);
    }else if((*message)[*i] == 3){
        print("response is", (*message)[*i]);
        *i = *i +1;
        read255(message, i, 3);
    }else if((*message)[*i] == 4){
        print("send", (*message)[*i]);
        *i = *i +1;
        read255(message, i, 3);
    }
}

void newEnv(unsigned char** message, int* i){
    checkZeroUntilTwo(message, i, "is", "send", "info");
    checkZeroUntilThree(message, i, "var", "value", "esc", "uservar");
    while((*message)[*i] != 255){
        if((*message)[*i] <= 3 && (*message)[*i] >= 0){
            checkZeroUntilThree(message, i, "var", "value", "esc", "uservar");
        }else{
            printf("%c", (*message)[*i]);
            *i = *i +1;
        }
    }
}

void encrypt(unsigned char** message, int* i){
	checkZeroUntilEight(message, i, "is", "support", "reply", "start", "end", "request-start", "request-end", "enc_keyid", "dec_keyid");
    while((*message)[*i] != 255){
        if((*message)[*i] <= 11 && (*message)[*i] >= 0){
			check0Until4And8Until11(message, i, "null", "des_cfb64", "des_ofb64", "des3_cfb64", "des3_ofb64", "cast5_40_cfb64", "cast5_40_ofb64", "cast128_cfb64", "cast128_ofb64");
        }else{
            printf("%d", (*message)[*i]);
            *i = *i +1;
        }
    }
}

void comPort(unsigned char** message, int* i){
	checkOneUntilSeven(message, i, "set-baudrate", "set-datasize", "set-parity", "set-stopsize", "set-control", "notify-linestate", "notify-modemstate");
	checkEightUntilEleven(message, i, "flowcontrol-suspend", "flowcontrol-resume", "set-linestate-mask", "set-modemstate-stack");
    if((*message)[*i] == 12){
        print("purge-data", (*message)[*i]);
        *i = *i +1;
    }
    read255(message, i, 1);
}


void print_sb(unsigned char** message, int* i, int* option){
    switch((*option)){
        case 5:
        case 24:
        case 32:
        case 35:
            checkZeroOne(message, i, "is", "send");
            read255(message, i, 0);
            break;
        case 10:
        case 12:
        case 13:
        case 15:
        case 16:
            checkZeroOne(message, i, "dr", "ds");
            read8(message, i);
            break;
        case 11:
        case 14:
            checkZeroOne(message, i, "dr", "ds");
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
        case 26:
        case 27:
            read32(message, i);
            break;
        case 28:
            read8(message, i);
            read32(message, i);
            read32(message, i);
            break;
        case 29:
            checkZeroOne(message, i, "is", "are");
            read255(message, i, 0);
            break;
        case 30:
            x3Pad(message, i);
            break;
        case 33:
            checkZeroUntilThree(message, i, "off", "on", "restart-now", "restart-xon");
            read8(message, i);
            break;
        case 36 :
            checkZeroUntilTwo(message, i, "is", "send", "info");
            read255(message, i, 0);
            break;
        case 37:
            checkZeroUntilThree(message, i, "is", "send", "reply", "name");
            read255(message, i, 0);
            break;
        case 38:
        	encrypt(message, i);
        	break;
        case 39:
            newEnv(message, i);
            break;
        case 40:
        	checkZeroUntilEight(message, i, "associate", "connect", "device-type", "functions", "is", "reason", "reject", "request", "send");
           	checkZeroUntilEight(message, i, "associate", "connect", "device-type", "functions", "is", "reason", "reject", "request", "send");
           	read255(message, i, 1);
        	break;
        case 42:
        	checkOneUntilSeven(message, i, "request", "accept", "reject", "ttable-is", "ttable-rejected", "ttable-ack", "ttable-nack");
        	read255(message, i, 0);
        	break;
        case 44:
        	comPort(message, i);
        	break;
        default:
            break;
    }
}
