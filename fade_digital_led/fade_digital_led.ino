//http://www.rngtng.com/2009/05/17/arduino-fade-and-pulse-a-led-with-just-using-a-digitalport/


int led_array[4] = {2,3,4,5};
 
unsigned int i = 0;
boolean rise = true;
int breath_period = 1000;



void setup()
{
  Serial.begin(9600);
  int j;
  for (j=0; j < (sizeof(led_array)/sizeof(int)); j++){
      pinMode(led_array[j], OUTPUT);
    }  
}




//breath the led through certain digital pin 
void breath_led(int leds[], int period){
  if (i == breath_period)
  {
    i = 1;
    rise = !rise;
  }
  if (rise == false)
  {
    int j;
    for (j=0; j < (sizeof(led_array)/sizeof(int)); j++){
      digitalWrite(leds[j], LOW);
    }
    delayMicroseconds(i);
    for (j=0; j < (sizeof(led_array)/sizeof(int)); j++){
      digitalWrite(leds[j], HIGH);
    }
    delayMicroseconds(breath_period - i);
    i = i + 1;
  }
  if (rise == true)
  {
    int j;
    for (j=0; j < (sizeof(led_array)/sizeof(int)); j++){
      digitalWrite(leds[j], LOW);
    }
    delayMicroseconds(breath_period - i);
    for (j=0; j < (sizeof(led_array)/sizeof(int)); j++){
      digitalWrite(leds[j], HIGH);
    }
    delayMicroseconds(i);
    i = i + 1;
  }  
}


void loop()
{
  
  //by manupilating the leds_array elements we could control all
  breath_led(led_array, breath_period);

  
}



