// 5. Hacer un programa que determine si una palabra es palíndroma.

#include <iostream>
#include <locale>

void pedirPalabra(char palabra[], const int tamMax);
int  charLongitud(char palabra[]);
void copiarPalabra(char palabraOriginal[], char palabraCopia[],
                   const int longitud);
bool esPalindromo(char palabraOriginal[], char palabraCopia[]);
void mostrarResultados(char palabraOriginal[], char palabraCopia[],
                       bool palindromo);

int main()
{
    setlocale(LC_ALL, "es_ES");

    constexpr int tamMax{ 50 };
    char palabraOriginal[tamMax]{};
    char palabraCopia[tamMax]{};
    bool palindromo{ true };
    int longitud{};

    pedirPalabra(palabraOriginal, tamMax);
    longitud = charLongitud(palabraOriginal);
    copiarPalabra(palabraOriginal, palabraCopia, longitud);
    palindromo = esPalindromo(palabraOriginal, palabraCopia);
    mostrarResultados(palabraOriginal, palabraCopia, palindromo);

    return 0;
}

void pedirPalabra(char palabra[], const int tamMax)
{
    std::cout << "Ingrese una palabra: "; 
    std::cin.getline(palabra, tamMax, '\n');
    std::cout << "\n";
}

void copiarPalabra(char palabraOriginal[], char palabraCopia[], 
                   const int longitud)
{
    int j{ longitud - 1 };
    char aux{};

    for (int i{ 0 }; i < longitud; i++)
    {
        palabraCopia[i] = palabraOriginal[j];
        j--;
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

bool esPalindromo(char palabraOriginal[], char palabraCopia[]) 
{
    for (int i{ 0 }; palabraOriginal[i] != '\0'; i++)
    {
        if (palabraOriginal[i] != palabraCopia[i])
        {
            return false;
        }
    }
    return true;
}

void mostrarResultados(char palabraOriginal[], char palabraCopia[], 
                       bool palindromo)
{
    std::cout << "Palabra original: " << palabraOriginal << "\n";
    std::cout << "Palabra al revés: " << palabraCopia << "\n";

    if (palindromo) 
    {
        std::cout << "\nThe palabra es palíndroma." << "\n";
    }
    else 
    {
        std::cout << "\nLa palabra no es palíndroma." << "\n";
    }
}