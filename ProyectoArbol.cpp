#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class ArbolBin;
class Pila;
class Pila{
	ArbolBin *dato;
	Pila *sig;

public:
	void iniciarPila(Pila *&cab){
		cab = new Pila;
		cab->dato = NULL;
		cab->sig = NULL;
	}
	bool pilaVacia(Pila *cab){
		if (!cab->sig)
			return true;
		else
			return false;
	}
	void agregarPila(Pila *&cab, ArbolBin *dato){
		Pila *aux = cab;
		while (aux->sig)
			aux = aux->sig;
		aux->sig = new Pila;
		aux->sig->sig = NULL;
		aux->sig->dato = dato;
	}
	ArbolBin *retirarPila(Pila *&cab){
		Pila *aux = cab, *aux1;
		ArbolBin *dir_dato;
		aux1 = aux;
		if (!pilaVacia(aux)){
			while (aux->sig)
			{
				aux1 = aux;
				aux = aux->sig;
			}
			aux1->sig = NULL;
			dir_dato = aux->dato;
			delete aux;
			return dir_dato;
		}
		else
			cout << "Pila vacia ...." << endl;
	}
};
class ArbolBin{
	char placa[6],marca[20],color[20];
    int potencia;
    bool tipo;//Carga 0 y pasajeros 1
	ArbolBin *izq, *der;

public:
	void crearRaiz(ArbolBin *&raiz, char placa[6],char marca[20],char color[20],int potencia,bool tipo){
		raiz = new ArbolBin;
        strcpy(raiz->placa, placa);
        strcpy(raiz->marca,marca);
        strcpy(raiz->color,color);
		raiz->potencia=potencia;
		raiz->tipo=tipo;
		raiz->izq = NULL;
		raiz->der = NULL;
	}
	void agregarIzq(ArbolBin *&temp,char placa[6],char marca[20],char color[20],int potencia,bool tipo){
		ArbolBin *nuevo;
		nuevo = new ArbolBin;
		strcpy(nuevo->placa, placa);
        strcpy(nuevo->marca,marca);
        strcpy(nuevo->color,color);
		nuevo->potencia=potencia;
		nuevo->tipo=tipo;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		temp->izq = nuevo;
	}
	void agregarDer(ArbolBin *&temp, char placa[6],char marca[20],char color[20],int potencia,bool tipo){
		ArbolBin *nuevo;
		nuevo = new ArbolBin;
		strcpy(nuevo->placa, placa);
        strcpy(nuevo->marca,marca);
        strcpy(nuevo->color,color);
		nuevo->potencia=potencia;
		nuevo->tipo=tipo;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		temp->der = nuevo;
	}
	// void crearArbol(ArbolBin *&raiz){
	// 	ArbolBin *temp1, *temp2;
	// 	int dato = 666;
	// 	while (dato != -1)
	// 	{
	// 		cout << "Dato > ";
	// 		cin >> dato;
	// 		if (dato != -1){
	// 			if (!raiz){
	// 				crearRaiz(raiz, dato);
	// 			}else{
	// 				temp1 = temp2 = raiz;
	// 				while (temp2 && temp1->dato != dato){
	// 					temp1 = temp2;
	// 					if (dato < temp1->dato)
	// 						temp2 = temp2->izq;
	// 					else
	// 						temp2 = temp2->der;
	// 				}
	// 				if (temp1->dato == dato){
	// 					cout << "Numero repetido" << endl;
	// 				}else{
	// 					if (dato < temp1->dato)
	// 						agregarIzq(temp1, dato);
	// 					else
	// 						agregarDer(temp1, dato);
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	void mostrarALL(ArbolBin *raiz){
		cout<<"MARCA"<<raiz->marca<<endl;
		cout<<"COLOR"<<raiz->color<<endl;
		cout<<"PLACA"<<raiz->placa<<endl;
		cout<<"TIPO"<<raiz->tipo<<endl;
		cout<<"POTENCIA"<<raiz->potencia<<endl;
		cout<<"------------------------------------------------------------"<<endl;
	}
	void inorden(ArbolBin *raiz){
		Pila *aux, obj_pila;
		ArbolBin *temp = raiz;
		cout << "Arbol Binario ....." << endl;
		obj_pila.iniciarPila(aux);
		while (temp)
		{
			obj_pila.agregarPila(aux, temp);
			temp = temp->izq;
		}
		while (!obj_pila.pilaVacia(aux))
		{
			temp = obj_pila.retirarPila(aux);
			mostrarALL(temp);
			temp = temp->der;
			while (temp)
			{
				obj_pila.agregarPila(aux, temp);
				temp = temp->izq;
			}
		}
	}
	ArbolBin *buscar(ArbolBin *raiz,char placa[6]){
		Pila *aux, obj_pila;
		ArbolBin *temp = raiz;
		obj_pila.iniciarPila(aux);
		while(temp){
			obj_pila.agregarPila(aux,temp);
			temp=temp->izq;
		}
		while(!obj_pila.pilaVacia(aux)){
			temp = obj_pila.retirarPila(aux);
			if(0==strcmp(temp->placa,placa))
				return temp;
			temp = temp->der;
			while (temp){
				obj_pila.agregarPila(aux, temp);
				temp = temp->izq;
			}
		}
		temp=NULL;
		return temp;
	}
	int calcularNivel(ArbolBin *raiz){
		int nivel=0;
		if(raiz->izq&&raiz->izq->der!=raiz)
			nivel++;	
		if(raiz->der&&raiz->der->izq!=raiz)
			nivel++;
		return nivel;
	}
	char getClave(ArbolBin *raiz){
		return *raiz->placa;
	}
};
void menu(){
	cout << "Menu de opciones" << endl;
	cout << "[1].Mostrar Todo(inorden)" << endl;
	cout << "[2].Consulta Placa"<< endl;//Tiene mostrar las caracteristicas del vehiculo
	cout << "[3].Cantidad de Vehiculos de color"<< endl;//Cantidad de carros con x color
	cout << "[4].Mostrar vehiculos de carga" << endl; 
	cout << "[5].Mostrar vehiculos de pasajeros" << endl; 
	cout << "[6].Consultar por rango potencia(vehiculos que tiene la misma o mayor potencia)" << endl; 
	cout << "[7].Mostrar vehiculos por marca" << endl;//Mostrar toda la info de todos los vehiculos que contienen esa marca 
	cout << "[8].Agregar Vehiculo" << endl;//Mostrar toda la info de todos los vehiculos que contienen esa marca 
	cout << "[9].Eliminar vehiculo" << endl; 
	cout << "[10].Salir" << endl;
}
void mtipo(){
	cout << "Escoja una opcion de tipo de auto" << endl;
	cout << "[1].Vehiculo de carga" << endl;
	cout << "[2].Vehiculo de pasajeros"<< endl;
}
int main(){
	char placa[6],marca[20],color[20];
	int potencia,tv;
	bool tipo;//Carga 0 y pasajeros 1
	ArbolBin *raiz = NULL, obj_arbol,*aux;
	// ArbolBin *&raiz, char placa[6],char marca[20],char color[20],int potencia,bool tipo
 	cout << "Ingrese el primer vehiculo"<< endl;
	cout << "[Ingrese Placa]"<< endl;
	cin.getline(placa,7,'\n');
	fflush(stdin);
	cout << "[Ingrese Marca]"<< endl;
	cin.getline(marca,21,'\n');
	fflush(stdin);
	cout << "[Ingrese Color]"<< endl;
	cin.getline(color,21,'\n');
	fflush(stdin);
	cout << "[Ingrese potencia]"<< endl;
	cin>>potencia;
	cout<<"[Escoja tipo de vehiculo]"<< endl;
	mtipo();
	cin>>tv;
	if(tv==1)
		tipo==0;
	else
 		tipo==1;
	cout<<"PLACA >"<<placa<<"\nMARCA >"<<marca<<"\nCOLOR >"<<color<<"\nPOTENCIA >"<<potencia<<"\nTIPO >"<<tipo<<endl;
	obj_arbol.crearRaiz(raiz,placa,marca,color,potencia,tipo);
	system("pause");
	int opt,dato;
	do{
		fflush;
		system("cls");
		menu();
		cin>>opt;
		switch (opt){
		case 1: // [1].Mostrar Todo(inorden)
			obj_arbol.inorden(raiz);
			system("pause");		
			break;
		case 2: // [2].Consulta Placa			
			cout<<"SIN PROGRAMAR"<<endl;
			system("pause");
			break;
		case 3: // [3].Cantidad de Vehiculos de color
			cout<<"SIN PROGRAMAR"<<endl;
			system("pause");
			break;
		case 4: // [4].Mostrar vehiculos de carga
			cout<<"SIN PROGRAMAR"<<endl;
			system("pause");
			break;
		case 5: // [5].Mostrar vehiculos de pasajeros	
			cout<<"SIN PROGRAMAR"<<endl;
			system("pause");
			break;
		case 6: // [6].Consultar por rango potencia(vehiculos que tiene la misma o mayor potencia)
			cout<<"SIN PROGRAMAR"<<endl;
			system("pause");
			break;
		case 7: // [7].Mostrar vehiculos por marca
			cout<<"SIN PROGRAMAR"<<endl;
			system("pause");
			break;
		case 8: // [8].Agregar vehiculo			
			cout<<"SIN PROGRAMAR"<<endl;
			system("pause");
			break;
			break;
		case 9: // [9].Eliminar vehiculo			
			cout<<"SIN PROGRAMAR"<<endl;
			system("pause");
			break;
		case 10: // [9].Salir 
			break;
		default: // ERROR EN OPCION
			cout << "Intentelo denuevo" << endl;
			system("pause");
			break;
		}
	} while (opt != 10);
	return 0;
}
