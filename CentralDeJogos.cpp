#include <iostream>

#include <string.h>

#include <stdlib.h>

#include <time.h>

#include <windows.h>

#include <locale>

using namespace std;
struct Carta {
  string nome;
  int valor;
  string naipe;
};
struct Usuario { // Estrutura do usuario
  int idade;
  string nome;
  string nickname;
  int cod_jogador;
  int pontosDoJogador;
};
//Métodos
//INICIO
void CentralDeJogosEstetica(int numero);
void mostrarRanking(Usuario usuario[]);
void menuLoginRegistro();
bool existeUsuarioParaPlayer2(Usuario usuario[], int tentativa);
bool loginPlayer2JogoDaVelha(Usuario usuario[]);
void jogoDaVelhaLoginRegistroPlayer2(Usuario usuario[]);
void jogoDaVelha(Usuario usuario[]);
void JogoDaForca();
void jogo21(Usuario usuario[]);
void trocarCartas();
int gerarNumeroParaEmbaralhar();
void gerarcarta();
void exibircarta();
void mensagemDeErroGenerica(int codigoDaMensagem);
Usuario registroDeUsuario(Usuario usuario[]);
bool existeUsuario(Usuario usuario[], int tentativa);
void login(Usuario usuario[]);
void batalhaNaval(Usuario usuario[]);
void centralDeJogos(Usuario usuario[]);
void creditos();
//FIM

//Jogos
//INICIO
void jogoDaVelha(Usuario usuario[]);
void batalhaNaval(Usuario usuario[]);
void JogoDaForca();

//FIM

//Variaveis
//INICIO
int
const tamanhoVetorUsuario = 20; //variavel de controle
int CodigoDeJogadorParaPontuacaoNoRanking, CodigoDePlayer2ParaPontuacaoNoRanking, usuarioLogado; //variaveis de controle para controlar pontuação no ranking
Usuario usuario[tamanhoVetorUsuario];
void trocarCartas();
void exibircarta();
void gerarcarta();
int gerarNumeroParaEmbaralhar();
int funcaoEmbaralhar();
void jogo21();
int variavelDo21 = 100000;
int
const tam = 52;
Carta carta[tam];
int i; //variavel de controle para determinar quantos usuarios ja foram logados
//FIM

int main() {
  setlocale(LC_ALL, "");
  menuLoginRegistro();
}
void menuLoginRegistro() { //Função que mostra o primeiro menu do algoritmo
  int opcao; //Variavel de escolha da opção
  do {
    CentralDeJogosEstetica(1);
    cout << " 1 - Registrar\n";
    cout << " 2 - Login\n";
    cout << " 3 - Sair\n\n";
    cout << " Escolha: ";
    cin >> opcao;
    CentralDeJogosEstetica(2);
    switch (opcao) {
    case 1:
      system("cls");
      CentralDeJogosEstetica(1);
      registroDeUsuario(usuario);
      CentralDeJogosEstetica(2);
      system("cls");
      break;
    case 2:
      system("cls");
      CentralDeJogosEstetica(1);
      login(usuario);
      opcao = 50;
      CentralDeJogosEstetica(2);
      system("cls");
      break;
    case 3:
      system("cls");
      CentralDeJogosEstetica(1);
      cout << "Saindo...\n\n";
      CentralDeJogosEstetica(2);
      return;
      system("cls");
      break;
    case 50:
      system("cls");
      CentralDeJogosEstetica(1);
      system("cls");
      break;
    default:
      mensagemDeErroGenerica(1);
      system("cls");
      break;

    }
  } while (opcao != 2);
}
void centralDeJogos(Usuario usuario[]) { //Procedimento que mostra o menu da central de jogos
  int opcao1;
  do {
    CentralDeJogosEstetica(1);
    cout << " 1 - Batalha Naval\n";
    cout << " 2 - Forca\n";
    cout << " 3 - 21\n";
    cout << " 4 - Jogo da velha\n";
    cout << " 5 - Ranking\n";
    cout << " 6 - Créditos\n";
    cout << " 7 - Sair\n";
    cout << "\n Escolha: ";
    cin >> opcao1;
    switch (opcao1) {
    case 1:
      system("cls");
      batalhaNaval(usuario);
      system("cls");
      break;
    case 2:
      system("cls");
      JogoDaForca();
      system("cls");
      break;
    case 3:
      system("cls");
      jogo21(usuario);
      system("cls");
      break;
    case 4:
      system("cls");
      jogoDaVelhaLoginRegistroPlayer2(usuario);
      system("cls");
      break;
    case 5:
      system("cls");
      mostrarRanking(usuario);
      system("cls");
      break;
    case 6:
      system("cls");
      creditos();
      break;
    case 7:
      return;
      break;
    default:
      mensagemDeErroGenerica(1);
      system("cls");
      break;
      CentralDeJogosEstetica(2);
      system("pause");
      system("cls");
      break;
    }
  } while (opcao1 <= 5 || opcao1 >= 1);
}
void login(Usuario usuario[]) { //Procedimento para logar
  int codigoDeJogador;
  cout << "Cod_jogador: ";
  cin >> codigoDeJogador;
  /*Teste logico realizado para logar usuario, caso ele retorne verdadeiro o usuario e logado,
  se ele retorna falso indica uma mensagem de erro e o usuario não será logado*/
  if (existeUsuario(usuario, codigoDeJogador)) {
    cout << "\n\nLogin realizado com sucesso\n\n\n\n";
    CentralDeJogosEstetica(2);
    system("cls");
    centralDeJogos(usuario);
  } else {
    mensagemDeErroGenerica(2);
    return;
  }
}
bool existeUsuario(Usuario usuario[], int tentativa) { //Função para verificar se existe algum usuario registrado
  /*Aqui foi criado um sistema que verifica o codigo de jogador inserido pelo usuario com algum existente no vetor usuario,
  caso o codigo inserido seja igual a algum no vetor usuario o sistema criado retorna verdadeiro e ele é logado*/
  for (int j = 0; j < 20; j++) {
    if (tentativa == usuario[j].cod_jogador) {
      CodigoDeJogadorParaPontuacaoNoRanking = usuario[j].cod_jogador - 1; //Foi salvo na variavel CodigoDeJogadorParaPon... qual usuario esta logado.
      usuarioLogado = usuario[j].cod_jogador; //Foi criado para mostrar qual usuario esta logado o tempo todo
      return true;
    }
  }
  return false;
}
Usuario registroDeUsuario(Usuario usuario[]) { //Predimento que registra usuario
  cout << "Digite seu nome: ";
  cin >> usuario[i].nome;
  cout << "Digite seu nickname: ";
  cin >> usuario[i].nickname;
  cout << "Digite sua idade: ";
  cin >> usuario[i].idade;
  cout << "\n\nSeu codigo de jogador é " << i + 1 << "\n\n\n\n";
  usuario[i].cod_jogador = i + 1;
  i = i + 1;
  return *usuario;
}
void CentralDeJogosEstetica(int numero) { //Procedimento criado para deixa o algoritmo mais bonito
  switch (numero) {
  case 1:
    cout << "________________________________________________________________________________\n\n\t\t\t\tCENTRAL DE JOGOS\n\n________________________________________________________________________________\n\n";
    break;
  case 2:
    cout << "________________________________________________________________________________";
    system("pause");
    break;
  }
}
void mostrarRanking(Usuario usuario[]) { //Procedimento que mostra o Ranking dos Jogadores ordenado de forma que o maior pontuador seja o primeiro
  CentralDeJogosEstetica(1);

  int auxPonto, auxIdade, auxCod;
  string auxNome, auxNick;
  int y, x;
  int min, maior;

  for (x = 0; x < (i - 1); x++) {
    min = x;

    for (y = y + 1; y < i; y++) {
      if (usuario[y].pontosDoJogador > usuario[min].pontosDoJogador) {
        min = y;
      }
    }
    if (x != min) {
      auxPonto = usuario[x].pontosDoJogador;
      auxIdade = usuario[x].idade;
      auxCod = usuario[x].cod_jogador;
      auxNome = usuario[x].nome;
      auxNick = usuario[x].nickname;

      usuario[x].pontosDoJogador = usuario[min].pontosDoJogador;
      usuario[x].idade = usuario[min].idade;
      usuario[x].cod_jogador = usuario[min].cod_jogador;
      usuario[x].nome = usuario[min].nome;
      usuario[x].nickname = usuario[min].nickname;

      usuario[min].pontosDoJogador = auxPonto;
      usuario[min].idade = auxIdade;
      usuario[min].cod_jogador = auxCod;
      usuario[min].nome = auxNome;
      usuario[min].nickname = auxNick;

    }
  }

  for (int j = 0; j < i; j++) {
    cout << j + 1 << " - Nickname: " << usuario[j].nickname;
    cout << "\tPontos: " << usuario[j].pontosDoJogador << "\n\n";
  }

  CentralDeJogosEstetica(2);
  return;
}
void batalhaNaval(Usuario usuario[]) { //Procedimento da batalha naval
  int tamanho = 16, quant_erros = 0, quant_barcos = 0;
  int numero, letra, m;
  string letra_char, continuar = "s";
  string letra_vetor[14] = {
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n"
  };
  string jogo[tamanho][tamanho] = {
    {
      "",
      " A",
      "B",
      "C",
      "D",
      "E",
      "F",
      "G",
      "H",
      "I",
      "J",
      "K",
      "L",
      "M",
      "N"
    },
    {
      "1 ",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "2 ",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "3 ",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "4 ",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "5 ",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "6 ",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "7 ",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "8 ",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "9 ",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "10",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "11",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "12",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "13",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "14",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
    {
      "15",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-",
      "-"
    },
  };
  string matriz[tamanho][tamanho][tamanho] = {
    {
      {
        "",
        " A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N"
      }, {
        "1 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^"
      }, {
        "2 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^"
      }, {
        "3 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      }, {
        "4 ",
        "-",
        "-",
        "^",
        "^",
        "^",
        "^",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      }, {
        "5 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-"
      }, {
        "6 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-"
      }, {
        "7 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-"
      }, {
        "8 ",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-"
      }, {
        "9 ",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      }, {
        "10",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      }, {
        "11",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      }, {
        "12",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      }, {
        "13",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      }, {
        "14",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      }, {
        "15",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
    },
    {
      {
        "",
        " A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N"
      },
      {
        "1 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "2 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "^",
        "^",
        "-"
      },
      {
        "3 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "4 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "5 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "6 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "7 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "8 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "9 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "10",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "11",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "12",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "^",
        "^",
        "^",
        "-",
        "-",
        "-"
      },
      {
        "13",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "14",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "15",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
    },
    {
      {
        "",
        " A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N"
      },
      {
        "1 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "2 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "3 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "4 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "5 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "6 ",
        "-",
        "^",
        "^",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "7 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-"
      },
      {
        "8 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-"
      },
      {
        "9 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "10",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "11",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "12",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "13",
        "-",
        "-",
        "-",
        "^",
        "^",
        "^",
        "^",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "14",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "15",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
    },
    {
      {
        "",
        " A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N"
      },
      {
        "1 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "2 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "3 ",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "4 ",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-"
      },
      {
        "5 ",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-"
      },
      {
        "6 ",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-"
      },
      {
        "7 ",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "8 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "9 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "10",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "11",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "12",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "13",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "14",
        "-",
        "-",
        "-",
        "^",
        "^",
        "^",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "15",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
    },
    {
      {
        "",
        " A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N"
      },
      {
        "1 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "2 ",
        "-",
        "-",
        "^",
        "^",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "3 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "4 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "5 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "6 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "7 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "^",
        "^",
        "^",
        "^",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "8 ",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "9 ",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "10",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "11",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "^"
      },
      {
        "12",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "13",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "14",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "15",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
    },
    {
      {
        "",
        " A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N"
      },
      {
        "1 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "2 ",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "3 ",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "4 ",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "^",
        "^",
        "^",
        "-"
      },
      {
        "5 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "6 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "7 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "8 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "9 ",
        "-",
        "-",
        "-",
        "-",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "10",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "11",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "12",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "13",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "14",
        "-",
        "-",
        "-",
        "-",
        "^",
        "^",
        "^",
        "^",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
      {
        "15",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-",
        "-"
      },
    }
  };

  time_t t;
  srand(time( & t));

  m = rand() % 7;
  do {
    cout << "________________________________________________________________________________\n\t\t\t\t Batalha Naval\n________________________________________________________________________________";

    for (int i = 0; i < tamanho; i++) { // Mostra o jogo
      for (int j = 0; j < tamanho; j++) {
        cout << jogo[i][j] << " ";
        if (i == 0 && j == 0) {
          cout << "\t\t\t  ";
        }
      }
      cout << "\n\t\t\t";
    }

    cout << "\nDigite as coordenadas \n\nLetra: ";
    cin >> letra_char;
    cout << "Número: ";
    cin >> numero;
    system("pause");

    if (numero <= 0 || numero > 15) {
      system("cls");
      cout << "________________________________________________________________________________\n\t\t\t\t Batalha Naval\n________________________________________________________________________________";
      cout << "\n\n\nSó são permitidos números entre 1 e 15, tente novamente\n\n\n";
      system("pause");
      system("cls");
      continue;
    }

    for (int i = 0; i < 15; i++) { // Converte letra para o número correspondente
      if (letra_char == letra_vetor[i]) {
        letra = i + 1;
        break;
      }
    }

    if (letra <= 0 || letra > 15) {
      system("cls");
      cout << "________________________________________________________________________________\n\t\t\t\t Batalha Naval\n________________________________________________________________________________";
      cout << "\n\n\nSó são permitidas letras entre A e M, tente novamente\n\n\n";
      system("pause");
      system("cls");
      continue;
    }

    if (matriz[m][numero][letra] == "-") {
      if (jogo[numero][letra] == "*") {
        system("cls");
        cout << "________________________________________________________________________________\n\t\t\t\t Batalha Naval\n________________________________________________________________________________";
        cout << "\n\n\nVocê já não achou nada aqui!\n\n\n";
        system("pause");
        system("cls");
        continue;
      }
      jogo[numero][letra] = "*";
      quant_erros++;
      if (quant_erros > 30) {
        system("cls");
        cout << "________________________________________________________________________________\n\t\t\t\t Batalha Naval\n________________________________________________________________________________";
        cout << "\n\n\nVocê atingiu a quantidade máxima de erros!!!!!\n\nVocê perdeeeu!\n\n\n";
        system("pause");
        continue;
      }
      system("cls");
      cout << "________________________________________________________________________________\n\t\t\t\t Batalha Naval\n________________________________________________________________________________";
      cout << "\n\n\nVocê não encontrou NADA! Você tem " << 30 - quant_erros << " tentativas restantes!\n\n\n";
    } else if (matriz[m][numero][letra] == "^") {

      if (jogo[numero][letra] == "^") {

        system("cls");
        cout << "________________________________________________________________________________\n\t\t\t\t Batalha Naval\n________________________________________________________________________________";
        cout << "\n\n\nVocê já achou um barco aqui!\n\n\n";
        system("pause");
        system("cls");
        continue;
      }

      jogo[numero][letra] = "^";
      quant_barcos++;

      if (quant_barcos == 14) {
        system("cls");
        cout << "________________________________________________________________________________\n\t\t\t\t Batalha Naval\n________________________________________________________________________________";
        cout << "\n\n\nVocê encontrou todos os barcos!!!\n\nParabéns, você venceu!!\n\n\n";
        cout << "\n\nVocê ganhou um ponto !";
        usuario[CodigoDeJogadorParaPontuacaoNoRanking].pontosDoJogador++;
        system("pause");
        continue;
      }
      system("cls");
      cout << "________________________________________________________________________________\n\t\t\t\t Batalha Naval\n________________________________________________________________________________";
      cout << "\n\n\nVocê encontrou um BARCO! Faltam mais " << 14 - quant_barcos << " peças de barcos.\n\n\n";
    }

    cout << "\nDeseja continuar a jogar? [s/n] : ";
    cin >> continuar;
    cout << "\n\n";
    system("pause");
    system("cls");

  } while (quant_erros <= 30 && quant_barcos <= 14 && continuar == "s");
  return;
}
void jogoDaVelha(Usuario usuario[]) { //Procedimento Jogo
  int jogadas, v = 0, p = 0, vitoria1 = 0, vitoria2 = 0;
  string vetor[10] = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9"
  };
  string jogador1, jogador2, o = "O", x = "X";
  string posicao;
  string matriz[3][3];
  char continuar;
  do {
    jogadas = 0;
    v = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        v++;
        matriz[i][j] = vetor[v];
      }
    }

    do {
      cout << "________________________________________________________________________________\n\t\t\t\tJogo da Velha\n________________________________________________________________________________";
      cout << "\n\nJogador 1:\n\nX ou O?\n\nEscolha: ";
      cin >> jogador1;
      cout << "\n\n\n";
      if (jogador1 != "x" && jogador1 != "X" && jogador1 != "o" && jogador1 != "O")
        cout << "\n\nOpção inválida!!!\n\n\n";
    } while (jogador1 != "x" && jogador1 != "X" && jogador1 != "o" && jogador1 != "O");
    if (jogador1 == "x" || jogador1 == "X") {
      jogador1 = x;
      jogador2 = o;
      system("pause");
      system("cls");
      cout << "________________________________________________________________________________\n\t\t\t\tJogo da Velha\n________________________________________________________________________________";
      cout << "\n\nJogador1 joga com X\n\nJogador2 joga com O\n\n";
    } else if (jogador1 == "o" || jogador1 == "O") {
      jogador1 = o;
      jogador2 = x;
      system("pause");
      system("cls");
      cout << "________________________________________________________________________________\n\t\t\t\tJogo da Velha\n________________________________________________________________________________";
      cout << "\n\nJogador1 joga com O\n\nJogador2 joga com X\n\n";
    }
    system("pause");
    system("cls");

    do {
      cout << "________________________________________________________________________________\n\t\t\t\tJogo da Velha\n________________________________________________________________________________";

      cout << "\n   " << matriz[0][0] << " | " << matriz[0][1] << "| " << matriz[0][2] << "\n";
      cout << "   --|--|--\n";
      cout << "   " << matriz[1][0] << " | " << matriz[1][1] << "| " << matriz[1][2] << "\n";
      cout << "   --|--|--\n";
      cout << "   " << matriz[2][0] << " | " << matriz[2][1] << "| " << matriz[2][2] << "\n" << "\n\n";

      //do{

      cout << "\n\nPlacar:\nJogador 1: " << vitoria1 << " vitórias" << "\nJogador 2: " << vitoria2 << " vitórias";
      do {
        cout << "\n\nVez de Jogador 1:\n\nDigite uma posição: ";
        cin >> posicao;
        if (posicao != "1" && posicao != "2" && posicao != "3" && posicao != "4" && posicao != "5" && posicao != "6" && posicao != "7" && posicao != "8" && posicao != "9")
          cout << "\n\nPosição inexistente";
      } while (posicao != "1" && posicao != "2" && posicao != "3" && posicao != "4" && posicao != "5" && posicao != "6" && posicao != "7" && posicao != "8" && posicao != "9");
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (posicao == matriz[i][j]) {
            matriz[i][j] = jogador1;
            jogadas++;
          }
        }
      }

      if ((matriz[0][0] == matriz[0][1]) && (matriz[0][1] == matriz[0][2]) && (matriz[0][0] == jogador1) || (matriz[0][2] == matriz[1][2]) && (matriz[1][2] == matriz[2][2]) && (matriz[0][2] == jogador1) || (matriz[1][0] == matriz[1][1]) && (matriz[1][1] == matriz[1][2]) && (matriz[1][0] == jogador1) || (matriz[2][0] == matriz[2][1]) && (matriz[2][1] == matriz[2][2]) && (matriz[2][0] == jogador1) || (matriz[0][0] == matriz[1][0]) && (matriz[1][0] == matriz[2][0]) && (matriz[0][0] == jogador1) || (matriz[0][1] == matriz[1][1]) && (matriz[1][1] == matriz[2][1]) && (matriz[0][1] == jogador1) || (matriz[0][1] == matriz[1][1]) && (matriz[1][1] == matriz[2][1]) && (matriz[0][1] == jogador1) || (matriz[0][0] == matriz[1][1]) && (matriz[1][1] == matriz[2][2]) && (matriz[0][0] == jogador1) || (matriz[0][2] == matriz[1][1]) && (matriz[1][1] == matriz[2][0]) && (matriz[0][2] == jogador1)) {

        system("cls");
        cout << "________________________________________________________________________________\n\t\t\t\tJogo da Velha\n________________________________________________________________________________";
        cout << "\n\n\n\n\t\t\tGanhador: Jogador 1\n\n\n\n\n";

        vitoria1++;
        usuario[CodigoDeJogadorParaPontuacaoNoRanking].pontosDoJogador++;
        system("pause");
        system("cls");
        break;
      }
      if (jogadas == 9) {
        system("cls");
        cout << "________________________________________________________________________________\n\t\t\t\tJogo da Velha\n________________________________________________________________________________";
        cout << "\n\n\n\n\t\tDeu velha!\n";
        system("pause");
        vitoria1++;
        vitoria2++;

        system("cls");
        break;
      }

      system("cls");

      cout << "________________________________________________________________________________\n\t\t\t\tJogo da Velha\n________________________________________________________________________________";

      cout << "\n   " << matriz[0][0] << " | " << matriz[0][1] << "| " << matriz[0][2] << "\n";
      cout << "   --|--|--\n";
      cout << "   " << matriz[1][0] << " | " << matriz[1][1] << "| " << matriz[1][2] << "\n";
      cout << "   --|--|--\n";
      cout << "   " << matriz[2][0] << " | " << matriz[2][1] << "| " << matriz[2][2] << "\n" << "\n\n";

      cout << "\n\nPlacar:\n Jogador 1: " << vitoria1 << " vitórias" << "\nJogador 2: " << vitoria2 << " vitórias";
      do {
        cout << "\n\nVez de Jogador 2:\n\nDigite uma posição: ";
        cin >> posicao;
        if (posicao != "1" && posicao != "2" && posicao != "3" && posicao != "4" && posicao != "5" && posicao != "6" && posicao != "7" && posicao != "8" && posicao != "9")
          cout << "\nPosição inexistente";
      } while (posicao != "1" && posicao != "2" && posicao != "3" && posicao != "4" && posicao != "5" && posicao != "6" && posicao != "7" && posicao != "8" && posicao != "9");

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (posicao == matriz[i][j]) {
            matriz[i][j] = jogador2;
            jogadas++;
          }
        }
      }
      system("cls");
      if ((matriz[0][0] == matriz[0][1]) && (matriz[0][1] == matriz[0][2]) && (matriz[0][0] == jogador2) || (matriz[0][2] == matriz[1][2]) && (matriz[1][2] == matriz[2][2]) && (matriz[0][2] == jogador2) || (matriz[1][0] == matriz[1][1]) && (matriz[1][1] == matriz[1][2]) && (matriz[1][0] == jogador2) || (matriz[2][0] == matriz[2][1]) && (matriz[2][1] == matriz[2][2]) && (matriz[2][0] == jogador2) || (matriz[0][0] == matriz[1][0]) && (matriz[1][0] == matriz[2][0]) && (matriz[0][0] == jogador2) || (matriz[0][1] == matriz[1][1]) && (matriz[1][1] == matriz[2][1]) && (matriz[0][1] == jogador2) || (matriz[0][1] == matriz[1][1]) && (matriz[1][1] == matriz[2][1]) && (matriz[0][1] == jogador2) || (matriz[0][0] == matriz[1][1]) && (matriz[1][1] == matriz[2][2]) && (matriz[0][0] == jogador2) || (matriz[0][2] == matriz[1][1]) && (matriz[1][1] == matriz[2][0]) && (matriz[0][2] == jogador2)) {

        system("cls");
        cout << "________________________________________________________________________________\n\t\t\t\tJogo da Velha\n________________________________________________________________________________";
        cout << "\n\n\n\n\t\t\tGanhador: Jogador 2\n\n\n\n\n";
        vitoria2++;
        usuario[CodigoDePlayer2ParaPontuacaoNoRanking].pontosDoJogador++;

        system("pause");
        system("cls");
        break;
      }
      system("cls");
    } while (vitoria1 >= 0 || vitoria2 >= 0);
    if (vitoria1 > 0 || vitoria2 > 0) {

      do {
        cout << "________________________________________________________________________________\n\t\t\t\tJogo da Velha\n________________________________________________________________________________";
        cout << "\n\nDeseja continuar a jogar?[s/n]\n\nEscolha: ";
        cin >> continuar;
        if (continuar != 'n' && continuar != 'N' && continuar != 's' && continuar != 'S') {
          cout << "\n\nResposta inválida\n\n";
          system("pause");
          system("cls");
        }
        system("cls");
      } while (continuar != 'n' && continuar != 'N' && continuar != 's' && continuar != 'S');
    }
  } while (continuar == 's' || continuar == 'S');
  return;
}
void jogoDaVelhaLoginRegistroPlayer2(Usuario usuario[]) { //Procedimento mostrar o menu logar ou registrar o segundo player no jogo da velha
  int opcao2;
  do {
    CentralDeJogosEstetica(1);
    cout << "Observação: O Primeiro Jogador será quem estiver logado primeiro !\n\n";
    cout << "1 - Logar player 2\n";
    cout << "2 - Registrar player 2\n";
    cout << "3 - Sair\n\n";
    cout << "Escolha: ";
    cin >> opcao2;
    switch (opcao2) {
    case 1:
      system("cls");
      CentralDeJogosEstetica(1);
      if (loginPlayer2JogoDaVelha(usuario)) {
        jogoDaVelha(usuario);
        CentralDeJogosEstetica(2);
        system("cls");
        break;
      } else {
        system("cls");
        opcao2 = 4;
        break;
      }
    case 2:
      system("cls");
      CentralDeJogosEstetica(1);
      registroDeUsuario(usuario);
      CentralDeJogosEstetica(2);
      system("cls");
      break;
    case 3:
      return;
      break;
    default:
      //mensagem de erro
      break;
    }
  } while (opcao2 != 1);
  return;
}
bool loginPlayer2JogoDaVelha(Usuario usuario[]) { //Função criada para logar o player 2
  int codigoDeJogador;
  cout << "Cod_jogador do player 2: ";
  cin >> codigoDeJogador;
  /* Teste logico realizado para ver se o jogador colocou codigo igual ao que ja está logado,
     caso ele estiver logado o programa da um return.*/
  if (codigoDeJogador == usuarioLogado) {
    cout << "\nVocê precisa entrar com um codigo de jogador diferente do que ja está logado";
    system("pause");
    return false;
  }
  if (existeUsuarioParaPlayer2(usuario, codigoDeJogador)) { //Chama a função para verificar se o usuario existe
    cout << "\n\nLogin realizado com sucesso\n\n\n\n";
    CentralDeJogosEstetica(2);
    system("cls");
    return true;
  } else {
    cout << "\nNão existe este usuário!\n";
    system("pause");
    return false;
  }

}
bool existeUsuarioParaPlayer2(Usuario usuario[], int tentativa) { //Função criado para validar se existe usuario registrado para player 2
  for (int j = 0; j < 20; j++) {
    if (tentativa == usuario[j].cod_jogador) {
      CodigoDePlayer2ParaPontuacaoNoRanking = usuario[j].cod_jogador - 1;
      return true;
    }
  }
  return false;
}
void mensagemDeErroGenerica(int codigoDaMensagem) {
  switch (codigoDaMensagem) {
  case 1:
    cout << "\n\nEscolha uma das opções acima !!\n\n";
    system("pause");
    break;
  case 2:
    cout << "\nNão existe este usuário!\n";
    break;

  }
}
void JogoDaForca() {
  setlocale(LC_ALL, "");
  int
  const tamanho = 10;
  int p = 0, s, quant_erro = 0, quant_acerto = 0, letra_certa = 0, letra_repetida = 0, cont = 0, num = 0;
  string palavras, letra, continuar = "s";
  string aparencia[6] = {
    " ",
    " ",
    " ",
    " ",
    " ",
    " "
  };
  char * palavra[10] = {
    "computador",
    "teclado",
    "software",
    "monitor",
    "programacao",
    "cooler",
    "codeblocks",
    "gabinete",
    "hardware",
    "memoria"
  };

  srand(time(NULL));

  do {

    quant_acerto = 0;
    quant_erro = 0;
    cont = 0;

    p = rand() % 10; //Sorteia qual palavra será usada no jogo

    s = strlen(palavra[p]); //Verifica quantos caracteres há na palavra sorteada

    string palavra_sorteada[s]; //Cria um vetor com o tamanho da palavra sorteada
    string comparacao_erro[s]; //Vetor para não haver repeticao de letras erradas
    string comparacao[s]; //Vetor para não haver repeticao de letras acertadas
    string aparencia2[s];

    for (int i = 0; i < s; i++) { //Divide cada posicao do vetor em letras da palavra sorteada
      palavra_sorteada[i] = palavra[p][i];
      comparacao[i] = "-";
      aparencia2[i] = "_ ";
    }
    for (int i = 0; i < 6; i++) {
      comparacao_erro[i] = "-";
      aparencia[i] = " ";
    }

    do {
      letra_certa = 0;
      letra_repetida = 0;

      cout << "________________________________________________________________________________\n\t\t\t\t   Forca\n________________________________________________________________________________";
      cout << "\t\t\t*          ___       \t\t*\n";
      cout << "\t\t\t*         |   |      \t\t*\n";
      cout << "\t\t\t*         |   " << aparencia[0] << "\t\t\t*\n";
      cout << "\t\t\t*         |  " << aparencia[2] << aparencia[1] << aparencia[3] << "\t\t*\n";
      cout << "\t\t\t*         |  " << aparencia[4] << " " << aparencia[5] << "\t\t*\n";
      cout << "\t\t\t*         |          \t\t*\n";
      cout << "\t\t\t*         |______    \t\t*\n";
      cout << "\t\t\t*                    \t\t*\n";
      cout << "\t\t\t*                    \t\t*\n";

      for (int i = 0; i < s; i++) {
        cout << aparencia2[i];
      }

      cout << "\n\nDica: Relacionado a Informática!\n\n";
      cout << "Digite uma letra: ";
      cin >> letra;
      cout << "\n";

      for (int i = 0; i < s; i++) {
        if (letra == palavra_sorteada[i]) {
          if (comparacao[i] == "-" && letra_repetida == 0) {
            cout << "\n\nVocê encontrou a letra " << letra << "!\n\n";
            letra_repetida++;
            letra_certa++;
            aparencia2[i] = letra + " ";
            comparacao[i] = letra;
            quant_acerto++;

            if (quant_acerto == s) {
              system("pause");
              system("cls");
              cout << "________________________________________________________________________________\n\t\t\t\t   Forca\n________________________________________________________________________________";
              cout << "\n\nParabéns, você venceu!\n\nMais um ponto foi somado para seu perfil\n\n\n";
              usuario[CodigoDeJogadorParaPontuacaoNoRanking].pontosDoJogador++;
              system("pause");
              system("cls");
              continue;
            }
            system("pause");
            system("cls");
            continue;
          } else if (comparacao[i] == letra) {
            cout << "\n\nVocê já tentou essa letra!\n\n";
            letra_certa++;
            system("pause");
            system("cls");
            break;
          } else if (letra_repetida != 0) {
            cout << "________________________________________________________________________________\n\t\t\t\t   Forca\n________________________________________________________________________________";
            cout << "\n\nVocê encontrou mais uma letra " << letra << "!\n\n";
            aparencia2[i] = letra + " ";
            letra_certa++;
            quant_acerto++;
            system("pause");
            system("cls");
          }
        }
      }

      if (letra_certa == 0) {
        for (int i = 0; i < 6; i++) {
          if (letra == comparacao_erro[i]) {
            num = i;
            break;
          } else {
            num = cont;
          }
        }

        if (comparacao_erro[num] == "-") {

          quant_erro++;
          cout << "\nNão existe a letra " << letra << " na palavra!\n\nVocê tem mais " << 6 - quant_erro << " chances restantes!\n";
          comparacao_erro[cont] = letra;

          if (quant_erro == 1) {
            aparencia[0] = "O";
            cont++;
          } else if (quant_erro == 2) {
            aparencia[1] = "|";
            cont++;
          } else if (quant_erro == 3) {
            aparencia[2] = "/";
            cont++;
          } else if (quant_erro == 4) {
            aparencia[3] = "\\";
            cont++;
          } else if (quant_erro == 5) {
            aparencia[4] = "/";
            cout << "\nÚltima chance!\n";
            cont++;

          } else if (quant_erro >= 6) {
            aparencia[5] = "\\";
            cout << "\n\nSuas tentativas se esgotaram, você perdeu!\n\nA palavra era " << palavra[p] << "!\n\n";
            system("pause");
            system("cls");
            break;

          }

        } else if (letra == comparacao_erro[num]) {
          cout << "\n\nVocê já tentou essa letra e errou.\n\n";
          system("pause");
          system("cls");
          continue;
        }
        system("pause");
        system("cls");
      }

    } while (quant_erro < 6 && quant_acerto != s);

    cout << "________________________________________________________________________________\n\t\t\t\t   Forca\n________________________________________________________________________________";
    cout << "\n\nDeseja continuar a jogar? [s/n]\n\nEscolha: ";
    cin >> continuar;
    cout << "\n\n";
    system("pause");
    system("cls");

  } while (continuar == "s" || continuar == "S");

}
void creditos() {
  CentralDeJogosEstetica(1);
  cout << "\nUriel Alves   : Registro/Login de Usuário, Ranking e Jogo 21";
  cout << "\n\nIago Homero   : Batalha Naval e Jogo da Forca";
  cout << "\n\nIander Marques: Jogo da velha";
  cout << "\n\nDaniel Gomes  : Apoio moral e Mochila\n\n";
  CentralDeJogosEstetica(2);
  system("cls");
  return;
}
void jogo21(Usuario usuario[]) {
  int l = 0;
  int perdeu;
  gerarcarta();
  trocarCartas();
  int somaMao1 = 0;
  int somaMao2 = 0;
  char opcao = 's';
  char continuarJogando = 's';
  string vencedor;
  do {
    cout << "\tJogo do 21\n\n\n";
    do {
      somaMao1 = somaMao1 + carta[l].valor;
      if (somaMao1 == 21) {
        opcao = 'n';
        perdeu = 0;
        cout << "\nVocê tirou 21 parabens !!\n";
        system("pause");
        continue;
      }
      if (somaMao1 > 21) {
        cout << "\nVoce explodiu BOOM !\n";
        perdeu = 1;
        cout << "\nVocê perdeu";
        opcao = 'n';
        system("pause");
        system("cls");
      }
      if (somaMao1 < 21) {
        cout << "\nJogador 1: ";
        cout << "\nCartas: " << carta[l].nome << " " << carta[l].naipe;
        cout << " Voce somou: " << somaMao1 << "\n";
        cout << "Você deseja pegar mais cartas? (s/n) \n";
        cin >> opcao;
        if (opcao == 's') {
          l++;
        }
      }

      if (somaMao2 < 21 && somaMao2 > 16) {
        cout << "\nA maquina decidiu parar\n\n";
        system("pause");
      } else {
        if (somaMao2 < 21) {
          somaMao2 = somaMao2 + carta[l].valor;
          cout << "\nA maquina está com " << somaMao2 << "\n";
          l++;
        }
        if (somaMao2 == 21) {
          opcao = 'n';
          perdeu = 1;
          cout << "\nA maquina tirou 21 !!\n";
          system("pause");
        }
        if (somaMao2 > 21) {
          opcao = 'n';
          perdeu = 0;
          cout << "\nA maquina explodiu !!\n";
          system("pause");
          continue;
        }
      }
    } while (opcao != 'n');

    system("cls");
    if (somaMao1 < 21 && somaMao2 < 21) {
      if (somaMao1 > somaMao2) {
        perdeu = 0;
      } else {
        cout << "A maquina ganhou !! ela ficou com" << somaMao2 << "\n\n";
      }
      if (somaMao1 == somaMao2) {
        cout << "\nDeu empate!! \n";

      }

    }
    if (perdeu == 0) {
      cout << "O vencedor foi voce\n\n";
      usuario[CodigoDeJogadorParaPontuacaoNoRanking].pontosDoJogador++;
    }
    cout << "Deseja continuar jogando ? s/n\n";
    cin >> continuarJogando;
    somaMao1 = 0;
    somaMao2 = 0;
    system("cls");
  } while (continuarJogando == 's');
}
void exibircarta() {
  for (int l = 0; l < tam; l++) {
    cout << "\nCarta: " << carta[l].nome << " - " << carta[l].naipe << "\n";
  }
}
void trocarCartas() {
  int troca;
  for (int o = 0; o < 51; o++) {
    troca = gerarNumeroParaEmbaralhar();
    swap(carta[o], carta[troca]);
  }
}
int gerarNumeroParaEmbaralhar() {
  time_t t;
  srand(time( & t) + variavelDo21);
  Sleep(100);
  int x = rand() % 51;
  variavelDo21 = variavelDo21 - 12039;
  return x;
}
void gerarcarta() {
  carta[0].nome = "AS";
  carta[0].valor = 1;
  carta[0].naipe = "ouro";

  carta[1].nome = "AS";
  carta[1].valor = 1;
  carta[1].naipe = "copas";

  carta[2].nome = "AS";
  carta[2].valor = 1;
  carta[2].naipe = "Paus";

  carta[3].nome = "AS";
  carta[3].valor = 1;
  carta[3].naipe = "Espada";
  //--
  carta[4].nome = "2";
  carta[4].valor = 2;
  carta[4].naipe = "Paus";

  carta[5].nome = "2";
  carta[5].valor = 2;
  carta[5].naipe = "ouro";

  carta[6].nome = "2";
  carta[6].valor = 2;
  carta[6].naipe = "Espada";

  carta[7].nome = "2";
  carta[7].valor = 2;
  carta[7].naipe = "Copas";
  //--
  carta[8].nome = "3";
  carta[8].valor = 3;
  carta[8].naipe = "Paus";

  carta[9].nome = "3";
  carta[9].valor = 3;
  carta[9].naipe = "Ouro";

  carta[10].nome = "3";
  carta[10].valor = 3;
  carta[10].naipe = "Espada";

  carta[11].nome = "3";
  carta[11].valor = 3;
  carta[11].naipe = "Copas";
  //--
  carta[12].nome = "4";
  carta[12].valor = 4;
  carta[12].naipe = "Paus";

  carta[13].nome = "4";
  carta[13].valor = 4;
  carta[13].naipe = "Ouro";

  carta[14].nome = "4";
  carta[14].valor = 4;
  carta[14].naipe = "Espada";

  carta[15].nome = "4";
  carta[15].valor = 4;
  carta[15].naipe = "Copas";
  //--
  carta[16].nome = "5";
  carta[16].valor = 5;
  carta[16].naipe = "Paus";

  carta[17].nome = "5";
  carta[17].valor = 5;
  carta[17].naipe = "Ouro";

  carta[18].nome = "5";
  carta[18].valor = 5;
  carta[18].naipe = "Espada";

  carta[19].nome = "5";
  carta[19].valor = 5;
  carta[19].naipe = "Copas";
  //--
  carta[20].nome = "6";
  carta[20].valor = 6;
  carta[20].naipe = "Paus";

  carta[21].nome = "6";
  carta[21].valor = 6;
  carta[21].naipe = "Ouro";

  carta[22].nome = "6";
  carta[22].valor = 6;
  carta[22].naipe = "Espada";

  carta[23].nome = "6";
  carta[23].valor = 6;
  carta[23].naipe = "Copas";
  //--
  carta[24].nome = "7";
  carta[24].valor = 7;
  carta[24].naipe = "Paus";

  carta[25].nome = "7";
  carta[25].valor = 7;
  carta[25].naipe = "Ouro";

  carta[26].nome = "7";
  carta[26].valor = 7;
  carta[26].naipe = "Espada";

  carta[27].nome = "7";
  carta[27].valor = 7;
  carta[27].naipe = "Copas";
  //--
  carta[28].nome = "8";
  carta[28].valor = 8;
  carta[28].naipe = "Paus";

  carta[29].nome = "8";
  carta[29].valor = 8;
  carta[29].naipe = "Ouro";

  carta[30].nome = "8";
  carta[30].valor = 8;
  carta[30].naipe = "Espada";

  carta[31].nome = "8";
  carta[31].valor = 8;
  carta[31].naipe = "Copas";
  //--
  carta[32].nome = "9";
  carta[32].valor = 9;
  carta[32].naipe = "Paus";

  carta[33].nome = "9";
  carta[33].valor = 9;
  carta[33].naipe = "Ouro";

  carta[34].nome = "9";
  carta[34].valor = 9;
  carta[34].naipe = "Espada";

  carta[35].nome = "9";
  carta[35].valor = 9;
  carta[35].naipe = "Copas";
  //--
  carta[36].nome = "10";
  carta[36].valor = 10;
  carta[36].naipe = "Paus";

  carta[37].nome = "10";
  carta[37].valor = 10;
  carta[37].naipe = "Ouro";

  carta[38].nome = "10";
  carta[38].valor = 10;
  carta[38].naipe = "Espada";

  carta[39].nome = "10";
  carta[39].valor = 10;
  carta[39].naipe = "Copas";
  //--
  carta[40].nome = "J";
  carta[40].valor = 10;
  carta[40].naipe = "Paus";

  carta[41].nome = "J";
  carta[41].valor = 10;
  carta[41].naipe = "Ouro";

  carta[42].nome = "J";
  carta[42].valor = 10;
  carta[42].naipe = "Espada";

  carta[43].nome = "J";
  carta[43].valor = 10;
  carta[43].naipe = "Copas";
  //--
  carta[44].nome = "Q";
  carta[44].valor = 10;
  carta[44].naipe = "Paus";

  carta[45].nome = "Q";
  carta[45].valor = 10;
  carta[45].naipe = "Ouro";

  carta[46].nome = "Q";
  carta[46].valor = 10;
  carta[46].naipe = "Espada";

  carta[47].nome = "Q";
  carta[47].valor = 10;
  carta[47].naipe = "Copas";
  //--
  carta[48].nome = "K";
  carta[48].valor = 10;
  carta[48].naipe = "Paus";

  carta[49].nome = "K";
  carta[49].valor = 10;
  carta[49].naipe = "Ouro";

  carta[50].nome = "K";
  carta[50].valor = 10;
  carta[50].naipe = "Espada";

  carta[51].nome = "K";
  carta[51].valor = 10;
  carta[51].naipe = "Copas";
  //--
}