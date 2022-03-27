/*
  mapeamento do hardware#
  -display
   * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  * 10K resistor:
  * ends to +5V and ground
  * wiper to LCD VO pin (pin 3)
  
 -teclado
  * TCL A0 leitura das teclas 
    * OK,ESC,<,>
    * leitura analogica de varios boteos 
    * valores  4.05 , 3.55 , 3.05 , 2.65
    
    
 -rtc ds3231
  *
    
 -bomba act
  * pin D13
    
    
    
  mapeamento do hardware#   
 */

// include library
#include <Wire.h>         //Biblioteca para manipulação do protocolo I2C
//#include <DS3231.h>       //Biblioteca para manipulação do DS3231
#include <LiquidCrystal.h>  //Biblioteca para manipulação do display
#include <EEPROM.h>


int bomba = 13;
int teclado = A0;
float sensorValue = 0.0;
float voltage = 0.0;

//AUXS ACTS
int flag=0;
int c_time = 0;


//times controles
unsigned long tempo_1;
unsigned long tempoAUX1;
//unsigned long tempo_2;
//unsigned long tempo_3;

//variaveis EEPROM
int address = 0; //
char dado = ''   // dado armazenado


//infos
int cicloAtual = 0;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  tempo_1 = millis();
  //tempo_2 = millis();
  //tempo_3 = millis();
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
  pinMode(bomba,INPUT);
  pinMode(teclado,INPUT);
}

void loop() {
  sensorValue  = analogRead(teclado);
  voltage = sensorValue * (5.0 / 1023.0);
  //lcd.setCursor(0, 1);
  //lcd.print("teclado - ");
  //lcd.print(voltage);
  //delay(100);
  //lcd.clear();
  
  
  menus(1);
  
  
  //if(c_time > 50000){
    //c_time = 0;
  //}else{
    //c_time++;
  //}
  //delay(10);
}
 












//YAH
void menus(int opt){
  switch(opt){
    
    case 1://APRESENTACAO 
      lcd.setCursor(0, 0);
      lcd.print(" YAH-AUTOMATION");
    
      if(flag == 0){
          lcd.setCursor(0, 1); 
          lcd.print(" HORTA AUTONOMA");
        }else if(flag == 1){
          lcd.setCursor(0, 1); 
          lcd.print(" SISTEMA  ATIVO");
        }else if(flag == 2){
          lcd.setCursor(0, 1);
          lcd.print("VERIFICANDO ...");
        }else if(flag == 3){
          lcd.setCursor(0, 1);
          lcd.print("PRESS ACT P/MENU");
        }else if(flag == 4){
          lcd.setCursor(0, 1);
          lcd.write(byte(7));
        }
    
      tempoAUX1 = millis();
      if((tempoAUX1 - tempo_1) > 1500){
          flag++;
          if(flag > 5) flag = 0;
          tempo_1 = millis();
       }
    
    break;
    
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("YAH-");
    
      //lcd.setCursor(0, 5);
      lcd.print("CICLOS REGA");
        lcd.setCursor(0, 1);
        lcd.print(voltage);
    break;
    
    case 3:
      lcd.setCursor(0, 1);
      lcd.print("teclado - ");
      lcd.print(voltage);
    break;
    case 4:
        lcd.setCursor(0, 1);
      lcd.print("teclado - ");
      lcd.print(voltage);
    break;
    
    
  }
  delay(100);
  lcd.clear();
}






//****aplicar a escrita  ao fim de cada dia
//void EPROM-W_R(){

//leitura
//EEPROM.read(address);

//escrita
//EEPROM.write(address,dado);

//}



//////continuar
