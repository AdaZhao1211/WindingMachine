//this will run only once
int temp = 0;
void setup() {
  pinMode(9, OUTPUT); //pin 9 to TIP122
  Serial.begin(9600);
}


//this will run forever
void loop() {
  if (Serial.available() > 0) {
    Serial.println("reading");
    temp = Serial.parseInt();
  }
  digitalWrite(9, temp);
}
