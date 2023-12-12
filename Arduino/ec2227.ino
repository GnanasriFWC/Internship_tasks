const int ledPin1 = 2;
const int ledPin2 = 3;
int x =1,y=0,z=0;
void setup(){
    pinMode(ledPin1,OUTPUT);
    pinMode(ledPin1,OUTPUT);
}
void loop(){
    int result1 = x || (y&&z);
    int result2 = x || (x&&y) || (y&&z);
    
    digitalWrite(ledPin1,result1);
    digitalWrite(ledPin2,result2);
    
}