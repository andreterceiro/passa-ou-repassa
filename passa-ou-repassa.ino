int botao1 = 0;
int botao2 = 1;
int botaoJuiz = 2;
int led1 = 3;
int led2 = 4;
boolean jaApertou = false;
boolean valendo = true;
boolean piscarLed1 = false;
boolean piscarLed2 = false;

void setup() {
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(botao1, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);  
  
}

void loop() {
    if (valendo) {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        valendo = false;
    }
  
    if (digitalRead(botaoJuiz)) {
        valendo = true;
        piscarLed1 = false;
        piscarLed2 = false;
    }
  
    if ((valendo && digitalRead(botao1) == HIGH) || (piscarLed1)) {
        piscar(1);
        piscarLed1 = true;
    }
    if ((valendo && digitalRead(botao2) == HIGH) || (piscarLed2)) {
        piscar(2);
        piscarLed2 = true;
    }
   
    if (digitalRead(botaoJuiz) == HIGH) {
        permitido = true;
    } else {
        permitido = false;
    }
}

void piscar(led) {
    if (led == 1) {
        digitalWrite(led1, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        delay(500);        
    } else if (led == 2) {
        digitalWrite(led2, HIGH);
        delay(500);
        digitalWrite(led2, LOW);
        delay(500);              
    }
}
