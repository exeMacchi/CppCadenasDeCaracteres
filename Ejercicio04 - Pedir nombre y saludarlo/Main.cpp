/*
    4. Crear una cadena que tenga la siguiente frase: "Hola que tal", luego 
       crear otra cadena para preguntarle al usuario su nombre, por último 
       añadir el nombre al final de la primera cadena y mostrar el mensaje 
       completo: "Hola que tal (nombreDelUsuario)".
*/

#include <iostream>
#include <locale>

void pedirNombreUsuario(char nombreUsuario[], int tamMaxNombre);
int  charLongitud(char palabra[]);
void charConcatenar(char mensaje[], char saludo[], char nombreUsuario[],
                    int longSaludo, int longNombre);
void mostrarMensaje(char mensaje[]);

int main()
{
    setlocale(LC_ALL, "es_ES");

    char saludo[] = "Hola! Qué tal, ";
    constexpr int tamMaxNombre{ 30 }, tamMaxMensaje{ 50 };
    char nombreUsuario[tamMaxNombre]{};
    char mensaje[tamMaxMensaje]{};
    int longitudSaludo{}, longitudNombre{};

    pedirNombreUsuario(nombreUsuario, tamMaxNombre);
    longitudSaludo = charLongitud(saludo);
    longitudNombre = charLongitud(nombreUsuario);
    charConcatenar(mensaje, saludo, nombreUsuario, longitudSaludo, 
                   longitudNombre);
    mostrarMensaje(mensaje);

    return 0;

}

void pedirNombreUsuario(char nombreUsuario[], int tamMaxNombre)
{
    std::cout << "Ingrese su nombre: "; 
    std::cin.getline(nombreUsuario, tamMaxNombre, '\n');
    std::cout << "\n";
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

void charConcatenar(char mensaje[], char saludo[], char nombreUsuario[], 
                    int longSaludo, int longNombre)
{
    int x{ 0 };

    for (int i{ 0 }; i < longSaludo; i++)
    {
        mensaje[x] = saludo[i];
        x++;
    }

    for (int i{ 0 }; i < longNombre; i++)
    {
        mensaje[x] = nombreUsuario[i];
        x++;
    }
}

void mostrarMensaje(char mensaje[])
{
    std::cout << mensaje << "\n";
}