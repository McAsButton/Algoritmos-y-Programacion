// Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
using namespace std;

// Para las variables que no se pudo determinar el tipo se utiliza la constante
// SIN_TIPO. El usuario debe reemplazar sus ocurrencias por el tipo adecuado
// (usualmente int,float,string o bool).
#define SIN_TIPO string

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

int main() {
	float cant;
	float cantt1;
	float cantt2;
	float cantt3;
	float cantt4;
	float cantt5;
	float i;
	float loc;
	SIN_TIPO precio;
	float rect;
	float salir;
	float total;
	float valloc1;
	float valloc2;
	float valloc3;
	float valloc4;
	float valloc5;
	for (i=1;i<=5;i++) {
		cout << "Ingrese el precio de la localidad " << i << endl;
		cin >> precio;
		if (valloc1==0) {
			valloc1 = precio;
		} else {
			if (valloc2==0) {
				valloc2 = precio;
			} else {
				if (valloc3==0) {
					valloc3 = precio;
				} else {
					if (valloc4==0) {
						valloc4 = precio;
					} else {
						if (valloc5==0) {
							valloc5 = precio;
						}
					}
				}
			}
		}
	}
	for (i=1;i<=2;i+=0) {
		cout << "Ingrese la localidad que se esta vendiendo" << endl;
		cin >> loc;
		cout << "Ingrese la cantidad de boletos" << endl;
		cin >> cant;
		if (loc==1) {
			total = cant*valloc1;
			cantt1 = cantt1+cant;
		} else {
			if (loc==2) {
				total = cant*valloc2;
				cantt2 = cantt2+cant;
			} else {
				if (loc==3) {
					total = cant*valloc3;
					cantt3 = cantt3+cant;
				} else {
					if (loc==4) {
						total = cant*valloc4;
						cantt4 = cantt4+cant;
					} else {
						if (loc==5) {
							total = cant*valloc5;
							cantt5 = cantt5+cant;
						}
					}
				}
			}
		}
		rect = rect+total;
		cout << "*---------------------------------------*" << endl;
		cout << "La clave es: " << loc << endl;
		cout << "La cantidad de boletos es: " << cant << endl;
		cout << "El total de la venta es: " << total << endl;
		cout << "*---------------------------------------*" << endl;
		cout << "Ingrese 1 para realizar otra venta o 0 para salir" << endl;
		cin >> salir;
		if (salir==0) {
			i = 3;
		}
	}
	cout << "La cantidad de boletas vendidas de la localidad 1 es: " << cantt1 << endl;
	cout << "La cantidad de boletas vendidas de la localidad 2 es: " << cantt2 << endl;
	cout << "La cantidad de boletas vendidas de la localidad 3 es: " << cantt3 << endl;
	cout << "La cantidad de boletas vendidas de la localidad 4 es: " << cantt4 << endl;
	cout << "La cantidad de boletas vendidas de la localidad 5 es: " << cantt5 << endl;
	cout << "El recaudo total del estadio es: " << rect << endl;
	return 0;
}

