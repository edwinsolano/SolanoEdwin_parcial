/*
 *UTN_FICA-CITEL
 *SISTEMAS EMBEBIDOS 
 *primer parcial 
 *Nombre:Solano Edwin
 */
 #include <MsTimer2.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (13,12,11,10,9,8);
int segundos=0;
int on=0;
int btn1;

 void setup() {
  lcd.begin(16,2);
   Serial.begin(9600);
  attachInterrupt(0,activacion,LOW);    
}

void loop() { 
if(on==1){
  MsTimer2::set(1000,reloj);
  MsTimer2::start();
}
}
void reloj(){ 
  if(segundos<20){
  segundos--;
    if(segundos==0)
    segundos=20;
}
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(String(segundos));
 }

 void cambio(){
  btn1=analogRead(0);//lectura del potencimoetro
  btn1=map(btn1,0,1023,10,20);//variable para colocar segundos
  segundos=btn1;
  Serial.println(String("tiempo: ")+String(segundos)+String(" segundos"));
}
void activacion(){
  switch(on){
    case 0:
      Serial.println("INICIO DE SISTEMA");
      Serial.println("Ingrese entre 10 a 20");
      cambio();
      on++;
    break;
    case 1:
      Serial.println("cuenta regresiva");
      on++;
    break;
    case 2:
      Serial.println("FIN DEL PROGRAMA");
      on=0;
      segundos=0;
    break;
  }
}
