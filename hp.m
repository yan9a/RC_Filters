%High pass filter
clc;
clear all;
close all;

R=22e3 %resistance (Ohm)
C=1e-6 %capacitance (F)
vc=1/(R*C) %angular cutoff frequency (rad/s)
fc=1/(2*pi*R*C) %cutoff frequency (Hz)
RC=R*C
H=tf([RC 0],[RC 1]) %transfer function for 1/(sRC+1)
T=0.01 %sampling period (second)
Hd=c2d(H,T,'zoh') %discrete model using zero order hold
a=exp(-T/(RC)) %just to check coefficient

figure;
step(H,'-',Hd,'--')%check step response

figure;
bode(H,Hd) %check bode plot 

figure;
margin(Hd);%check gain margin and phase margin
