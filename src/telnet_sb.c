#include "telnet_sb.h"

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
        checkOneUntilFour(message, i, "bad-choice", "too-long", "wrong length", "other");
    }else if((*message)[*i] == 4){
        print("litteral", (*message)[*i]);
        *i = *i +1;
        read8(message, i);
    }else if((*message)[*i] == 5){
        print("please_cancel", (*message)[*i]);
        *i = *i +1;
        read8(message, i);
        checkOneUntilFour(message, i, "bad-choice", "too-long", "wrong length", "other");
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

void det(unsigned char** message, int* i){
    checkOneUntilSeven(message, i, "edit_facilities", "erase_facilities", "transmit_facilities", "format_facilities", "move cursor", "skip_to_line", "skip_to_char");
    checkEightUntilEleven(message, i, "up", "down", "left", "right");
    checkTwelveUntilTwenty(message, i, "home", "line_insert", "line_delete", "char_insert", "char_delete", "read_cursor", "cursor_position", "reverse_tab", "transmit_screen");
    checkTwentyOneUtilThirty(message, i, "transmit_unprotected", "transmit_line", "transmit_field", "transmit_rest_of_screen", "transmit_rest_of_line", "transmit_rest_of_field", "transmit_modified", "data_transmit", "erase screen", "erase_line");
    checkThirtyOneUtilFortyOne(message, i, "erase_field", "erase_rest_of_screen", "erase_rest_of_line", "erase_rest_of_field", "erase_unprotected", "format_date", "repeat", "suppress_protection", "field_separator", "fn", "error");
    read255(message, i, 1);
}

void command(unsigned char** message, int* i){
    if((*message)[*i] == 251){
        print("will", (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 252){
        print("wont", (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 253){
        print("do", (*message)[*i]);
        *i = *i +1;
    }else if((*message)[*i] == 254){
        print("dont", (*message)[*i]);
        *i = *i +1;
    }
}

void linemode(unsigned char** message, int* i){
    if((*message)[*i] == 1){
        print("mode", (*message)[*i]);
        *i = *i +1;
        checkZeroUntilFour(message, i, "default", "edit", "trapsig", "echo", "mode_ack");
        read255(message, i, 1);
    }else if((*message)[*i] == 2){
        print("forwardmask", (*message)[*i]);
        *i = *i +1;
        command(message, i);
        read255(message, i, 0);
    }else if((*message)[*i] == 3){
        print("slc", (*message)[*i]);
        *i = *i +1;
        while((*message)[*i] != 255){
            if(checkZeroUntilEight(message, i, "default", "slc_synch", "slc_brk", "slc_ip", "slc_ao", "slc_ayt", "slc_eor", "slc_abort", "slc_eof") == 1);
            else if(checkEightUntilEleven(message, i, "slc_eof", "slc_susp", "slc_ec", "slc_el") == 1);
            else if(checkTwelveUntilTwenty(message, i, "slc_ew", "slc_rp", "slc_lnext", "slc_xon", "slc_xoff", "slc_forw1", "slc_forw2", "slc_mcl", "slc_mcr") == 1);
            else if(checkTwentyOneUtilThirty(message, i, "slc_mcwl", "slc_mcwr", "slc_mcbol", "slc_mceol", "slc_insrt", "slc_over", "slc_ecr", "slc_ewr", "slc_ebol", "slc_eeol") == 1);
            else if((*message)[*i] == 32){
                print("slc_flushout", (*message)[*i]);
                *i = *i +1;
            }else if((*message)[*i] == 64){
                print("slc_flushin", (*message)[*i]);
                *i = *i +1;
            }else if((*message)[*i] == 128){
                print("slc_ack", (*message)[*i]);
                *i = *i +1;
            }else{
                printf("%d ", (*message)[*i]);
                *i = *i +1;
            }
        }
    }
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
        case 7:
            read255(message, i, 1);
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
        case 20:
            det(message, i);
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
            checkZeroUntilFour(message, i, "set", "response set", "is", "response is", "send");
            read255(message, i, 3);
            break;
        case 33:
            checkZeroUntilThree(message, i, "off", "on", "restart-now", "restart-xon");
            read8(message, i);
            break;
        case 34:
            linemode(message, i);
            break;
        case 36 :
            checkZeroUntilTwo(message, i, "is", "send", "info");
            read255(message, i, 0);
            break;
        case 37:
            checkZeroUntilThree(message, i, "is", "send", "reply", "name");
            checkZeroUntilEight(message, i, "null", "kerberos_v4", "kerberos_v5", "spx", "mink", "srp", "rsa", "ssl", "unassigned");
            checkEightUntilEleven(message, i, "unassigned", "unassigned", "loki", "ssa");
            checkTwelveUntilFifteen(message, i, "kea_sj", "kea_sj_integ", "dss", "ntlm");
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
        case 41 :
        case 43 :
        case 45 :
        case 46 :
        case 48 :
        case 49 :
        case 138 :
        case 139 :
        case 140 :
        	checkOneUntilThree(message, i, "ofb64_IV", "ofb64_IV_ok", "ofb64_IV_bad");
        	read255(message, i, 1);
        	break;
        case 42:
        	checkOneUntilSeven(message, i, "request", "accept", "reject", "ttable-is", "ttable-rejected", "ttable-ack", "ttable-nack");
        	read255(message, i, 0);
        	break;
        case 44:
        	comPort(message, i);
        	break;
        case 47:
            checkZeroUntilFour(message, i, "start-server", "stop-server", "req-start-server", "req-stop-server", "req");
            checkEightUntilNine(message, i, "resp-start-server", "resp-stop-server");
            read255(message, i, 1);
            break;
        default:
            break;
    }
}
