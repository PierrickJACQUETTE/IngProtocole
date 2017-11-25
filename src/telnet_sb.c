#include "telnet_sb.h"

void read255(unsigned char** message, int* i){
    while((*message)[*i] != 255){
        printf("%c",(*message)[*i]);
        *i = *i +1;
    }
}

void isSend(unsigned char** message, int* i){
    if((*message)[*i] == 1){
        print("Send", (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 0){
        print("Is", (*message)[*i]);
        *i = *i +1;
        read255(message, i);
    }
}

void print_sb(unsigned char** message, int* i, int* option){
    switch((*option)){
        case 5:
        case 24:
        case 32:
        case 35:
            isSend(message, i);
            break;
        default:
            break;
    }
    printf("   ");
}
