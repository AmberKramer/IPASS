#include "ServoSupport.hpp"
#include "hwlib.hpp"


void Servo::SetServoPosition(int P){
    if(P==1){
        for(int i=0;i<6;i++){
            servoInput.write(1);
            servoInput.flush();
            hwlib::wait_ms(1);
            servoInput.write(0);
            servoInput.flush();
            hwlib::wait_ms(19);
        }
    }else if(P==2){
        for(int i=0;i<6;i++){
            servoInput.write(1);
            servoInput.flush();
            hwlib::wait_ms(2);
            servoInput.write(0);
            servoInput.flush();
            hwlib::wait_ms(18);
        }
    }else{
        for(int i=0;i<6;i++){
            servoInput.write(0);
            servoInput.flush();
            hwlib::wait_ms(20);
        }
    }
}