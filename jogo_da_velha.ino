int tabuleiro[3][3];
int linha;
int coluna;
int diagonal;
int velha = 1;
int jogadordavez = 1;
String jogador1 = "Jogador 1";
String jogador2 = "Jogador 2";
String jogada;
bool HaVencedor;

bool validaposicao(String entrada){};



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int linha = 0; linha <= 2; linha++) {
    for (int coluna = 0; coluna <= 2; coluna++) {
      tabuleiro[linha][coluna] = 0;
    }
  }
  for (int linha = 0; linha <= 2; linha++) {
    if (linha == 1 || linha == 2) {
      Serial.println("");
    }
    for (int coluna = 0; coluna <= 2; coluna++) {
      Serial.print(tabuleiro[linha][coluna]);
    }
  }
  Serial.println("");
  Serial.print("Digite sua jogada Jogador");
  Serial.println(jogadordavez);
}

void loop() {

  if (Serial.available() > 0) {
    String entrada = Serial.readString();
    Serial.print("Valor da jogada: ");
    Serial.println(entrada);

    linha = entrada.substring(0, 1).toInt();
    coluna = entrada.substring(2, 3).toInt();

    if (linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2) {

      if (tabuleiro[linha][coluna] == 0) {

        tabuleiro[linha][coluna] = jogadordavez;

        for (int linha = 0; linha <= 2; linha++) {
          if (linha == 1 || linha == 2) {
            Serial.println("");
          }
          for (int coluna = 0; coluna <= 2; coluna++) {
            Serial.print(tabuleiro[linha][coluna]);
          }
        }
        if (jogadordavez == 1) {
          jogadordavez = 2;
        } else {
          jogadordavez = 1;
        }


        Serial.println("");
        Serial.print("Digite sua jogada Jogador");
        Serial.println(jogadordavez);

      } else {
        Serial.println("Posicao ocupada");
        Serial.print("Digite novamente jogador");
        Serial.println(jogadordavez);
      }

    } else {
      Serial.println("Jogada Invalida");
      Serial.print("Digite novamente jogador");
      Serial.println(jogadordavez);
    }
    if (tabuleiro[0][0] == JogadorDaVez && tabuleiro[0][1] == JogadorDaVez && tabuleiro[0][2] == JogadorDaVez || tabuleiro[1][0] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[1][2] == JogadorDaVez || tabuleiro[2][0] == JogadorDaVez && tabuleiro[2][1] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez)
      HaVencedor = true;
  }
  if (tabuleiro[coluna][linha] == jogadordavez && tabuleiro[coluna][linha] == jogadordavez && tabuleiro[coluna][linha] == jogadordavez || tabuleiro[coluna][linha] == jogadordavez && tabuleiro[coluna][linha] == jogadordavez && tabuleiro[coluna][linha] == jogadordavez || tabuleiro[coluna][linha] == jogadordavez && tabuleiro[coluna][linha] == jogadordavez && tabuleiro[coluna][linha] == jogadordavez) {
    HaVencedor = true;
  }
}
}
