
#include "vm.h"
#include "hal.h"
#include "out.h"
#include <avr/io.h>


#define FOSC  16000000 // Clock Speed
#define BAUD 57600
#define MYUBRR FOSC/16/BAUD-1
#define MS_DELAY 1000

#define Target      "(ATMega328P)"
#define VMName      "Cm Virtual Machine "
#define AppSuffix   ""
#define AppName     "cm"
#define Version     " v0.1.00.1101a "
#define Copyright   "Copyright (c) 2001-2020  Michel de Champlain"

#define SuccessCmd 0x40
#define UnknownCmd 0x41
#define InvalidCmd 0x42
#define InvalidAddr 0x43
#define MemoryFailed 0x44
#define ChecksumInvalid 0x45
#define Ack 0xCC
#define Nack 0x33
#define statusPacketSize 0x03

u8 USART_Receive(void){
  
    /* Wait for data to be received */
    while (!(UCSR0A & (1<<RXC0)));
    /* Get and return received data from buffer */
    return UDR0;
}


u8* uart_get(u8 len) {
    u8 recv_byte;
    int size_counter = 0;
    u8* recv = (u8*)malloc(len);
    memset(recv,0,len);

    while(len--){
        recv_byte = USART_Receive();
        recv[size_counter++] = recv_byte; 
    } 
    return recv;
}


static void DisplayBanner() {
    VMOut_PutS(VMName); VMOut_PutS(AppSuffix); VMOut_PutS(Version); VMOut_PutS(Target); VMOut_PutN();
    VMOut_PutS(Copyright); VMOut_PutN();
}

void sendAck(){
    VMOut_PutC((char)Ack); 
    VMOut_PutC((char)0);
}

void sendNack(){
    VMOut_PutC((char)Nack); 
    VMOut_PutC((char)0);

}

void sendStatus(status){
    VMOut_PutC((char)Ack);
    VMOut_PutC((char)statusPacketSize);
    VMOut_PutC((char)status);
    VMOut_PutC((char)status);
    VMOut_PutC((char)0);
}

int checksum(u8 len, u8* mem){
    int checksumInPacket = mem[0];
    int checksum = 0;
    int i = 0;
    for (i = 1; i < len; i++){
        checksum += mem[i];
    }
    if ((checksum &=checksumInPacket) == checksumInPacket)
        return 1;
    else 
        return 0;

}



int main (void) {
   
    Hal_Init();
    u8 *mem = 0;
    u8 *ptr = 0;
    u8 *zero = 0;
    int dataSize = 0, chunkSize = 0, verifyChecksum = 1;
    static u8 status = 0;

    while(1){

        u8 len = USART_Receive(); //receive lenght of incoming packet
        if (len < 3){   // the min lenght of a packet is 3 bytes
            status = InvalidAddr;
            continue;
        }else {
            mem = uart_get(len-1); // receive the packet without the size byte because we already got it
            u8 zero = USART_Receive(); // receive zero   

            verifyChecksum = checksum(len-1, mem);
            chunkSize = len-3;  // payload in packet
        }

        switch(mem[1]){  // mem[1] is the commnad 
            case 32: {   // ping
                sendAck();
                status = SuccessCmd;
            } break;
            case 36: { // receiving data
                if(chunkSize) {

                    if(verifyChecksum == 1){
                        ptr = (u8*)realloc(ptr,dataSize+chunkSize);
                        memcpy(ptr + dataSize, mem+2, chunkSize);
                        dataSize += chunkSize;
                        status = SuccessCmd;
                        sendAck();
                    }else {
                        status = ChecksumInvalid;
                        sendNack();
                    }   
                }
                else{
                    status = InvalidAddr;
                    sendNack();
                }
               
            } break;
            case 34: {  // run
                sendAck();
                DisplayBanner();
                VM_Init(ptr);
                VM_execute(ptr);
                sendAck();
                status = SuccessCmd;
                free(ptr);
                ptr = 0;
            } break;
            case 35: {  // getStatus
                //sendAck();
                sendStatus(status);
            } break;
            default: {
                status = UnknownCmd;
            }
        }
        free(mem);
        USART_Flush();
    }
}