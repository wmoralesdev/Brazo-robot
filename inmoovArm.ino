#include <Servo.h>

Servo fingerServo[5];
const int ctrServo[] = {95, 75, 75, 50, 50, 75};
const int strServo[] = {175, 0, 175, 175, 175};

bool defaultFlag = true;

const int fingerPos[][5] = {                                         
    {175, 0, 175, 175, 175},    // Palma                            pal
    {95, 75, 75, 50, 75},       // Punio                            pun
    {95, 0, 175, 50, 75},       // Paz                              paz8
    {95, 75, 175, 50, 75},      // ???                              sed
    {175, 0, 75, 50, 175},      // Spiderman                        spm
    {95, 75, 175, 175, 175},    // Ok                               okk
    {95, 75, 75, 50, 175},      // Menique                          bem
    {175, 75, 75, 50, 175}      // ???                              ppp
};

void setup()
{
    fingerServo[0].attach(13);   
    fingerServo[1].attach(12);
    fingerServo[2].attach(11);
    fingerServo[3].attach(10);
    fingerServo[4].attach(9);

    for(int i = 0;i < 5; i++) {
        fingerServo[i].write(strServo[i]);
    }

    for(int i = 0; i < 5; i++) {
        fingerServo[i].write(fingerPos[3][i]);
    }

    Serial.begin(9600);
    randomSeed(analogRead(0));
}

void loop()
{
    byte keyboardData;
    
    if(Serial.available()){
        keyboardData = Serial.read();

        if((int)keyboardData == 666){
            playRock();
            return;
        }

        for(int i = 0; i < 5; i++){
            fingerServo[i].write(fingerPos[(int)keyboardData][i]);
        }
    }
}

void playRock(void){
    int random = random(3);

    for(int i = 0; i < 5; i++)
        fingerServo[i].write(fingerPos[random][i]);
    return;
}