// 7. Pedir el nombre del usuario en mayúsculas, si su nombre empieza con la letra A, convertir su nombre a 
//    minusculas, caso contrario no convertirlo.

#include <iostream>
#include <locale>


using std::cout;
using std::cin;

bool pedirNombre(char[]);
void verificarNombre(char[], bool);
char charMinusculas(char);
void mostrarResultado(char[]);

int main()
{
    setlocale(LC_ALL, "es_ES");

    char nombre[20];
    bool nombreIncorrecto = false;

    nombreIncorrecto = pedirNombre(nombre);
    verificarNombre(nombre, nombreIncorrecto);
    mostrarResultado(nombre);

    return 0;
}


bool pedirNombre(char nombre[])
{
    int i{ 0 };

    cout << "Por favor, ingrese su nombre en mayúsculas: "; cin.getline(nombre, 20, '\n');
    cout << "\n";

    while (nombre[i] != '\0')
    {
        if (nombre[i] < 65 || nombre[i] > 90)
        {
            return true;
        }
        i++;
    }
    
    return false;
}

void verificarNombre(char nombre[], bool nombreIncorrecto)
{
    int i{ 0 };

    while(nombreIncorrecto)
    {
        nombreIncorrecto = pedirNombre(nombre);
    }

    if (nombre[0] == 'A') 
    {
        while (nombre[i] != '\0') 
        {
            nombre[i] = charMinusculas(nombre[i]);
            i++;
        }
    }
}

char charMinusculas(char letra) 
{
    if (letra >= 65 && letra <= 90)
    {
        return (char)((int)letra + 32);
    }
    else
    {
        return letra;
    }
}

void mostrarResultado(char nombre[])
{
    cout << nombre << "\n";
}