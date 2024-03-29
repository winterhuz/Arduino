#define ADC_ch A0
#define ADC_level 1000
#define sampleDelay 200
unsigned long initTime;

void setup(){
    Serial.begin(9600);
analogSetPinAttenuation(ADC_ch,ADC_11db);
adcAttachPin(ADC_ch);

initTime = millis();
while(analogRead(ADC_ch) > ADC_level) {
Serial.print(analogRead(ADC_ch));
Serial.print("\t");
Serial.println(millis()-initTime);
}
Serial.println(".....reading ADC.....");
}

void loop(){
int ADC_value;
ADC_value = analogRead(ADC_ch);
Serial.println(ADC_value);
delay(sampleDelay);
}
