#pragma once
#ifndef CURSA_H
#define CURSA_H
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
	bool metaVertical;
	map<string,Concursant> participants;
	vector <vector<int>> circuit; //0 es circuit 1 es limit
	vector <Punt2D> casellesInicials;
	vector<Punt2D> meta;
	
public:

	static Cursa* GetInstance();
	~Cursa();


	pair<Punt2D, Punt2D> GetAvaliableStartPosAndDirection();
	void AfegirConcursant(const Concursant& c);
	Concursant * BuscarConcursant(const string& nom);
	void InicialitzarCircuit(const vector<vector<int>>& circ, const vector<Punt2D>& m, bool vertical, int width, int height, int vueltas);
	bool HiHaParticipants() const;
	void MostrarCircuit() const;
	void MostrarCircuit(const Punt2D& jugadorConcret) const;
	bool EsTransitable(const Punt2D& p ) const;
	bool HiHaColisio(const Punt2D& p, shared_ptr<Vehicle> colisionat) const;
	vector <Punt2D> GetMeta() const;
	int GetVoltes() const;
	void MostraConcursants() const;
	void MostraClassificacio() const;

};

#endif