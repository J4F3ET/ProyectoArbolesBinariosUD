#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
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
char trans(char palabra[],int t){
	palabra[t];
	for (int i=0;palabra[i]!='\0'; ++i){//minusculas a matyusculas
		palabra[i] = toupper(palabra[i]);
	}
	return *palabra;
}
class ArbolBin;
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
	char placa[7],marca[21],color[21];
    int potencia;
    bool tipo;//Carga 0 y pasajeros 1
	ArbolBin *izq, *der;
public:
	void crearRaiz(ArbolBin *&raiz, char placa[6],char marca[20],char color[20],int potencia,bool tipo){
		raiz = new ArbolBin;
		strcpy(raiz->placa,placa);
		strcpy(raiz->color,color);
		strcpy(raiz->marca,marca);
		raiz->potencia=potencia;
		raiz->tipo=tipo;
		raiz->izq = NULL;
		raiz->der = NULL;
	}
	void agregarIzq(ArbolBin *&temp,char placa[6],char marca[20],char color[20],int potencia,bool tipo){
		ArbolBin *nuevo;
		nuevo = new ArbolBin;
		strcpy(nuevo->placa, placa);
        strcpy(nuevo->color,color);
        strcpy(nuevo->marca,marca);
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
        strcpy(nuevo->color,color);
        strcpy(nuevo->marca,marca);
		nuevo->potencia=potencia;
		nuevo->tipo=tipo;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		temp->der = nuevo;
	}
	bool placaMenor(ArbolBin *raiz,char placa[6]){
		bool orden = false;
		int i=0;
		while(raiz->placa[i]==placa[i]){
			i++;
		}
		if(raiz->placa[i]>placa[i])
			orden=true;
		return orden;
	}
	void agregarAuto(ArbolBin *&raiz){  //Se añade un automovil
		ArbolBin *temp1, *temp2;
			int dato = 666;
			char placa[6],marca[20],color[20];//MIEMBROS DE LA CLASE ARBOL BIN
			int potencia,tv;//MIEMBROS DE LA CLASE ARBOL BIN
			bool tipo;//Carga 0 y pasajeros 1 MIEMBROS DE LA CLASE ARBOL BIN
		cout << "Para finalizar el registro del vehiculo debe poner ' . ' en PLACA"<< endl;
		while (placa[0]!='.'){
			fflush(stdin);
			//INICIA EL FORMULARIO DE DATOS
			cout << "Registrando vehiculo nuevo"<< endl;
			cout << "[Ingrese Placa]"<< endl;
			cin.getline(placa,7,'\n');
			if(placa[0]!='.'){
				for (int i=0;placa[i]!='\0'; ++i){//minusculas a matyusculas
					placa[i] = toupper(placa[i]);
				}
			}
			fflush(stdin);
			if(placa[0]!='.'){
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
					tipo=0;
				else
					tipo=1;
				
					
					
				//FIN FORMULARIO DE DATOS
				if(placa[0]!='.'){
					temp1 = temp2 = raiz;
					while(temp2 &&strcmp(temp1->placa,placa)){//SI TEMP2 EXISTE Y RAIZ->PLACA ES DIFERENTE A PLACA
							temp1 = temp2;
							if (placaMenor(temp1,placa))//SI PLACAMENOR() EXPULSA UN FALSE ENTONCES, PLACA ES MAYOR QUE RAIZ, POR ENDE VA A DERECHA
								temp2 = temp2->izq;
							else
								temp2 = temp2->der;
						}
						if(!strcmp(temp1->placa, placa)){//RAIZ->PLACA ES IGUAL A PLACA
							cout << "Placa existente..." << endl;
						}else{
							if(placaMenor(temp1,placa))
								agregarIzq(temp1,placa,marca,color,potencia,tipo);
							else
								agregarDer(temp1,placa,marca,color,potencia,tipo);
					}
				}
			}
		}
	}
	void mostrarALL(ArbolBin *raiz){
		cout<<"------------------------------------------------------------"<<endl;
		cout<<"PLACA ENCONTRADA \n";
		cout<<"\t Placa : "<<raiz->placa<<endl;
		cout<<"\t Marca : "<<raiz->marca<<endl;
		cout<<"\t Potencia : "<<raiz->potencia<<endl;
		cout<<"\t Color : "<<raiz->color<<endl;
		if(raiz->tipo==0){
			cout<<"\t Tipo de vehiculo : Vehiculo de carga "<<endl;
		}else if(raiz->tipo==1){
			cout<<"\t Tipo de vehiculo : Vehiculo de pasajeros "<<endl;
		}
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
	void buscarPlaca(ArbolBin *raiz,char placa[6]){ //METODO DE BUSCAR LA PLACA DEL VEHICULO
		Pila *aux, obj_pila;
		ArbolBin *temp = raiz;
		cout << "Arbol Binario ....." << endl;
		obj_pila.iniciarPila(aux);
		while (temp){
			obj_pila.agregarPila(aux, temp);
			temp = temp->izq;
		}
		while (!obj_pila.pilaVacia(aux)){
			temp = obj_pila.retirarPila(aux);
			if(!strcmp(temp->placa,placa))
				mostrarALL(temp);
			temp = temp->der;
			while (temp)
			{
				obj_pila.agregarPila(aux, temp);
				temp = temp->izq;
			}
		}
		cout<<"PLACA NO ENCONTRADA... \n";
	}

	void buscarPotencia(ArbolBin *raiz, int potencia){ //METODO DE BUSCAR POTENCIA (POTENCIAS MAYORES O IGUALES ALA DIGITADA)
	cout<<"LOS VEHICULOS QUE TIENEN UNA POTENCIA MAYOR E IGUAL A ("<<potencia<<") SON : "<<endl;
		Pila *aux, obj_pila; //Pila puesta por defecto 
		
		ArbolBin *temp=raiz;
		
		obj_pila.iniciarPila(aux);
		
		while(temp){
			obj_pila.agregarPila(aux,temp);
			temp=temp->izq;
		}
		
		while(!obj_pila.pilaVacia(aux)){
			temp=obj_pila.retirarPila(aux);
				if(temp->potencia>=potencia){ //Si el temporal ubicado en un nodo del arbol, en su parte potencia es mayor e igual a potencia
				cout<<"------------------------------------- \n";
					cout<<"\t Placa : "<<temp->placa<<endl;
					cout<<"\t Marca : "<<temp->marca<<endl;
					cout<<"\t Potencia : "<<temp->potencia<<endl;
					cout<<"\t Color : "<<temp->color<<endl;
				
					if(temp->tipo==0){
						cout<<"\t Tipo de vehiculo : Vehiculo de carga "<<endl;
					}else if(temp->tipo==1){
						cout<<"\t Tipo de vehiculo : Vehiculo de pasajeros "<<endl;
					}
					cout<<"------------------------------------- \n"<<endl;
				}
			temp=temp->der;
			
			while(temp){
				obj_pila.agregarPila(aux,temp);
				temp=temp->izq;
			}
			
		}		
	}
	int calcularNivel(ArbolBin *raiz){
		int nivel=0;
		if(raiz->izq&&raiz->izq->der!=raiz)
			nivel++;	
		if(raiz->der&&raiz->der->izq!=raiz)
			nivel++;
		return nivel;
	}
	void mostrarTipoVehiculo(ArbolBin *raiz,bool tipo){
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
			if(temp->tipo==tipo)
				mostrarALL(temp);	
			temp = temp->der;
			while (temp)
			{
				obj_pila.agregarPila(aux, temp);
				temp = temp->izq;
			}
		}
	}
	ArbolBin *buscarPadre(ArbolBin *raiz,char placa[6]){
		Pila *aux, obj_pila;
		ArbolBin *temp2,*temp = raiz;
		obj_pila.iniciarPila(aux);
		while(temp){
			obj_pila.agregarPila(aux,temp);
			temp=temp->izq;
		}
		while(!obj_pila.pilaVacia(aux)){
			temp2=temp;
			temp = obj_pila.retirarPila(aux);
			if(0==strcmp(temp2->placa,placa))
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
	void reemplazarN(ArbolBin *&raiz,ArbolBin *&nuevoNodo){
		ArbolBin *padre;
		padre=buscarPadre(raiz,raiz->placa);
		if(padre){
			//Detectar si es padre por derecha o izq
			if(!strcmp(raiz->placa,padre->izq->placa)){//detecta izq
				padre->izq=nuevoNodo;
			}else if(!strcmp(raiz->placa,padre->der->placa)){//detecta der
				padre->der=nuevoNodo;
			}
		}
	}
	void eliminarVehiculo(ArbolBin *&raiz,char placa[6]){
		ArbolBin *aux,*aux2;
		int auxI;//Auxiliar entero
		aux=buscar(raiz,placa);
		if(aux){//DETECTA SI EL NODO EXISTE O NO
			//CLASIFICAR QUE CLASE DE NODO ES 
			auxI=calcularNivel(aux);//Metodo retorna la cantidad de hijos
			if(auxI==2){//Nodo tiene dos hijos
				aux2=aux;
				aux2=aux2->der;
				while(aux2->izq){
					aux2=aux2->izq;
				}
				//RESCRIBIENDO NODO
				strcpy(aux->placa,aux2->placa);
				strcpy(aux->marca,aux2->marca);
				strcpy(aux->color,aux2->color);
				aux->potencia=aux2->potencia;
				aux->tipo=aux2->tipo;
			}else if(auxI==1){//Nodo tiene un hijo
				if(aux->izq&&aux->izq->der!=aux){
					reemplazarN(aux,aux->izq);
					aux->izq=NULL;
					aux->der=NULL;
				}else if(aux->der&&aux->der->izq!=aux){
					reemplazarN(aux,aux->der);
					aux->izq=NULL;
					aux->der=NULL;
				}
				delete aux;
			}else if(auxI==0){//Nodo tiene no tiene hijos
				aux2=buscarPadre(aux,placa);
				if(aux2->izq&&aux2->izq->der!=aux2)
					aux2->izq=NULL;
				else if(aux->der&&aux->der->izq!=aux2)
					aux2->der=NULL;
				aux->izq=aux->der=NULL;
				delete aux;
			}
		}else
			cout<<"Placa no encontrada..."<<endl;
	}
	void buscarMarca(ArbolBin *raiz,char marca[20]){
		Pila *aux, obj_pila;
		ArbolBin *temp = raiz;
		obj_pila.iniciarPila(aux);

		while(temp){
			obj_pila.agregarPila(aux,temp);
			temp=temp->izq;
		}
		while(!obj_pila.pilaVacia(aux)){
			temp = obj_pila.retirarPila(aux);
			if(!strcmp(temp->marca,marca)){
				cout<<"MARCA ENCONTRADA \n";
				cout<<"\t Placa : "<<temp->placa<<endl;
				cout<<"\t Marca : "<<temp->marca<<endl;
				cout<<"\t Potencia : "<<temp->potencia<<endl;
				cout<<"\t Color : "<<temp->color<<endl;
					if(temp->tipo==0){
						cout<<"\t Tipo de vehiculo : Vehiculo de carga "<<endl;
					}else if(temp->tipo==1){
						cout<<"\t Tipo de vehiculo : Vehiculo de pasajeros "<<endl;
					}
                }
                    temp = temp->der;
                    while (temp){
                        obj_pila.agregarPila(aux, temp);
                        temp = temp->izq;
                    }
                }

            }
	void buscarColor(ArbolBin *raiz,char marca[20]){
		Pila *aux, obj_pila;
		ArbolBin *temp = raiz;
		int c=0;
		obj_pila.iniciarPila(aux);

		while(temp){
			obj_pila.agregarPila(aux,temp);
			temp=temp->izq;
		}
		while(!obj_pila.pilaVacia(aux)){
			temp = obj_pila.retirarPila(aux);
			if(!strcmp(temp->color,marca)){
				c++;
				cout<<"COLOR ENCONTRADO\n";
				cout<<"\t Placa : "<<temp->placa<<endl;
				cout<<"\t Marca : "<<temp->marca<<endl;
				cout<<"\t Potencia : "<<temp->potencia<<endl;
				cout<<"\t Color : "<<temp->color<<endl;
				if(temp->tipo==0)
					cout<<"\t Tipo de vehiculo : Vehiculo de carga "<<endl;
				else if(temp->tipo==1)
					cout<<"\t Tipo de vehiculo : Vehiculo de pasajeros "<<endl;
            }
			temp = temp->der;
			while (temp){
				obj_pila.agregarPila(aux, temp);
				temp = temp->izq;
			}
			if(c==0)
				cout<<"NO COLOR \n";
		}
		cout<<"Cantidad total de vehiculos de color "<<marca<<" es "<<c<<endl;
    }
};
int main(){
	char placa[6],marca[20],color[20];
	int potencia,tv;
	bool tipo;//Carga 0 y pasajeros 1
	ArbolBin *raiz = NULL, obj_arbol,*aux;
 	cout << "Ingrese el primer vehiculo"<< endl;
	cout << "[Ingrese Placa]"<< endl;
	cin.getline(placa,7,'\n');
	for (int i=0;placa[i]!='\0'; ++i){//minusculas a matyusculas
		placa[i] = toupper(placa[i]);
	}
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
		tipo=false;
	else
 		tipo=true;
	obj_arbol.crearRaiz(raiz,placa,marca,color,potencia,tipo);
	system("pause");
	int opt,dato;
	do{
		fflush(stdin);
		system("cls");
		menu();
		cin>>opt;
		switch (opt){
		case 1: // [1].Mostrar Todo(inorden)
			obj_arbol.inorden(raiz);
			system("pause");		
			break;
		case 2: // [2].Consulta Placa			
			cout<<endl<<"INGRESE LA PLACA A BUSCAR\n";
				fflush(stdin);
				cout<<": ";
				cin.getline(placa,7,'\n');
		
					for (int i=0;placa[i]!='\0'; ++i){ //TRANSFORMA MINUSCULAS A MAYUSCULAS
						placa[i] = toupper(placa[i]);
					}

			obj_arbol.buscarPlaca(raiz,placa);
			system("pause");
			break;
		case 3: // [3].Cantidad de Vehiculos de color
			fflush(stdin);
			cout<<"COLOR A BUSCAR:"<<endl;
            cin.getline(marca,21,'\n');
            for (int i=0;marca[i]!='\0'; ++i){ //TRANSFORMA MINUSCULAS A MAYUSCULAS
                marca[i] = toupper(marca[i]);
            }
		    obj_arbol.buscarColor(raiz,marca);
			system("pause");
			break;
		case 4: // [4].Mostrar vehiculos de carga
			// cout << "[0].Vehiculo de carga" << endl;
			obj_arbol.mostrarTipoVehiculo(raiz,0);
			system("pause");
			break;
		case 5: // [5].Mostrar vehiculos de pasajeros	
			// cout << "[1].Vehiculo de pasajeros"<< endl;
			obj_arbol.mostrarTipoVehiculo(raiz,1);
			system("pause");
			break;
		case 6: // [6].Consultar por rango potencia(vehiculos que tiene la misma o mayor potencia)
			fflush(stdin);
			cout<<"INGRESE LA POTENCIA DEL VEHICULO A BUSCAR \n";
				cin>>potencia;
				obj_arbol.buscarPotencia(raiz,potencia);
			system("pause");
			break;
		case 7: // [7].Mostrar vehiculos por marca
			fflush(stdin);
			cout<<"MARCA A BUSCAR:"<<endl;
            cin.getline(marca,21,'\n');
            for (int i=0;marca[i]!='\0'; ++i){ //TRANSFORMA MINUSCULAS A MAYUSCULAS
                marca[i] = toupper(marca[i]);
            }
		    obj_arbol.buscarMarca(raiz,marca);
			system("pause");
			break;
		case 8: // [8].Agregar vehiculo			
			obj_arbol.agregarAuto(raiz);
			system("pause");
			break;
			break;
		case 9: // [9].Eliminar vehiculo			
			fflush(stdin);
			cout<<"PLACA A BUSCAR:"<<endl;
            cin.getline(placa,7,'\n');
            for (int i=0;placa[i]!='\0'; ++i){ //TRANSFORMA MINUSCULAS A MAYUSCULAS
                placa[i] = toupper(placa[i]);
            }
			obj_arbol.eliminarVehiculo(raiz,placa);
			system("pause");
			break;
		case 10: // [10].Salir 
			break;
		default: // ERROR EN OPCION
			cout << "Intentelo denuevo" << endl;
			system("pause");
			break;
		}
	} while (opt != 10);
	return 0;
}
