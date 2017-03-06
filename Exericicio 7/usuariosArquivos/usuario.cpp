#include <iostream>
#include <stdio_ext.h>
#include <cstring>
#include "usuario.h"

using namespace std;
Usuario *_usuario;

void insereUsuarios(Usuario *pUsuario, int i);

void sair() {
    free(_usuario);
}

void numeroDeUsuariosCadastrados() {
    cout << "Número de usuários cadastrados: " << contadorDeLinhasDeUmArquivo() << endl;
}

int numeroDeUsuarios() {

    FILE *arquivo;
    int numeroDeLinhas = 0;

    arquivo = fopen("usuarios.csv", "r");

    if(arquivo == NULL) {
        return 0;
    }

    char linha[500];
    while(fgets(linha, 500, arquivo)) {
        ++numeroDeLinhas;
    }

    return numeroDeLinhas;
}

void listarUsuarios() {

    FILE *arquivo = fopen("usuarios.csv", "r");

    Usuario *usuario = (Usuario *) malloc(sizeof(Usuario));

    if(arquivo == NULL) {
        cout << "Erro na Abertura do arquivo" << endl;
        return;
    }

    if(numeroDeUsuarios() == 0) {
        cout << "Não Há usuários cadastrados" << endl;
        return;
    }

    char espaco = ' ';
    cout << "============================================================================================================" << endl;
    printf("| Nome %-19c | RG %-13c | CPF %-12c | Endereço %-30c |\n", espaco, espaco, espaco, espaco);
    cout << "============================================================================================================" << endl;

    char linha[500];
    while(fgets(linha, 500, arquivo)) {

        linha[strlen(linha) - 1] = '\0';

        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];",
               usuario->nome,
               usuario->rg,
               usuario->cpf,
               usuario->endereco
        );

        printf("|%-25s |%-17s |%-17s |%-41s|\n",
               usuario->nome,
               usuario->rg,
               usuario->cpf,
               usuario->endereco
        );
    }

    cout << endl << endl;
    fclose(arquivo);

}

void cadastrarUsuario() {

    Usuario *usuario;
    int contador = numeroDeUsuarios();

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

    if((arquivo = fopen("usuarios.csv", "a+")) == NULL) {
        cout << "Erro ao criar o arquivo";
    }

    fprintf(arquivo, "%s;%s;%s;%s\n",
            pUsuario->nome,
            pUsuario->rg,
            pUsuario->cpf,
            pUsuario->endereco
    );

    fclose(arquivo);

}

void removerUltimoUsuario() {

    FILE *arquivo = fopen("usuarios.csv", "r");

    if(arquivo == NULL) {
        cout << "Erro ao criar o arquivo" << endl;
    }

    Usuario *usuarios = (Usuario *) malloc(numeroDeUsuarios() * sizeof(Usuario));

    char linha[500];
    int i = 0;
    for(; fgets(linha, 500, arquivo); i++) {
        linha[strlen(linha) - 1] = '\0';
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];",
               usuarios[i].nome,
               usuarios[i].rg,
               usuarios[i].cpf,
               usuarios[i].endereco
        );
    }
    cout << "N: " << i << endl;
    fclose(arquivo);
    insereUsuarios(usuarios, i);
    free(usuarios);

    cout << "Usuário removido com sucesso!" << endl;

}

void insereUsuarios(Usuario *pUsuario, int numUsuarios) {

    FILE * arquivo;

    if((arquivo = fopen("usuarios.csv", "w")) == NULL) {
        cout << "Erro ao criar o arquivo";
    }

    cout << "N: " << numUsuarios << endl;

    for(int i = 0; i < (numUsuarios-1); i++) {
        fprintf(arquivo, "%s;%s;%s;%s\n",
                pUsuario[i].nome,
                pUsuario[i].rg,
                pUsuario[i].cpf,
                pUsuario[i].endereco
        );
    }

    fclose(arquivo);

}
