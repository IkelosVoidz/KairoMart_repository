#include "Cursa.h"
#include "string"
#include <iomanip>

Cursa* Cursa::instance = nullptr;

Cursa::Cursa() {
	instance = nullptr;
	voltes = 0;
	sizeX = 0;
	sizeY = 0;
	metaVertical = false;
}

Cursa* Cursa::GetInstance()
{
	if (instance == nullptr) {
		instance = new Cursa();
	}
	return instance;
}

Cursa::~Cursa()
{
	delete instance;
}

pair<Punt2D,Punt2D> Cursa::GetAvaliableStartPosAndDirection()
{
	//considerem que els circuits sempre seran clock wise

	Punt2D dir;
	shared_ptr<Vehicle> unused;

	if (metaVertical) {
		for (Punt2D p : meta)
		{
			dir = Punt2D(-1, 0);
			p.moure(dir);
			
			if (not HiHaColisio(p, unused)) {
				return pair< Punt2D, Punt2D>({p , dir,});
			}
		}
	}
	else {
		for (Punt2D p : meta)
		{
			dir = Punt2D(0, -1);
			p.moure(dir);
			if (not HiHaColisio(p, unused)) {
				return pair< Punt2D, Punt2D>({ p , dir, });
			}
		}
	}

	return pair< Punt2D, Punt2D>({ Punt2D() , Punt2D(),});
}

void Cursa::AfegirConcursant(const Concursant& c)
{
	//ponerlos en lugares de la linia de inicio vacios y denegar si no hay espacios libres
	participants.insert({ c.GetNom() , c});
}

Concursant * Cursa::BuscarConcursant(const string& nom)
{
	map<string, Concursant>::iterator it = participants.find(nom);

	if (it != participants.end()) {
		return &it->second;
	}
	else return nullptr;
}

void Cursa::InicialitzarCircuit(const vector<vector<int>>& circ, const vector<Punt2D>& m, bool vertical, int width, int height, int vueltas)
{
	circuit = circ;
	sizeX = width;
	sizeY = height;
	voltes = vueltas;
	meta = m;
	metaVertical = vertical;
}

bool Cursa::HiHaParticipants() const
{
	return participants.size() > 0;
}

void Cursa::MostrarCircuit() const
{
	cout << "Circuit en situacio actual:\n" << endl;

	vector<vector<string>> circuitMostrar;
	circuitMostrar.resize(sizeX);
	for (int i = 0; i < sizeX; i++)
	{
		circuitMostrar[i].resize(sizeY);
	}

	for (int y = 0;  y < sizeY;  y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			circuitMostrar[x][y] = to_string(circuit[x][y]);
		}
	}

	int i = 0;
	for (auto it : participants) {

		Punt2D pos = it.second.GetPosicio();
		string apodo = it.second.GetNom().substr(0, 3);
		circuitMostrar[pos.get_x()][pos.get_y()] = apodo;
		i++;
	}

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			cout << setw(3) << fixed  << circuitMostrar[x][y];;
		}
		cout << endl;
	}
	cout << endl;
}

void Cursa::MostrarCircuit(const Punt2D& jugadorConcret) const
{
	cout << "Circuit en situacio actual:\n" << endl;

	vector<vector<string>> circuitMostrar;
	circuitMostrar.resize(sizeX);
	for (int i = 0; i < sizeX; i++)
	{
		circuitMostrar[i].resize(sizeY);
	}

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			circuitMostrar[x][y] = to_string(circuit[x][y]);
			//cout << setfill('0') << setw(2) << circuitMostrar[x][y];
		}
	}

	int i = 0;
	for (auto it : participants) {

		Punt2D pos = it.second.GetPosicio();
		string apodo;
		if (pos == jugadorConcret) apodo = "TU";
		else apodo = it.second.GetNom().substr(0, 3);
		circuitMostrar[pos.get_x()][pos.get_y()] = apodo;
		i++;
	}

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			cout << setw(3) << circuitMostrar[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool Cursa::EsTransitable(const Punt2D& p) const
{
	if ((p.get_x() < 0 or p.get_x() >= sizeX) or (p.get_y() < 0 or p.get_y() >= sizeY)) return false;

	return circuit[(int)p.get_x()][(int)p.get_y()] == 0;
}

bool Cursa::HiHaColisio(const Punt2D& p, shared_ptr<Vehicle>& colisionat) const
{
	bool colisiona = false;
	
	for (auto it : participants) {
		if (it.second.GetPosicio() == p) {
			colisionat = it.second.GetVehicle();
			colisiona = true;
			break;
		}
	}
	
	return colisiona;
}

vector<Punt2D> Cursa::GetMeta() const
{
	return meta;
}

int Cursa::GetVoltes() const
{
	return voltes;
}

void Cursa::MostraConcursants() const
{
	int i = 0;
	for (auto it : participants) {
		cout << "CONCURSANT " << i << " (" << it.second.GetNom() << " , " 
			<< it.second.GetVehicle()->GetNomVehicle() << " , " 
			<< it.second.GetPersonatge()->GetNom() << ")" << endl;
		i++;
	}
}

void Cursa::MostraClassificacio() const
{
	int i = 0;
	for (auto it : participants) {
		cout << i << "- " << it.second.GetNom() 
			<< ": POSICIO:" << it.second.GetPosicio() 
			<< ", VOLTES: " << it.second.GetVoltesFetes() << endl;
		i++;
	}
}

