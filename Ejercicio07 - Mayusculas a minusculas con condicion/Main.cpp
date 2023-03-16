/*
    7. Pedir el nombre del usuario en mayúsculas, si su nombre empieza con la 
       letra A, convertir su nombre a minusculas, caso contrario no convertirlo.
*/

#include <iostream>
#include <locale>

void pedirNombre(char nombre[], const int tamMax);
bool verificarNombre(char nombre[]);
void verificarLetraA(char nombre[]);
char charMinusculas(char letra);
void mostrarResultado(char nombre[]);

int main()
{
    setlocale(LC_ALL, "es_ES");

    constexpr int tamMax{ 30 };
    char nombre[tamMax]{};

    pedirNombre(nombre, tamMax);
    verificarLetraA(nombre);
    mostrarResultado(nombre);

    return 0;
}


void pedirNombre(char nombre[], const int tamMax)
{
    bool nombreCorrecto{ false };
    
    while (!nombreCorrecto)
    {
		std::cout << "Por favor, ingrese su nombre en mayúsculas: "; 
		std::cin.getline(nombre, tamMax, '\n');
		std::cout << "\n";

        nombreCorrecto = verificarNombre(nombre);
    }
}

bool verificarNombre(char nombre[])
{
    for (int i{ 0 }; nombre[i] != '\0'; i++)
    {
        if (nombre[i] < 65 || nombre[i] > 90)
        {
            std::cout << "Error: por favor, escriba todo su nombre en "
                      << "mayúsculas." << "\n";
            return false;
        }
    }
    return true;
}

void verificarLetraA(char nombre[])
{
    if (nombre[0] == 'A') 
    {
        for (int i{ 0 }; nombre[i] != '\0'; i++)
        {
            nombre[i] = charMinusculas(nombre[i]);
        }
    }
}

char charMinusculas(char letra) 
{
    if (letra >= 65 && letra <= 90)
    {
        return static_cast<char>( static_cast<int>(letra + 32) );
    }
    else
    {
        return letra;
    }
}

void mostrarResultado(char nombre[])
{
    std::cout << nombre << "\n";
}