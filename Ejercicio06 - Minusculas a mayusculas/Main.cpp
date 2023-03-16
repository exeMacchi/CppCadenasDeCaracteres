/*
    6. Convertir dos cadenas de minúsculas a mayúsculas. Luego, compararlas y 
       decir si ambas son iguales.
*/

#include <iostream>
#include <locale>

void pedirPalabras(char palabra1[], char palabra2[], const int tamMax);
void verificarMayus(char palabra[]);
char charMayus(char letra);
int  charLongitud(char palabra[]);
void mostrarResultados(char palabraUno[], char palabraDos[]);

int main()
{
    setlocale(LC_ALL, "es_ES");

    constexpr int tamMax{ 50 };
    char Palabra1[tamMax]{}, Palabra2[tamMax]{};

    pedirPalabras(Palabra1, Palabra2, tamMax);
    verificarMayus(Palabra1);
    verificarMayus(Palabra2);
    mostrarResultados(Palabra1, Palabra2);

    return 0;
}

void pedirPalabras(char palabra1[], char palabra2[], const int tamMax)
{
    std::cout << "Ingrese la primera palabra: "; 
    std::cin.getline(palabra1, tamMax, '\n');

    std::cout << "Ingrese la segunda palabra: "; 
    std::cin.getline(palabra2, tamMax, '\n');
    std::cout << "\n";
}

void verificarMayus(char palabra[])
{
    for (int i{ 0 }; palabra[i] != '\0'; i++)
    {
        palabra[i] = charMayus(palabra[i]);
    }
}

char charMayus(char letra) 
{
    if (letra >= 97 && letra <= 122)
    {
        return static_cast<char>( static_cast<int>(letra - 32) );
    }
    else
    {
        return letra;
    }
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

void mostrarResultados(char palabraUno[], char palabraDos[])
{
    std::cout << palabraUno << "\n";
    std::cout << palabraDos << "\n";
    std::cout << "\n";
    
    int longitud = charLongitud(palabraUno);
    
    if (longitud == charLongitud(palabraDos))
    {
        for (int i{ 0 }; i < longitud; i++)
        {
            if (palabraUno[i] != palabraDos[i]) 
            {
                std::cout << "Ambas palabras son diferentes." << "\n";
                return;
            }
        }
        std::cout << "Ambas palabras son iguales." << "\n";
    }
    else
    {
        std::cout << "Ambas palabras son diferentes." << "\n";
        return;
    }
}