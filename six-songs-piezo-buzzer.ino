// C++ code
//

// Define pins for switches
#define SWITCH_1 2
#define SWITCH_2 3
#define SWITCH_3 4
#define SWITCH_4 5
#define SWITCH_5 6
#define SWITCH_6 7

// Define pin for Piezo Buzzer
#define BUZZER_PIN 8

//Define the Notes
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

int tempoNGYU = 114;
int tempoFE = 80;


int melodyNGYU[] = {
    REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
    NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

    NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,-8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //18
    NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,8, NOTE_A4,8, NOTE_A4,8, 
    NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
    NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
    NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

    NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  //23
    NOTE_E5,4, NOTE_D5,2, REST,4,
};

int melodyFurElise[] = {
    NOTE_E5, 16, NOTE_DS5, 16, 
    NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
    NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
    NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
    NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
    
    NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,//6
    NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
    NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
    NOTE_A4 , 4, REST, 8,
};

int notesNGYU = sizeof(melodyNGYU) / sizeof(melodyNGYU[0]) / 2;
int notesFE = sizeof(melodyFurElise) / sizeof(melodyFurElise[0]) / 2;

int wholeNoteNGYU = (60000 * 4) / tempoNGYU;
int wholeNoteFE = (60000 * 4) / tempoFE;

int divider = 0, noteDuration = 0;






void setup()
{
  pinMode(SWITCH_1, INPUT_PULLUP);
  pinMode(SWITCH_2, INPUT_PULLUP);
  pinMode(SWITCH_3, INPUT_PULLUP);
  pinMode(SWITCH_4, INPUT_PULLUP);
  pinMode(SWITCH_5, INPUT_PULLUP);
  pinMode(SWITCH_6, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.print("<<<< ARDUINO JUKE BOX >>>>");
  Serial.print("1. Never Gonna Give You Up");
  Serial.print("2. Baa Baa Black Sheep");
  Serial.print("3. London Bridge is falling");
  Serial.print("4. Five Little Ducks");
  Serial.print("5. If you’re Happy and You Know it");
  Serial.print("6. Rain Rain Go Away");
}

void loop()
{
  if (digitalRead(SWITCH_1) == LOW) {
    playSong(1);
  } else if (digitalRead(SWITCH_2) == LOW) {
    playSong(2);
  } else if (digitalRead(SWITCH_3) == LOW) {
    playSong(3);
  } else if (digitalRead(SWITCH_4) == LOW) {
    playSong(4);
  } else if (digitalRead(SWITCH_5) == LOW) {
    playSong(5);
  } else if (digitalRead(SWITCH_6) == LOW) {
    playSong(6);
  }
}

void playSong(int songNumber) {
  // Display selected song
  Serial.print("Playing Song ");
  Serial.println(songNumber);

  switch (songNumber) {
    case 1:
      playNeverGonnaGiveYouUp();
      break;
    case 2:
      playFurElise();
      break;
    case 3:
      playLondonBridge();
      break;
    case 4:
      playFiveLittleDucks();
      break;
    case 5:
      playIfYoureHappy();
      break;
    case 6:
      playRainRainGoAway();
      break;
    default:
      break;
  }
}

void playNeverGonnaGiveYouUp() {
    for (int thisNote = 0; thisNote < notesNGYU * 2; thisNote = thisNote + 2) {
    divider = melodyNGYU[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholeNoteNGYU) / divider;
    } else if (divider < 0) {
      noteDuration = (wholeNoteNGYU) / abs(divider);
      noteDuration *= 1.5; 
    }
    tone(BUZZER_PIN, melodyNGYU[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(BUZZER_PIN);
  }
}

void playFurElise() {
  for (int thisNote = 0; thisNote < notesFE * 2; thisNote = thisNote + 2) {
    divider = melodyFurElise[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholeNoteFE) / divider;
    } else if (divider < 0) {
      noteDuration = (wholeNoteFE) / abs(divider);
      noteDuration *= 1.5; 
    }
    tone(BUZZER_PIN, melodyFurElise[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(BUZZER_PIN);
  }
}

void playLondonBridge() {
  // Implement code to play London Bridge is falling
}

void playFiveLittleDucks() {
  // Implement code to play Five Little Ducks
}

void playIfYoureHappy() {
  // Implement code to play If You’re Happy and You Know It
}

void playRainRainGoAway() {
  // Implement code to play Rain Rain Go Away
}