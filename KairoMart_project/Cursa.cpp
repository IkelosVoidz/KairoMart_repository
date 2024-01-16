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
	participants.insert(c);
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
	return circuit[p.get_x()][p.get_y()] == 0;
}

bool Cursa::NoColisiona(const Punt2D&, Vehicle *& colisionat) const
{
	return false;
}
