#include "telnet_option.h"

void print_option(unsigned char* message, int *i, int* option){
    switch(*message){
        case 0:
            print("binary", *message);
            *option = 0;
            break;
        case 1:
            print("echo", *message);
            *option = 1;
            break;
        case 2:
            print("reconnection", *message);
            *option = 2;
            break;
        case 3:
            print("supresse go head", *message);
            *option = 3;
            break;
        case 4:
            print("approx (*telnet)->message size negotiation", *message);
            *option = 4;
            break;
        case 5:
            print("status", *message);
            *option = 5;
            break;
        case 6:
            print("timing mark", *message);
            *option = 6;
            break;
        case 7:
            print("remote controlled trans and echo", *message);
            *option = 7;
            break;
        case 8:
            print("output line width", *message);
            *option = 8;
            break;
        case 9:
            print("output page size", *message);
            *option = 9;
            break;
        case 10:
            print("ouput carriage return disposition", *message);
            *option = 10;
            break;
        case 11:
            print("output horizontal tabstops", *message);
            *option = 11;
            break;
        case 12:
            print("output horizontal tab disposition", *message);
            *option = 12;
            break;
        case 13:
            print("output formfeed disposition", *message);
            *option = 13;
            break;
        case 14:
            print("output vertical tabstops", *message);
            *option = 14;
            break;
        case 15:
            print("output vertival tab disposition", *message);
            *option = 15;
            break;
        case 16:
            print("output linefeed disposition", *message);
            *option = 16;
            break;
        case 17:
            print("extended ASCII", *message);
            *option = 17;
            break;
        case 18:
            print("logout", *message);
            *option = 18;
            break;
        case 19:
            print("byte macro", *message);
            *option = 19;
            break;
        case 20:
            print("data entry terminal", *message);
            *option = 20;
            break;
        case 21:
            print("SUPDUP", *message);
            *option = 21;
            break;
        case 22:
            print("SUPDUP output", *message);
            *option = 22;
            break;
        case 23:
            print("send location", *message);
            *option = 23;
            break;
        case 24:
            print("terminal type", *message);
            *option = 24;
            break;
        case 25:
            print("end of record", *message);
            *option = 25;
            break;
        case 26:
            print("TACAS user identification", *message);
            *option = 26;
            break;
        case 27:
            print("output marking", *message);
            *option =27;
            break;
        case 28:
            print("terminal location number", *message);
            *option = 28;
            break;
        case 29:
            print("TELNET 3270 regime", *message);
            *option = 29;
            break;
        case 30:
            print("X3 PAD", *message);
            *option = 30;
            break;
        case 31:
            print("negotiate about window size", *message);
            *option = 31;
            break;
        case 32:
            print("terminal speed", *message);
            *option = 32;
            break;
        case 33:
            print("remote flow control", *message);
            *option = 33;
            break;
        case 34:
            print("line mode", *message);
            *option = 34;
            break;
        case 35:
            print("X display location", *message);
            *option = 35;
            break;
        case 36:
            print("env option", *message);
            *option = 36;
            break;
        case 37:
            print("TELNET authentification option", *message);
            *option = 37;
            break;
        case 38:
            print("encryption option", *message);
            *option = 38;
            break;
        case 39:
            print("new env option", *message);
            *option = 39;
            break;
        case 40:
            print("TN3270E", *message);
            *option = 40;
            break;
        case 41:
            print("XAUTH", *message);
            *option = 41;
            break;
        case 42:
            print("CHARSET", *message);
            *option = 42;
            break;
        case 43:
            print("telnet remote serial port", *message);
            *option = 43;
            break;
        case 44:
            print("com port control option", *message);
            *option = 44;
            break;
        case 45:
            print("telnet suppress local echo", *message);
            *option = 45;
            break;
        case 46:
            print("telnet start TLS", *message);
            *option = 46;
            break;
        case 47:
            print("KERMIT", *message);
            *option = 47;
            break;
        case 48:
            print("SEND-URL", *message);
            *option = 48;
            break;
        case 49:
            print("FORWARD_X", *message);
            *option = 49;
            break;
        case 138:
            print("TELOPT PRAGMA LOGON", *message);
            *option = 138;
            break;
        case 139:
            print("TELOPT SSPI LOGON", *message);
            *option = 139;
            break;
        case 140:
            print("TELOPT PRAGMA HEARTBEAT", *message);
            *option = 140;
            break;
        case 255:
            print("EXOPL", *message);
            *option = 255;
            break;
        default:
            *i = *i-1;
            break;
    }
}
