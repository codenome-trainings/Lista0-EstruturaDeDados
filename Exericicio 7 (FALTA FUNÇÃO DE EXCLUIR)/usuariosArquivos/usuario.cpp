#include <iostream>
#include <stdio_ext.h>
#include <cstring>
#include "usuario.h"

using namespace std;
Usuario *_usuario;

void sair() {
    free(_usuario);
}

void numeroDeUsuariosCadastrados() {
    cout << "Número de usuários cadastrados: " << contadorDeLinhasDeUmArquivo() << endl;
}

int contadorDeLinhasDeUmArquivo() {

    FILE *arquivo;
    int numeroDeLinhas = 0;

    arquivo = fopen("usuarios", "r");

    if(arquivo == NULL) {
        cout << "Erro na abertura do arquivo" << endl;
        return 0;
    }

    char linha[500];
    while(fgets(linha, 500, arquivo)) {
        ++numeroDeLinhas;
    }

    return numeroDeLinhas;
}

void listarUsuarios() {

    char *saida = (char *) malloc(256 * sizeof(char));
    char espaco = ' ';

    FILE *arquivo = fopen("usuarios", "r");

    if(arquivo == NULL) {
        cout << "Erro na Abertura do arquivo" << endl;
        return;
    }

    cout << "======================================================================================================================================" << endl;
    printf("| Nome %-25c | RG %-17c | CPF %-17c | Endereço %-41c |\n", espaco, espaco, espaco, espaco);
    cout << "======================================================================================================================================" << endl;


    while(fgets(saida, sizeof(saida), arquivo) != NULL) {
        printf("%s", saida);
    }

    cout << endl << endl;

    free(saida);
    fclose(arquivo);

}

void cadastrarUsuario() {

    Usuario *usuario;

    int contador = contadorDeLinhasDeUmArquivo();
    cout << "Contador: " << contador << endl;

    if(contador > 0) usuario = (Usuario *) realloc(usuario, sizeof(Usuario));
    else usuario = (Usuario *) malloc(sizeof(Usuario));

    if(!usuario) {
        cout << "Exaustão de memória!" << endl;
        exit(1);
    }

    __fpurge(stdin);
    cin.clear();
    cout << "Digite seu nome: ";
    cin.getline(usuario->nome, 100);

    __fpurge(stdin);
    cin.clear();
    cout << "Digite seu RG: ";
    cin.getline(usuario->rg, 9);

    __fpurge(stdin);
    cin.clear();
    cout << "Digite seu CPF: ";
    cin.getline(usuario->cpf, 11);

    __fpurge(stdin);
    cin.clear();
    cout << "Digite seu Endereço: ";
    cin.getline(usuario->endereco, 100);

    insereUsuario(usuario);
    free(usuario);
}

void insereUsuario(Usuario *pUsuario) {

    FILE * arquivo;

    if((arquivo = fopen("usuarios", "a+")) == NULL) {
        cout << "Erro ao criar o arquivo";
    }

    fprintf(arquivo, "| %-30s | %-20s | %-21s | %-50s |\n",
            pUsuario->nome,
            pUsuario->rg,
            pUsuario->cpf,
            pUsuario->endereco
    );

    fclose(arquivo);

}

//void removerUltimoNumero() {
//
//    FILE *arquivo, *copiaDoArquivo;
//
//    arquivo = fopen("usuarios", "r");
//    copiaDoArquivo = fopen("copiaUsuarios", "wr");
//
//    for(register int i = )
//
//}
