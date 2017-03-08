// Description: First Order RC filters with Analog Input and Output
// Author: Yan Naing Aye
// http://coolemerald.blogspot.sg/
// Date: 2016 April 21

#include "FOFilters.h"
//--------------------------------------------------------
//Constants 
#define T 0.005    // Sampling time period in second
//--------------------------------------------------------
//define timer
unsigned long cm=0; //current time in milliseconds
unsigned long lm=0; //store last updated time
//--------------------------------------------------------
//external variable
int x=0,y=0;
//--------------------------------------------------------
void setup() {
  analogReadResolution(10);
  //for Arduino Zero (A0 - A5) have 12 bit resolution 
  //but here it is set to match its output.
  analogWriteResolution(10); //for Arduino Zero A0 DAC
  InitLowPass(T,1/(2*PI*22000*0.000001));
  //InitHighPass(T,1/(2*PI*22000*0.000001));
}
void loop() {
  cm=millis(); //get current time
  if((cm-lm)>=(1000*T)) {//if timeout
    lm=cm;   //store the updated time
    //----------------------------------------------------
    //Tasks at each sampling instant    
    x=analogRead(A5);
    y=LowPass(x);
    //y=HighPass(x); y+=512;//shift back to 0-1023 range
    analogWrite(A0,y);//output to A0
    //----------------------------------------------------
  }        
}


