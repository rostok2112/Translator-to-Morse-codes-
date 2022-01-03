#define SHORT 200
#define LONG  600
#define DELAY_SIGNAL 200
#define DELAY_CHAR 600
#define DELAY_WORD 800
#define BUTTON 2
#define LED 9
#define BUZZER 10

void beepDigital(short, byte, byte);
void beepShort();
void beepLong();
void printMorse();
void printMorseChar(char);


typedef void (*pfn_BeepFuncs)();

typedef struct Char {

  pfn_BeepFuncs * beepFuncArr;
  byte numOfBeeps;

} Char_t;


Char_t charA, charB, charC, charD, charE, charF, charG, charH, charI, charJ, charK, charL, charM, charN, charO, charP, charQ, charR, charS, charT, charU, charV, charW, charX, charY, charZ;


String str;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);

  charA.beepFuncArr = new pfn_BeepFuncs[2]; charA.numOfBeeps = 2; charA.beepFuncArr[0] = beepShort; charA.beepFuncArr[1] = beepShort;
  charB.beepFuncArr = new pfn_BeepFuncs[4]; charB.numOfBeeps = 4; charB.beepFuncArr[0] = beepLong; charB.beepFuncArr[1] = beepShort; charB.beepFuncArr[2] = beepShort; charB.beepFuncArr[3] = beepShort;
  charC.beepFuncArr = new pfn_BeepFuncs[4]; charC.numOfBeeps = 4; charC.beepFuncArr[0] = beepLong; charC.beepFuncArr[1] = beepShort; charC.beepFuncArr[2] = beepLong; charC.beepFuncArr[3] = beepShort;
  charD.beepFuncArr = new pfn_BeepFuncs[3]; charD.numOfBeeps = 3; charD.beepFuncArr[0] = beepLong; charD.beepFuncArr[1] = beepShort; charD.beepFuncArr[2] = beepShort;
  charE.beepFuncArr = new pfn_BeepFuncs[1]; charE.numOfBeeps = 1; charE.beepFuncArr[0] = beepShort;
  charF.beepFuncArr = new pfn_BeepFuncs[4]; charF.numOfBeeps = 4; charF.beepFuncArr[0] = beepShort; charF.beepFuncArr[1] = beepShort; charF.beepFuncArr[2] = beepLong; charF.beepFuncArr[3] = beepShort;
  charG.beepFuncArr = new pfn_BeepFuncs[3]; charG.numOfBeeps = 3; charG.beepFuncArr[0] = beepLong; charG.beepFuncArr[1] = beepLong; charG.beepFuncArr[2] = beepShort;
  charH.beepFuncArr = new pfn_BeepFuncs[4]; charH.numOfBeeps = 4; charH.beepFuncArr[0] = beepShort; charH.beepFuncArr[1] = beepShort; charH.beepFuncArr[2] = beepShort; charH.beepFuncArr[3] = beepShort;
  charH.beepFuncArr = new pfn_BeepFuncs[4]; charH.numOfBeeps = 4; charH.beepFuncArr[0] = beepShort; charH.beepFuncArr[1] = beepShort; charH.beepFuncArr[2] = beepShort; charH.beepFuncArr[3] = beepShort;
  charI.beepFuncArr = new pfn_BeepFuncs[2]; charI.numOfBeeps = 2; charI.beepFuncArr[0] = beepShort; charI.beepFuncArr[1] = beepShort;
  charJ.beepFuncArr = new pfn_BeepFuncs[4]; charJ.numOfBeeps = 4; charJ.beepFuncArr[0] = beepShort; charJ.beepFuncArr[1] = beepLong; charJ.beepFuncArr[2] = beepLong; charJ.beepFuncArr[3] = beepLong;
  charK.beepFuncArr = new pfn_BeepFuncs[3]; charK.numOfBeeps = 3; charK.beepFuncArr[0] = beepLong; charK.beepFuncArr[1] = beepShort; charK.beepFuncArr[2] = beepLong;
  charL.beepFuncArr = new pfn_BeepFuncs[4]; charL.numOfBeeps = 4; charL.beepFuncArr[0] = beepShort; charL.beepFuncArr[1] = beepLong; charL.beepFuncArr[2] = beepShort; charL.beepFuncArr[3] = beepShort;
  charM.beepFuncArr = new pfn_BeepFuncs[2]; charM.numOfBeeps = 2; charM.beepFuncArr[0] = beepLong; charM.beepFuncArr[1] = beepLong;
  charN.beepFuncArr = new pfn_BeepFuncs[2]; charN.numOfBeeps = 2; charN.beepFuncArr[0] = beepLong; charN.beepFuncArr[1] = beepShort;
  charO.beepFuncArr = new pfn_BeepFuncs[3]; charO.numOfBeeps = 3; charO.beepFuncArr[0] = beepLong; charO.beepFuncArr[1] = beepLong; charO.beepFuncArr[2] = beepLong;
  charP.beepFuncArr = new pfn_BeepFuncs[4]; charP.numOfBeeps = 4; charP.beepFuncArr[0] = beepShort; charP.beepFuncArr[1] = beepLong; charP.beepFuncArr[2] = beepLong; charP.beepFuncArr[3] = beepShort;
  charQ.beepFuncArr = new pfn_BeepFuncs[4]; charQ.numOfBeeps = 4; charQ.beepFuncArr[0] = beepLong; charQ.beepFuncArr[1] = beepLong; charQ.beepFuncArr[2] = beepShort; charQ.beepFuncArr[3] = beepLong;
  charR.beepFuncArr = new pfn_BeepFuncs[3]; charR.numOfBeeps = 3; charR.beepFuncArr[0] = beepShort; charR.beepFuncArr[1] = beepLong; charR.beepFuncArr[2] = beepShort;
  charS.beepFuncArr = new pfn_BeepFuncs[3]; charS.numOfBeeps = 3; charS.beepFuncArr[0] = beepShort; charS.beepFuncArr[1] = beepShort; charS.beepFuncArr[2] = beepShort;
  charT.beepFuncArr = new pfn_BeepFuncs[1]; charT.numOfBeeps = 1; charT.beepFuncArr[0] = beepLong;
  charU.beepFuncArr = new pfn_BeepFuncs[3]; charU.numOfBeeps = 3; charU.beepFuncArr[0] = beepShort; charU.beepFuncArr[1] = beepShort; charU.beepFuncArr[2] = beepLong;
  charV.beepFuncArr = new pfn_BeepFuncs[4]; charV.numOfBeeps = 4; charV.beepFuncArr[0] = beepShort; charV.beepFuncArr[1] = beepShort; charV.beepFuncArr[2] = beepShort; charV.beepFuncArr[3] = beepLong;
  charW.beepFuncArr = new pfn_BeepFuncs[3]; charW.numOfBeeps = 3; charW.beepFuncArr[0] = beepShort; charW.beepFuncArr[1] = beepLong; charW.beepFuncArr[2] = beepLong;
  charX.beepFuncArr = new pfn_BeepFuncs[4]; charX.numOfBeeps = 4; charX.beepFuncArr[0] = beepLong; charX.beepFuncArr[1] = beepShort; charX.beepFuncArr[2] = beepShort; charX.beepFuncArr[3] = beepLong;
  charY.beepFuncArr = new pfn_BeepFuncs[4]; charY.numOfBeeps = 4; charY.beepFuncArr[0] = beepLong; charY.beepFuncArr[1] = beepShort; charY.beepFuncArr[2] = beepLong; charY.beepFuncArr[3] = beepLong;
  charZ.beepFuncArr = new pfn_BeepFuncs[4]; charZ.numOfBeeps = 4; charZ.beepFuncArr[0] = beepLong; charZ.beepFuncArr[1] = beepLong; charZ.beepFuncArr[2] = beepShort; charZ.beepFuncArr[3] = beepShort;

  Serial.println("Enter the word for translate to Morse ");


}


void loop() {
  static bool f = 0;

  char character = ' ';

  while (Serial.available()) {

    character = Serial.read();
    str += character;

  }

  if (str.length())
  {

    (!f) ? Serial.println("You wrote: " + str) : Serial.println("The sentence to repeat: " + str);

    Serial.println("Press the button or restart for input sentence again");
    while (!digitalRead(BUTTON));

    printMorse();

    f = 1;
  }

}


void beep(short times, byte portD, byte portA) {

  digitalWrite(portD, HIGH);
  tone(portA, 1000);
  delay(times);
  digitalWrite(portD, LOW);
  noTone(portA);

}



void beepShort() {

  beep(SHORT, LED, BUZZER);


}

void beepLong() {

  beep(LONG, LED, BUZZER);


}

void printMorse() {

  for (int i = 0; i < str.length() - 1; i++)
  {
    printMorseChar(str.c_str()[i]);
    delay(DELAY_CHAR);
  }

}

void printMorseChar(char ch) {

  ch -= (ch > 90) ? 32 : 0;

  switch (ch)
  {
    case 32: delay(DELAY_WORD); break;

    case 65: startBeepChar(charA); break;
    case 66: startBeepChar(charB); break;
    case 67: startBeepChar(charC); break;
    case 68: startBeepChar(charD); break;
    case 69: startBeepChar(charE); break;
    case 70: startBeepChar(charF); break;
    case 71: startBeepChar(charG); break;
    case 72: startBeepChar(charH); break;
    case 73: startBeepChar(charI); break;
    case 74: startBeepChar(charJ); break;
    case 75: startBeepChar(charK); break;
    case 76: startBeepChar(charL); break;
    case 77: startBeepChar(charM); break;
    case 78: startBeepChar(charN); break;
    case 79: startBeepChar(charO); break;
    case 80: startBeepChar(charP); break;
    case 81: startBeepChar(charQ); break;
    case 82: startBeepChar(charR); break;
    case 83: startBeepChar(charS); break;
    case 84: startBeepChar(charT); break;
    case 85: startBeepChar(charU); break;
    case 86: startBeepChar(charV); break;
    case 87: startBeepChar(charW); break;
    case 88: startBeepChar(charX); break;
    case 89: startBeepChar(charY); break;
    case 90: startBeepChar(charZ); break;


    default: ;
  }

}

void startBeepChar(Char_t ch)
{

  for (int i = 0; i < ch.numOfBeeps; i++)
  {
    ch.beepFuncArr[i]();
    delay(DELAY_SIGNAL);
  }

}
