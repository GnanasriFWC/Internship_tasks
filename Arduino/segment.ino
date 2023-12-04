const int segmentPins[] = {2,3,4,5,6,7,8,9};

void setup(){
    for(int i=0;i<8;i++){
        pinMode(segmentPins[i],OUTPUT);
    }
}

void loop(){
    for (int num =0;num < 10; num++){
        displayNumber(num);
        delay(1000);
    }
}

void displayNumber(int num){
    byte patterns[] = {
        B11000000,
        B11111001,
        B00100100,
        B00110000,
        B00011001,
        B00010010,
        B00000010,
        B11111000,
        B00000000,
        B00010000
    };
    
    for(int i=0;i<8;i++){
        digitalWrite(segmentPins[i],bitRead(patterns[num],i));
    }
}