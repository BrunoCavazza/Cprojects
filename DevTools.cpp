#include <iostream> //libreria de entrada y salida por pantalla
#include <fstream> //libreria para manejo de archivos
#include <ctime>
#include <string>

using namespace std;


void creator(int); // Funcion que crea un txt en base a los datos de los monstruos que le pasemos.
void print(int);  // Funcion que muestra los monstruos en base a los datos de los txt cargados.
void randomicer(); // Funcion que elije monstruos al azar en base a los datos de los txt cargados.
void LoaderComun();// Funcion que carga monstruos al struct en base a los datos de los txt cargados.
void LoaderRaro();// Funcion que carga monstruos al struct en base a los datos de los txt cargados.
void LoaderEpico();// Funcion que carga monstruos al struct en base a los datos de los txt cargados.
void LoaderLegendario();// Funcion que carga monstruos al struct en base a los datos de los txt cargados.

struct mostro
{
	int id;
	string nombre;
	string descripcion;
	string img;
	
};


int main(int argc, char *argv[]) {
	int option = 0;
	int rareza = 0;
	string trash;
	
	
	ifstream ifs; //creo un objeto de la libreria ifstream
	ifs.open("MemonstersComunes.txt"); //abro el archivo
	
	
	do{
		cout<<"Dev Tools: -Ingrese la opcion a realizar-"<<endl;
		cout<<"1. Crear Memonsters."<<endl;
		cout<<"2. Simular encuentro de Memonster.(asegurese de tener las listas creadas)"<<endl;
		cout<<"3. Imprimir lista de Memonster."<<endl;
		cout<<"4. Cargar los monstruos con sus TXT."<<endl;
		cout<<"0. Salir."<<endl;
		cin>>option;
				
		switch(option){
		case 1:
			cout<<"ingrese la rareza para crear una lista de estos:\n -1- Comun \n -2- Raro \n -3- Epico \n -4- Legendario"<<endl;
			cin>>rareza;
			creator(rareza); // Funcion que crea un txt en base a los datos de los monstruos que le pasemos.
			break;
		case 2:
			randomicer(); // Funcion que elije monstruos al azar en base a los datos de los txt cargados.
			break;
		case 3:
			cout<<"ingrese la rareza para ver la lista creada:\n -1- Comun \n -2- Raro \n -3- Epico \n -4- Legendario"<<endl;
			cin>>rareza;
			print(rareza); // Funcion que muestra los monstruos en base a los datos de los txt cargados.
			break;
		case 4:
			LoaderComun();	// Funcion que carga monstruos al struct en base a los datos de los txt cargados.	
			LoaderRaro();
			LoaderEpico();
			LoaderLegendario();
			break;
		default:
			cout<<"Ingrese una opcion valida"<<endl;
			break;
		}
	}while(option != 0);
	
	
	return 0;
}


	


void creator(int rar){
	int n = 0;
	
	if(rar == 1){
		
		cout<<"--- Creando rareza COMUN ---"<<endl;
	}
	else if(rar == 2){
		cout<<"--- Creando rareza RARA ---"<<endl;
	}
	else if(rar == 3){
		cout<<"--- Creando rareza EPICA ---"<<endl;
	}
	else if(rar == 4){
		cout<<"--- Creando rareza LEGENDARIA ---"<<endl;
	}
		cout<<"Ingrese la cantidad de memonsters a agregar: "<<endl;
		cin>>n;
		struct mostro *memonster;
		memonster = new mostro[n];
		
		for(int i=0; i<n;i++){
			memonster[i].id = i+1;
			cout<<"\nIngrese los datos del mostro: "<<i+1<<endl;
			cout<<"Nombre: ";
			cin>>memonster[i].nombre;
			cout<<"Descripcion (usar _ para los espacios): ";
			cin>>memonster[i].descripcion;
		}
		
			ofstream ofs; //creo un objeto de la libreria ofstream
			
			if(rar == 1){
				ofs.open("MemonstersComunes.txt"); }
			else if(rar == 2){
				ofs.open("MemonstersRaros.txt"); }
			else if(rar == 3){
				ofs.open("MemonstersEpicos.txt"); }
			else if(rar == 4){
				ofs.open("MemonstersLegendarios.txt");}
			ofs<<"Cantidad_Total: "<<n<<"\n"	<<endl;
			for(int i=0; i<n;i++){
				ofs<<"ID: "<<memonster[i].id<<"\nNombre: "<<memonster[i].nombre<<"\nURL_Imagen: ./"<<memonster[i].nombre<<".png"<<"\nDescripcion: "<<memonster[i].descripcion<<"\n\n";
			}
			ofs.close(); 
			
			//Leer el archivo
			cout<<"\nLectura Del Archivo:"<<endl;
			string mensaje=" ";
			ifstream ifs; //creo un objeto de la libreria ifstream
			
			if(rar == 1){
				ifs.open("MemonstersComunes.txt"); }
			else if(rar == 2){
				ifs.open("MemonstersRaros.txt"); }
			else if(rar == 3){
				ifs.open("MemonstersEpicos.txt"); }
			else if(rar == 4){
				ifs.open("MemonstersLegendarios.txt");}
			
			while(!ifs.eof()) { //recorre el archivo hasta que llega al fin de linea
				getline(ifs,mensaje); 
				cout<<mensaje<<endl;
			}
			ifs.close(); //Cierro el archivo
		
	}
	
	
	
void randomicer(){
	int rng = 0;
	int op = 0;
	int tc = 0;
	string trash;
	srand(time(NULL));
	
	
	
	
	
	do{
		cout<<"Iniciador de encuentros"<<endl;
		cout<<"1. Iniciar un encuentro de memonster full random"<<endl;
		cout<<"0. Salir."<<endl;
		cin>>op;
		
		switch(op){
		case 1:
			rng = rand() % 100;
			if (rng >0 && rng <= 50){
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
				}
				ifsc.close(); 
				
			} else if (rng >50 && rng <= 85){
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
				}
				ifsr.close(); 
			} else if (rng >85 && rng <= 97){
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
				}
				ifse.close(); 
				
			} else if (rng >97 && rng <= 100){
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
				}
				ifsl.close(); 
			}
			break;
		default:
			cout<<"Ingrese una opcion valida"<<endl;
			break;
		}
	}while(op != 0);
	
}
	
	
void print(int rar){
		
			//Leer el archivo
			cout<<"\nLectura Del Archivo:"<<endl;
			string mensaje=" ";
			ifstream ifs; //creo un objeto de la libreria ifstream
			
			if(rar == 1){
			ifs.open("MemonstersComunes.txt"); }
			else if(rar == 2){
			ifs.open("MemonstersRaros.txt"); }
			else if(rar == 3){
			ifs.open("MemonstersEpicos.txt"); }
			else if(rar == 4){
			ifs.open("MemonstersLegendarios.txt");}
			
			while(!ifs.eof()) { //recorre el archivo hasta que llega al fin de linea
				getline(ifs,mensaje); 
				cout<<mensaje<<endl;
			}
			ifs.close(); //Cierro el archivo
		
		
		
		
		
		
		
		
	}
void LoaderComun(){	//Leer el archivo y cargar datos en struct
	string trash;
	int size = 0;

	
	cout<<"\n-----COMUNES-----\n"<<endl;
	ifstream ifs; //creo un objeto de la libreria ifstream
	ifs.open("MemonstersComunes.txt"); //abro el archivo
	
	if (ifs.is_open()){
		ifs >> trash;
		ifs >> size;
	
		struct mostro *comun;
		comun = new mostro[size];	
	
	cout<<"Tamanio: "<<size<<"\n"<<endl;
	
	for(int i=0; i<size;i++){
		
		ifs >> trash;
		ifs >> comun[i].id;
		cout<<"ID:"<<comun[i].id<<endl;
		
		ifs >> trash;
		ifs >> comun[i].nombre;
		cout<<"Nombre: "<<comun[i].nombre<<endl;
		
		ifs >> trash;
		ifs >> comun[i].img;
		cout<<"URL de la imagen: "<<comun[i].img<<endl;
		
		ifs >> trash;
		ifs >> comun[i].descripcion; 
		cout<<"Descripcion: "<<comun[i].descripcion<<"\n"<<endl;
		}
	}
	ifs.close(); //Cierro el archivo
}
	
void LoaderRaro(){	//Leer el archivo y cargar datos en struct
	string trash;
	int size = 0;
	
	cout<<"\n-----RAROS-----\n"<<endl;
	ifstream ifs; //creo un objeto de la libreria ifstream
	ifs.open("MemonstersRaros.txt"); //abro el archivo
	
	if (ifs.is_open()){
		ifs >> trash;
		ifs >> size;
		
		struct mostro *raras;
		raras = new mostro[size];	
		
		cout<<"Tamanio: "<<size<<"\n"<<endl;
		
		for(int i=0; i<size;i++){
			
			ifs >> trash;
			ifs >> raras[i].id;
			cout<<"ID:"<<raras[i].id<<endl;
			
			ifs >> trash;
			ifs >> raras[i].nombre;
			cout<<"Nombre: "<<raras[i].nombre<<endl;
			
			ifs >> trash;
			ifs >> raras[i].img;
			cout<<"URL de la imagen: "<<raras[i].img<<endl;
			
			ifs >> trash;
			ifs >> raras[i].descripcion; 
			cout<<"Descripcion: "<<raras[i].descripcion<<"\n"<<endl;
		}
	}
	ifs.close(); //Cierro el archivo
}
void LoaderEpico(){	//Leer el archivo y cargar datos en struct
	string trash;
	int size = 0;
	
	cout<<"\n-----EPICOS-----\n"<<endl;
	ifstream ifs; //creo un objeto de la libreria ifstream
	ifs.open("MemonstersEpicos.txt"); //abro el archivo
	
	if (ifs.is_open()){
		ifs >> trash;
		ifs >> size;
		
		struct mostro *epicos;
		epicos = new mostro[size];	
		
		cout<<"Tamanio: "<<size<<"\n"<<endl;
		
		for(int i=0; i<size;i++){
			
			ifs >> trash;
			ifs >> epicos[i].id;
			cout<<"ID:"<<epicos[i].id<<endl;
			
			ifs >> trash;
			ifs >> epicos[i].nombre;
			cout<<"Nombre: "<<epicos[i].nombre<<endl;
			
			ifs >> trash;
			ifs >> epicos[i].img;
			cout<<"URL de la imagen: "<<epicos[i].img<<endl;
			
			ifs >> trash;
			ifs >> epicos[i].descripcion; 
			cout<<"Descripcion: "<<epicos[i].descripcion<<"\n"<<endl;
		}
	}
	ifs.close(); //Cierro el archivo
	}

void LoaderLegendario(){	//Leer el archivo y cargar datos en struct
	string trash;
	int size = 0;
	
		cout<<"\n-----LEGENDARIOS-----\n"<<endl;
		string mensaje=" ";
		ifstream ifs; //creo un objeto de la libreria ifstream
		ifs.open("MemonstersLegendarios.txt"); //abro el archivo
		
		if (ifs.is_open()){
			ifs >> trash;
			ifs >> size;
			
			struct mostro *legendarios;
			legendarios = new mostro[size];	
			
			cout<<"Tamanio: "<<size<<"\n"<<endl;
			
			for(int i=0; i<size;i++){
				
				ifs >> trash;
				ifs >> legendarios[i].id;
				cout<<"ID:"<<legendarios[i].id<<endl;
				
				ifs >> trash;
				ifs >> legendarios[i].nombre;
				cout<<"Nombre: "<<legendarios[i].nombre<<endl;
				
				ifs >> trash;
				ifs >> legendarios[i].img;
				cout<<"URL de la imagen: "<<legendarios[i].img<<endl;
				
				ifs >> trash;
				ifs >> legendarios[i].descripcion; 
				cout<<"Descripcion: "<<legendarios[i].descripcion<<"\n"<<endl;
			}
	}
	ifs.close(); //Cierro el archivo
}
	
	
	
	
	
	
	
	
