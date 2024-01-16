#include "Concursant.h"
#include "Cursa.h"
Concursant::Concursant() {
	id = 0;
	nom = " ";
	posicio = Punt2D();
	voltesFetes = 0;
	personatgeSeleccionat = nullptr;
	vehicleSeleccionat = nullptr;
	AccRecte = make_shared<Accelerar>(Accelerar());
	AccDerr = make_shared<AccelerarDerrepant>(AccelerarDerrepant());
	AccGir = make_shared<AccelerarGirant>(AccelerarGirant());
}
Concursant::Concursant(const string& n)
{
	nom = n;
	id = 0;
	posicio = Punt2D();
	voltesFetes = 0;
	personatgeSeleccionat = nullptr;
	vehicleSeleccionat = nullptr;
	AccRecte = make_shared<Accelerar>(Accelerar());
	AccDerr = make_shared<AccelerarDerrepant>(AccelerarDerrepant());
	AccGir = make_shared<AccelerarGirant>(AccelerarGirant());
}
Concursant::Concursant(const string& _nom, int _id, const Punt2D& pos) {
	id = _id;
	nom = _nom;
	posicio = pos;
	voltesFetes = 0;
	personatgeSeleccionat = nullptr;
	vehicleSeleccionat = nullptr;
	AccRecte = make_shared<Accelerar>(Accelerar());
	AccDerr = make_shared<AccelerarDerrepant>(AccelerarDerrepant());
	AccGir = make_shared<AccelerarGirant>(AccelerarGirant());
}

Concursant::Concursant(const Concursant& other)
{
	*this = other;
}

Concursant& Concursant::operator=(const Concursant& other)
{
	nom = other.nom;
	id = other.id;
	posicio = other.posicio;
	voltesFetes = other.voltesFetes;
	vehicleSeleccionat = other.vehicleSeleccionat;
	personatgeSeleccionat = other.personatgeSeleccionat;
	AccRecte = other.AccRecte;
	AccDerr = other.AccDerr;
	AccGir = other.AccGir;

	return *this;
}

Concursant::~Concursant()
{
	/*
	delete vehicleSeleccionat;
	delete personatgeSeleccionat;
	*/
}

void Concursant::Conduir(const Punt2D& dir)
{
	Punt2D dirActual = vehicleSeleccionat->GetDireccio();

	if (not ((dir.get_x() - dirActual.get_x() == 0) or (dir.get_y() - dirActual.get_y() == 0))) 
	{

		cout << "Has seleccionat un canvi de direccio, per tant has de girar, Escolleix un d'aquests dos comportaments: " << endl;
		cout << "1-Derrape" << endl;
		cout << "2-Gir normal" << endl;
		cout << "OPCIO: ";
		int opcio;
		cin >> opcio;

		if (opcio == 1) vehicleSeleccionat->CambiarAccelerar(AccDerr);
		else if (opcio == 2) vehicleSeleccionat->CambiarAccelerar(AccGir);
	}

	Punt2D newPos = vehicleSeleccionat->FesAccelerar(dir, posicio);
	Cursa* instanciaCursa = Cursa::GetInstance();

	if (newPos.es_igual(Punt2D())) {
		
		cout << "La Posicio es invalida, torna-ho a intentar" << endl;
		vehicleSeleccionat->CambiarAccelerar(AccRecte); //tornem al default
		return;
	}
	else {
		vehicleSeleccionat->CambiarAccelerar(AccRecte);
		// mirar si ha creuat la meta i sumar/restar les voltes actuals en conseqüència.
		vector<Punt2D> meta = instanciaCursa->GetMeta();


		cout << "Voltes fetes abans de calcular: " << voltesFetes << endl;

		if (newPos.get_x() >= meta[0].get_x() and posicio.get_x() < meta[0].get_x()) {
			voltesFetes++;
		}
		else if (newPos.get_x() < meta[0].get_x() and posicio.get_x() >= meta[0].get_x()) {
			voltesFetes--;
		}

		cout << "Voltes fetes despres de calcular: " << voltesFetes << endl;

		// mirar si ha acabat la carrera
		if (voltesFetes >= instanciaCursa->GetVoltes()) {
			cout << "He acabado la carrera hehe";
		}

		posicio = newPos;
	}
}

string Concursant::GetNom() const
{
	return nom;
}

int Concursant::GetId() const
{
	return id;
}

int Concursant::GetVoltesFetes() const
{
	return voltesFetes;
}

Punt2D Concursant::GetPosicio() const
{
	return posicio;
}

shared_ptr<Vehicle> Concursant::GetVehicle() const
{
	return vehicleSeleccionat;
}

shared_ptr<Personatge> Concursant::GetPersonatge() const
{
	return personatgeSeleccionat;
}

void Concursant::SeleccionarVehicle(shared_ptr<Vehicle> vec)
{
	vehicleSeleccionat = vec;
	vehicleSeleccionat->CambiarAccelerar(AccRecte);
}

void Concursant::SeleccionarPersonatge(shared_ptr<Personatge> pers)
{
	personatgeSeleccionat = pers;
}

bool Concursant::EstaPenalitzat()
{
	return vehicleSeleccionat->EstaPenalitzat();
}
