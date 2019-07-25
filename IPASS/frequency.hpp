#ifndef FREQUENCY_HPP
#define FREQUENCY_HPP 

#include "hwlib.hpp"

/// @file

/// \brief
/// frequency class
/// \details
/// 
/// This is a library that measures the frequency coimming in on a given pin.
/// There is also a sampleAmount saved, to determine how often the scan is taken.
class frequency {   
private:
    hwlib::pin_in & input;
    int sampleAmount;
    
/// \brief
/// Result variable
/// \details
///
/// This variable is used to calculate the end result of the measurement(s).
/// It's set to zero to make sure no other (magic) values are entered when initialized.
    int result=0; 


public:
    
/// \brief
/// Constructor
/// \details
/// This constructor sets up the input pin that'll give the frequency.
/// The sample amount is also set and has a standerd value of 1, 
/// so if the users doesn't enter an amount it scans once.

    frequency ( 
    hwlib::pin_in & input, 
    int  sampleAmount = 1 
    ):
        input(input), 
        sampleAmount(sampleAmount)
    {}
    
/// \brief
/// Measure function
/// \details
/// This function measures and calculats the frequency and returns in as an int.
    int measure();
};

#endif // FREQUENCY_HPP