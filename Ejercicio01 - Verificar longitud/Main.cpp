/*
    1. Hacer un programa que pida al usuario que digite una cadena de caracteres, 
       luego verificar la longitud de la cadena, y, si esta supera a 10 caracteres,
       mostrarla en pantalla, caso contrario no mostrarla.
*/

#include <iostream>
#include <locale>

void pedirPalabras(char palabra[], const int tamMax);
int charLongitud(char palabra[]);
void mostrarResultado(char palabra[], int longitud);

int main()
{
    setlocale(LC_ALL, "es_ES");

    constexpr int tamMax{ 50 };
    char palabra[tamMax]{};
    int longitud{};

    pedirPalabras(palabra, tamMax);
    longitud = charLongitud(palabra);
    mostrarResultado(palabra, longitud);

    return 0;
}

void pedirPalabras(char palabra[], const int tamMax)
{
    std::cout << "Escriba una palabra: "; 
    std::cin.getline(palabra, tamMax, '\n');
}

int charLongitud(char palabra[]) 
{
    int longitud{ 0 };

    for (int i{ 0 }; palabra[i] != '\0'; i++)
    {
        longitud++;
    }

    return longitud;
}

void mostrarResultado(char palabra[], int longitud)
{
    if (longitud > 10)
    {
        std::cout << "La palabra \"" << palabra << "\" supera los 10 caracteres."
                  << "\n";
    }
    else
    {
        std::cout << "La palabra introducida no supera los 10 caracteres.\n";
    }
}