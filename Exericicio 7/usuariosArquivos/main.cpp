#include <iostream>
#include <stdio_ext.h>
#include "usuario.h"

using namespace std;

int main() {
    menu();
    return 0;
}

void menu() {

    char escolha = ' ';

    cout << "1. Cadastrar usuário" << endl;
    cout << "2. Exibir usuario(s) cadastrado(s)" << endl;
    cout << "3. Exibir quantidade de usuario(s) cadastrado(s)" << endl;
    cout << "4. Remover o ultimo usuário cadastrado" << endl;
    cout << "5. Sair" << endl;
    cout << "Digite uma opção válida: ";
    cin.clear();
    __fpurge(stdin);
    cin >> escolha;

    switch (escolha) {
        case '5':
            sair();
            return;
        case '1':
            cadastrarUsuario();
            break;
        case '2':
            listarUsuarios();
            break;
        case '3':
            numeroDeUsuariosCadastrados();
            break;
        case '4':
            removerUltimoUsuario();
            break;
        default:
            cout << "Opção inválida! Tente novamente..." << endl;
    }

    __fpurge(stdin);
    cout << "Pressione ENTER para prosseguir..." << endl;
    getchar();
    menu();
}