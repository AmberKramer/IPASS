#include "frequency.hpp"
#include "hwlib.hpp"

int frequency::measure(){
    
    for(int i=0; i<sampleAmount; i++){
        while (input.read());
        while (!input.read());
        int t1=hwlib::now_us();
        while (input.read());
        while (!input.read());
        int t2=hwlib::now_us();
        result=result+(t2-t1);
    }
    result=result/sampleAmount;
    return result;
}