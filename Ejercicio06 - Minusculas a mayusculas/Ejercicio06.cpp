// 6. Convertir dos cadenas de minúsculas a mayúsculas. Luego, compararlas y decir si ambas son iguales.

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

void pedirPalabras(char[], char[]);
void verificarMayus(char[]);
char charMayus(char);
int charLongitud(char[]);
void mostrarResultados(char[], char[]);

int main()
{
    setlocale(LC_ALL, "es_ES");

    char Palabra1[50], Palabra2[50];
    int i{ 0 };

    pedirPalabras(Palabra1, Palabra2);

    verificarMayus(Palabra1);
    verificarMayus(Palabra2);

    mostrarResultados(Palabra1, Palabra2);

    return 0;
}

void pedirPalabras(char palabra1[], char palabra2[])
{
    cout << "Ingrese la primera palabra: "; cin.getline(palabra1, 50, '\n');
    cout << "Ingrese la segunda palabra: "; cin.getline(palabra2, 50, '\n');
    cout << "\n";
}

void verificarMayus(char palabra[])
{
    int i{ 0 };

    while (palabra[i] != '\0')
    {
        palabra[i] = charMayus(palabra[i]);
        i++;
    }
}

char charMayus(char letra) 
{
    if (letra >= 97 && letra <= 122)
    {
        return (char)( (int)letra - 32);
    }
    else
    {
        return letra;
    }
}

int charLongitud(char palabra[]) {
    int longitud{ 0 }, i{ 0 };

    while (palabra[i] != '\0') 
    {
        longitud++;
        i++;
    }

    return longitud;
}

void mostrarResultados(char palabra1[], char palabra2[])
{
    cout << palabra1 << "\n";
    cout << palabra2 << "\n";
    cout << "\n";

    if (charLongitud(palabra1) == charLongitud(palabra2))
    {
        int longitud = charLongitud(palabra1);

        for (int i = 0; i < longitud; i++) 
        {
            if (palabra1[i] != palabra2[i]) 
            {
                cout << "Ambas palabras son diferentes." << "\n";
                return;
            }
        }

    }
    else
    {
        cout << "Ambas palabras son diferentes." << "\n";
        return;
    }

    cout << "Ambas palabras son iguales." << "\n";
}
