// First Order RC High Pass and Low Pass filters
// Author: Yan Naing Aye
// http://coolemerald.blogspot.sg/
// Date: 2016 April 21
//-----------------------------------------------------
//External variables
float ah=0; //for high pass filter
float al=0; //for low pass filter
//-----------------------------------------------------
//initialize low pass filter
//input: (T: sampling period, fc: cutoff frequency)
void InitLowPass(float T,float fc) {al=exp(-T*2*PI*fc);}
//-----------------------------------------------------
//Low Pass Filter
float LowPass(float x){static float yl=0; yl=x+al*(yl-x); return yl;}
//--------------------------------------------------------
//initialize high pass filter
//input: (T: sampling period, fc: cutoff frequency)
void InitHighPass(float T,float fc) {ah=exp(-T*2*PI*fc);}
//-----------------------------------------------------
//High Pass Filter
float HighPass(float x){static float yh=0,xh=0; yh=ah*(x-xh+yh); xh=x; return yh;}
//-----------------------------------------------------
