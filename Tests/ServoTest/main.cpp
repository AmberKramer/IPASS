#include "Servo9g.hpp"
#include "hwlib.hpp"

int main(void){
    namespace target = hwlib::target;

    auto button = target::pin_in( target::pins::d3 );
    
    auto start = target::pin_out( target::pins::d7 );
    auto one = target::pin_out( target::pins::d31 );
    auto two = target::pin_out( target::pins::d32 );
    auto three = target::pin_out( target::pins::d35 );
    auto four = target::pin_out( target::pins::d36 );
    auto five = target::pin_out( target::pins::d39 );
    auto six = target::pin_out( target::pins::d40 );
    
    Servo Chamber(start);
    Servo Red(one);
    Servo Orange(two);
    Servo Yellow(three);
    Servo Green(four);
    Servo Blue(five);

while(true){

    if(button.read()==1){
        Chamber.SetPosition(1);
        hwlib::wait_ms(1000);
        Chamber.SetPosition(2); 
        
        Red.SetPosition(2);
        hwlib::wait_ms(1000);
        Red.SetPosition(1);
        
        Orange.SetPosition(2);
        hwlib::wait_ms(1000);
        Orange.SetPosition(1);
        
        Yellow.SetPosition(2);
        hwlib::wait_ms(1000);
        Yellow.SetPosition(1);
        
        Green.SetPosition(2);
        hwlib::wait_ms(1000);
        Green.SetPosition(1);
        
        Blue.SetPosition(2);
        hwlib::wait_ms(1000);
        Blue.SetPosition(1);
    }
}
}