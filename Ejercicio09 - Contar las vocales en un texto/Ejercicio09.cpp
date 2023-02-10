// 9. Realice un programa que lea una cadena de caracteres de la entrada estándar y muestre en la salida estándar 
//    cuántas ocurrencias de cada vocal existen en la cadena.

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

void pedirTexto(char[]);
void contadorDeVocales(char[], int&, int&, int&, int&, int&);
void resultadosFinales(int, int, int, int, int);

int main()
{
    setlocale(LC_ALL, "es_ES");

    char oracion[100];
    int vocalA{ 0 }, vocalE{ 0 }, vocalI{ 0 }, vocalO{ 0 }, vocalU{ 0 };

    pedirTexto(oracion);

    contadorDeVocales(oracion, vocalA, vocalE, vocalI, vocalO, vocalU);

    resultadosFinales(vocalA, vocalE, vocalI, vocalO, vocalU);

    return 0;
}

void pedirTexto(char oracion[])
{
    cout << "Ingrese un pequeño texto: "; cin.getline(oracion, 100, '\n');
    cout << "\n";
}

void contadorDeVocales(char Palabra[], int& vocalA, int& vocalE, int& vocalI, int& vocalO, int& vocalU) {
    int i{ 0 };

    while (Palabra[i] != '\0') 
    {
        switch (Palabra[i]) 
        {
            case 'a': case 'A': vocalA++; break;
            case 'e': case 'E': vocalE++; break;
            case 'i': case 'I': vocalI++; break;
            case 'o': case 'O': vocalO++; break;
            case 'u': case 'U': vocalU++; break;
        }

        i++;
    }
}

void resultadosFinales(int vocalA, int vocalE, int vocalI, int vocalO, int vocalU)
{
    cout << "Cantidad de veces que aparece la vocal 'a' aparece: " << vocalA << "\n";
    cout << "Cantidad de veces que aparece la vocal 'e' aparece: " << vocalE << "\n";
    cout << "Cantidad de veces que aparece la vocal 'i' aparece: " << vocalI << "\n";
    cout << "Cantidad de veces que aparece la vocal 'o' aparece: " << vocalO << "\n";
    cout << "Cantidad de veces que aparece la vocal 'u' aparece: " << vocalU << "\n";
}