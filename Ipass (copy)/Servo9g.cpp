#include "Servo9g.hpp"
#include "hwlib.hpp"


void Servo::SetPosition(int P){
    if(P==1){
        for(int i=0;i<6;i++){
            wave.write(1);
            wave.flush();
            hwlib::wait_ms(1);
            wave.write(0);
            wave.flush();
            hwlib::wait_ms(19);
        }
    }else if(P==2){
        for(int i=0;i<6;i++){
            wave.write(1);
            wave.flush();
            hwlib::wait_ms(2);
            wave.write(0);
            wave.flush();
            hwlib::wait_ms(18);
        }
    }else{
        for(int i=0;i<6;i++){
            wave.write(0);
            wave.flush();
            hwlib::wait_ms(20);
        }
    }
}