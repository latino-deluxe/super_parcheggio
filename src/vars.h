#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#ifndef MAIN
#define extr extern
#else
#define extr
#endif



//Luci
#define FTR1 A0
#define FTR2 A1
#define LIGHTSPIN 12

//Pulsanti
#define PU1 2

//IR
#define IR1 A5
#define IR2 A3
#define IR3 A4
#define EM 11

extr int FR1;
extr int FR2;
extr int FRM;
extr bool sunny;

extr int VP1;
extr bool entry1;
extr bool entry2;
extr bool exit1;
extr bool exit2;

extr int VIR1;
extr int VIR2;
extr int VIR3;

extr int i;

extr int posti;
