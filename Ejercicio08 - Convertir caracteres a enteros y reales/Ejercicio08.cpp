// 8. Pedir al usuario 2 cadenas de caracteres de n�meros, uno entero y otro real, convertirlos a sus respectivos 
//    valores y, por �ltimo, sumarlos.

#include <iostream>
#include <locale.h>
#include <stdlib.h>

using std::cout;
using std::cin;

int main()
{
    setlocale(LC_ALL, "es_ES");

    char enteros[20], reales[20];
    int numEnteros{};
    float numReales{}, Resultado{ 0 };

    cout << "Ingrese un n�mero entero: "; cin.getline(enteros, 20, '\n');
    cout << "Ingrese un n�mero real (con decimales): "; cin.getline(reales, 30, '\n');

    numEnteros = atoi(enteros);
    numReales = atof(reales);
    Resultado = numEnteros + numReales;

    cout << "\nEl resultado es: " << Resultado << "\n";

    return 0;
}