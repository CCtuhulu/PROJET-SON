#include <Audio.h>
#include "project.h"

//project object
project proj;

AudioInputI2S in;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;

//Reglage des sorties audios
AudioConnection patchCord0(in,0,proj,0);
AudioConnection patchCord1(in,1,proj,1);
AudioConnection patchCord2(proj,0,out,0);
AudioConnection patchCord3(proj,1,out,1);

//Variable pour le bouton mute
int mute = -1;

void setup() {
  Serial.begin(9600);
  AudioMemory(6);
  audioShield.enable();

  //Setup l'input micro
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(10);
  audioShield.volume(0);

  //Setup les valeurs de bases
  proj.setParamValue("Volume", 0);
  proj.setParamValue("Frequence",0);
  proj.setParamValue("Echo",0);

}

void loop() {

  OnOffSwitch();

  if (mute == -1){
    audioShield.volume(0);
  }
  else {
    audioShield.volume(1);

    volumeChanger();
    frequenceChanger();
    echoChanger();
  }

}


//Demarrer ou arreter l'output
void OnOffSwitch(){
  if (digitalRead(0)){
    Serial.println("Mute: " + String(mute));
    mute *= -1;
    delay(500);
  }
}


//Changer la valeur du volume
void volumeChanger(){
  float volumeValue = map(analogRead(A0), 0, 1023, -20, 20);
  Serial.println("Volume: " + String(volumeValue) );
  proj.setParamValue("Volume", volumeValue);
  delay(25);
}


//Changer la valeur de la frequence (plus aigu ou grave)
void frequenceChanger(){
  float frequenceValue = map(analogRead(A1), 0, 1023, -20, 20);
  Serial.println("FrequenceShift: " + String(frequenceValue) );
  proj.setParamValue("Frequence", frequenceValue);
  delay(25);
}


//Changer la duree de l'echo
void echoChanger(){
  float echoValue = analogRead(A2)*0.8/1023.0;
  Serial.println("EchoFade: " + String(echoValue) );
  proj.setParamValue("Echo", echoValue);
  delay(25);
}
