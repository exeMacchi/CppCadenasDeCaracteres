// 4. Crear una cadena que tenga la siguiente frase: "Hola que tal", luego crear otra cadena para preguntarle al usuario
//    su nombre, por último añadir el nombre al final de la primera cadena y mostrar el mensaje completo:
//    "Hola que tal (nombreDelUsuario)".

#include <iostream>
#include <string.h>
#include <locale.h>

using std::cout;
using std::cin;

int charLongitud(char[]);
void charConcatenar(char[], char[], char[], int, int);
void mostrarMensaje(char[]);

int main()
{
    setlocale(LC_ALL, "es_ES");

    char saludo[] = "Hola! Qué tal, ";
    char nombre[30];
    char mensaje[50];
    int longitudSaludo{}, longitudNombre{};

    cout << "Ingrese su nombre: "; cin.getline(nombre, 30, '\n');
    cout << "\n";

    longitudSaludo = charLongitud(saludo);
    longitudNombre = charLongitud(nombre);

    charConcatenar(mensaje, saludo, nombre, longitudSaludo, longitudNombre);

    mostrarMensaje(mensaje);
    
    //strcpy(mensaje, saludo);
    //strcat(mensaje, nombre);
    //cout << mensaje << endl;

    return 0;

}

int charLongitud(char palabra[])
{
    int longitud{ 0 }, i{ 0 };

    while (palabra[i] != '\0')
    {
        i++;
        longitud++;
    }

    return longitud;
}

void charConcatenar(char mensaje[], char saludo[], char nombre[], int longSaludo, int longNombre)
{
    int x{ 0 };

    for (int i = 0; i < longSaludo; i++)
    {
        mensaje[x] = saludo[i];
        x++;
    }

    for (int i = 0; i < longNombre; i++)
    {
        mensaje[x] = nombre[i];
        x++;
    }

    mensaje[x] = '\0';
}

void mostrarMensaje(char mensaje[])
{
    int i{};

    while (mensaje[i] != '\0')
    {
        cout << mensaje[i];
        i++;
    }

    cout << "\n";
}
