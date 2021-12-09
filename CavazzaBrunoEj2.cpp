/*2. Crear en una TDA Pila con 10 números aleatorios del 1 al 100 que no se repitan. Luego crear las siguientes funciones: 
	
	- que muestren todos los valores
	
	- que muestre un listado con valores pares y otro listado con valores impares
	
	- que sumen todos los valores
	
	- que obtenga el valor máximo
	
	- que obtenga el valor mínimo */
	
#include <iostream>
#include <ctime>
#include <stack>

using namespace std;

void mostrarPila(stack<int>);
void paresPila(stack<int>);
void imparesPila(stack<int>);
void sumaPila(stack<int>);
void maxPila(stack<int>);
void minPila(stack<int>);


int main(int argc, char *argv[]) {
	
	stack<int> lapila; 
	int num=0;
	srand(time(NULL));
	
	cout << "Generando numeros aleratorios para la pila:"<<endl;
	
	for(int i=0; i<10;i++){
	
	num = rand() % 100;
	lapila.push(num);
	}
	
	mostrarPila(lapila);
	paresPila(lapila);
	imparesPila(lapila);
	sumaPila(lapila);
	maxPila(lapila);
	minPila(lapila);

	return 0;
}


void mostrarPila(stack<int> lapila){
	stack<int> aux_pila; 
	cout << "\nLos elementos de la pila son:\t";
	while(!lapila.empty())
	{
		cout << lapila.top() <<", ";
		aux_pila.push(lapila.top()); 
		lapila.pop();
	}
	lapila=aux_pila;
}
	
void paresPila(stack<int> lapila){
	stack<int> aux_pila; 
	cout << "\nLos elementos pares son:\t";
	while(!lapila.empty())
	{
		if(lapila.top() % 2 == 0){
			aux_pila.push(lapila.top());
			cout << lapila.top() <<", ";
			lapila.pop();
		}else{
		lapila.pop();
		}
		
	}
	lapila=aux_pila;
	
}
	void imparesPila(stack<int> lapila){
		stack<int> aux_pila; 
		cout << "\nLos elementos pares son:\t";
		while(!lapila.empty())
		{
			if(lapila.top() % 2 == 1){
				aux_pila.push(lapila.top());
				cout << lapila.top() <<", ";
				lapila.pop();
			}else{
				lapila.pop();
			}
			
		}
		lapila=aux_pila;
		
	}
	
		void sumaPila(stack<int> lapila){
			int sum =0;
			stack<int> aux_pila; 
			cout << "\nLa suma de los elementos es:\t";
			while(!lapila.empty())
			{
					aux_pila.push(lapila.top());
					sum = lapila.top() + sum;
					lapila.pop();
				
				
			}
			cout << sum <<endl;
			lapila=aux_pila;
			
		}
			void maxPila(stack<int> lapila){
				int max = 0;
				stack<int> aux_pila; 
				cout << "El mayor elemento es:\t\t";
				while(!lapila.empty())
				{
					if(lapila.top() >= max){
						aux_pila.push(lapila.top());
						max = lapila.top();
					}
					lapila.pop();
					
					
				}
				cout << max <<endl;
				lapila=aux_pila;
				
			}

				void minPila(stack<int> lapila){
					int min = 100;
					stack<int> aux_pila; 
					cout << "El menor elemento es:\t\t";
					while(!lapila.empty())
					{
						if(lapila.top() <= min){
						aux_pila.push(lapila.top());
						min = lapila.top();
						}
						lapila.pop();
						
						
					}
					cout << min <<endl;
					lapila=aux_pila;
					
				}	
