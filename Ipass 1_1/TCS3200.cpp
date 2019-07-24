#include "TCS3200.hpp"
#include "hwlib.hpp"

void TCS3200::SetScale(bool a, bool b){
    s0.write(a);
    s0.flush();
    s1.write(b);
    s1.flush();
}

void TCS3200::Scan(){
    red=ScanColor(0,0);
    clear=ScanColor(1,0);
    blue=ScanColor(0,1);
    green=ScanColor(1,1);
}

int TCS3200::ScanColor(bool c, bool d){
    frequency freq(out,50);
    s2.write(c);
    s3.write(d);
    return freq.measure();
}
