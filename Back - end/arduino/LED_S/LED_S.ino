#define LED_VERMELHO 4
#define LED_AMARELO1 3
#define LED_VERDE 2
#define LED_AMARELO2 5

#define BOTAO_VERMELHO 10
#define BOTAO_AMARELO1 8
#define BOTAO_VERDE 9
#define BOTAO_AMARELO2 11

#define INDEFINIDO -1

#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

#define TAMANHO_SEQUENCIA 4

enum Estados{
  PRONTO_PARA_PROX_RODADA,
  USUARIO_RESPONDENDO,
  JOGO_FINALIZADO_SUCESSO,
  JOGO_FINALIZADO_FALHA
};

int sequenciaLuzes[TAMANHO_SEQUENCIA];

void setup() {
  Serial.begin(9600);
  iniciaPortas();
  iniciaJogo();
}

void iniciaJogo(){
  int jogo = analogRead(0);
  randomSeed(jogo);
  for (int indice = 0; indice < TAMANHO_SEQUENCIA; indice ++){
    sequenciaLuzes[indice]= sorteiaCor();
  }

}

int sorteiaCor (){
  return random(LED_VERDE, LED_AMARELO2 + 1);
}

void iniciaPortas(){
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO1, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO2, OUTPUT);

  pinMode(BOTAO_VERDE, INPUT_PULLUP);
  pinMode(BOTAO_AMARELO1, INPUT_PULLUP);
  pinMode(BOTAO_VERMELHO, INPUT_PULLUP);
  pinMode(BOTAO_AMARELO2, INPUT_PULLUP);
}

int rodada = 0;

int leds_respondidos = 0;

void loop() {
  switch(estadoAtual()){
    case PRONTO_PARA_PROX_RODADA:
      Serial.println("Pronto para proxima rodada");
      preparaNovaRodada();
      break;
    case USUARIO_RESPONDENDO:
      Serial.println("Usuario respondendo");
      processaRespostaUsuario();
      break;
    case JOGO_FINALIZADO_SUCESSO:
      Serial.println("Jogo finalizado sucesso");
      jogoFinalizadoSucesso();
      break;
    case JOGO_FINALIZADO_FALHA:
      Serial.println("Jogo finalizado falha");
      jogoFinalizadoFalha();
      break;
  }
  delay(500);
}

void preparaNovaRodada(){
  rodada++;
  leds_respondidos = 0;
  if(rodada <= TAMANHO_SEQUENCIA){
    tocaLedsRodada();
  }
}

void processaRespostaUsuario(){
  int resposta = checaRespostaJogador();

  if(resposta == INDEFINIDO){
    return;
  }
  
  if (resposta == sequenciaLuzes[leds_respondidos]){
    leds_respondidos++; 
  }else{
    Serial.println("Resposta errada");
    rodada = TAMANHO_SEQUENCIA +2;
  }
}

int estadoAtual(){
  if (rodada <= TAMANHO_SEQUENCIA){
    if(leds_respondidos == rodada){
      return PRONTO_PARA_PROX_RODADA;
    }else{
      return USUARIO_RESPONDENDO;
    }
  }else if (rodada == TAMANHO_SEQUENCIA +1){
    return JOGO_FINALIZADO_SUCESSO;
  }else{
    return JOGO_FINALIZADO_FALHA;
  }
}

void tocaLedsRodada(){
   for (int indice = 0; indice < rodada; indice++) {
     piscaLed(sequenciaLuzes[indice]);
   }
  
}

int checaRespostaJogador(){
  if(digitalRead(BOTAO_VERMELHO) == LOW){
    return piscaLed(LED_VERMELHO);
  }
  if(digitalRead(BOTAO_AMARELO1) == LOW){
    return piscaLed(LED_AMARELO1);
  }
  if(digitalRead(BOTAO_VERDE) == LOW){
    return piscaLed(LED_VERDE);
  }
  if(digitalRead(BOTAO_AMARELO2) == LOW){
    return piscaLed(LED_AMARELO2);
  }

  return INDEFINIDO;
}

int piscaLed(int portaLed){
  digitalWrite(portaLed,HIGH);
  delay(UM_SEGUNDO);
  digitalWrite(portaLed,LOW);
  delay(MEIO_SEGUNDO);
  return portaLed;
}

void jogoFinalizadoSucesso(){
  piscaLed(LED_VERMELHO);
  piscaLed(LED_AMARELO1);
  piscaLed(LED_VERDE);
  piscaLed(LED_AMARELO2);
  delay(MEIO_SEGUNDO);
}

void jogoFinalizadoFalha(){
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AMARELO1, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AMARELO2, HIGH);
  delay(UM_SEGUNDO);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO1, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO2, LOW);
}
