/* ETUDE 4 
 *  Adèle Bédard & Jessica Filippelli
 *  The goal of our etude is to modify the controllers for the 
 *  skateboard online game Sk8boarder.
 *  
 *  Instead of using the 'x' and 'a' as controls, it uses a hand 
 *  driven controler, in that case the breadboard.
 *  We used an accelerometer and a sound sensor.
 *  We tried using also a knock sensor, to sense horizontal 
 *  vibrations, but it did not work correctly for our usage, because
 *  it could also sense our vertical vibrations, which had to be
 *  independant. The accelerometer allowed more control on 
 *  direction, so that is why we chose to use only the accelerometer 
 *  for this purpose.
 *  
 *  In the original game, the player had to press 'x' to crouch, 
 *  then release it to jump, then press x again to tilt the 
 *  skateboard to stay on the rail.
 *  In our version, the player has to move the controler 
 *  horizontally to crouch, then vertically to jump, and then 
 *  to the left so that the skateboard tilts to the left.
 *  
 *  In the original game, the user could also press 'a' while on
 *  the rail to boost the bottom progression bar.
 *  In our version, you have to make noise to boost the progression
 *  bar, like say words of encouragement.
 *  
 *  The game could alternatively be played with the key 'z', which 
 *  works similarly than the 'x' key, but the board would be tilted
 *  the other way. We tried to implement it, by sensing movement to
 *  the right side, but it did not work properly so we decided to 
 *  remove this functionnality, since it did not enhance the game.
 *  The implementation of it has been put as commentary.

*/ 


#include <Keyboard.h>

int jumpThreshold = 400;
int vibrateLeftThreshold = 390;
int vibrateRightThreshold = 300;
int soundHighThreshold = 250;
int soundLowThreshold = 180;

void setup()
{
  Keyboard.begin();
}
void loop()
{
  // Get raw accelerometer data for each axisz  
  int rawX = analogRead(A0); 
  int rawY = analogRead(A1);
  int rawZ = analogRead(A2);
  
  //Get sound sensor raw data
  int rawS = analogRead(A3); 

  
  //Compare the raw data with thresholds to determine keyboard actions to perform
  
  if (rawS  > soundHighThreshold){
    Keyboard.press('a');
  }
  
  if (rawS < soundLowThreshold) {
    Keyboard.release('a');
  }
  
   if (rawY > jumpThreshold) {
    Keyboard.release('x');
    //Keyboard.release('z');
   }

   if (rawX > vibrateLeftThreshold) {
    Keyboard.press('x');
   }
   
  //if(rawX < vibrateRightThreshold) {
    //Keyboard.press('z');
  //}

  delay(10);
}
