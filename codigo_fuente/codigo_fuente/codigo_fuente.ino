#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);
int pos0 = 150;
int pos180 = 600;
int lectura;
Servo myservo;
//===================================================================DEFINICION DE VARIABLES 
const int filas[] = { 2, 3, 4, 5, 6, 7, 8, 9 };  // Pines para las filas
const int columnas[] = { 10, 11, 12, 13, A0, A1, A2, A3 };           // Pines para las columnas
//===================================================================PATRONES
//Patron de Corazon
int corazon[8][8] = { { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 0, 0, 1, 1, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0, 1 }, { 1, 1, 0, 0, 0, 0, 1, 1 }, { 1, 1, 1, 0, 0, 1, 1, 1 } };
int sonrisa[8][8] = { { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 0, 0, 1, 1, 0, 0, 1 }, { 1, 0, 0, 1, 1, 0, 0, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 0, 1, 1, 1, 1, 0, 1 }, { 1, 1, 0, 0, 0, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 } };
int tristeza[8][8] = { { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 0, 0, 1, 1, 0, 0, 1 }, { 1, 0, 0, 1, 1, 0, 0, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 0, 0, 0, 0, 1, 1 }, { 1, 0, 1, 1, 1, 1, 0, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 } };
int fachero[8][8] = { { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 1, 0, 0, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 0, 1, 1, 1, 1, 0, 1 }, { 1, 1, 0, 0, 0, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 } };
//===================================================================VOID SETUP
void setup() {
  servos.begin();
  servos.setPWMFreq(50);
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
      pinMode(filas[i], OUTPUT);
      pinMode(columnas[i], OUTPUT);
  }

  //===============================================Pines
  //pin0= hombro derecho
  //pin1= brazo derecho
  //pin2= mano derecho
  //pin3= pierna derecha
  //pin4= pie derecho
  //pin5= hombro izquierdo
  //pin6= brazo izquierdo
  //pin7= mano izquierda
  //pin8= pierna izquierda
  //pin9= pie izquierdo
  //pin10=
  //pin11=
  //===============================================Elegir opcion
}  //Cierre Setup
//===================================================================CONJUNTO DE FUNCIONES
//========================================FUNCION ENCENDER TODOS LOS LEDS 
void encenderTodosLosLEDs() {
  // Poner todas las filas en HIGH
  for (int i = 0; i < 8; i++) {
    digitalWrite(filas[i], HIGH);
  }
  delay(1000);
  for (int i = 0; i < 8; i++) {
    digitalWrite(filas[i], LOW);
  }
  // Poner todas las columnas en LOW (asumiendo ánodo común)
  //for (int i = 0; i < 8; i++) {
  //digitalWrite(columnas[i], LOW);
}  //Cierre void
//========================================FUNCION MOSTRAR PATRON
void mostrarPatron(int patron[8][8]) {
  for (int x = 0; x < 300; x++) {
    for (int fila = 0; fila < 8; fila++) {
      digitalWrite(filas[fila], HIGH);  // Encender fila actual
      for (int columna = 0; columna < 8; columna++) {
        digitalWrite(columnas[columna], patron[fila][columna]);
      }
      delay(1);                        // Ajusta el delay según la velocidad de parpadeo deseada
      digitalWrite(filas[fila], LOW);  // Apagar fila actual para siguiente iteración
    }
  }
}
//cierre void
//========================================FUNCION TRADUCIR PULSOS A GRADOS
void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty = map(angulo, 0, 180, pos0, pos180);
  servos.setPWM(n_servo, 0, duty);
}
//===================================================================VOID LOOP 
void loop() {
  int tiempito = 320;
  Serial.println('Ingrese su opcion: ');
  while (Serial.available() == 0) {
  }
  lectura = Serial.parseInt();
  if (lectura == 1) {  //La Macarena=====================================================================
    for (int n = 180; n >= 0; n--) {
      setServo(5, n);
      delay(2);
    }
    setServo(7, 0);
    delay(1000);
    for (int n = 0; n <= 90; n++) {
      setServo(0, n);
      delay(2);
    }
    for (int n = 90; n >= 0; n--) {
      setServo(1, n);
      delay(5);
    }
    for (int n = 0; n <= 90; n++) {
      setServo(1, n);
      delay(10);
    }
    setServo(7, 90);
    for (int n = 0; n <= 90; n++) {
      setServo(5, n);
      delay(2);
    }
    delay(100);
    setServo(7, 90);
    setServo(2, 90);
    for (int n = 90; n <= 180; n++) {
      setServo(5, n);
      delay(2);
    }
    setServo(7, 150);
    for (int m = 1; m <= 5; m++) {
      for (int n = 160; n >= 0; n--) {
        setServo(2, n);
        delay(1);
      }
      for (int n = 0; n <= 160; n++) {
        setServo(2, n);
        delay(1);
      }
    }
    setServo(7, 90);
    setServo(2, 90);
    for (int n = 90; n <= 180; n++) {
      setServo(0, n);
      delay(2);
    }
    setServo(2, 160);
    setServo(7, 160);
    for (int i = 1; i <= 2; i++) {
      for (int n = 65; n >= 10; n--) {
        setServo(9, n);
        delay(10);
      }
      for (int n = 10; n <= 65; n++) {
        setServo(9, n);
        delay(10);
      }
    }
    setServo(2, 90);
    setServo(7, 90);
    delay(100);
    //Paso macarena------------------------------------
    for (int n = 180; n >= 90; n--) {
      setServo(0, n);
      delay(2);
    }
    delay(tiempito);
    for (int n = 180; n >= 90; n--) {
      setServo(5, n);
      delay(2);
    }
    delay(tiempito);
    for (int n = 90; n >= 0; n--) {
      setServo(2, n);
      delay(2);
    }
    delay(tiempito);
    for (int n = 90; n >= 0; n--) {
      setServo(7, n);
      delay(2);
    }
    delay(tiempito);
    for (int n = 0; n <= 90; n++) {
      setServo(2, n);
      delay(2);
    }
    delay(tiempito);
    for (int n = 0; n <= 90; n++) {
      setServo(7, n);
      delay(2);
    }
    delay(tiempito);
    for (int n = 90; n <= 180; n++) {
      setServo(0, n);
      delay(2);
    }
    delay(tiempito);
    for (int n = 90; n >= 0; n--) {
      setServo(5, n);
      delay(2);
    }
    delay(tiempito);
    for (int n = 180; n >= 0; n--) {
      setServo(0, n);
      delay(1);
    }
    delay(tiempito);
    for (int n = 0; n <= 180; n++) {
      setServo(5, n);
      delay(1);
    }
    delay(tiempito);
    setServo(2, 50);
    delay(tiempito);
    setServo(7, 50);
    delay(tiempito);
    for (int n = 65; n >= 10; n--) {
      setServo(4, n);
      delay(2);
    }
    delay(tiempito + 400);
    for (int n = 65; n >= 10; n--) {
      setServo(9, n);
      delay(2);
    }
    delay(tiempito + 800);
    for (int n = 10; n <= 65; n++) {
      setServo(9, n);
      setServo(4, n);
      delay(2);
    }
    setServo(2, 90);
    setServo(7, 90);
    delay(100);
    //--------------------------------
    for (int m = 1; m <= 2; m++) {
      for (int n = 0; n <= 180; n++) {
        setServo(0, n);
        delay(2);
      }
      for (int n = 180; n >= 0; n--) {
        setServo(0, n);
        delay(2);
      }
      delay(500);
      for (int n = 0; n <= 90; n++) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(2);
      }
      delay(500);
      for (int n = 90; n >= 0; n--) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(2);
      }
      for (int n = 180; n >= 0; n--) {
        setServo(5, n);
        delay(2);
      }
      for (int n = 0; n <= 180; n++) {
        setServo(5, n);
        delay(2);
      }
      //delay(500);
      for (int n = 0; n <= 90; n++) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(2);
      }
      delay(500);
      for (int n = 90; n >= 0; n--) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(2);
      }
    }
    //Segunda parte===================
    for (int n = 180; n >= 90; n--) {
      setServo(5, n);
      delay(2);
    }
    delay(2);
    for (int n = 0; n <= 180; n++) {
      setServo(0, n);
      delay(2);
    }
    delay(2);
    for (int n = 90; n >= 0; n--) {
      setServo(1, n);
      delay(2);
    }
    delay(2);
    for (int n = 180; n >= 0; n--) {
      setServo(0, n);
      delay(2);
    }
    delay(2);
    for (int n = 0; n <= 90; n++) {
      setServo(1, n);
      delay(2);
    }
    delay(2);
    for (int n = 0; n <= 180; n++) {
      setServo(5, n);
      delay(2);
    }
    delay(2);
    //=========================
    for (int n = 180; n >= 0; n--) {
      setServo(5, n);
      delay(2);
    }
    delay(2);
    for (int n = 0; n <= 90; n++) {
      setServo(0, n);
      delay(2);
    }
    delay(2);
    for (int n = 90; n >= 0; n--) {
      setServo(6, n);
      delay(2);
    }
    delay(2);
    for (int n = 0; n <= 180; n++) {
      setServo(5, n);
      delay(2);
    }
    delay(2);
    for (int n = 0; n <= 90; n++) {
      setServo(6, n);
      delay(2);
    }
    delay(2);
    for (int n = 90; n >= 0; n--) {
      setServo(0, n);
      delay(2);
    }
    delay(1000);
    //Macarena otra vez=============
    for (int m = 1; m <= 2; m++) {
      for (int n = 180; n >= 90; n--) {
        setServo(0, n);
        delay(2);
      }
      delay(tiempito);
      for (int n = 180; n >= 90; n--) {
        setServo(5, n);
        delay(2);
      }
      delay(tiempito);
      for (int n = 90; n >= 0; n--) {
        setServo(2, n);
        delay(2);
      }
      delay(tiempito);
      for (int n = 90; n >= 0; n--) {
        setServo(7, n);
        delay(2);
      }
      delay(tiempito);
      for (int n = 0; n <= 90; n++) {
        setServo(2, n);
        delay(2);
      }
      delay(tiempito);
      for (int n = 0; n <= 90; n++) {
        setServo(7, n);
        delay(2);
      }
      delay(tiempito);
      for (int n = 90; n <= 180; n++) {
        setServo(0, n);
        delay(2);
      }
      delay(tiempito);
      for (int n = 90; n >= 0; n--) {
        setServo(5, n);
        delay(2);
      }
      delay(tiempito);
      for (int n = 180; n >= 0; n--) {
        setServo(0, n);
        delay(1);
      }
      delay(tiempito);
      for (int n = 0; n <= 180; n++) {
        setServo(5, n);
        delay(1);
      }
      delay(tiempito);
      setServo(2, 50);
      delay(tiempito);
      setServo(7, 50);
      delay(tiempito);
      for (int n = 65; n >= 10; n--) {
        setServo(4, n);
        delay(2);
      }
      delay(tiempito + 400);
      for (int n = 65; n >= 10; n--) {
        setServo(9, n);
        delay(2);
      }
      delay(tiempito + 800);
      for (int n = 10; n <= 65; n++) {
        setServo(9, n);
        setServo(4, n);
        delay(2);
      }
      setServo(2, 90);
      setServo(7, 90);
      //delay(500);
    }
    delay(200);
    //--------------------------------------
    for (int m = 1; m <= 2; m++) {
      for (int n = 0; n <= 180; n++) {
        setServo(0, n);
        delay(2);
      }
      for (int n = 180; n >= 0; n--) {
        setServo(0, n);
        delay(2);
      }
      delay(500);
      for (int n = 0; n <= 90; n++) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(2);
      }
      delay(500);
      for (int n = 90; n >= 0; n--) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(2);
      }
      for (int n = 180; n >= 0; n--) {
        setServo(5, n);
        delay(2);
      }
      for (int n = 0; n <= 180; n++) {
        setServo(5, n);
        delay(2);
      }
      //delay(500);
      for (int n = 0; n <= 90; n++) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(2);
      }
      delay(500);
      for (int n = 90; n >= 0; n--) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(2);
      }
    }
  }
  if (lectura == 2) { //I was made to love you
    //Coro================================
    setServo(0, 90);
    setServo(5, 90);
    setServo(2, 0);
    setServo(7, 160);
    for (int m = 1; m <= 6; m++) {
      for (int n = 0; n <= 160; n++) {
        setServo(2, n);
        setServo(7, 160 - n);
        if (n >= 90 and n <= 130) {
          setServo(3, n);
          setServo(8, n - 20);
        }
        delay(2);
      }
      for (int n = 160; n >= 0; n--) {
        setServo(2, n);
        setServo(7, 160 - n);
        if (n >= 90 and n <= 130) {
          setServo(3, n - 20);
          setServo(8, n);
        }
        delay(2);
      }
    }
    setServo(3, 90);
    setServo(8, 90);
    setServo(2, 90);
    setServo(7, 90);
    setServo(1, 90);
    setServo(6, 90);
    for (int m = 0; m <= 3; m++) {
      for (int n = 90; n >= 50; n--) {
        setServo(1, n);
        delay(5);
      }
      delay(5);
      for (int n = 50; n <= 90; n++) {
        setServo(1, n);
        delay(5);
      }
      delay(5);
      for (int n = 90; n >= 50; n--) {
        setServo(6, n);
        delay(5);
      }
      delay(5);
      for (int n = 50; n <= 90; n++) {
        setServo(6, n);
        delay(5);
      }
      delay(5);
      for (int n = 90; n >= 50; n--) {
        setServo(1, n);
        delay(5);
      }
      delay(5);
      for (int n = 50; n <= 90; n++) {
        setServo(1, n);
        delay(5);
      }
      delay(5);
      //--------------------------------
      for (int n = 90; n <= 120; n++) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(5);
      }
      delay(5);
      for (int n = 120; n >= 90; n--) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(5);
      }
    }
    //Verso==========================
    setServo(0, 0);
    for (int z = 1; z <= 2; z++) {
      for (int n = 90; n >= 0; n--) {
        setServo(5, n);
        delay(5);
      }
      delay(5);
      for (int n = 0; n <= 180; n++) {
        setServo(5, n);
        delay(5);
      }
      for (int m = 1; m <= 3; m++) {
        for (int n = 65; n >= 30; n--) {
          setServo(4, n);
          delay(5);
        }
        delay(5);
        for (int n = 30; n <= 65; n++) {
          setServo(4, n);
          delay(5);
        }
        delay(5);
      }
      for (int n = 180; n >= 0; n--) {
        setServo(5, n);
        delay(5);
      }
      delay(5);
      for (int n = 0; n <= 90; n++) {
        setServo(5, n);
        delay(5);
      }
      delay(3500);
      for (int n = 90; n >= 0; n--) {
        setServo(5, n);
        delay(5);
      }
      delay(5);
      for (int n = 0; n <= 180; n++) {
        setServo(5, n);
        delay(5);
      }
      for (int m = 1; m <= 3; m++) {
        for (int n = 65; n >= 30; n--) {
          setServo(4, n);
          delay(5);
        }
        delay(5);
        for (int n = 30; n <= 65; n++) {
          setServo(4, n);
          delay(5);
        }
        delay(5);
      }
      for (int n = 180; n >= 0; n--) {
        setServo(5, n);
        delay(5);
      }
      delay(5);
      for (int n = 0; n <= 90; n++) {
        setServo(5, n);
        delay(5);
      }
      if (z == 1) {
        delay(3000);
      }
    }
    delay(1000);
    //ProCoro======================
    setServo(5, 90);
    delay(100);
    for (int n = 90; n >= 0; n--) {
      setServo(5, n);
      delay(2);
    }
    for (int m = 1; m <= 3; m++) {
      for (int n = 65; n >= 40; n--) {
        setServo(4, n);
        setServo(9, n);
        delay(5);
      }
      delay(5);
      for (int n = 40; n <= 65; n++) {
        setServo(4, n);
        setServo(9, n);
        delay(5);
      }
      delay(5);
    }
    for (int n = 0; n <= 180; n++) {
      setServo(5, n);
      delay(2);
    }
    //Coro================================
    setServo(0, 90);
    setServo(5, 90);
    setServo(2, 0);
    setServo(7, 160);
    for (int m = 1; m <= 6; m++) {
      for (int n = 0; n <= 160; n++) {
        setServo(2, n);
        setServo(7, 160 - n);
        if (n >= 90 and n <= 130) {
          setServo(3, n);
          setServo(8, n - 20);
        }
        delay(2);
      }
      for (int n = 160; n >= 0; n--) {
        setServo(2, n);
        setServo(7, 160 - n);
        if (n >= 90 and n <= 130) {
          setServo(3, n - 20);
          setServo(8, n);
        }
        delay(2);
      }
    }
    setServo(3, 90);
    setServo(8, 90);
    setServo(2, 90);
    setServo(7, 90);
    setServo(1, 90);
    setServo(6, 90);
    for (int m = 0; m <= 3; m++) {
      for (int n = 90; n >= 50; n--) {
        setServo(1, n);
        delay(5);
      }
      delay(5);
      for (int n = 50; n <= 90; n++) {
        setServo(1, n);
        delay(5);
      }
      delay(5);
      for (int n = 90; n >= 50; n--) {
        setServo(6, n);
        delay(5);
      }
      delay(5);
      for (int n = 50; n <= 90; n++) {
        setServo(6, n);
        delay(5);
      }
      delay(5);
      for (int n = 90; n >= 50; n--) {
        setServo(1, n);
        delay(5);
      }
      delay(5);
      for (int n = 50; n <= 90; n++) {
        setServo(1, n);
        delay(5);
      }
      delay(5);
      //--------------------------------
      for (int n = 90; n <= 120; n++) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(5);
      }
      delay(5);
      for (int n = 120; n >= 90; n--) {
        setServo(0, n);
        setServo(5, 180 - n);
        delay(5);
      }
    }
  }
  if (lectura == 3) {//Da baa dee====================================================================================
    
    for (int n = 0; n <= 1; n++) {
      //Mover brazo izquierdo
      for (int i = 180; i >= 90; i--) {
        setServo(5, i);
        delay(2);
      }
      for (int i = 90; i >= 0; i--) {
        setServo(6, i);
        delay(7);
      }
      for (int i = 0; i <= 90; i++) {
        setServo(6, i);
        delay(7);
      }
      for (int i = 90; i <= 180; i++) {
        setServo(5, i);
        delay(2);
      }
      //Mover brazo derecho
      for (int i = 0; i <= 90; i++) {
        setServo(0, i);
        delay(2);
      }
      for (int i = 90; i >= 0; i--) {
        setServo(1, i);
        delay(7);
      }
      for (int i = 0; i <= 90; i++) {
        setServo(1, i);
        delay(7);
      }
      for (int i = 90; i >= 0; i--) {
        setServo(0, i);
        delay(2);
      }
      //Segundo pasito
      for (int i = 0; i <= 1; i++) {
        setServo(5, 90);
        setServo(4, 35);
        delay(200);
        setServo(7, 0);
        delay(200);
        setServo(7, 90);
        delay(200);
        setServo(5, 160);
        setServo(4, 65);
        delay(200);
        setServo(0, 90);
        setServo(9, 35);
        delay(200);
        setServo(2, 0);
        delay(200);
        setServo(2, 90);
        delay(200);
        setServo(0, 0);
        setServo(9, 65);
        delay(200);
      }
      if (n == 0) {
        delay(450);
      }
    }
    //Tercer pasito
    setServo(8, 160);
    for (int i = 0; i <= 3; i++) {
      setServo(6, 50);
      setServo(1, 80);
      setServo(7, 120);
      setServo(2, 60);
      delay(480);
      setServo(6, 80);
      setServo(1, 50);
      setServo(7, 60);
      setServo(2, 120);
      delay(480);
    }
    setServo(8, 90);
    setServo(3, 0);
    for (int i = 0; i <= 3; i++) {
      setServo(6, 50);
      setServo(1, 80);
      setServo(7, 120);
      setServo(2, 60);
      delay(480);
      setServo(6, 80);
      setServo(1, 50);
      setServo(7, 60);
      setServo(2, 120);
      delay(480);
    }
    setServo(3, 90);
    //Cuarto pasito
    setServo(0, 90);
    setServo(5, 90);
    setServo(1, 90);
    setServo(6, 90);
    setServo(2, 0);
    setServo(7, 0);
    delay(400);
    for (int i = 0; i < 2; i++) {
      setServo(4, 95);
      delay(400);
      setServo(4, 65);
      delay(400);
    }
    //Quinto paso
    setServo(2, 90);
    setServo(7, 90);
    setServo(0, 0);
    setServo(5, 160);
    for (int i = 0; i <= 1; i++) {
      setServo(9, 95);
      setServo(6, 50);
      setServo(1, 80);
      setServo(7, 120);
      setServo(2, 60);
      delay(380);
      setServo(6, 80);
      setServo(1, 50);
      setServo(7, 60);
      setServo(2, 120);
      setServo(9, 65);
      delay(380);
    }
    //Sexto paso (Igual al 4to)
    setServo(0, 90);
    setServo(5, 90);
    setServo(1, 90);
    setServo(6, 90);
    setServo(2, 0);
    setServo(7, 0);
    delay(400);
    for (int i = 0; i < 2; i++) {
      setServo(4, 95);
      delay(400);
      setServo(4, 65);
      delay(400);
    }
    //Septimo paso (Antes del da ba dee)
    setServo(0, 160);
    setServo(5, 0);
    for (int i = 90; i <= 120; i++) {
      setServo(2, i);
      setServo(7, i);
      delay(40);
    }
    for (int i = 120; i >= 90; i--) {
      setServo(2, i);
      setServo(7, i);
      delay(40);
    }
    for (int h = 160; h >= 0; h--) {
      setServo(0, h);
      setServo(5, 160 - h);
      delay(5);
    }
    //Da ba dee
    for (int i = 0; i <= 3; i++) {
      setServo(5, 0);
      delay(480);
      setServo(5, 160);
      setServo(0, 160);
      delay(480);
      setServo(5, 0);
      setServo(0, 0);
      delay(480);
      setServo(5, 160);
      setServo(0, 160);
      delay(480);
      setServo(5, 0);
      setServo(0, 0);
      delay(400);
      setServo(5, 160);
      delay(200);
      setServo(4, 25);
      setServo(9, 25);
      delay(230);
      setServo(4, 65);
      setServo(9, 65);
      delay(230);
      setServo(4, 25);
      setServo(9, 25);
      delay(230);
      setServo(4, 65);
      setServo(9, 65);
      delay(230);
      setServo(4, 25);
      setServo(9, 25);
      delay(230);
      setServo(4, 65);
      setServo(9, 65);
      delay(230);
    }
    for (int i = 0; i <= 3; i++) {
      setServo(0, 90);
      setServo(5, 90);
      setServo(1, 90);
      setServo(6, 90);
      setServo(2, 0);
      setServo(7, 0);
      for (int j = 0; j <= 1; j++) {
        setServo(9, 95);
        delay(400);
        setServo(9, 65);
        setServo(4, 95);
        delay(400);
        setServo(4, 65);
      }
      delay(400);
      setServo(9, 65);
      setServo(0, 0);
      setServo(5, 160);
      setServo(2, 90);
      setServo(7, 90);
      for (int j = 0; j <= 1; j++) {
        setServo(9, 95);
        delay(400);
        setServo(9, 65);
        setServo(4, 95);
        delay(400);
        setServo(4, 65);
      }
      delay(400);
      setServo(9, 65);
    }
    setServo(9, 65);
    setServo(2, 90);
    setServo(7, 90);
    setServo(0, 0);
    setServo(5, 160);
  }
}  //Cierre void loop