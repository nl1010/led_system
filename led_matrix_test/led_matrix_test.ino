

//fade control
int max_fade_intensity = 255;
int min_fade_intensity = 40;
int fade_intensity_decrement_step = 5; //ms
int dimming_step = 30; //ms 
int lighting_interval = 1000; //ms
int fades_interval = 1000; //ms 
// end of fade control 

//matrix vars 
int rings[2] = {2 ,4};
int sectors[2] = {9,10};
// ==>
int matrix_pins[2][2] = {
  {2,4},
  {9,10}
};
// end of matrix vars

//test vars
int LA1[2] = {rings[0], sectors[0]};
int LA2[2] = {rings[0], sectors[1]};
int LB1[2] = {rings[1], sectors[0]};
int LB2[2] = {rings[1], sectors[1]};
//


void setup() {
  Serial.begin(9600);
  // init all pins
  for (int i=0; i<2; i++){
    for (int j=0; j<2; j++){
      pinMode(matrix_pins[i][j], OUTPUT);
    }
  }

  //set up pins need to light up 

}

void loop() {
//  fade_pwm_led(LA1);
  fade_pwm_led(2,10);
}


void fade_pwm_led(int x, int y) {
  digitalWrite(x, LOW); //enable sector
//  digitalWrite(4, HIGH); //disable other sectors
//  matrix_aux_enable_sectors();
//  digitalWrite(4, HIGH); //shut down the LED ** need test the damage *** 
  for (int fadeValue = min_fade_intensity ; fadeValue <= max_fade_intensity; fadeValue += fade_intensity_decrement_step) {
    // sets the value (range from 0 to 255):
    
    analogWrite(y, fadeValue);
    // wait for n milliseconds to see the dimming effect
    delay(dimming_step);
  }
  delay (lighting_interval);
  for (int fadeValue = max_fade_intensity ; fadeValue >= min_fade_intensity; fadeValue -= fade_intensity_decrement_step) {
    // sets the value (range from 0 to 255):
//    analogWrite(10, fadeValue);
    analogWrite(y, fadeValue);
    // wait for n milliseconds to see the dimming effect
    delay(dimming_step);
  }
    delay (fades_interval);
//  matrix_aux_clear_leds();
}

// enable the sector number and disable others 
void matrix_aux_enable_sectors(int sectors[]){
  
}

void matrix_aux_clear_leds(){
  for (int i=0; i< (sizeof(rings)/sizeof(int)); i++) {
    analogWrite(rings[i], 0);
  }
  for (int j=0; j< (sizeof(sectors)/sizeof(int)); j++){
    digitalWrite(sectors[j], HIGH);
  }
}



