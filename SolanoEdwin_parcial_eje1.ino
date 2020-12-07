/*
 * UTN-FICA-CITEL
 * SISTEMAS EMBEBIDOS
 * evalucion parcial 
 * Nombre: Solano Edwin
 * 
 */
 const int led1=7;//led1 salida
 int conversor;
 int cont=0;
 int btn1;
 int on=0;
 int tiempo=0;
 int i;
 
 void setup() {
  Serial.begin(9600);
 pinMode(led1,OUTPUT);
 attachInterrupt(0,activacion,LOW);
 
 }

void loop() {
if(on==1){
 encender();
}

}
void cambio(){
  btn1=analogRead(0);//lectura del potencimoetro
  btn1=map(btn1,0,1023,0,10000);//variable para colocar segundos
  tiempo=btn1;
  int valor;
  btn1=analogRead(0);//lectura del potencimoetro
  btn1=map(btn1,0,1023,0,10);//variable para colocar segundos
  valor=btn1;
  Serial.println(String("tiempo: ")+String(valor)+String("segundos"));
}
void activacion(){
  switch(on){
    case 0:
      Serial.println("INICIO DE SISTEMA");
      Serial.println("Ingrese valor del 0 a 10");
      cambio();
      on++;
    break;
    case 1:
      Serial.println("encendido del led");
      on++;
    break;
    case 2:
      Serial.println("FIN DEL PROGRAMA");
      on=0;
      tiempo=0;
      i=0;
    break;
  }
}

void encender(){
    digitalWrite(led1,HIGH);
    delay(tiempo);
  digitalWrite(led1,LOW);
  delay(tiempo);
}
  
