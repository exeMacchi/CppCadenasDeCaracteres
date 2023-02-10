// 1. Hacer un programa que pida al usuario que digite una cadena de caracteres, luego verificar la longitud de la
//    cadena, y, si esta supera a 10 caracteres, mostrarla en pantalla, caso contrario no mostrarla.

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

int charLongitud(char palabra[50]);

int main()
{
    setlocale(LC_ALL, "es_ES");
    char palabra[50];
    int longitud{};

    cout << "Escriba una palabra: "; cin.getline(palabra, 50, '\n');
    longitud = charLongitud(palabra);
    
    if (longitud > 10)
    {
        cout << "La palabra " << palabra << " supera los 10 caracteres." << "\n";
    }
    else
    {
        cout << "La palabra introducida no supera los 10 caracteres." << "\n";
    }

    return 0;
}

int charLongitud(char palabra[50]) {
    int longitud{ 0 }, i{ 0 };

    while (palabra[i] != '\0') {
        longitud++;
        i++;
    }

    return longitud;
}
