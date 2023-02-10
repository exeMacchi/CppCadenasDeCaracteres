// 2. Pedir al usuario una cadena de caracteres, almacenarla en un arrelgo y copiar todo su contenido hacia otro 
//    arreglo de caracteres.

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

int charLongitud(char palabraOriginal[50]);
void charCopia(int longitud, char palabraOriginal[50], char palabraCopia[50]);

int main()
{
    setlocale(LC_ALL, "es_ES");
    char palabraOriginal[50], palabraCopia[50];
    int longitud{ 0 };

    cout << "Escriba algo: "; cin.getline(palabraOriginal, 50, '\n');

    longitud = charLongitud(palabraOriginal);

    charCopia(longitud, palabraOriginal, palabraCopia);

    cout << "\nTexto original: " << palabraOriginal << "\n";
    cout << "Texto copiado: " << palabraCopia << "\n";
    return 0;
}

int charLongitud(char palabraOriginal[50]) {
    int longitud{ 0 }, i{ 0 };

    while (palabraOriginal[i] != '\0') {
        longitud++;
        i++;
    }

    return longitud;
}

void charCopia(int longitud, char palabraOriginal[50], char palabraCopia[50]) {
    for (int i = 0; i <= longitud; i++) 
    {
        palabraCopia[i] = palabraOriginal[i];
    }
}
