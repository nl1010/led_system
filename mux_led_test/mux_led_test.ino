#include <TaskScheduler.h>


void mux_all_leds_callback();
void fading_signal_gen_callback();

//Tasks
Task t_mux_all_leds(2, TASK_FOREVER, &mux_all_leds_callback);
Task t_fading_signal_gen(2, TASK_FOREVER, &fading_signal_gen_callback);

//scheduler
Scheduler runner;


////

enum { s0 = 2, s1 = 3, s2 = 4, s3 = 5};
int SIG_pin = 9;


int channels[] = {1, 2, 3, 4, 5, 6};
#define NUM_CHANNELS (sizeof(channels)/sizeof(int))



//fade control
int max_fade_intensity = 255;
int min_fade_intensity = 40;
int fade_intensity_decrement_step = 5; //ms
int dimming_step = 30; //ms
int lighting_interval = 1000; //ms
int fades_interval = 1000; //ms
// end of fade control



void mux_all_leds_callback() {
  read_mux(channels, NUM_CHANNELS);
}

void fading_signal_gen_callback() {
  fade_pwm_led(SIG_pin);
}





void read_mux(int channels[], int loop_size) {
  for (int j = 0; j < loop_size; j++) {
    int controlPin[] = {s0, s1, s2, s3};
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
    //loop through the 4 sig
    for (int fadeValue = min_fade_intensity ; fadeValue <= max_fade_intensity; fadeValue += fade_intensity_decrement_step) {
      for (int i = 0; i < 4; i ++) {
        digitalWrite(controlPin[i], muxChannel[channels[j]][i]);
        //      t_mux_all_leds.yield(&fading_signal_gen_callback);
      
      }
//      analogWrite(SIG_pin, fadeValue);
//      delay(dimming_step);
    }
  }
  Serial.println("read_mux");
}


void fade_pwm_led(int led) {
  for (int fadeValue = min_fade_intensity ; fadeValue <= max_fade_intensity; fadeValue += fade_intensity_decrement_step) {

    // sets the value (range from 0 to 255):
    analogWrite(led, fadeValue);
    // wait for n milliseconds to see the dimming effect
//    delay(dimming_step);
    //    t_fading_signal_gen.yield(&mux_all_leds_callback);
  }
  delay (lighting_interval);
  for (int fadeValue = max_fade_intensity ; fadeValue >= min_fade_intensity; fadeValue -= fade_intensity_decrement_step) {
    // sets the value (range from 0 to 255):
    //    analogWrite(10, fadeValue);
    analogWrite(led, fadeValue);
    // wait for n milliseconds to see the dimming effect
//    delay(dimming_step);
  }
//  delay (fades_interval);
  //  matrix_aux_clear_leds();
  Serial.println("fading..");

}







void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  //  analogWrite(SIG_pin, 255);
  Serial.begin(9600);

  runner.init();
  runner.addTask(t_mux_all_leds);
  runner.addTask(t_fading_signal_gen);

  t_mux_all_leds.enable();
  t_fading_signal_gen.enable();


}

void loop() {
  ////  fade_pwm_led(SIG_pin);
  //  read_mux(channels, NUM_CHANNELS);
  runner.execute();
}





