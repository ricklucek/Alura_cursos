#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    cout <<"***********" << endl;
    cout <<"  Welcome " << endl;
    cout <<"Start Game" << endl;
    cout <<"***********" << endl;

    cout <<"Escolha a dificuldade... " << endl;
    cout <<"Facil (F) Medio (M) Dificil (D) " << endl;
    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if(dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else if(dificuldade == 'D'){
        numero_de_tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;
    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_de_tentativas;tentativas++){
        int chute;
        cout <<"Qual o seu chute?";
        cin >> chute;

        double pontos_perdidos = abs((chute - NUMERO_SECRETO))/2.0;
        pontos = pontos - pontos_perdidos;

        cout <<"chute: "<< chute << endl;
        cout <<"Tentativa numero "<< tentativas << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou){
            cout <<"Parabens, voce acertou o numero!" << endl;
            nao_acertou = false;
            break;
        }
        else if(maior){
            cout <<"Seu chute foi maior que o numero secreto" << endl;
        }
        else{
            cout <<"Seu chute foi menor que o numero secreto" << endl;
        }
    }

    cout <<"Fim de jogo!" <<  endl;
    if(nao_acertou){
        cout <<"Voce excedeu o numero de tentativas :(" << endl;
    }
    else{
    cout <<"Voce tentou "<< tentativas <<" vezes." << endl; 
    cout.precision(2);
    cout << fixed;
    cout <<"Pontuacao: "<< pontos << endl;
    } 

}