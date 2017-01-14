#include <LEDFader.h>

// Create new LED Fader on pin 3
LEDFader led = LEDFader(9);

//MUX

enum { s0 = 2, s1 = 3, s2 = 4, s3 = 5};
int SIG_pin = 9;

int channels[] = {0,1, 2,8,10,11,12,13,14,15};
#define NUM_CHANNELS (sizeof(channels)/sizeof(int))

int muxChannel[16][4] = {
  {0, 0, 0, 0}, //channel 0
  {1, 0, 0, 0}, //channel 1
  {0, 1, 0, 0}, //channel 2
  {1, 1, 0, 0}, //channel 3
  {0, 0, 1, 0}, //channel 4
  {1, 0, 1, 0}, //channel 5
  {0, 1, 1, 0}, //channel 6
  {1, 1, 1, 0}, //channel 7
  {0, 0, 0, 1}, //channel 8
  {1, 0, 0, 1}, //channel 9
  {0, 1, 0, 1}, //channel 10
  {1, 1, 0, 1}, //channel 11
  {0, 0, 1, 1}, //channel 12
  {1, 0, 1, 1}, //channel 13
  {0, 1, 1, 1}, //channel 14
  {1, 1, 1, 1} //channel 15
};




void setup() {
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  read_mux(channels, NUM_CHANNELS);

//  led.fade(255, 3000);

}

void loop() {
  led.update();
  if (led.is_fading() == false) {
    // Fade from 255 - 0
    if (led.get_value() == 255) {
      led.fade(0, 1000);
    }
    // Fade from 0 - 255
    else {
      led.fade(255, 1000);
    }
  }
  read_mux(channels, NUM_CHANNELS);
  
}

void read_mux(int channels[], int loop_size) {
  for (int j = 0; j < loop_size; j++) {
//    Serial.println(channels[j]);
    int controlPin[] = {s0, s1, s2, s3};
    //loop through the 4 sig
    for (int i = 0; i < 4; i ++) {
      digitalWrite(controlPin[i], muxChannel[channels[j]][i]);
      led.update();
    }
  }
}


