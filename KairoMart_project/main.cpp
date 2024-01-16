
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Punt2D.h"
#include "Cursa.h"
#include "Cavall.h"
#include "Bigue.h"
#include "Quadrigue.h"
#include <memory>
using namespace std;


int IniciCursa();
void InscriureConcursant(const vector<Personatge>& pers, const vector<Vehicle>& vec);
void MoureVehicle();
void MostrarClassificacio();

int main() 
{
	if (IniciCursa() == -1) return -1;

	vector<Personatge> characters;
	vector<Vehicle> vehicles;

	characters.push_back(Personatge("Mario"));
	characters.push_back(Personatge("Luigi"));
	characters.push_back(Personatge("Peach"));
	characters.push_back(Personatge("Bowser"));

	vehicles.push_back(Cavall("Cavall(Rocinante)", 1));
	vehicles.push_back(Bigue("Bigue(Motorola)", 2));
	vehicles.push_back(Quadrigue("Quadrigue(RayoMcQueen)", 3));


	bool fi = false;

	cout << "1- Inscriure Concursant" << endl;
	cout << "2- Moure Vehicle a la Cursa" << endl;
	cout << "3- Mostrar situacio actual Cursa" << endl;
	cout << "0- Sortir Programa" << endl;
	cout << "Escull Opcio:" << endl;

	while (not fi) {
		int opcio;
		cin >> opcio;

		switch (opcio)
		{
		case 1:
			InscriureConcursant(characters, vehicles);
			break;
		case 2:
			MoureVehicle();
			break;
		case 3:
			MostrarClassificacio();
			break;
		case 0:
			fi = true;
			break;

		default:
			break;
		}


		cout << "1- Inscriure Concursant" << endl;
		cout << "2- Moure Vehicle a la Cursa" << endl;
		cout << "3- Mostrar situacio actual Cursa" << endl;
		cout << "0- Sortir Programa" << endl;
		cout << "Escull Opcio:" << endl;
	}
	return 0;
}

void InscriureConcursant(const vector<Personatge>& pers , const vector<Vehicle>& vec) 
{
	string nom;
	cout << "Introdueix dades nou Concursant" << endl;
	cout << "Nom: ";
	cin >> nom;
	Cursa::GetInstance()->MostrarCircuit();

	//pos , dir
	pair<Punt2D,Punt2D> start = Cursa::GetInstance()->GetAvaliableStartPosAndDirection();

	if (start.first == Punt2D()) {
		cout << "No hi han mes slots disponibles en aquest moment" << endl;
		return;
	}

	Concursant nouC = Concursant(nom,0,start.first);

	cout << "Escull Personatge:\n" << endl;

	for (int i = 0; i < pers.size(); i++)
	{
		cout << i+1 << "- ";
		cout << pers[i].GetNom() << endl;
	}

	int opcio;
	cout << "OPCIO: ";
	cin >> opcio;

	shared_ptr<Personatge> nouPers = make_shared<Personatge>(pers[opcio - 1]);
	nouC.SeleccionarPersonatge(nouPers);

	cout << "Escull Vehicle:" << endl;

	for (int i = 0; i < vec.size(); i++)
	{
		cout << i + 1 << "- ";
		cout << vec[i].GetNomVehicle() << endl;
	}

	cout << "OPCIO: ";
	cin >> opcio;


	shared_ptr<Vehicle> nouVec = make_shared<Vehicle>(vec[opcio - 1]);
	nouVec->SetDireccio(start.second); //direccio inicial respecte al que s'ha definit a la meta
	nouC.SeleccionarVehicle(nouVec);

	Cursa::GetInstance()->AfegirConcursant(nouC);
	Cursa::GetInstance()->MostraConcursants();
	Cursa::GetInstance()->MostrarCircuit();
}

void MoureVehicle() 
{
	if (not Cursa::GetInstance()->HiHaParticipants()) {
		cout << "No hi ha Participants a la cursa" << endl;
		return;
	}

	Cursa::GetInstance()->MostraConcursants();

	string nom; 
	cout << "Quin concursant vols moure" << endl;
	cout << "NOM: ";
	cin >> nom;

	Concursant* c = Cursa::GetInstance()->BuscarConcursant(nom);

	if (c == nullptr) {
		cout << "No existeix aquest concursant" << endl;
		return;
	}

	Cursa::GetInstance()->MostrarCircuit(c->GetPosicio());

	int opcio;
	cout << "En quina direccio et vols moure (tingues en conte que no pots atravessar pareds i que si canvies de direccio perds velocitat i has de fer un gir)" << endl;
	cout << "Direccio actual: " << c->GetVehicle()->GetDireccio() << endl;
	cout << "Velocitat actual: " << c->GetVehicle()->GetVelocitat() << endl;
	cout << "1- Amunt" << endl;
	cout << "2- Avall" << endl;
	cout << "3- Esquerra" << endl;
	cout << "4- Dreta" << endl;
	cin >> opcio;


	Punt2D dirNova;

	switch (opcio)
	{
	case 1:
		dirNova = Punt2D(0, -1);
		break;
	case 2:
		dirNova = Punt2D(0, 1);
		break;
	case 3:
		dirNova = Punt2D(-1, 0);
		break;
	case 4:
		dirNova = Punt2D(1,0);
		break;
	default:
		break;
	}

	c->Conduir(dirNova);
	Cursa::GetInstance()->MostrarCircuit(c->GetPosicio());
}

void MostrarClassificacio() {
	if (not Cursa::GetInstance()->HiHaParticipants()) {
		cout << "No hi ha Participants a la cursa" << endl;
		return;
	}


}
int IniciCursa() {

	string path;
	cout << "Indica'm el path local del fitxer de configuracio del circuit (si no s'ha tocat la carpeta hauria de ser 'circuit.txt'" << endl;
	//cin >> path;

	ifstream file("circuit.txt");
	if (not file.is_open()) {
		cout << "No s'ha pogut trobar el fitxer de configuracio del circuit" << endl;
		return -1;
	}

	string buffer = "";
	int width, height, vueltas;
	while (not file.eof())
	{
		file >> buffer;

		if (buffer == "sizeX") {
			file >> width;
		}
		else return -1; //es podria fer try catch pero no ens dona temps , i tampoc es el focus de la practica

		file >> buffer;

		if (buffer == "sizeY") {
			file >> height;
		}
		else return -1;

		file >> buffer;

		if (buffer == "vueltas") {
			file >> vueltas;
		}
		else return -1;

		//se que tot aixo es optimitzable, pero repeteixo, no ens dona temps, i tampoc es el focus de la practica
		vector < vector<int>> circuit;
		circuit.resize(width);

		for (int i = 0; i < width; i++)
		{
			circuit[i].resize(height);
		}

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				file >> buffer;
				if (buffer != "0" and buffer != "1") {
					return -1;
				}

				circuit[x][y] = stoi(buffer);
				cout << buffer << " ";
			}
			cout << endl;
		}

		file >> buffer;
		bool vertical = (buffer == "V");
		file >> buffer;
		int metasize = stoi(buffer);
		vector<Punt2D> meta;

		int x = 0, y = 0;
		for (int j = 0; j < metasize; j++)
		{
			file >> x;
			file >> y;

			meta.push_back(Punt2D(x, y));
			cout << meta[j].get_x() << " " << meta[j].get_y() << endl;
		}


		Cursa::GetInstance()->InicialitzarCircuit(circuit,meta,vertical, width, height, vueltas);

	}

	return 0;
}