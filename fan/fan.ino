int buttonPin = 2; // button连接到数字2
int relayPin = 3; // 继电器连接到数字3
int relayState = HIGH; // 继电器初始状态为HIGH
int buttonState; // 记录button当前状态值
int lastButtonState = LOW; // 记录button前一个状态值
long lastDebounceTime = 0;
long debounceDelay = 50; //去除抖动时间
void setup() {
 pinMode(buttonPin, INPUT);
 pinMode(relayPin, OUTPUT);

digitalWrite(relayPin, relayState); // 设置继电器的初始状态
}
void loop() {
 int reading = digitalRead(buttonPin); //reading用来存储buttonPin的数据

 // 一旦检测到数据发生变化，记录当前时间
 if (reading != lastButtonState) {
 lastDebounceTime = millis();
 } 
  if ((millis() - lastDebounceTime) > debounceDelay) {
     if (reading != buttonState) {
       buttonState = reading;

         if (buttonState == HIGH) {
           relayState = !relayState;
         }
    }
 }
 digitalWrite(relayPin, relayState);
 // 改变button前一个状态值
 lastButtonState = reading;
}
