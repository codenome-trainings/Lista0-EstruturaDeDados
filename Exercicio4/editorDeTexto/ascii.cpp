#include <iostream>
#include <stdio_ext.h>
#include "getch.h"
#include "ascii.h"

using namespace std;

void programa() {

    char digito;

    __fpurge(stdin);
    cout << "Digite qualquer tecla ou pressione ESC para sair: ";
    digito = getch();

    if (converteAscii(digito) == 27) {
        cout << "Você pressiou ESC para sair do programa." << endl;
        return;
    }
    cout << "Caracter: " << digito << endl;
    cout << "ASCII   :" << converteAscii(digito) << endl;

    programa();

}

int converteAscii(char digito) {
    return (int) digito;
}

