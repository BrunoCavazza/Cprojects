#include <iostream>
#include <string>

using namespace std;

class Memonster{
private:
	
	int codigo;
	string nombre;
	string descripcion;
	string rareza;
	
public:
	Memonster();
	
	void setCodigo(int cod);
	int getCodigo();
	
	void setNombre(string nom);
	string getNombre();
	
	void setDescripcion(string desc);
	string getDescripcion();
	
	void setRareza(string rar);
	string getRareza();

};

Memonster::Memonster() { //es el contructor por defecto
}

void Memonster::setCodigo(int cod) {
	codigo = cod;}
int Memonster::getCodigo() {
	return codigo; }

void Memonster::setNombre(string nom) {
	nombre = nom;}
string Memonster::getNombre() {
	return nombre; }

void Memonster::setDescripcion(string desc) {
	descripcion = desc;}
string Memonster::getDescripcion() {
	return descripcion; }

void Memonster::setRareza(string rar) {
	rareza = rar;}
string Memonster::getRareza() {
	return rareza; }
