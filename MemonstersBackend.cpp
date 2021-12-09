#include <iostream> //libreria de entrada y salida por pantalla
#include <fstream> //libreria para manejo de archivos
#include <ctime>
#include <string>
#include "Memonsters.h"
#include <stack>
#include <queue>

using namespace std;

void encounter(); // Funcion que elije monstruos al azar en base a los datos de los txt cargados.

struct mostro
{
	int id;
	string nombre;
	string descripcion;
	string img;
	
};


int main(int argc, char *argv[]) {
	int option = 0;
	int rngesus = 0;
	string trash;
	srand(time(NULL));
	
	queue<int> que; 
	//Aca uso Pilas <---------
	srand(time(NULL));
	int num = 0;
	for (int i = 0; i < 10; i++){
		num = 1 + rand()%100;
		que.push(num);
	}
	
	do{
		cout<<"MEMONSTERS!!!"<<endl;

		cout<<"1. Buscar Memonster (30%)"<<endl;
		cout<<"2. Encontrar Memonster"<<endl;
		cout<<"0. Salir."<<endl;
		cin>>option;
		
		switch(option){
		case 1:
			rngesus = rand() % 100;
			if (rngesus >0 && rngesus <= 30){
				cout<<"Se encontro un Memonster!!!\n"<<endl;
				encounter(); // Funcion que elije monstruos al azar en base a los datos de los txt cargados.
			}else{
				cout<<"No se encontro ningun Memonster!\n"<<endl;
			}
			break;
		case 2:
			encounter(); // Funcion que elije monstruos al azar en base a los datos de los txt cargados.
			break;
		default:
			cout<<"Ingrese una opcion valida"<<endl;
			break;
		}
	}while(option != 0);
	
	
	return 0;
}





	
void encounter(){
	int rng = 0, tc = 0;
	int numeroBot=0, numeroPlayer=0, vidas=3, win=0, num=0, calidad=0, id=0;
	string trash=" ", player=" ", bot=" ", nombre=" ", descripcion=" ";
	srand(time(NULL));
	
	Memonster p;
	queue<Memonster> pilaMemonster;
			
	queue<int> que; //insertar esto afuera del press E
	//Aca uso Pilas <---------
	srand(time(NULL));
	for (int i = 0; i < 10; i++){ 
		num = 1 + rand()%100;
		que.push(num);
	}
	
	
	
	rng = que.front(); //insertar esto dentro del press E
	que.pop();
	num = 1 + rand()%100;
	que.push(num);
			
			if (rng >0 && rng <= 50){
				calidad = 1;
				cout<<"\n("<<rng<<") Memonster Comun \n"<<endl;
				
				ifstream ifsc; //creo un objeto de la libreria ifstream
				ifsc.open("MemonstersComunes.txt"); //abro el archivo
				
				if (ifsc.is_open()){
					ifsc >> trash;
					ifsc >> tc;
					
					struct mostro *comun;
					comun = new mostro[tc];	
					
					cout<<"Tamanio: "<<tc<<"\n"<<endl;
					
					for(int i=0; i<tc;i++){
						
						ifsc >> trash;
						ifsc >> comun[i].id;
						
						ifsc >> trash;
						ifsc >> comun[i].nombre;
						
						ifsc >> trash;
						ifsc >> comun[i].img;
						
						ifsc >> trash;
						ifsc >> comun[i].descripcion; 
						
					}
					
					rng = rand() % tc;
					cout<<"Aparecio... "<<comun[rng].nombre<<endl;
					cout<<comun[rng].descripcion<<"\n"<<endl;
					cout<<comun[rng].img<<"\n"<<endl;
					
					id = comun[rng].id;
					nombre = comun[rng].nombre;
					descripcion = comun[rng].descripcion;
				}
				ifsc.close(); 
				
			} else if (rng >50 && rng <= 85){
				calidad = 2;
				cout<<"\n("<<rng<<") Memonster Raro \n"<<endl;
				
				ifstream ifsr; //creo un objeto de la libreria ifstream
				ifsr.open("MemonstersRaros.txt"); //abro el archivo
				
				if (ifsr.is_open()){
					ifsr >> trash;
					ifsr >> tc;
					
					struct mostro *raro;
					raro = new mostro[tc];	
					
					for(int i=0; i<tc;i++){
						
						ifsr >> trash;
						ifsr >> raro[i].id;
						
						ifsr >> trash;
						ifsr >> raro[i].nombre;
						
						ifsr >> trash;
						ifsr >> raro[i].img;
						
						ifsr >> trash;
						ifsr >> raro[i].descripcion; 
						
					}	
					
					rng = rand() % tc;
					cout<<"Aparecio... "<<raro[rng].nombre<<endl;
					cout<<raro[rng].descripcion<<"\n"<<endl;
					
					id = raro[rng].id;
					nombre = raro[rng].nombre;
					descripcion = raro[rng].descripcion;
				}
				ifsr.close(); 
			} else if (rng >85 && rng <= 97){
				calidad = 3;
				cout<<"\n("<<rng<<") Memonster Epico \n"<<endl;
				ifstream ifse; //creo un objeto de la libreria ifstream
				ifse.open("MemonstersEpicos.txt"); //abro el archivo
				
				if (ifse.is_open()){
					ifse >> trash;
					ifse >> tc;
					
					struct mostro *epico;
					epico = new mostro[tc];	
					
					cout<<"Tamanio: "<<tc<<"\n"<<endl;
					
					for(int i=0; i<tc;i++){
						
						ifse>> trash;
						ifse>> epico[i].id;
						
						ifse>> trash;
						ifse>> epico[i].nombre;
						
						ifse>> trash;
						ifse>> epico[i].img;
						
						ifse>> trash;
						ifse>> epico[i].descripcion; 
						
					}
					
					rng = rand() % tc;
					cout<<"Aparecio... "<<epico[rng].nombre<<endl;
					cout<<epico[rng].descripcion<<"\n"<<endl;
					
					id = epico[rng].id;
					nombre = epico[rng].nombre;
					descripcion = epico[rng].descripcion;
				}
				ifse.close(); 
				
			} else if (rng >97 && rng <= 100){
				calidad = 4;
				cout<<"\n("<<rng<<") Memonster Legendario \n"<<endl;
				ifstream ifsl; //creo un objeto de la libreria ifstream
				ifsl.open("MemonstersLegendarios.txt"); //abro el archivo
				
				if (ifsl.is_open()){
					ifsl >> trash;
					ifsl >> tc;
					
					struct mostro *legendario;
					legendario = new mostro[tc];	
					
					cout<<"Tamanio: "<<tc<<"\n"<<endl;
					
					for(int i=0; i<tc;i++){
						
						ifsl >> trash;
						ifsl >> legendario[i].id;
						
						ifsl >> trash;
						ifsl >> legendario[i].nombre;
						
						ifsl >> trash;
						ifsl >> legendario[i].img;
						
						ifsl >> trash;
						ifsl >> legendario[i].descripcion; 
						
					}
					
					rng = rand() % tc;
					cout<<"Aparecio... "<<legendario[rng].nombre<<endl;
					cout<<legendario[rng].descripcion<<"\n"<<endl;
					
					id = legendario[rng].id;
					nombre = legendario[rng].nombre;
					descripcion = legendario[rng].descripcion;
					
				}
				ifsl.close(); 
			}
				// ACA COMIENZA EL PIEDRA PAPEL O TIJERAS <--------------------------------
				vidas=3;
				win=0;
				
				queue<int> op; 
				//Aca uso Pilas <---------
				num = 1 + rand()%3;
				op.push(num);
				//cout<<lapila.top()<<endl; <- descomentame y haces trampa
				num = 1 + rand()%3;
				op.push(num);
				//cout<<lapila.top()<<endl; <- descomentame y haces trampa
				num = 1 + rand()%3;
				op.push(num);
				//cout<<lapila.top()<<endl; <- descomentame y haces trampa
				
				for (int i=vidas; (i>0 && win==0); i--){
					cout<<"Numero del player: "<<endl;
					cout<<"1 = FUERZA\t(Gana a Tecnica)"<<endl;
					cout<<"2 = AGILIDAD\t(Gana a Fuerza)"<<endl;
					cout<<"3 = TECNICA\t(Gana a Agilidad)"<<endl;
					cin>>numeroPlayer;		
					
					numeroBot = op.front();
					op.pop();
					
					if(numeroPlayer == 1){
						player = "Fuerza";
					}else if(numeroPlayer == 2){
						player = "Agilidad";
					}else if(numeroPlayer == 3){
						player = "Tecnica";
					}
					if(numeroBot == 1){
						bot = "Fuerza";
					}else if(numeroBot == 2){
						bot = "Agilidad";
					}else if(numeroBot == 3){
						bot = "Tecnica";
					}
					
					
					cout<<"\nTu Eleccion:"<<endl;
					cout<<player<<"\n"<<endl;
					cout<<"Memonster:"<<endl;
					cout<<bot<<"\n"<<endl;
					
					
					if((numeroPlayer==1 && numeroBot==3) || (numeroPlayer==2 && numeroBot==1) || (numeroPlayer==3 && numeroBot==2)){
						cout<<"Lo Capturaste!!!"<<endl;
						win++;
					}else if(numeroPlayer>3){
						cout<<"Opcion no valida"<<endl;
						num = 1 + rand()%3;
						op.push(num);
						i++;
					}else{
						cout<<"Pediste, te queda(n) "<<i-1<<" Intento(s)"<<endl;
						vidas--;
						win=0;
					}
					cout<<endl;
				}
				if(win==1){
					cout<<"Capturaste el Memonster!!!"<<endl;
					cout<<"Vidas restantes: "<<vidas<<"\n Guardando Memonster en la Memopedia. . .\n"<<endl;
					
					
					
					
					
					
					// En este punto se Cargan los memonsters Capturados <---------------------------------------------
					int totalCapturados = 0, code = 0;
					string name = " ", description = " ", rarity = " "; 
					
					
					//Leer el archivo
					ifstream lecap; //creo un objeto de la libreria ifstream
					lecap.open("MemonstersCapturados.txt"); //abro el archivo
					
					if (lecap.is_open()){
						lecap >> trash;
						lecap >> totalCapturados;
						
						for(int i=0; i<totalCapturados;i++){
							
							lecap >> trash;
							lecap >> code;
							p.setCodigo(code);
							
							lecap >> trash;
							lecap >> name;
							p.setNombre(name);
							
							lecap >> trash;
							lecap >> description;
							p.setDescripcion(description);
							
							lecap >> trash;
							lecap >> rarity; 
							p.setRareza(rarity);
							
							pilaMemonster.push(p);
							
						}
						
						
						
					}
					lecap.close(); 
					

					
					// En este punto se Guardan los memonsters Capturados <---------------------------------------------
					p.setCodigo(id);
					p.setNombre(nombre);
					p.setDescripcion(descripcion);
					if(calidad==1){ 
						p.setRareza("Comun");
					}else if(calidad==2){ 
						p.setRareza("Raro");
					}else if(calidad==3){ 
						p.setRareza("Epico");
					}else if(calidad==4){ 			
						p.setRareza("Legendario");}
					
					pilaMemonster.push(p);
					totalCapturados++;
					
					ofstream ofcap; //creo un objeto de la libreria ofstream
					
					ofcap.open("MemonstersCapturados.txt");
					
					
					ofcap<<"Cantidad_Total: "<<totalCapturados<<"\n"<<endl;
					for(int i=0; i<totalCapturados;i++){
						p=pilaMemonster.front();
						ofcap<<"ID: "<<p.getCodigo()<<"\nNombre: "<<p.getNombre()<<"\nDescripcion: "<<p.getDescripcion()<<"\nRareza: "<<p.getRareza()<<"\n\n";
						cout<<"--------\nCodigo:"<<"\nNombre: "<<p.getNombre()<<"\nDescripcion: "<<p.getDescripcion()<<"\nRareza: "<<p.getRareza()<<"\n--------\n"<<endl;
						pilaMemonster.pop();
					}
					ofcap.close(); 
					
		
				}else if(win==0){
					cout<<"El Memonster se escapo!!!\n"<<endl;
				}
				
				
				
			}
