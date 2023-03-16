/*
    3. Pedir al usuario que digite 2 cadenas de caracteres e indicar si ambas 
       cadenas son iguales; en caso de no serlo, indicar cual es mayor 
       alfabeticamente.
*/

#include <iostream>
#include <locale>

void rellenarCadenas(char palabraUno[], char palabraDos[], const int tamMax);
int  charLongitud(char palabra[]);
void verificarCadenas(char palabraUno[], char palabraDos[],
                      int longitudPalabraUno, int longitudPalabraDos,
                      bool& similitud, bool& mayor);
bool charSimilar(char palabra1[], char palabra2[], int longitud);
bool charMayor(char palabra1[], char palabra2[], int longitud);
void mostrarResultados(bool similitud, bool mayor);

int main()
{
    setlocale(LC_ALL, "es_ES");

    constexpr int tamMax{ 50 };
    char palabraUno[tamMax]{}, palabraDos[tamMax]{};
    int longitudPalabraUno{ 0 }, longitudPalabraDos{ 0 };
    bool similitud{ false }, mayor{};

    rellenarCadenas(palabraUno, palabraDos, tamMax);
    longitudPalabraUno = charLongitud(palabraUno);
    longitudPalabraDos = charLongitud(palabraDos);
    verificarCadenas(palabraUno, palabraDos, longitudPalabraUno,
                     longitudPalabraDos, similitud, mayor);

    mostrarResultados(similitud, mayor);

    return 0;
}

void rellenarCadenas(char palabraUno[], char palabraDos[], const int tamMax)
{
    for (int i{ 1 }; i <= 2; i++)
    {
        std::cout << i << ". Escriba una palabra: ";
        if (i == 1)
        {
            std::cin.getline(palabraUno, tamMax, '\n');
        }
        else
        {
            std::cin.getline(palabraDos, tamMax, '\n');
        }
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

void verificarCadenas(char palabraUno[], char palabraDos[],
                      int longitudPalabraUno, int longitudPalabraDos, 
                      bool& similitud, bool& mayor)
{
    if (longitudPalabraUno == longitudPalabraDos)
    {
        similitud = charSimilar(palabraUno, palabraDos, longitudPalabraUno);

        if (!similitud)
        {
            mayor = charMayor(palabraUno, palabraDos, longitudPalabraUno);
        }
    }
    else
    {
        similitud = false;
        mayor = charMayor(palabraUno, palabraDos, longitudPalabraUno);
    }

}

bool charSimilar(char palabra1[], char palabra2[], int longitud)
{
    for (int i{ 0 }; i < longitud; i++)
    {
        if (palabra1[i] != palabra2[i]) 
        {
            return false;
        }
    }
    return true;
}

bool charMayor(char palabra1[], char palabra2[], int longitud) 
{
    for (int i{ 0 }; i < longitud; i++)
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

void mostrarResultados(bool similitud, bool mayor)
{
    if (similitud) 
    {
        std::cout << "Ambas palabras son iguales." << "\n";
    }
    else 
    {
        if (mayor) 
        {
            std::cout << "La primera palabra es mayor alfabéticamente que "
                      << "la segunda." << "\n";
        }
        else 
        {
            std::cout << "La segunda palabra es mayor alfabéticamente que "
                      << "la primera." << "\n";
        }
    }
}