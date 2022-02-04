#include<iostream>
using namespace std;

int main () {
    cout << "************************************" << endl;
    cout << "* Bem vindo ao jogo da adivinhacao *" << endl;
    cout << "************************************" << endl;

    const int NUMERO_SECRETO = 42;
    bool nao_acertou = true;
    int tentativas = 0;

    while(nao_acertou){
        tentativas++;

        cout << "tentativa numero " << tentativas << endl;

        int chute;
        cout << "Qual seu chute? " ;
        cin >> chute;

        cout << "Seu chute e: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou){
        cout << "Parabens! Voce acertou o numero secreto!" << endl;
        nao_acertou = false;
         }
        else if (maior){
        cout << "Seu chute foi maior que o numero secreto!" << endl;
        }
        else {
        cout << "Seu chute foi menor que o numero secreto!" << endl;
        }

     
    }

    cout << "FIM DE JOGO!" << endl;

    cout << "Voce acertou o numero secreto em "<< tentativas << " tentativas" << endl;
    
}