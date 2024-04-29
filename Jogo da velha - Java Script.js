function main() {
    // Criar tabuleiro e jogadores, zerar as variáveis.
    // 
    // 0: Posição vazia
    // 1: jogada na posição do jogador 1
    // 2: jogada na posição do jogador 2
    var tabuleiro = createArray(9);
    var haVencedor;

    haVencedor = 0;
    var i;

    for (i = 0; i <= 8; i++) {
        tabuleiro[i] = 0;
    }
    var jogador1;

    jogador1 = "Jogador 1";
    var jogador2;

    jogador2 = "Jogador 2";
    var jogada;
    var jogadordavez;

    jogadordavez = 1;
    var velha;
    var linha;
    var coluna;
    var resultadoValidotabuleiro;

    // Registrar a jogada do primeiro jogador
    velha = 1;
    do {
        window.alert(tabuleiro[0].ToString() + tabuleiro[1] + tabuleiro[2]);
        window.alert(tabuleiro[3].ToString() + tabuleiro[4] + tabuleiro[5]);
        window.alert(tabuleiro[6].ToString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";
        window.alert("Digite a posição da sua peça, Jogador" + jogadordavez);
        jogada = window.prompt('Enter a value for jogada');

        // Converter a jogada texto em dois interios linha e coluna
        // Simula a função Serial.parseInt() do arduino
        // Verificar se a posição "jogada" é valida
        if (validaPosicao(jogada)) {
            linha = parseInt(jogada.charAt(0));
            coluna = parseInt(jogada.charAt(2));
            window.alert("Linha: " + linha + "; Coluna:" + coluna);
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadordavez;
                resultadoValidotabuleiro = validotabuleiro(tabuleiro, jogadordavez);
                if (resultadoValidotabuleiro != 2) {
                    if (jogadordavez == 1) {
                        jogadordavez = 2;
                    } else {
                        jogadordavez = 1;
                    }
                }
                velha = velha + 1;
            } else {
                window.alert("Posição ocupada, jogue novamente");

                // Informar ao Jogador 1 que a posição está preenchida, é inválida e ele precisa informar uma posição válida. (vai virar do while)
            }
        }
    } while (resultadoValidotabuleiro == 0 && velha <= 9);
    if (resultadoValidotabuleiro == 2) {
        window.alert("Parabéns! Você ganhou jogador" + jogadordavez);
    } else {
        window.alert("Deu velha");
    }

    // Verificar o tabuleiro, se houver vencedor ou empate, finalizar o jogo.
}

function validaPosicao(entrada) {
    var entradaValida;

    entradaValida = false;
    window.alert(entrada.length());
    if (entrada.length() == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                entradaValida = true;
            }
        }
    }
    
    return entradaValida;
}

function validotabuleiro(tabuleiro, jogadordavez) {
    var resultado;

    resultado = 0;
    window.alert(jogadordavez);
    if (tabuleiro[0] == jogadordavez && tabuleiro[1] == jogadordavez && tabuleiro[2] == jogadordavez || tabuleiro[3] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[5] == jogadordavez || tabuleiro[6] == jogadordavez && tabuleiro[7] == jogadordavez && tabuleiro[8] == jogadordavez) {

        // Verificar jogada vencedora nas linhas
        resultado = 2;
    } else {
        if (tabuleiro[0] == jogadordavez && tabuleiro[3] == jogadordavez && tabuleiro[6] == jogadordavez || tabuleiro[1] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[7] == jogadordavez || tabuleiro[2] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[6] == jogadordavez) {

            // Verificar jogada vencedora nas linhas
            resultado = 2;
        } else {
            if (tabuleiro[0] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[8] == jogadordavez || tabuleiro[2] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[6] == jogadordavez) {

                // Verificar jogada vencedora nas linhas
                resultado = 2;
            }
        }
    }
    
    return resultado;
}
