#include "pcap.h"

int main (int argc, char* argv[]){
    if(argc > 1){
        verbose = 0;
        if(argc>2 && strcmp(argv[2], "-v")==0){
            verbose = 1;
        }
        pcap(argv[1]);
    }else{
        fprintf(stderr, "Merci d'indiquer un fichier en argument\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
