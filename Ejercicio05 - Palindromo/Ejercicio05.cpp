// 5. Hacer un programa que determine si una palabra es palíndroma.

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

void pedirPalabra(char[]);
int charLongitud(char palabra[]);
void copiarPalabra(char[], char[], int);
bool esPalindromo(char[], char[]);
void mostrarResultados(char[], char[], bool);

int main()
{
    setlocale(LC_ALL, "es_ES");

    char palabra[50];
    char palabraCopia[50];
    bool palindromo = true;

    pedirPalabra(palabra);

    int longitud = charLongitud(palabra);

    copiarPalabra(palabra, palabraCopia, longitud);

    palindromo = esPalindromo(palabra, palabraCopia);

    mostrarResultados(palabra, palabraCopia, palindromo);

    return 0;
}

void pedirPalabra(char palabra[])
{
    cout << "Ingrese una palabra: "; cin.getline(palabra, 50, '\n');
    cout << "\n";
}

void copiarPalabra(char palabraOriginal[], char palabraCopia[], int longitud)
{
    int j{ longitud - 1 };
    char aux;

    for (int i = 0; i < longitud; i++)
    {
        palabraCopia[i] = palabraOriginal[j];
        j--;
    }

    palabraCopia[longitud] = '\0';
}

int charLongitud(char palabra[]) 
{
    int longitud{ 0 }, i{ 0 };

    while (palabra[i] != '\0') 
    {
        longitud++;
        i++;
    }

    return longitud;
}

bool esPalindromo(char palabra[], char palabraCopia[]) 
{
    bool palindromo = true;
    int i = 0;

    while (palabra[i] != '\0' && palindromo) 
    {
        if (palabra[i] == palabraCopia[i]) 
        {
            palindromo = true;
        }
        else 
        {
            palindromo = false;
        }
        i++;
    }

    return palindromo;
}

void mostrarResultados(char palabraOriginal[], char palabraCopia[], bool palindromo)
{
    cout << palabraOriginal << "\n";
    cout << palabraCopia << "\n";

    if (palindromo) 
    {
        cout << "\nThe palabra es palíndroma." << "\n";
    }
    else 
    {
        cout << "\nLa palabra no es palíndroma." << "\n";
    }
}
