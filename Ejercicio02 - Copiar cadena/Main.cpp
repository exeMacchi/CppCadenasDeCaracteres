/*
    2. Pedir al usuario una cadena de caracteres, almacenarla en un arreglo y 
       copiar todo su contenido hacia otro arreglo de caracteres.
*/

#include <iostream>
#include <locale>

void pedirPalabras(char palabraOriginal[], const int tamMax);
int  charLongitud(char palabraOriginal[]);
void charCopia(int longitud, char palabraOriginal[], char palabraCopia[]);
void mostrarResultados(char palabraOriginal[], char palabraCopia[]);

int main()
{
    setlocale(LC_ALL, "es_ES");

    constexpr int tamMax{ 50 };
    char palabraOriginal[tamMax]{}, palabraCopia[tamMax]{};
    int longitud{};

    pedirPalabras(palabraOriginal, tamMax);
    longitud = charLongitud(palabraOriginal);
    charCopia(longitud, palabraOriginal, palabraCopia);
    mostrarResultados(palabraOriginal, palabraCopia);

    return 0;
}

void pedirPalabras(char palabraOriginal[], const int tamMax)
{
    std::cout << "Escriba algo: "; 
    std::cin.getline(palabraOriginal, tamMax, '\n');
}

int charLongitud(char palabraOriginal[]) 
{
    int longitud{ 0 };

    for (int i{ 0 }; palabraOriginal[i] != '\0'; i++)
    {
        longitud++;
    }

    return longitud;
}

void charCopia(int longitud, char palabraOriginal[], char palabraCopia[]) 
{
    for (int i{ 0 }; i <= longitud; i++)
    {
        palabraCopia[i] = palabraOriginal[i];
    }
}

void mostrarResultados(char palabraOriginal[], char palabraCopia[])
{
    std::cout << "Texto original: " << palabraOriginal << "\n";
    std::cout << "Texto copiado: " << palabraCopia << "\n";
}