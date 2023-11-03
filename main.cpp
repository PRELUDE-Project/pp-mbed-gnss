#include "mbed.h"
RawSerial gps(p9, p10, 9600);       // TX, RX
RawSerial pc(USBTX, USBRX, 9600);    // TX, RX
// default baud rate of the reciever is 9600
char rcmd, gpsdata;
int main()
{
    pc.printf(">> Get GNSS data Start\r\n");
    pc.printf(">> Please Input Command\r\n");
    while(1){
        rcmd=pc.getc();
        switch(rcmd){
            case '1':
                pc.printf(">>>> LOG VERSION\r\n");
                gps.printf("LOG VERSION\r\n");
                break;
            case '2':
                pc.printf(">>>> LOG RXSTATUS\r\n");
                gps.printf("LOG RXSTATUS\r\n");
                break;
            case '3':
                pc.printf(">>>> LOG GPGGA\r\n");
                gps.printf("LOG GPGGA\r\n");
                break;
            case 'a':
                pc.printf(">>>> LOG GPGGA ONTIME 1\r\n");
                gps.printf("LOG GPGGA ONTIME 1\r\n");
                break;
            case '5':       
                pc.printf(">>>> LOG RANGEA\r\n");
                gps.printf("LOG RANGEA\r\n");
                break;
            case '6':
                pc.printf(">>>> LOG TIMEA\r\n");
                gps.printf("LOG TIMEA\r\n");
                break;
            case '7':
                pc.printf(">>>> LOG RANGEGPSL1A\r\n");
                gps.printf("LOG RANGEGPSL1A\r\n");
                break;
            case '8':
                pc.printf(">>>> LOG RANGEGPSL2A\r\n");
                gps.printf("LOG RANGEGPSL2A\r\n");
                break;
            case 'b':
                pc.printf(">>>> LOG RANGEGPSL1A ONTIME 1\r\n");
                gps.printf("LOG RANGEGPSL1A ONTIME 1\r\n");
                break;
            case 'c':
                pc.printf(">>>> LOG RANGEGPSL2A ONTIME 1\r\n");
                gps.printf("LOG RANGEGPSL2A ONTIME 1\r\n");
                break;
            case 'd':       
                pc.printf(">>>> LOG RANGEA ONTIME 1\r\n");
                gps.printf("LOG RANGEA ONTIME 1\r\n");
                break;
        }
        while(1){
            pc.putc(gps.getc());
        }
    }
}