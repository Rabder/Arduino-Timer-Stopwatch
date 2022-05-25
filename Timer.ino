#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
#include <LCD.h>      // libreria para funciones de LCD
#include <LiquidCrystal_I2C.h>    // libreria para LCD por I2C

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7



void setup() {
 // put your setup code here, to run once:

 Serial.begin(9600);
 Timer1.initialize();
 MFS.initialize(&Timer1); // initialize multi-function shield library
 lcd.setBacklightPin(3,POSITIVE);
 lcd.setBacklight(HIGH);
 lcd.begin(16, 2);
 int touch = analogRead(A0);

 int timer();




}

bool btn1 = false;
bool btn2 = false;
bool btn3 = false;
byte btn;

int timer() {

  bool finish = false;
  lcd.print("TIMER");
  float sbegin = 0.00;
  float smin = 0;
  MFS.write(sbegin, 2);
  btn1 = true;
  byte btn11;
  byte buttonAction11;
  byte buttonNumber11;
  bool flast = false;
  bool counting = false;
  bool reback = false;
  int ad = 0;
  bool next = false;
  while (true){
    int touch = analogRead(A0);
    Serial.println(touch);
    delay(1);
    btn11 = 0;
    buttonAction11 = 0;
    buttonNumber11 = 0;
    btn11 = MFS.getButton();




    if (btn11){
      buttonAction11 = btn11 & B11000000;
      buttonNumber11 = btn11 & B00111111;
    }

      if (buttonAction11 == BUTTON_LONG_PRESSED_IND && buttonNumber11 == 1){
        MFS.write(0.00, 2);
        break;
      }



      if (buttonAction11 == BUTTON_SHORT_RELEASE_IND && buttonNumber11 == 1 && btn1 == true){
        sbegin = sbegin + 0.10;
        counting = true;
        if (sbegin == 0.60){
          smin = smin + 1;
          sbegin = 0.0;
          MFS.write(smin+sbegin, 2);
        }
        else if (smin == 0){
          MFS.write(sbegin, 2);
        }
        else{
          MFS.write(smin+sbegin, 2);
        }
        delay(100);
      }

      if (buttonAction11 == BUTTON_SHORT_RELEASE_IND && buttonNumber11 == 2 && btn1 == true){
        counting = true;
        smin = smin + 1;
        MFS.write(smin+sbegin, 2);
        delay(100);
      }

    if (touch < 650)
    {
      ad = 0;
      if (ad == 0)
        {
            ad++;
              Serial.print("IT WORKS");
              lcd.clear();
              lcd.print("POMODORO");
              smin = 25;
              sbegin = 0;
              MFS.write(smin+sbegin, 2);
              delay(1000);
              while (true)
              {
                touch = analogRead(A0);
                Serial.print(btn11);
                btn11 = MFS.getButton();
                if (btn11){
                  buttonAction11 = btn11 & B11000000;
                  buttonNumber11 = btn11 & B00111111;

              if (buttonAction11 == BUTTON_SHORT_RELEASE_IND && buttonNumber11 == 3)
              {
                Serial.print("DIE");
                ad = 0;
                reback = true;
                break;
              }
             }
             if (touch < 650)
             {
              sbegin = 0;
              smin = 0;
              break;
             }
              }
          lcd.clear();
        }
       if (ad == 1)
       {
          ad++;
              Serial.print("IT WORKS");
              lcd.clear();
              lcd.print("SHORT BREAK");
              smin = 5;
              sbegin = 0;
              MFS.write(smin+sbegin, 2);
              delay(1000);
              while (true)
              {
                touch = analogRead(A0);
                Serial.print(btn11);
                btn11 = MFS.getButton();
                if (btn11){
                  buttonAction11 = btn11 & B11000000;
                  buttonNumber11 = btn11 & B00111111;

              if (buttonAction11 == BUTTON_SHORT_RELEASE_IND && buttonNumber11 == 3)
              {
                Serial.print("DIE");
                ad = 0;
                reback = true;
                break;
              }
             }
             if (touch < 650)
             {
              sbegin = 0;
              smin = 0;
              break;
             }
              }
          lcd.clear();
       }
       if (ad == 2)
       {
          ad++;
              Serial.print("IT WORKS");
              lcd.clear();
              lcd.print("LONG BREAK");
              smin = 15;
              sbegin = 0;
              MFS.write(smin+sbegin, 2);
              delay(1000);
              while (true)
              {
                touch = analogRead(A0);
                Serial.print(btn11);
                btn11 = MFS.getButton();
                if (btn11){
                  buttonAction11 = btn11 & B11000000;
                  buttonNumber11 = btn11 & B00111111;

              if (buttonAction11 == BUTTON_SHORT_RELEASE_IND && buttonNumber11 == 3)
              {
                Serial.print("DIE");
                ad = 0;
                reback = true;
                break;
              }
             }
             if (touch < 650)
             {
              sbegin = 0;
              smin = 0;
              ad = 0;
              break;
             }
              }
          lcd.clear();
       }
       touch = 1000;
    delay(500);
    lcd.print("FREE SELECTION");
     MFS.write(0.00, 2);
    }

 if (next == true){
  lcd.print("FREE SELECTION");
  smin = 0;
  sbegin = 0;
  MFS.write(smin+sbegin, 2);
  while(next){
    btn11 = MFS.getButton();
    if (btn11){
      buttonAction11 = btn11 & B11000000;
      buttonNumber11 = btn11 & B00111111;

    if (buttonAction11 == BUTTON_SHORT_RELEASE_IND && buttonNumber11 == 1 && btn1 == true){
        sbegin = sbegin + 0.10;
        counting = true;
        if (sbegin == 0.60){
          smin = smin + 1;
          sbegin = 0.0;
          MFS.write(smin+sbegin, 2);
        }
        else if (smin == 0){
          MFS.write(sbegin, 2);
        }
        else{
          MFS.write(smin+sbegin, 2);
        }
        delay(100);
      }
     if (buttonAction11 == BUTTON_SHORT_RELEASE_IND && buttonNumber11 == 3)
     {
      next = false;
     }
    }
    }
  }




      if (buttonAction11 == BUTTON_SHORT_RELEASE_IND && buttonNumber11 == 3 && counting == true or reback == true)
      {
        int i = 0;
        while (true){
          flast = true;
          btn11 = MFS.getButton();
          buttonNumber11 = btn11 & B00111111;
          Serial.print("\n");
          Serial.print(buttonNumber11 + '0');
          if (buttonNumber11 == 1 && i == 0){
            i = i + 1;
          }
          else if (buttonNumber11 == 1){
            btn11 = false;
            btn1 = false;
            delay(1000);
            break;
          }
          if (buttonAction11 == BUTTON_LONG_PRESSED_IND && buttonNumber11 == 1){
            MFS.write(0.00, 2);
             break;
            }
          else
          {
          MFS.write(smin+sbegin, 2);
          delay(1000);
          if (smin == 0 && sbegin <= 0.01){
            MFS.beep();
            delay(350);
            MFS.beep();
            delay(1000);
            MFS.beep();
            delay(350);
            MFS.beep();
            delay(1000);
            MFS.beep(50);
            break;
          }
        else{
          sbegin = sbegin-0.01;
          if (sbegin <= 0.00 && smin > 0){
            smin = smin - 1;
            sbegin = 0.59;
          }
        }
          }
       }
      }
      if (smin == 0 && sbegin <= 0.01 && flast == true){
            MFS.write(0.00, 2);
            lcd.clear();
            lcd.print("TIME IS OVER");
            delay(5000);
            lcd.clear();
            break;
          }
        if (btn1 == false)
        {
          while (true){
            btn11 = MFS.getButton();
            finish = false;
            if (btn11){
               buttonNumber11 = btn11 & B00111111;
               buttonAction11 = btn11 & B11000000;

               if (buttonNumber11 == 1 && buttonAction11 == BUTTON_SHORT_RELEASE_IND)
               {
                  delay(1000);
                  reback = true;
                  break;
               }
               else if (buttonNumber11 == 1 && buttonAction11 == BUTTON_LONG_PRESSED_IND)
               {
                finish = true;
                break;
               }
          }
        }
        }
        if (finish == true){
          break;
        }
  }



  btn11 = false;
  btn1 = false;
  buttonAction11 = 0;
  buttonNumber11 = 0;

  return 0;
}

int stopwatch()
{
  lcd.print("STOPWATCH");
  float sbegin = 0;
  float smin = 0;
  MFS.write(sbegin, 2);
  byte buttonAction22;
  byte buttonNumber22;
  btn2 = true;
  byte btn22;
  byte buttonNumber2 = 0;
  bool reback = false;
  while (true){

    btn22 = MFS.getButton();

    if (btn22 or reback == true){
      buttonNumber22 = btn22 & B00111111;
      buttonAction22 = btn22 & B11000000;


    if (buttonAction22 == BUTTON_LONG_PRESSED_IND && buttonNumber22 == 2){
        break;
      }

      if (buttonNumber22 == 1 && btn22 == true or reback == true){
        Serial.print("OK");
        MFS.beep();

        delay(1000);
        btn22 = false;

        while (true){
          btn22 = MFS.getButton();
          buttonNumber22 = btn22 & B00111111;
          Serial.print("\n");
          Serial.write(buttonNumber22 + '0');
          if (buttonNumber22 == 2){
            btn2 = false;
            reback = false;
            delay(1000);
            break;
          }
          Serial.print(btn1);
          sbegin = sbegin+0.01;
          if (sbegin >= 0.59){
            smin = smin + 1;
            sbegin = 0.0;
        }
          MFS.write(smin+sbegin, 2);
          delay(1000);
        }
      }
     }

      if (btn2 == false){
        Serial.print("ITS HAPPENING");
        while(true)
        {

            btn22 = MFS.getButton();
            if (btn22){
               buttonNumber22 = btn22 & B00111111;
               buttonAction22 = btn22 & B11000000;

            if (buttonAction22 == BUTTON_LONG_PRESSED_IND)
            {
              return 0;
              break;
            }
            else if (buttonAction22 == BUTTON_SHORT_RELEASE_IND && buttonNumber22 == 1)
            {
              Serial.print("WHY");
              btn2 = true;
              reback = true;
              buttonNumber22 = 1;
              break;
            }
          }
      }

      }


  }

  return 0;
}

int watch()
{

}



void loop(){

  MFS.write("--.--");

  btn = MFS.getButton();

  lcd.clear();


  if (btn)
 {
 byte buttonNumber = btn & B00111111;
 byte buttonAction = btn & B11000000;

 Serial.print("BUTTON_");
 Serial.write(buttonNumber + '0');
 Serial.print("_");

 if (buttonAction == BUTTON_PRESSED_IND)
 {
 Serial.println("PRESSED");
 }

 else if (buttonAction == BUTTON_SHORT_RELEASE_IND)
 {
  if (buttonNumber == 1)
  {
    Serial.println("SHORT_RELEASE");
    timer();
  }
  else if (buttonNumber == 2){
    buttonNumber = 0;
    buttonAction = 0;
    Serial.println("stopwatch");
    stopwatch();
  }
  else
  {
    Serial.println("SHORT_RELEASE");
    watch();
  }
 }
 }


}
