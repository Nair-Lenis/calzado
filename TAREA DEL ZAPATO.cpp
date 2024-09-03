#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Calzado {
private:
	int talla;
	char ladopie;
public:
	Calzado() {
		talla = 30;
		ladopie = 'D';
	}
	Calzado(int tam) {
		ladopie = 'D';
		talla = tam;
	}
	Calzado(int tam, char lado) {
		ladopie = lado;
		talla = tam;
	}
	bool esParde(const Calzado& cal) const {
		return talla == cal.talla && ladopie != cal.ladopie;
	}
	Calzado crearPar() const {
		Calzado par;
		par.talla = talla;
		par.ladopie = ladopie == 'D' ? 'I' : 'D';
		return par;
	}
	void randomizar() {
		talla = rand() % 50 + 20;        
		ladopie = rand() % 2 == 0 ? 'D' : 'I'; 
	}
	void VerDatos() const {
		cout << "Talla: " << talla << ", Lado: " << ladopie << endl;
		dibujarZapato();
	}
	void dibujarZapato() const {
		if (ladopie == 'D') {
			cout << "        _______" << endl;
			cout << "       |       |" << endl;
			cout << "       |       |" << endl;
			cout << "       |" << talla << "     |" << endl;
			cout << "       |       |" << endl;
			cout << " ______|       |" << endl;
			cout << " |             |" << endl;
			cout << " |  D          |" << endl;
			cout << " |_____________|" << endl;
		} else {
			cout << "  _______" << endl;
			cout << " |       |" << endl;
			cout << " |       |" << endl;
			cout << " |" << talla << "     |" << endl;
			cout << " |       |" << endl;
			cout << " |       |_____" << endl;
			cout << " |             |" << endl;
			cout << " |  I          |" << endl;
			cout << " |_____________|" << endl;
		}
	}
};

int main() {
	srand(time(0)); // seed for random numbers
	Calzado a, b(45), c(30, 'I'), d(30, 'D');
	if (a.esParde(b))
		cout << "a es par de b \n";
	else
		cout << "a no es par de b \n";
	Calzado x = b.crearPar();
	if (x.esParde(b))
		cout << "x es par de b\n";
	else
		cout << "x no es par de b\n";
	while (true) {
		a.randomizar();
		b.randomizar();
		cout << "Indica si a es par de b?" << endl;
		a.VerDatos();
		b.VerDatos();
		int resp;
		cout << "Ingrese 1 si a es par de b, 0 si no: ";
		cin >> resp; // 1->el usuario asume que es verdad, 0->el usuario indica que es falso
		if ((a.esParde(b) && resp == 1) || (!a.esParde(b) && resp == 0))
			cout << "Adivinaste\n";
		else
			cout << "No es correcto\n";
	}
	return 0;
}
