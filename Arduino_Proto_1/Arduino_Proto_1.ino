#include <Stepper.h>

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

#include <TM1638.h>

// define a module on data pin 12, clock pin 13 and strobe pin 11 
TM1638 module(12, 13, 11);

byte buttons, oldbuttons;

int Players = 4;
int Cards = 5;

bool Deal = false;



void setup() {

  Serial.begin(9600);

  oldbuttons = 0;



}

void loop() {

    

    // display a variables at 1st and 5th position
  module.setDisplayDigit(Players, 0, false);
  module.setDisplayDigit(Cards, 4, false);
  

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
                            case 16:
                                Cards = ++Cards;
                                buttons = 0;
                                break;
                            case 32:
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
    Serial.print (Players);
    Serial.print (Cards);
    Deal = false;
    //Test    
    
   }

  /*Serial.print (Players);
  Serial.print (Cards);
  Serial.print (Deal);
  //Serial.print (buttons);
  */
  }
