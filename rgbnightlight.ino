/*
  SparkFun Inventor’s Kit
  Circuit 1D-RGB Nightlight

  Turns an RGB LED on or off based on the light level read by a photoresistor.
  Change colors by turning the potentiometer.

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/
/* define the pins corresponding to components*/

#define photoresistor A0
#define potentiometer A1

//LEDS
#define redLED 9
#define greenLED 10
#define blueLED 11

int threshold = 400;            //if the photoresistor reading is lower than this value the light will turn on

//the darker the lower the value for the photoresistor
//the brighter the higher the value


void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {

  int photoVal = analogRead(photoresistor);         //read the value of the photoresistor
  int potentVal = 2*analogRead(potentiometer);

  Serial.print("Photoresistor value:");
  Serial.print(photoVal);          //print the photoresistor value to the serial monitor
  Serial.print("  Potentiometer value:");
  Serial.println(potentVal);          //print the potentiometer value to the serial monitor

  if (photoVal < threshold) {        //if it's dark (the photoresistor value is below the threshold) turn the LED on
    //These nested if statements check for a variety of ranges and
    //call different functions based on the current potentiometer value.
    //Those functions are found at the bottom of the sketch.
    if (potentVal > 0 && potentVal <= 204)
      red();
    if (potentVal > 204 && potentVal <= 409)
      orange();
    if (potentVal > 409 && potentVal <= 613)
      green();
    if (potentVal > 613 && potentVal <= 818)
      olive();
    if (potentVal > 818 && potentVal <= 1023)
      teal();
    if (potentVal > 1023 && potentVal <= 1227)
      blue();
    if (potentVal > 1227 && potentVal <= 1432)
      lilac();
    if (potentVal > 1432 && potentVal <= 1636)
      pink();
    if (potentVal > 1636 && potentVal <= 1841)
      grey();
    if (potentVal > 1841)
      white();
  }
  else {                                //if it isn't dark turn the LED off

    turnOff();                            //call the turn off function

  }

  delay(100);                             //short delay so that the printout is easier to read
}

void red () {

  //set the LED pins to values that make red
  analogWrite(redLED, 100);
  analogWrite(greenLED, 0);
  analogWrite(blueLED, 0);
}
void orange () {

  //set the LED pins to values that make orange
  analogWrite(redLED, 100);
  analogWrite(greenLED, 50);
  analogWrite(blueLED, 0);
}
void yellow () {

  //set the LED pins to values that make yellow
  analogWrite(redLED, 100);
  analogWrite(greenLED, 100);
  analogWrite(blueLED, 0);
}
void green () {

  //set the LED pins to values that make green
  analogWrite(redLED, 0);
  analogWrite(greenLED, 100);
  analogWrite(blueLED, 0);
}

void teal(){
    analogWrite(redLED,0);
    analogWrite(greenLED, 50);
    analogWrite(blueLED,50);
}
void cyan () {

  //set the LED pins to values that make cyan
  analogWrite(redLED, 0);
  analogWrite(greenLED, 100);
  analogWrite(blueLED, 100);
}
void blue () {

  //set the LED pins to values that make blue
  analogWrite(redLED, 0);
  analogWrite(greenLED, 0);
  analogWrite(blueLED, 100);
}
void navy (){
    analogWrite(redLED, 0);
    analogWrite(greenLED, 0);
    analogWrite(blueLED, 50);
}
void magenta () {

  //set the LED pins to values that make magenta
  analogWrite(redLED, 100);
  analogWrite(greenLED, 0);
  analogWrite(blueLED, 100);
}

void lilac(){
    analogWrite(redLED, 62);
    analogWrite(greenLED, 14);
    analogWrite(blueLED, 100);
}

void white(){
    analogWrite(redLED, 100);
    analogWrite(greenLED, 100);
    analogWrite(blueLED,100);
}
void pink(){
    analogWrite(redLED, 100);
    analogWrite(greenLED, 10);
    analogWrite(blueLED, 40);
}

void olive(){
    analogWrite(redLED,50);
    analogWrite(greenLED, 50);
    analogWrite(blueLED, 0);
}

void grey (){
    analogWrite(redLED,50);
    analogWrite(greenLED, 50);
    analogWrite(blueLED, 50);
}

void turnOff () {

  //set all three LED pins to 0 or OFF
  analogWrite(redLED, 0);
  analogWrite(greenLED, 0);
  analogWrite(blueLED, 0);
}
