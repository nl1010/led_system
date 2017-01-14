//
//int s0 = 2;
//int s1 = 3;
//int s2 = 4;
//int s3 = 5;
enum { s0 = 2, s1 = 3, s2 = 4, s3 = 5};
int SIG_pin = 9; 


int channels[] = {1,2,3,4,5};

void setup() {
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  analogWrite(SIG_pin, 255);
  Serial.begin(9600);
  Serial.println(sizeof(channels));
}

void loop() {
  read_mul_mux(channels);
//  Serial.println(sizeof(channels));
}


void read_mul_mux (int channels[]) {
  Serial.println(sizeof(channels));

  for (int i = 0; i<(sizeof(channels)/sizeof(int)); i++) {
    read_mux(channels[i]);
  }
}


void read_mux(int channel){
  int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }



  //read the value at the SIG pin
//  int val = analogRead(SIG_pin);

  //return the value
//  return val;
}

