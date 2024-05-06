int tabuleiro[3][3];
int linha;
int coluna;
int diagonal;
int velha = 1;
int jogadordavez = 1;
String jogador1 = "Jogador 1"; String jogador2 = "Jogador 2";
String jogada;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int linha = 0; linha <= 2; linha++) {
    for (int coluna = 0; coluna <= 2; coluna++) {
      tabuleiro[linha][coluna] = 0;
    }
  }
}

void loop() {
for {
    Serial.println(tabuleiro[0] && tabuleiro[1] && tabuleiro[2]);
    Serial.println(tabuleiro[3] && tabuleiro[4] && tabuleiro[5]);
    Serial.println(tabuleiro[6] && tabuleiro[7] && tabuleiro[8]);
    jogada = "";
    Serial.println("Digite a posição da sua peça JOGADOR" && jogadordavez)
    Serial.readString(jogada);
    if(validaPosicao(jogada)) {
      linha = toInt(jogada[0]);
      coluna = toInt(jogada[2]);
      Serial.println()
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String entrada = Serial.readString();
  }
}
