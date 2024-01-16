#include <iostream>
#include <cmath>
#include "Punt2D.h"
#include <sstream>
#include <memory>
using namespace std;

// Constructors

  Punt2D::Punt2D() {
     x=0;
     y=0;
  }

  Punt2D::Punt2D(double posx, double posy) {
     x=posx;
     y=posy;
 }

// Consultors

  double Punt2D::get_x() const {
     return x;
  }

  double Punt2D::get_y() const {
     return y;
  }

  double Punt2D::distancia(Punt2D p) const {
     double difX = x-p.x;
     double difY = y-p.y;
     return sqrt(difX*difX+difY*difY);
  }

  void Punt2D::mostrar() const {
     cout << "(" << x << "," << y << ")" << endl;
  }

  bool Punt2D::es_igual(Punt2D p) const {
     return x == p.x and y == p.y;
  }

  Punt2D Punt2D::punt_mig(Punt2D p) const {
     return Punt2D((x+p.x)/2, (y+p.y)/2);
  }

// Modificadors

  void Punt2D::moure(double x, double y) {
     x += x;
     y += y;
  }

  void Punt2D::moure(Punt2D p) {
     x += p.x;
     y += p.y;
  }

  void Punt2D::llegir() {
     cin >> x >> y;
  }

  bool Punt2D::operator<(const Punt2D& p) const
  {
      bool menor = x < p.x;
      if (not menor) menor = y < p.y;
      return menor;
  }

  bool Punt2D::operator==(const Punt2D& p) const
  {
      return es_igual(p);
  }

  ostream& operator<<(ostream& os, const Punt2D& p)
  {
      stringstream ss;

      ss << "(" << p.get_x() << "," << p.get_y() << ")";
      return os << ss.str();
  }
