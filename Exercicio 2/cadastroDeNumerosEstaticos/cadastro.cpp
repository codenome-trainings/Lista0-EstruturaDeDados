#include <iostream>
#include <stdio_ext.h>
#include "cadastro.h"

using namespace std;

void menu(){

    int numeros[10];
    cadastraNumeros(numeros);

    init:
    char escolha = ' ';
    cout << "1. Exibir vetor" << endl;
    cout << "2. Exibir elementos impares" << endl;
    cout << "3. Exibir elementos pares" << endl;
    cout << "4. Encerrar programa" << endl;
    cout << "Digite uma opção: ";

    __fpurge(stdin);
    cin >> escolha;

    switch (escolha) {
        case '4':
            return;
        case '1':
            exibirNumeros(numeros);
            break;
        case '2':
            exibirNumerosImpares(numeros);
            break;
        case '3':
            exibirNumerosPares(numeros);
            break;
        default:
            cout << "Opção inválida! Tente novamente..." << endl;
    }

    __fpurge(stdin);
    cout << "Pressione qualquer tecla para continuar...";
    getchar();

    bool escolha2;
    cout << "Deseja cadastrar mais números e analiza-los? [1] SIM | [0] NÃO - ";
    cin >> escolha2;

    if(escolha2 == true) goto finish;
    else goto init;

    finish:
    menu();

}

void cadastraNumeros(const int *numeros) {
    for (int i = 0; i < 10; ++i) {
        cout << "Digite o " << i+1 << "º valor: ";
        scanf("%d", &numeros[i]); //Para const o comando "cin" não funciona
    }
}

void exibirNumerosPares(int vetor[]) {
    for (int i = 0; i < 10; ++i) {
        if (vetor[i]%2 == 0) cout << "Vetor na posição " << i << ": " << vetor[i] << endl;
    }
}

void exibirNumerosImpares(int vetor[]) {
    for (int i = 0; i < 10; ++i) {
        if (vetor[i]%2 == 1) cout << "Vetor na posição " << i << ": " << vetor[i] << endl;
    }
}

void exibirNumeros(int vetor[]) {
    for (int i = 0; i < 10; ++i) {
        cout << "Vetor na posição " << i << ": " << vetor[i] << endl;
    }
}