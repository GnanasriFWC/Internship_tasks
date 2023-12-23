#include <avr/io.h>

int main(void){
        
    int P = 1,Q=1;
    
    DDRD |= (1 << PD3);
    
    int result = ((P & Q) | (!P));
    PORTD |= (result << PD3);
    
}
