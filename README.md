# Pitch Shifter
## Prérequis
- Download Arduino IDE 1.8.19 from: `https://www.arduino.cc/en/software`
- Download Teensyduino from: `https://www.pjrc.com/teensy/td_download.html`

## Etapes d'implémentations
1. Download le dossier `project`
2. Connectez le teensy au pc avec un câble USB
3. Ouvrir le fichier `project.ino` avec l'Arduino
4. Allez au tab Tools > Board > Teensyduino > Teensy 4.0
5. Branchez le micro et le casque au teensy
6. Cliquez sur `Upload`
7. Tourner les potentiomètres pour ajuster les paramètres
8. Testez le programme!!

## Description des fichiers

Le projet contient:
- Fichier `project`: contient tout le code nécessaire: - `project.ino`: le code à upload dans le teensy
                                                       - `project.h` et `project.cpp`: le code faust exporté en C++

- `G2_MHAMDIwajdi_DIOUFmariama` : le poster du projet
- `faust.dsp` : le code en faust
