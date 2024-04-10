// Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
using namespace std;

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

int main() {
	float clave;
	float i;
	float imp;
	float salir;
	float t1;
	float t2;
	float t3;
	float tt;
	float val;
	for (i=1;i<=2;i+=0) {
		cout << "Ingrese la clave del vehiculo" << endl;
		cin >> clave;
		cout << "Ingrese el valor del vehiculo" << endl;
		cin >> val;
		if (clave==1) {
			imp = val*0.1;
			t1 = t1+imp;
		} else {
			if (clave==2) {
				imp = val*0.07;
				t2 = t2+imp;
			} else {
				if (clave==3) {
					imp = val*0.05;
					t3 = t3+imp;
				} else {
					cout << "Clave Invalida" << endl;
				}
			}
		}
		tt = tt+imp;
		cout << "El impuesto a pagar por este vehiculo es: " << imp << endl;
		cout << "Ingrese 1 para realizar otro registro o 0 para salir" << endl;
		cin >> salir;
		if (salir==0) {
			i = 3;
		}
	}
	cout << "El impuesto a pagar por todos los vehiculos es " << tt << endl;
	cout << "El impuesto a pagar por vehiculos de categoria 1 es " << t1 << endl;
	cout << "El impuesto a pagar por vehiculos de categoria 2 es " << t2 << endl;
	cout << "El impuesto a pagar por vehiculos de categoria 3 es " << t3 << endl;
	return 0;
}

