/*1. Una empresa dedicada al rubro de las telecomunicaciones brinda servicios de internet a las cooperativas de las comunas de las Sierras de Calamuchita. Generar un listado (TDA Lista) de las facturas del mes y año en curso de las cooperativas con los siguientes datos: 

Lista de Facturación de Noviembre 2021

N° Cliente	Comuna	Consumo	Monto a pagar*
1	Anisacate	100	7000
2	La Bolsa	30	2100
3	Villa Los Aromos	35	2450*Calcular la columna con una función, si el costo es 1 GB = $70.
Luego, crear un menú de opciones con las siguientes operaciones:

- Pago de factura. Cuando la comuna va pagar la factura, se realiza la búsqueda en el listado, muestra la factura y solicita el día de pago. En caso de que el pago se realice después del día 11 inclusive se le sumará un recargo de $10 por día de retraso. Finalmente muestra el recibo por pantalla y guarda el recibo en una TDA Cola.

- Mostrar la lista y cola*/

#include <iostream>
#include "facturas.h"
#include <queue>

using namespace std;

void mostrar(queue<Factura>);
void deuda(queue<Factura>);
queue <Factura> descontar(queue<Factura>);


int main(int argc, char *argv[]) {
	Factura p;
	queue<Factura> listaFactura;
	
	p.setCodigo(1);
	p.setCliente("Anisacate");
	p.setConsumo(100);
	p.setDeuda(p.getConsumo() * 70);
	listaFactura.push(p);
	
	p.setCodigo(2);
	p.setCliente("La Bolsa");
	p.setConsumo(30);
	p.setDeuda(p.getConsumo() * 70);
	listaFactura.push(p);
	
	p.setCodigo(3);
	p.setCliente("V. Los Aromos");
	p.setConsumo(35);
	p.setDeuda(p.getConsumo() * 70);
	listaFactura.push(p);
	
	int op = 0;
	do{
		cout<<"\n --- MENU DE OPCIONES ---"<<endl;
		cout<<"1) Mostrar Facturas."<<endl;
		cout<<"2) Pago de Factura."<<endl;
		cout<<"0) salir."<<endl;
		cout<<"\nOpcion: ";
		cin>>op;
		switch(op){
		case 1: 
			mostrar(listaFactura);
			break;
		case 2: 
			listaFactura=descontar(listaFactura);
			break;
		case 3: 
			deuda(listaFactura);
			break;
		default: 
			cout<<"Ingrese una opcion valida. ";
		}
		
	}while(op != 0);
	return 0;
}


void mostrar(queue <Factura> listaFactura){
	Factura p;
	queue<Factura> aux_lista; 
	cout<<"Codigo\t\tCliente\t\t\tCunsumo(GB)\tDeuda"<<endl;
	while(!listaFactura.empty())
	{
		p=listaFactura.front();
		cout<<p.getCodigo()<<"\t\t"<<p.getCliente()<<"\t\t"<<p.getConsumo()<<"\t\t"<<p.getDeuda()<<endl;
		aux_lista.push(listaFactura.front()); 
		listaFactura.pop();
	}
	listaFactura=aux_lista;	
}
void deuda(queue <Factura> listaFactura){
	Factura p;
	queue<Factura> aux_lista; 
	{
		p=listaFactura.front();
		aux_lista.push(listaFactura.front()); 
		p.setDeuda(p.getConsumo() * 70);
		listaFactura.pop();
	}
	listaFactura=aux_lista;	
}

	queue <Factura> descontar(queue <Factura> listaFactura){
		Factura p;
		queue<Factura> aux_lista; 
		int cod=0,desc=0, day=0, recargo=0;
		cout<<"Ingrese el codigo del producto a descontar: ";
		cin>>cod;
		while(!listaFactura.empty())
		{
			p=listaFactura.front();
			if(p.getCodigo()==cod){
				cout<<"Ingrese el dia que se realizo el pago: ";
				cin>>day;
				if(day > 11){
					recargo = (day-11)*10;
				}else{
					recargo = 0;
				}
				cout<<"Hay "<<p.getDeuda()<<"$ sin pagar del cliente "<<p.getCliente()<<", el cual tiene un recargo de: "<<recargo<<"$ Por pagar fuera de tiempo.\nIngrese la cantidad que pago para descontar de su deuda: ";
				p.setDeuda(p.getDeuda() + recargo);
				cout<<"\n(Total a pagar:"<<p.getDeuda()<<")\n";
				cin>>desc;
				
				while(desc>p.getDeuda()){
					cout<<"Ingrese una cantidad menor o igual a "<<p.getDeuda()<<": ";
					cin>>desc;
				}
				p.setDeuda(p.getDeuda()-desc);
			}
			aux_lista.push(p); 
			listaFactura.pop();
		}
		return aux_lista;
	}
		
