int state = 0;
int output = 0;
void setup() {
  Serial.begin(9600);
  DDRB |= (1 << 5);
}
void loop() {
  for(int i = 1000; i > 0; --i){
    Serial.println(i);
    if(checkIfValid(i)){
      lights(2,200);
      }
    }
}
bool checkIfValid(int in) {
  for (int i = 0; i < 16; ++i) {
  bool bitVal = (in >> 1) & 1;
  state = 0;
  if (state == 0 && bitVal) {
    state = 1;
    output = false;
  } else if (state == 1 && bitVal) {
    state = 2;
    output = 1;
  } else if (state == 2 && !bitVal) {
    state = 2;
    output = 1;
  } else if (state == 3) {
    state = 3;
    output = 0;
  } else {
    output = 0;
  }
}
return output;
}
void lights(int numOfFlash, int offTime){
  for(int i= 0; i < numOfFlash; ++i){
    DDRB |= (1 << 5);
    delay(offTime);
    DDRB |= ~(1 << 5);
    delay(offTime);
    }
  }
