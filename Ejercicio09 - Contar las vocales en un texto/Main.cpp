/*
    9. Realice un programa que lea una cadena de caracteres de la entrada 
       estándar y muestre en la salida estándar cuántas ocurrencias de cada 
       vocal existen en la cadena.
*/

#include <iostream>
#include <locale>

void pedirTexto(char oracion[], const int tamMax);
void contadorDeVocales(char palabra[], int& vocalA, int& vocalE, int& vocalI,
                       int& vocalO, int& vocalU);
void resultadosFinales(int vocalA, int vocalE, int vocalI, int vocalO, 
                       int vocalU);

int main()
{
    setlocale(LC_ALL, "es_ES");

    constexpr int tamMax{ 100 };
    char oracion[tamMax]{};
    int vocalA{ 0 }, vocalE{ 0 }, vocalI{ 0 }, vocalO{ 0 }, vocalU{ 0 };

    pedirTexto(oracion, tamMax);
    contadorDeVocales(oracion, vocalA, vocalE, vocalI, vocalO, vocalU);
    resultadosFinales(vocalA, vocalE, vocalI, vocalO, vocalU);

    return 0;
}

void pedirTexto(char oracion[], const int tamMax)
{
    std::cout << "Ingrese un pequeño texto: "; 
    std::cin.getline(oracion, tamMax, '\n');
    std::cout << "\n";
}

void contadorDeVocales(char palabra[], int& vocalA, int& vocalE, int& vocalI, 
                       int& vocalO, int& vocalU) 
{
    for (int i{ 0 }; palabra[i] != '\0'; i++)
    {
        switch (palabra[i]) 
        {
            case 'a': case 'A': vocalA++; break;
            case 'e': case 'E': vocalE++; break;
            case 'i': case 'I': vocalI++; break;
            case 'o': case 'O': vocalO++; break;
            case 'u': case 'U': vocalU++; break;
        }
    }
}

void resultadosFinales(int vocalA, int vocalE, int vocalI, int vocalO, 
                       int vocalU)
{
    std::cout << "Cantidad de veces que aparece la vocal 'a' aparece: " 
              << vocalA << "\n";

    std::cout << "Cantidad de veces que aparece la vocal 'e' aparece: " 
              << vocalE << "\n";

    std::cout << "Cantidad de veces que aparece la vocal 'i' aparece: " 
              << vocalI << "\n";

    std::cout << "Cantidad de veces que aparece la vocal 'o' aparece: " 
              << vocalO << "\n";

    std::cout << "Cantidad de veces que aparece la vocal 'u' aparece: " 
              << vocalU << "\n";
}