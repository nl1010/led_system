//http://www.rngtng.com/2009/05/17/arduino-fade-and-pulse-a-led-with-just-using-a-digitalport/


int led1 = 2;
int led2 = 3;
unsigned int i = 0;
boolean rise = true;
int breath_period = 1000;



void setup()
{
  pinMode(led1, OUTPUT);
}


void loop()
{
  breath_led(led1, led2, breath_period);
}


//breath the led through certain digital pin 
void breath_led(int led_pin1, int led_pin2,  int period){
  if (i == breath_period)
  {
    i = 1;
    rise = !rise;
  }
  if (rise == false)
  {
    digitalWrite(led_pin1, LOW);
    digitalWrite(led_pin2, LOW);
    delayMicroseconds(i);
    digitalWrite(led_pin1, HIGH);
    digitalWrite(led_pin2, HIGH);
    delayMicroseconds(breath_period - i);
    i = i + 1;
  }
  if (rise == true)
  {
    digitalWrite(led_pin1, LOW);
    digitalWrite(led_pin2, LOW);
    delayMicroseconds(breath_period - i);
    digitalWrite(led_pin1, HIGH);
    digitalWrite(led_pin2, HIGH);
    delayMicroseconds(i);
    i = i + 1;
  }  
}

