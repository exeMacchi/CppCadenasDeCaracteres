#include <iostream>
#include <locale>

void pedirNumeros(char numeroUno[], char numeroDos[], const int tamMax);
int  convertirANumero(char numero[]);
int  convertirDigito(char numero);
void mostrarSuma(int n1, int n2);

int main()
{
	setlocale(LC_ALL, "es_ES");

	constexpr int tamMax{ 10 };
	char numeroUno[tamMax]{}, numeroDos[tamMax]{};
	int numeroUnoEntero{}, numeroDosEntero{};

	pedirNumeros(numeroUno, numeroDos, tamMax);

	numeroUnoEntero = convertirANumero(numeroUno);
	numeroDosEntero = convertirANumero(numeroDos);

	mostrarSuma(numeroUnoEntero, numeroDosEntero);

	return 0;
}

void pedirNumeros(char numeroUno[], char numeroDos[], const int tamMax)
{
	std::cout << "Escriba el primer número: ";
	std::cin.getline(numeroUno, tamMax, '\n');
	
	std::cout << "Escriba el segundo número: ";
	std::cin.getline(numeroDos, tamMax, '\n');
}

int convertirANumero(char numero[])
{
	int signo{ (numero[0] == '-') ? -1 : 1 };
	int i{ (signo == -1) ? 1 : 0 };
	int numeroConvertido{ 0 };

	while (numero[i] != '\0')
	{
		numeroConvertido += convertirDigito(numero[i]);
		if (numero[i + 1] != '\0')
		{
			numeroConvertido *= 10;
		}
		i++;
	}

	return numeroConvertido * signo;
}

int convertirDigito(char numero)
{
	switch (numero)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

void mostrarSuma(int n1, int n2)
{
	std::cout << "La suma es: " << n1 + n2 << "\n";
}