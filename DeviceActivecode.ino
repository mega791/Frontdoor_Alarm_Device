int C = 1047;  
int D = 1175;  
int E = 1319; 
int F = 1397;  
int G = 1568; 
int A = 1760;  
int B = 1976;  

#define led_Red 6 // ON_Signal
#define led_Green 7 // OFF_Signal
#define inputPin  2 // Signal_pin
int pirState = LOW; // PIR Preferences 
int val = 0; 


#define Speaker 5 
int notes[25] = { G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C };   
int tempo = 200;

 
void setup() {
    pinMode(led_Red, OUTPUT); 
    pinMode(led_Green, OUTPUT); 
    pinMode(Speaker , OUTPUT);
    pinMode(inputPin, INPUT); //sensor
 
    Serial.begin(9600);
}
 
void loop(){
    val = digitalRead(inputPin);
    if (val == HIGH) { 
        if (pirState == LOW) {
//        Serial.println("Motion detected!");
        pirState = HIGH;
        digitalWrite(led_Red, HIGH);
        digitalWrite(led_Green, LOW);
        delay(300);
        
        for(int i=0; i < 6; i++) {
         tone(Speaker, notes[i], tempo);
         delay(300); 
        }
         noTone(Speaker);
        }
    } else {
       

        if (pirState == HIGH){                 
//            Serial.println("Motion ended!");
            pirState = LOW;
             digitalWrite(led_Green, HIGH);
             digitalWrite(led_Red, LOW);
             delay(300);
        }
    }

}
