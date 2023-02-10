// 3. Pedir al usuario que digite 2 cadenas de caracteres e indicar si ambas cadenas son iguales; en caso de no serlo,
//    indicar cual es mayor alfabeticamente.

#include <iostream>
#include <locale.h>


using std::cout;
using std::cin;

int charLongitud(char[]);
bool charSimilar(char[], char[], int);
bool charMayor(char[], char[], int);

int main()
{
    setlocale(LC_ALL, "es_ES");

    char palabra1[50], palabra2[50];
    int longitudPalabra1{ 0 }, longitudPalabra2{ 0 };
    bool similitud{ false }, mayor{};

    cout << "1. Escriba una palabra: "; cin.getline(palabra1, 50, '\n');
    cout << "2. Escriba una palabra: "; cin.getline(palabra2, 50, '\n');

    longitudPalabra1 = charLongitud(palabra1);
    longitudPalabra2 = charLongitud(palabra2);


    if (longitudPalabra1 == longitudPalabra2)
    {
        similitud = charSimilar(palabra1, palabra2, longitudPalabra1);

        if (!similitud)
        {
            mayor = charMayor(palabra1, palabra2, longitudPalabra1);
        }
    }
    else
    {
        similitud = false;
        mayor = charMayor(palabra1, palabra2, longitudPalabra1);
    }


    if (similitud) 
    {
        cout << "\nAmbas palabras son iguales." << "\n";
    }
    else 
    {
        if (mayor) 
        {
            cout << "\nLa primera palabra es mayor alfabéticamente que la segunda." << "\n";
        }
        else 
        {
            cout << "\nLa segunda palabra es mayor alfabéticamente que la primera." << "\n";
        }
    }

    return 0;
}


// Funciones

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

bool charSimilar(char palabra1[], char palabra2[], int iLongitud)
{
    bool similitud{ false };

    for (int i = 0; i < iLongitud; i++) 
    {
        if (palabra1[i] == palabra2[i]) 
        {
            similitud = true;
        }
        else 
        {
            similitud = false;
            return similitud;
        }
    }

    return similitud;
}

bool charMayor(char palabra1[], char palabra2[], int iLongitud) {
    bool banMayor{ false };

    for (int i = 0; i < iLongitud; i++)
    {
        if (palabra1[i] > palabra2[i])
        {
            return true;
        }
        else if (palabra2[i] > palabra1[i])
        {
            return false;
        }
    }
}
