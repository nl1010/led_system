//http://www.rngtng.com/2009/05/17/arduino-fade-and-pulse-a-led-with-just-using-a-digitalport/


int led1 = 2;
unsigned int i = 0;
boolean rise = true;
int breath_period = 1000;



void setup()
{
  pinMode(led1, OUTPUT);
}



void loop()
{
  breath_led(led1, breath_period);
}


//breath the led through certain digital pin 
void breath_led(int led_pin, int period){
  if (i == breath_period)
  {
    i = 1;
    rise = !rise;
  }
  if (rise == false)
  {
    digitalWrite(led_pin, LOW);
    delayMicroseconds(i);
    digitalWrite(led_pin, HIGH);
    delayMicroseconds(breath_period - i);
    i = i + 1;
  }
  if (rise == true)
  {
    digitalWrite(13, LOW);
    delayMicroseconds(breath_period - i);
    digitalWrite(13, HIGH);
    delayMicroseconds(i);
    i = i + 1;
  }  
}

