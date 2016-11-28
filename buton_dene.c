#include <16f628A.h>
#fuses INTRC
#use delay(clock=4M)
#use rs232 (baud=2400, xmit=pin_b2, rcv=pin_b1, parity=N)

#define btn1 pin_b4
#define btn2 pin_b5
#define btn4 pin_b6
#define btn8 pin_b7



char btn_oku(){
             unsigned char tus=0;
             
             if(input(btn1)){ tus |=0x01;  }
             if(input(btn2)){ tus |=0x02; }
             if(input(btn4)){ tus |=0x04; }
             if(input(btn8)){ tus |=0x08; }

return tus;

}

void main()
{
    set_tris_b(0xF0);
   
    
    while(1){
    
        
        while(btn_oku()!=0) {
        
                printf ("%d\n\r", putc(btn_oku()));
        
                output_A(btn_oku());
        
                delay_ms(250);
        }
    }

}
