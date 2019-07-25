#include "Servo9g.hpp"
#include "TCS3200.hpp"
#include "hwlib.hpp"

int main(void){
    namespace target = hwlib::target;
    
    auto start = target::pin_out( target::pins::d7 );
    
    auto button = target::pin_in( target::pins::d3 );
    
while(true){

    if(button.read()==1){
        start.write(1);
        start.flush();
//        for(int i=0;i<6;i++){
//            start.write(1);
//            start.flush();
//            hwlib::wait_ms(1);
//            start.write(0);
//            start.flush();
//            hwlib::wait_ms(19); 
//        }
//        
//        hwlib::wait_ms(1000);
//        
//        for(int i=0;i<6;i++){
//            start.write(1);
//            start.flush();
//            hwlib::wait_ms(2);
//            start.write(0);
//            start.flush();
//            hwlib::wait_ms(18);
//        }     
    }
    else{
        start.write(0);
        start.flush();
    }
}
}