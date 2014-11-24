int buzzer = 11;
int boton1 = 2;
int boton2 = 3;
int val1 = 0;
int val2 = 0;
int numeroAleatorio;
int instancia[50];
int pos = 0;
int flag = 0;


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));

}


void loop()
{

  delay(500);

  llenarVector();

  sonidoDeInicio();

  comenzarJuego();

  sonidoDeFin();

}

void llenarVector()
{
  int i = 0;
  int randNumber;

  while (i < 50) {
    randNumber = random(2, 4);
    instancia[i] = randNumber;
    i++;
  }
}

void sonidoDeInicio()
{
  for (int veces = 1; veces < 5; veces++)
  {
    analogWrite(buzzer, 128); //emite sonido
    delay(50); //espera medio segundo
    analogWrite(buzzer, LOW); //emite sonido
    delay(50); //espera medio segun
  }
  analogWrite(buzzer, 200);
  delay(200); //espera medio segundo
  analogWrite(buzzer, LOW); //emite sonido
  delay(50); //espera medio segundo
  delay(1000);
}

void sonidoDeFin()
{
  analogWrite(buzzer, 200);
  delay(1000);
  analogWrite(buzzer, LOW);

}



void proximoNivel()
{
  int i;
  if (instancia[pos] == 3)
  {
    Serial.println("Izquierda");
  }
  else
  {
    Serial.println("Derecha");
  };

  for (i = 0; i <= pos; i++)
  {
    sonarBoton(instancia[i], 300);
  };
  for (i = 0; i <= pos && flag == 0; i++)
  {
    while (digitalRead(boton1) == 0 && digitalRead(boton2) == 0 ) {}

    if (digitalRead(instancia[i]) == 1)
    {
      sonarBoton(instancia[i], 0);
      delay(200);
    }
    else
    {
      flag = 1;
    };
  }
  delay(300);

  if (flag == 0)
  {
    pos++;
    proximoNivel();
  }
  pos = 0;
  flag = 0;

}

void sonarBoton(int numero, int duracion)
{
  if (numero == 2)
  {
    digitalWrite(13, HIGH);
    analogWrite(buzzer, 100);
    delay(200);
    digitalWrite(13, LOW);
    analogWrite(buzzer, LOW);
    delay(duracion);
  };
  if (numero == 3)
  {
    analogWrite(buzzer, 200);
    delay(200);
    analogWrite(buzzer, LOW);
    delay(duracion);
  }
}


void comenzarJuego()
{
  proximoNivel();
}
