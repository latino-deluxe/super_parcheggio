#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Sistema di define per gestire le variabili globali
#ifndef MAIN
#define extr extern
#else
#define extr
#endif



//Luci
#define FTR1 A0
#define LIGHTSPIN 5

//Pulsanti
#define PU1 2
#define PU2 3

//LED Sbarra
#define LY1 6
#define LY2 7

//IR
#define IR1 A3
#define IR2 A4
#define EM 11

//Variabili globali fotoresistori
extr int FR1;
extr bool sunny;

//Variabili globali parking bar
extr int VP1;
extr int VP2;
extr bool entry1;
extr bool entry2;
extr bool exit1;
extr bool exit2;
extr bool AAAAA;
extr bool BBBBB;
extr bool entrata;

//Variabili globali valore infrarossi
extr int VIR1;
extr int VIR2;

//Variabili posti
extr int posti;

//Variabile ciclo for
extr int i;
