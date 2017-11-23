#include "telnet_option.h"

void print_option(unsigned char * message, int *i, int* option){
    switch(*message){
        case 0:
            print("binary", *message);
            break;
        case 1:
            print("echo", *message);
            break;
        case 2:
            print("reconnection", *message);
            break;
        case 3:
            print("supresse go head", *message);
            break;
        case 4:
            print("approx (*telnet)->message size negotiation", *message);
            break;
        case 5:
            print("status", *message);
            break;
        case 6:
            print("timing mark", *message);
            break;
        case 7:
            print("remote controlled trans and echo", *message);
            break;
        case 8:
            print("output line width", *message);
            break;
        case 9:
            print("output page size", *message);
            break;
        case 10:
            print("ouput carriage return disposition", *message);
            break;
        case 11:
            print("output horizontal tabstops", *message);
            break;
        case 12:
            print("output horizontal tab disposition", *message);
            break;
        case 13:
            print("output formfeed disposition", *message);
            break;
        case 14:
            print("output vertical tabstops", *message);
            break;
        case 15:
            print("output vertival tab disposition", *message);
            break;
        case 16:
            print("output linefeed disposition", *message);
            break;
        case 17:
            print("extended ASCII", *message);
            break;
        case 18:
            print("logout", *message);
            break;
        case 19:
            print("byte macro", *message);
            break;
        case 20:
            print("data entry terminal", *message);
            break;
        case 21:
            print("SUPDUP", *message);
            break;
        case 22:
            print("SUPDUP output", *message);
            break;
        case 23:
            print("send location", *message);
            break;
        case 24:
            print("terminal type", *message);
            break;
        case 25:
            print("end of record", *message);
            break;
        case 26:
            print("TACAS user identification", *message);
            break;
        case 27:
            print("output marking", *message);
            break;
        case 28:
            print("terminal location number", *message);
            break;
        case 29:
            print("TELNET 3270 regime", *message);
            break;
        case 30:
            print("X3 PAD", *message);
            break;
        case 31:
            print("window size", *message);
            break;
        case 32:
            print("terminal speed", *message);
            *option = 32;
            break;
        case 33:
            print("remote flow control", *message);
            break;
        case 34:
            print("line mode", *message);
            break;
        case 35:
            print("X display location", *message);
            break;
        case 36:
            print("env option", *message);
            break;
        case 37:
            print("TELNET authentification option", *message);
            break;
        case 38:
            print("encryption option", *message);
            break;
        case 39:
            print("new env option", *message);
            break;
        case 40:
            print("TN3270E", *message);
            break;
        case 41:
            print("XAUTH", *message);
            break;
        case 42:
            print("CHARSET", *message);
            break;
        case 43:
            print("telnet remote serial port", *message);
            break;
        case 44:
            print("com port control option", *message);
            break;
        case 45:
            print("telnet suppress local echo", *message);
            break;
        case 46:
            print("telnet start TLS", *message);
            break;
        case 47:
            print("KERMIT", *message);
            break;
        case 48:
            print("SEND-URL", *message);
            break;
        case 49:
            print("FORWARD_X", *message);
            break;
        case 138:
            print("TELOPT PRAGMA LOGON", *message);
            break;
        case 139:
            print("TELOPT SSPI LOGON", *message);
            break;
        case 140:
            print("TELOPT PRAGMA HEARTBEAT", *message);
            break;
        case 255:
            print("EXOPL", *message);
            break;
        default:
            *i = *i-1;
            break;
    }
}
