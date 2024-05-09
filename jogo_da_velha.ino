// Declaração de todas as variaveis
int tabuleiro[3][3];
int linha;
int coluna;
int diagonal;
int velha = 1;
int jogadordavez = 1;
bool HaVencedor = false;
// Estabelecer as Strings
String jogador1 = "Jogador 1";
String jogador2 = "Jogador 2";
String jogada;

// Função para zerar o tabuleiro, as variaveis e reiniciar.
int zerarJogo(int tabuleiro[3][3]) {
  HaVencedor = false;
  velha = 1;
  jogadordavez = 1;
  for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      tabuleiro[linha][coluna] = 0;
    }
  }
}
// Função que imprime o tabuleiro na Serial.
int imprimirTabuleiro(int tabuleiro[3][3]) {

  for (int linha = 0; linha <= 2; linha++) {
    if (linha == 1 || linha == 2) {
      Serial.println("");
    }
    for (int coluna = 0; coluna <= 2; coluna++) {
      Serial.print(tabuleiro[linha][coluna]);
    }
  }
// Imprime a mensagem para o jogador digitar sua jogada e declara o jogador que vai jogar.
  Serial.println("");
  Serial.print("Digite sua jogada Jogador");
  Serial.println(jogadordavez);
}

void setup() {
  // Velocidade da passagem dos dados da porta Serial.
  Serial.begin(115200);
  // Chamada da função para zerar as variaveis.
  zerarJogo(tabuleiro);
// Chamada da função para imprimir o tabuleiro na Serial
  imprimirTabuleiro(tabuleiro);
}
// Entrada no loop e inicio do jogo
void loop() {

  do {

    while (!Serial.available()) // verifica se há algo a ser lido na Serial.available.
      ;

    String entrada = Serial.readString(); // lê o valor que o jogador digita na Serial
    Serial.print("Valor da jogada: "); // imprime o valor digitado pelo jogador
    Serial.println(entrada);

     //Função que vai pegar uma parte da entrada(substring).
    linha = entrada.substring(0, 1).toInt();
    coluna = entrada.substring(2, 3).toInt();

    
    if (linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2) {
      if (tabuleiro[linha][coluna] == 0) {
        tabuleiro[linha][coluna] = jogadordavez;
        
        imprimirTabuleiro(tabuleiro); // Imprime tabuleiro na Serial.

        // Ifs que verificam ganhador em Linha, Coluna e Diagonal.
        if (tabuleiro[0][0] == jogadordavez && tabuleiro[0][1] == jogadordavez && tabuleiro[0][2] == jogadordavez || tabuleiro[1][0] == jogadordavez && tabuleiro[1][1] == jogadordavez && tabuleiro[1][2] == jogadordavez || tabuleiro[2][0] == jogadordavez && tabuleiro[2][1] == jogadordavez && tabuleiro[2][2] == jogadordavez) {
          HaVencedor = true;
        } else if (tabuleiro[0][0] == jogadordavez && tabuleiro[1][0] == jogadordavez && tabuleiro[2][0] == jogadordavez || tabuleiro[0][1] == jogadordavez && tabuleiro[1][1] == jogadordavez && tabuleiro[2][1] == jogadordavez || tabuleiro[0][2] == jogadordavez && tabuleiro[1][2] == jogadordavez && tabuleiro[2][2] == jogadordavez) {
          HaVencedor = true;
        } else if (tabuleiro[0][0] == jogadordavez && tabuleiro[1][1] == jogadordavez && tabuleiro[2][2] == jogadordavez || tabuleiro[0][2] == jogadordavez && tabuleiro[1][1] == jogadordavez && tabuleiro[2][0] == jogadordavez) {
          HaVencedor = true;
        } else {
          
          // If para mudança de jogador.
          if (jogadordavez == 1 && HaVencedor == false) {
            jogadordavez = 2;
          } else if (jogadordavez == 2 && HaVencedor == false) {
            jogadordavez = 1;
          }
          
          // Determina o empate(velha).
          Serial.println(velha);
          velha = velha + 1;

          // Imprime para o outro jogador digitar sua jogada.
          Serial.println("");
          Serial.print("Digite sua jogada Jogador");
          Serial.println(jogadordavez);
        }

       // Else que determina se a posição ja esta ocupada se estiver digite novamente.
      } else {
        Serial.println("Posicao ocupada");
        Serial.print("Digite novamente jogador");
        Serial.println(jogadordavez);
      }

    // Else que determina se a jogada foi valida, se não digitar novamente
    } else {
      Serial.println("Jogada Invalida");
      Serial.print("Digite novamente jogador");
      Serial.println(jogadordavez);
    }
   // função que determina, enquanto não tiver vencedor e nem velha, repita.
  } while (!HaVencedor && velha <= 9);
  
  // Função que determina o vencedor e imprime qual jogador venceu
  if (HaVencedor) {
    Serial.println("");
    Serial.println("Parabens!!");
    Serial.print("Vencedor, jogador");
    Serial.println(jogadordavez);
    
    //Após declarar vencedor, zera o tabuleiro e reinicia a partida, imprimimdo o tabuleiro novamente.
    zerarJogo(tabuleiro);
    imprimirTabuleiro(tabuleiro);

    //Se não ha vencedor e for velha, zerar o tabuleiro e reiniciar a partida, imprimindo o tabuleiro novamente.
  } else {
    Serial.println("VELHA");
    zerarJogo(tabuleiro);
    imprimirTabuleiro(tabuleiro);
  }
}
