//http://www.rngtng.com/2009/05/17/arduino-fade-and-pulse-a-led-with-just-using-a-digitalport/


int ledPin = 13;
unsigned int i = 0;
boolean rise = true;
int period = 1000;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
  if (i == period)
  {
    i = 1;
    rise = !rise;
  }
  if (rise == false)
  {
    digitalWrite(LED_BUILTIN, LOW);
    delayMicroseconds(i);
    digitalWrite(LED_BUILTIN, HIGH);
    delayMicroseconds(period - i);
    i = i + 1;
  }
  if (rise == true)
  {
    digitalWrite(13, LOW);
    delayMicroseconds(period - i);
    digitalWrite(13, HIGH);
    delayMicroseconds(i);
    i = i + 1;
  }
}

void breath_led(int led_pin, period){
  
}

