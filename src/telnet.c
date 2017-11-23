#include "telnet.h"

void destroyTelnet(struct telnet** telnet){
    free(*telnet);
}

void print_telnet(struct telnet** telnet){
    int i=0;
    printf("| ");
    couleur(RED);
    printf("Telnet: ");
    couleur(DEFAULT);
    while(i<(*telnet)->size_telnet){
        if((*telnet)->message[i]==13){
            i++;
        }else if((*telnet)->message[i]=='\n'){
            printf("\\n");
            i++;
        }else{
            print_message(&((*telnet)->message), &i);
        }
    }
}
