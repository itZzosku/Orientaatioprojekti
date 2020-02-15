

/*
Library examples for TM1638.

Copyright (C) 2011 Ricardo Batista <rjbatista at gmail dot com>

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <Stepper.h>

const int stepsPerRevolution = 200;

// initialize the stepper library on pins 7 through 10:
Stepper myStepper1(stepsPerRevolution, 7, 8, 9, 10);

// initialize the stepper library on pins 3 through 6:
Stepper myStepper2(stepsPerRevolution, 3, 4, 5, 6);

#include <TM1638.h>
// define a module on data pin 12, clock pin 13 and strobe pin 11 
TM1638 module(12, 13, 11, true, 1);

byte buttons, oldbuttons;

bool Deal = false;

int Players = 4;
int Cards = 5;
int Dealt_Cards = 0;

void setup() {


  // set the speed at 60 rpm:
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);
  
  Serial.begin(9600);


}

void loop() {

    

    // display a variables at 1st and 5th position
  module.setDisplayDigit(Players, 0, false);
  module.setDisplayDigit(Cards, 3, false);


  buttons = module.getButtons();


  if (buttons != 0) 
  {
      delay(300);
                            
                    switch (buttons)
                    
                      {
                            case 1:
                                Players = ++Players;
                                buttons = 0;
                                break;
                            case 2:
                                Players = --Players;
                                buttons = 0;
                                break;
                            case 8:
                                Cards = ++Cards;
                                buttons = 0;
                                break;
                            case 16:
                                Cards = --Cards;
                                buttons = 0;
                                break;
                            case 128:
                                Deal = true;
                                buttons = 0;
                                break; 
                                
                        }

  
    }

  if (Deal == true)
  {
    for (int i = 0; i < Cards; i++)
      {
        // step one revolution  in one direction:
        Serial.println("myStepper2 clockwise");
        myStepper2.step(stepsPerRevolution);
        ++Dealt_Cards;
        module.setDisplayToDecNumber(Dealt_Cards, 0, false);
        //Serial.println (Players);
        //Serial.println (Cards);  
        delay(100);
      }

    Serial.println("myStepper1 clockwise");
    myStepper1.step(stepsPerRevolution);
    delay(100);
    Serial.println("myStepper1 clockwise");
    myStepper1.step(stepsPerRevolution);

    for (int i = 0; i < Cards; i++)
      {
        // step one revolution  in one direction:
        Serial.println("myStepper2 clockwise");
        myStepper2.step(stepsPerRevolution);
        ++Dealt_Cards;
        module.setDisplayToDecNumber(Dealt_Cards, 0, false);
        //Serial.println (Players);
        //Serial.println (Cards);  
        delay(100);
      }

    Serial.println("myStepper1 clockwise");
    myStepper1.step(stepsPerRevolution);
    delay(100);
    Serial.println("myStepper1 clockwise");
    myStepper1.step(stepsPerRevolution);

    for (int i = 0; i < Cards; i++)
      {
        // step one revolution  in one direction:
        Serial.println("myStepper2 clockwise");
        myStepper2.step(stepsPerRevolution);
        ++Dealt_Cards;
        module.setDisplayToDecNumber(Dealt_Cards, 0, false);
        //Serial.println (Players);
        //Serial.println (Cards);  
        delay(100);
      }

    Serial.println("myStepper1 clockwise");
    myStepper1.step(stepsPerRevolution);
    delay(100);
    Serial.println("myStepper1 clockwise");
    myStepper1.step(stepsPerRevolution);

    for (int i = 0; i < Cards; i++)
      {
        // step one revolution  in one direction:
        Serial.println("myStepper2 clockwise");
        myStepper2.step(stepsPerRevolution);
        ++Dealt_Cards;
        module.setDisplayToDecNumber(Dealt_Cards, 0, false);
        //Serial.println (Players);
        ////Serial.println (Cards);   
        delay(100);
      }

    Serial.println("myStepper1 clockwise");
    myStepper1.step(stepsPerRevolution);
    delay(100);
    Serial.println("myStepper1 clockwise");
    myStepper1.step(stepsPerRevolution);

      Deal = false;
      Dealt_Cards = 0;
      
   }

  /*Serial.print (Players);
  Serial.print (Cards);
  Serial.print (Deal);
  //Serial.print (buttons);
  */
  }
