#include <iostream>
#include <string>

using namespace std;

class Factura{
private:
	
	int codigo;
	string cliente;
	int consumo;
	int deuda;
	
public:
	Factura();
	
	void setCodigo(int cod);
	int getCodigo();
	
	void setCliente(string nom);
	string getCliente();
	
	void setConsumo(int cant);
	int getConsumo();
	
	void setDeuda(int pre);
	int getDeuda();
};

Factura::Factura() { //es el contructor por defecto
}

void Factura::setCodigo(int cod) {
	codigo = cod;}
int Factura::getCodigo() {
	return codigo; }

void Factura::setCliente(string cli) {
	cliente = cli;}
string Factura::getCliente() {
	return cliente; }

void Factura::setConsumo(int cons) {
	consumo = cons;}
int Factura::getConsumo() {
	return consumo; }

void Factura::setDeuda(int deu) {
	deuda = deu;}
int Factura::getDeuda() {
	return deuda; }
