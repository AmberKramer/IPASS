#include "frequency.hpp"
#include "hwlib.hpp"

void frequency::measure(){
    
    for(int i=0; i<sampleAmount; i++){
        while (input.read());
        while (!input.read());
        t1=hwlib::now_us();
        while (input.read());
        while (!input.read());
        t2=hwlib::now_us();
        result=result+(t2-t1);
    }
    result=result/sampleAmount;
}