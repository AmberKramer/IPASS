#include "TCS3200.hpp"
#include "hwlib.hpp"
//#include "frequency.hpp"

void TCS3200::SetScale(int a, int b){
    if(a<2 and b<2){
        s0.write(a);
        s0.flush();
        s1.write(b);
        s1.flush();
    }
}

void TCS3200::Scan(){
    
    red=ScanColor(0,0);
    clear=ScanColor(1,0);
    blue=ScanColor(0,1);
    green=ScanColor(1,1);
}

int TCS3200::ScanColor(int c, int d){
    frequency freq(out,50);
    if(c<2 and d<2){
        s2.write(c);
        s3.write(d);
        freq.measure();
        return freq.result;
    }
    return 0;
}
