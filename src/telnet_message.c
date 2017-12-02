#include "telnet_message.h"

void commande(unsigned char* message, int* messageConnu, int* sb){
    *sb = 0;
    switch(*message){
        case 236:
            print("Eof", *message);
            break;
        case 237:
            print("Susp", *message);
            break;
        case 238:
            print("Abort", *message);
            break;
        case 240:
            print("Se", *message);
            break;
        case 241:
            print("No operation", *message);
            break;
        case 242:
            print("Data mark", *message);
            break;
        case 243:
            print("Break", *message);
            break;
        case 244:
            print("Interrupt process", *message);
            break;
        case 245:
            print("Abort output", *message);
            break;
        case 246:
            print("Are you there", *message);
            break;
        case 247:
            print("Erase character", *message);
            break;
        case 248:
            print("Erase line", *message);
            break;
        case 249:
            print("Go ahead", *message);
            break;
        case 250:
            print("Sb", *message);
            *sb = 1;
            break;
        case 251:
            print("Will", *message);
            break;
        case 252:
            print("Won't", *message);
            break;
        case 253:
            print("Do", *message);
            break;
        case 254:
            print("Don't", *message);
            break;
        case 255:
            print("Interpret as command", *message);
            break;
        default:
            *messageConnu = 0;
            printf("%c",*message);
            break;
    }
}

void print_message(unsigned char** message, int* i){
    int messageConnu = 1, sb = 0, option = -1;
    commande(&((*message)[*i]), &messageConnu, &sb);
     *i = *i +1;
     if(messageConnu == 1){
         print_option(&((*message)[*i]), i, &option);
         *i = *i + 1;
         if(sb == 1){
             print_sb(message, i, &option);
         }
         printf("   ");
     }
}
