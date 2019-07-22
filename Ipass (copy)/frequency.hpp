#ifndef FREQUENCY_HPP
#define FREQUENCY_HPP 

#include "hwlib.hpp"


class frequency {   
private:
    int t1;
    int t2;
    hwlib::pin_in & input;
    int sampleAmount;

public:
    int result=0; 
    
    frequency ( 
    hwlib::pin_in & input, 
    int  sampleAmount = 1 
    ):
        input(input), 
        sampleAmount(sampleAmount)
    {}
    
    void measure();
};

#endif // FREQUENCY_HPP