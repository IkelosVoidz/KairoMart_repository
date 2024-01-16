#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "Concursant.h"
#include "Punt2D.h"

using namespace std;
class Cursa
{
private:

	Cursa();
	static Cursa* instance;

	int sizeX;
	int sizeY;
	int voltes;
	map<Punt2D,Concursant> participants;
	vector <vector<int>> circuit; //0 es circuit 1 es limit
	vector <Punt2D> casellesInicials;
	vector<Punt2D> meta;
	
	
public:

	static Cursa* GetInstance();


	void AfegirConcursant(const Concursant& c);
	void InicialitzarCircuit(const vector<vector<int>>& circ);
	bool HiHaParticipants() const;
	void MostrarCircuit() const;
	bool EsTransitable(const Punt2D& p ) const;
	bool NoColisiona(const Punt2D& p, Vehicle*& colisionat) const;
	vector <Punt2D> GetMeta() const;
	int GetVoltes() const;

};

