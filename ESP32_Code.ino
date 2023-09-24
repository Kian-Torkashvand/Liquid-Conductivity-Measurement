const int pwmPin = 5;

void setup() {
  Serial.begin(115200);
  pinMode(pwmPin, OUTPUT );
  ledcSetup(0, 10000, 8);

  ledcAttachPin(pwmPin , 0);

  analogReadResolution(12);
}
void loop() {
  float sum=0;
  for (int i = 0 ; i<10000 ; i++)
  {
    float analogValue = analogRead(34);
    analogValue = (analogValue/4095) *3.3;
    sum += analogValue ;
  }
  float data = sum /10000 ;
  data = 365.4*data - 545.66;
  ledcWrite(0, 128);
  Serial.printf("ADC analog value = %2.3f\n",data);
  delay(1000);
}
