
byte leds[2][2];






void setup() {
  // put your setup code here, to run once:
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
}
void loop(){
   digitalWrite(2,LOW);
   digitalWrite(4,LOW);
   for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
}


//
//void loop() {
//  digitalWrite(12,LOW);
//  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
//    // sets the value (range from 0 to 255):
//    analogWrite(9, fadeValue);
//    // wait for 30 milliseconds to see the dimming effect
//    delay(30);
//  }
//
//  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
//    // sets the value (range from 0 to 255):
//    analogWrite(9, fadeValue);
//    // wait for 30 milliseconds to see the dimming effect
//    delay(30);
//  }  

  
    
  
  // put your main code here, to run repeatedly:

}
