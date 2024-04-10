#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;


//Variables Globales
int salas = 0;
int filas = 0;
int asientos = 0;
int ***SalaCine;
int PrecioAsiento;


//definicion de funciones
int generaAleatorio(int limInferior, int limSuperior);
void mostrarSaladecine();
void mostrarSala(int sala);
void mostrarMenu();
void inicializarlaSaladecine();
bool reservarAsiento(int cantidad, int sala, int fila, int asiento);
int calcularVentas();
void IniciarSistema();
void ElegirAsiento();
void Recibo(int cantidad, int sala, int fila, int asiento);


int main() {
	system("color f0");
	srand(time(NULL));
	IniciarSistema();
	int opcionElegida = 0;	
	system("cls");
	do {
		mostrarMenu();
		cout << "Elige una opcion\n";
		cin >> opcionElegida;
		system("cls");
		switch (opcionElegida) {
			case 0:
				cout << "Saliendo del sistema...\n";
				break;
			case 1:
				mostrarSaladecine();
				break;
			case 2:
				ElegirAsiento();
				break;
			case 3:
				cout << "El total vendido es de $" << calcularVentas() << "\n";
				break;
			default:
				cout << "Valor no Valido\n";
		}
		system("pause");
		system("cls");
	} while (opcionElegida!=0);
	return 0;
}

//Elaboracion de las funciones
int generaAleatorio(int limInferior, int limSuperior) {
	int aleatorio;
	aleatorio = limInferior + rand() % (limSuperior + 1 - limInferior);
	return aleatorio;
}

void ElegirAsiento() {
	int fila = 0;
	int asiento = 0;
	int sala = 0;
	int CantidadAsientos = 0;
	string yn;
	do {
		cout << "Ingrese la sala\n";
		cin >> sala;
		sala--;
		mostrarSala(sala);
		cout << "Ingrese la cantidad de asientos que desea reservar\n";
		cin >> CantidadAsientos;
		while ((asientos - CantidadAsientos) < 0)
		{
			cout << "Dato incorrecto, ingrese como maximo " << asientos << " asientos\n";
			cin >> CantidadAsientos;
		}
		cout << "Ingrese la fila\n";
		cin >> fila;
		fila--;
		cout << "Ingrese el asiento inicial (se reservaran de izquierda a derecha)\n";
		cin >> asiento;
		asiento--;
	} while (reservarAsiento(CantidadAsientos, sala, fila, asiento) == false);
	cout << "La reserva fue exitosa.\n";
	cout << "Desea imprimir un recibo.(Y:Si / N:No)\n";
	cin >> yn;
	while ((yn != "y") && (yn != "n") && (yn != "Y") && (yn != "N"))
	{
		if ((yn == "y") || (yn == "n") || (yn == "Y") || (yn == "N")) break;
		cout << "Dato incorrecto, ingrese Y o N: ";
		cin >> yn;
	}
	if ((yn == "y") || (yn == "Y")) {
		Recibo(CantidadAsientos, sala, fila, asiento);
	}
}

void Recibo(int cantidad, int sala, int fila, int asiento) {
	system("cls");
	time_t tmFechaHora = time(0); 
	cout << " ----------------------------------------------\n";
	cout << " |                                            |\n";
	cout << " |     ,-.-.             ,---.o               |\n";
	cout << " |     | | |,---.,---.   |    .,---.,---.     |\n";
	cout << " |     | | |,---|`---.---|    ||   ||---'     |\n";
	cout << " |     ` ' '`---^`---'   `---'``   '`---'     |\n";
	cout << " |                                            |\n";
	cout << " |     " << ctime(&tmFechaHora); //Si aparece el error C4996 seguir las instrucciones de este video https://www.youtube.com/watch?v=NZW7djD3mH8
	cout << " |                                            |\n";
	cout << " |     ";
	cout << cantidad << " asientos";
	cout << "                             |\n";
	cout << " |                                            |\n";

	for (int i=0; i < cantidad; i++) {
		cout << " |     Fila: "<<fila+1<<"          Asiento: "<<cantidad +1+i<<"            |\n";
	}

	cout << " |                                            |\n";
	cout << " |                                            |\n";

	cout << " |   TOTAL....................."<<cantidad*PrecioAsiento<<"          |\n";
	cout << " |                                            |\n";
	cout << " |                                            |\n";
	cout << " ----------------------------------------------\n";


}

void mostrarMenu() {

	cout << "\n";

	cout << "MMMMMMMM               MMMMMMMM                                                            CCCCCCCCCCCCC  iiii\n";
	cout << "M:::::::M             M:::::::M                                                         CCC::::::::::::C i::::i\n";
	cout << "M::::::::M           M::::::::M                                                       CC:::::::::::::::C  iiii\n";
	cout << "M:::::::::M         M:::::::::M                                                      C:::::CCCCCCCC::::C\n";
	cout << "M::::::::::M       M::::::::::M  aaaaaaaaaaaaa       ssssssssss                     C:::::C       CCCCCCiiiiiii nnnn  nnnnnnnn        eeeeeeeeeeee\n";
	cout << "M:::::::::::M     M:::::::::::M  a::::::::::::a    ss::::::::::s                   C:::::C              i:::::i n:::nn::::::::nn    ee::::::::::::ee\n";
	cout << "M:::::::M::::M   M::::M:::::::M  aaaaaaaaa:::::a ss:::::::::::::s                  C:::::C               i::::i n::::::::::::::nn  e::::::eeeee:::::ee\n";
	cout << "M::::::M M::::M M::::M M::::::M           a::::a s::::::ssss:::::s --------------- C:::::C               i::::i nn:::::::::::::::ne::::::e     e:::::e\n";
	cout << "M::::::M  M::::M::::M  M::::::M    aaaaaaa:::::a  s:::::s  ssssss  -:::::::::::::- C:::::C               i::::i   n:::::nnnn:::::ne:::::::eeeee::::::e\n";
	cout << "M::::::M   M:::::::M   M::::::M  aa::::::::::::a    s::::::s       --------------- C:::::C               i::::i   n::::n    n::::ne:::::::::::::::::e\n";
	cout << "M::::::M    M:::::M    M::::::M a::::aaaa::::::a       s::::::s                    C:::::C               i::::i   n::::n    n::::ne::::::eeeeeeeeeee\n";
	cout << "M::::::M     MMMMM     M::::::Ma::::a    a:::::a ssssss   s:::::s                   C:::::C       CCCCCC i::::i   n::::n    n::::ne:::::::e\n";
	cout << "M::::::M               M::::::Ma::::a    a:::::a s:::::ssss::::::s                   C:::::CCCCCCCC::::Ci::::::i  n::::n    n::::ne::::::::e\n";
	cout << "M::::::M               M::::::Ma:::::aaaa::::::a s::::::::::::::s                     CC:::::::::::::::Ci::::::i  n::::n    n::::n e::::::::eeeeeeee\n";
	cout << "M::::::M               M::::::M a::::::::::aa:::a s:::::::::::ss                        CCC::::::::::::Ci::::::i  n::::n    n::::n  ee:::::::::::::e\n";
	cout << "MMMMMMMM               MMMMMMMM  aaaaaaaaaa  aaaa  sssssssssss                             CCCCCCCCCCCCCiiiiiiii  nnnnnn    nnnnnn    eeeeeeeeeeeeee\n";


	cout << "\n";
	cout << "\n";

	cout << "-----------Menu 1.0-----------\n";
	cout << "0 - Salir del sistema.\n";
	cout << "1 - Mostrar ocupacion de las salas\n";
	cout << "2 - Reservar asiento.\n";
	cout << "3 - Calcular Ventas.\n";
	cout << "------------------------------\n";
}

void mostrarSala(int sala) {
		cout << "Sala " << sala + 1 << "\n";
		cout << "-------------PANTALLA-------------\n";
		cout << "\n";
		cout << "    ";
		for (int i = 0; i < asientos; i++) {
			cout << "(" << i + 1 << ")";
		}
		cout << "\n";
		for (int y = 0; y < filas; y++) {
			if (y < 9) {
				cout << "(" << y + 1 << ") ";
			}
			else
			{
				cout << "(" << y + 1 << ")";
			}

			for (int z = 0; z < asientos; z++) {
				cout << "[" << SalaCine[sala][y][z] << "]";
			}
			cout << "\n";
		}
		cout << "\n";
}

void mostrarSaladecine() {
	int ocupacion=0;
	for (int x = 0; x < salas; ++x)
	{
		cout << "Sala " << x + 1 << "\n";
		cout << "-------------PANTALLA-------------\n";
		cout << "\n";
		cout << "    ";
		for (int i = 0; i < asientos; i++) {
			cout << "("<<i+1<<")";
		}
		cout << "\n";
		for (int y = 0; y < filas; y++) {
			if (y < 9) {
				cout << "(" << y + 1 << ") ";
			}
			else
			{
				cout << "(" << y + 1 << ")";
			}

			for (int z = 0; z < asientos; z++) {
				cout << "[" << SalaCine[x][y][z] << "]";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	for (int i = 0; i < salas; i++) {
		for (int j = 0; j < filas; j++) {
			for (int k = 0; k < asientos; k++) {
				if (SalaCine[i][j][k] == 1) {
					ocupacion++;
				}
			}
		}
	}
	cout << "De los " << salas * filas * asientos << " asientos disponibles en el cine se tiene una ocupacion de: " << ocupacion << "\n";
}

void inicializarlaSaladecine() {
	for (int i = 0; i < salas; i++) {
		for (int j = 0; j < filas; j++) {
			for (int k = 0; k < asientos; k++) {
				SalaCine[i][j][k] = generaAleatorio(0, 1);
			}
		}
	}
}

bool reservarAsiento(int cantidad, int sala, int fila, int asiento) {
	int disponibles = 0;
	if ((asiento + cantidad) > asientos) {
		cout << "No es posible elejir este asiento como el inicial\n";
		system("pause");
		system("cls");
		return false;
	}
	for (int i = 0; i < cantidad; i++) {
		if (SalaCine[sala][fila][asiento+i] != 0) {
			disponibles++;
		}
	}
	if (disponibles == 0) {
		for (int i = 0; i < cantidad; i++) {
			SalaCine[sala][fila][asiento+i] = 1;
		}
		return true;
	}
	else {
		cout << "Esa cantidad de asientos no esta disponible, por favor elija otra ubicacion\n";
		system("pause");
		system("cls");
		return false;
	}

}

int calcularVentas() {
	int asientosVendidos = 0;
	int ventas = 0;
	for (int i = 0; i < salas; i++) {
		for (int j = 0; j < filas; j++) {
			for (int k = 0; k < asientos; k++) {
				if (SalaCine[i][j][k] == 1) {
					asientosVendidos++;
				}
			}
		}
	}
	ventas = asientosVendidos * PrecioAsiento;
	return ventas;
}

void IniciarSistema() {
	string yn;
	cout << "Ingrese la cantidad de salas de las que dispone el Cine\n";
	cin >> salas;
	while ((salas < 0))
	{
		if ((salas > 0)) break;
		cout << "Numero de salas no valido: \n";
		cin >> salas;
	}
	cout << "Ingrese la cantidad de filas de las que dispone cada sala (1-10)\n";
	cin >> filas;
	while ((filas < 1) || (filas > 10))
	{
		if ((filas > 0) && (filas < 11)) break;
		cout << "Numero de filas no valido: \n";
		cin >> filas;
	}
	cout << "Ingrese la cantidad de asientos de las que dispone cada fila (1-10)\n";
	cin >> asientos;
	while ((asientos < 1) || (asientos > 10))
	{
		if ((asientos > 0) && (asientos < 11)) break;
		cout << "Numero de asientos no valido: \n";
		cin >> asientos;
	}
	SalaCine = new int** [salas];
	for (int x = 0; x < salas; x++) {
		SalaCine[x] = new int* [filas];
		for (int y = 0; y < filas; y++) {
			SalaCine[x][y] = new int[asientos];
		}
	}
	cout << "Para efectos practicos desea llenar las salas aleatorimente? (Y:Si / N:No)\n";
	cin >> yn;
	while ((yn != "y") && (yn != "n") && (yn != "Y") && (yn != "N"))
	{
		if ((yn == "y") || (yn == "n") || (yn == "Y") || (yn == "N")) break;
		cout << "Dato incorrecto, ingrese Y o N: ";
		cin >> yn;
	}
	if ((yn == "y") || (yn == "Y")) {
		inicializarlaSaladecine();
	}
	else {
		for (int i = 0; i < salas; i++) {
			for (int j = 0; j < filas; j++) {
				for (int k = 0; k < asientos; k++) {
					SalaCine[i][j][k] = 0;
				}
			}
		}
	}
	cout << "¿Cual es el precio de las boletas de cine?\n";
	cin >> PrecioAsiento;
}