int pins[] = {12, 11, 10, 9, 8};

void setup(){
  int a = 0;
  while ( a < sizeof(pins)/2){
    pinMode(pins[a], OUTPUT);
    a++;
    
  }
}

void loop(){
  int a = 0;
    while (a < sizeof (pins)/2){
    analogWrite(pins[a], 255);
    delay (1000);
    a++; 
  }
  
  a -= a;
  while (a < sizeof (pins)/2){
    analogWrite(pins[a], 0);
    delay (1000);
    a++;
  }
}
