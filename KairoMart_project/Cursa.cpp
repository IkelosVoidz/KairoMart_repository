#include "Cursa.h"


Cursa::Cursa() {
	voltes = 0;
}

Cursa* Cursa::GetInstance()
{
	if (instance == nullptr) {
		instance = new Cursa();
	}
	return instance;
}

void Cursa::AfegirConcursant(const Concursant& c)
{
	participants.insert({ c.GetPosicio() , c });
}

void Cursa::InicialitzarCircuit(const vector<vector<int>>& circ)
{
}

bool Cursa::HiHaParticipants() const
{
	return participants.size() > 0;
}

void Cursa::MostrarCircuit() const
{
	cout << "circuit amb els personatges hehe" << endl;
}

bool Cursa::EsTransitable(const Punt2D& p) const
{
	if ((p.get_x() < 0 or p.get_x() >= sizeX) or (p.get_y() < 0 or p.get_y() >= sizeY)) return false;

	return circuit[p.get_x()][p.get_y()] == 0;
}

bool Cursa::NoColisiona(const Punt2D& p, Vehicle *& colisionat) const
{
	bool colisiona = false;
	map<Punt2D, Concursant>::const_iterator it = participants.find(p);
	if (it != participants.end()) {
		colisiona = true;
		colisionat = it->second.GetVehicle();
	}

	return colisiona;
}
