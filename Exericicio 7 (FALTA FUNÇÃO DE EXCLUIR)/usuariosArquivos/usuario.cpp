#include <iostream>
#include <stdio_ext.h>
#include <cstring>
#include "usuario.h"

using namespace std;

int quantidadeDeUsuarios = 0;
Usuario *_usuario;

void sair() {
    free(_usuario);
}

void removerUltimoNumero() {

    FILE *arquivo;

    char *linha = (char *) malloc(256 * sizeof(char));
    char *buffer = (char *) malloc(1000 * sizeof(char));
    char *ponteiro;

    memset(buffer, 0, 1000 * sizeof(char));
    ponteiro = buffer;

    arquivo = fopen("usuarios", "r");

    if(arquivo == NULL) {
        cout << "Erro na abertura do arquivo" << endl;
        return;
    }

    while(!feof(arquivo)) {

        fgets(linha, 256, arquivo);

        if(sizeof(linha) == true) {
            strcpy(ponteiro, linha);
            ponteiro += strlen(linha);
        }
    }

    fclose(arquivo);
    rescreveArquivo(arquivo, buffer);
    free(linha);
    free(buffer);
}

void rescreveArquivo(FILE *arquivo, const char *buffer) {
    arquivo = fopen("usuarios", "w");
    fprintf(arquivo, "%s", buffer);
    fclose(arquivo);
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

    while(EOF != (scanf("%*[^\n]") && scanf("%*c"))) {
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

    cout << "=========================================================================================================================================================" << endl;
    printf("| Nome %-25c | RG %-27c | CPF %-26c | Endereço %-41c |\n", espaco, espaco, espaco, espaco);
    cout << "=========================================================================================================================================================" << endl;

    for (int i = 1; fgets(saida, sizeof(saida), arquivo) != NULL; ++i) {
        printf("%s", saida);
    }

    cout << endl << endl;

    fclose(arquivo);

}

void cadastrarUsuario() {

    Usuario *usuario;

    usuario = _usuario;

    if(quantidadeDeUsuarios > 0) usuario = (Usuario *) realloc(usuario, quantidadeDeUsuarios * sizeof(Usuario));
    else usuario = (Usuario *) malloc(sizeof(Usuario));

    if(!usuario) {
        cout << "Exaustão de memória!" << endl;
        exit(1);
    }

    __fpurge(stdin);
    cin.clear();
    cout << "Digite seu nome: ";
    cin.getline(usuario[quantidadeDeUsuarios].nome, 100);

    __fpurge(stdin);
    cin.clear();
    cout << "Digite seu RG: ";
    cin.getline(usuario[quantidadeDeUsuarios].rg, 9);

    __fpurge(stdin);
    cin.clear();
    cout << "Digite seu CPF: ";
    cin.getline(usuario[quantidadeDeUsuarios].cpf, 11);

    __fpurge(stdin);
    cin.clear();
    cout << "Digite seu Endereço: ";
    cin.getline(usuario[quantidadeDeUsuarios].endereco, 100);

    _usuario = usuario;

    insereUsuario(_usuario);

    quantidadeDeUsuarios++;

}

void insereUsuario(Usuario *pUsuario) {

    FILE * arquivo;

    if((arquivo = fopen("usuarios", "a+")) == NULL) {
        cout << "Erro ao criar o arquivo";
    }

    fprintf(arquivo, "| %-30s | %-30s | %-30s | %-50s |\n",
            pUsuario->nome,
            pUsuario->rg,
            pUsuario->cpf,
            pUsuario->endereco
    );

    fclose(arquivo);

}
