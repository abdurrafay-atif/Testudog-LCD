int IRSensor = 9;
int LED = 13;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.print("Serial working");
    pinMode(IRSensor, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int sensorStatus = digitalRead(IRSensor);
    if(sensorStatus == 1)
    {
        digitalWrite(LED,LOW);
        Serial.println("Motion Detected");
    }
    else
    {
        digitalWrite(LED, HIGH);
        Serial.println("Motion Ended");
    }
}
