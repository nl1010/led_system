

//fade control
int max_fade_intensity = 255;
int fade_intensity_decrement_step = 5; //ms
int dimming_step = 30; //ms 
int lighting_interval = 1000; //ms
int fades_interval = 1000; 
// end of fade control 

//matrix 
int rings[2] = {2 ,4};
int sectors[2] = {9,10};



void setup() {
  // put your setup code here, to run once:
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
}
void loop() {
  fade_pwm_led(2, 9);
  fade_pwm_led(2,10);
}


void fade_pwm_led(int x, int y) {
  digitalWrite(x, LOW);
//  matrix_aux_set_sectors();
//  digitalWrite(4, HIGH); //shut down the LED ** need test the damage *** 
  for (int fadeValue = 0 ; fadeValue <= max_fade_intensity; fadeValue += fade_intensity_decrement_step) {
    // sets the value (range from 0 to 255):
//    analogWrite(10, fadeValue);
    analogWrite(y, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(dimming_step);
  }
  delay (lighting_interval);
  for (int fadeValue = max_fade_intensity ; fadeValue >= 0; fadeValue -= fade_intensity_decrement_step) {
    // sets the value (range from 0 to 255):
//    analogWrite(10, fadeValue);
    analogWrite(y, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(dimming_step);
  }
    delay (fades_interval);
  matrix_aux_clear_leds();
}

void matrix_aux_clear_leds(){
  for (int i=0; i< (sizeof(rings)/sizeof(int)); i++) {
    analogWrite(rings[i], 0);
  }
  for (int j=0; j< (sizeof(sectors)/sizeof(int)); j++){
    digitalWrite(sectors[j], HIGH);
  }
}



