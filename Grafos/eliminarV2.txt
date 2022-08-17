#include <iostream>
#include <stdlib.h>
using namespace std;
class ArbolBin;
class Pila;
class Pila{
	ArbolBin *dato;
	Pila *sig;

public:
	void iniciarPila(Pila *&cab)
	{
		cab = new Pila;
		cab->dato = NULL;
		cab->sig = NULL;
	}
	bool pilaVacia(Pila *cab)
	{
		if (!cab->sig)
			return true;
		else
			return false;
	}
	void agregarPila(Pila *&cab, ArbolBin *dato)
	{
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
		if (!pilaVacia(aux))
		{
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
	ArbolBin *izq, *der;

public:
	int dato;
	void crearRaiz(ArbolBin *&raiz, int dato){
		raiz = new ArbolBin;
		raiz->dato = dato;
		raiz->izq = NULL;
		raiz->der = NULL;
	}
	void agregarIzq(ArbolBin *&temp,int dato){
		ArbolBin *nuevo;
		nuevo = new ArbolBin;
		nuevo->dato = dato;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		temp->izq = nuevo;
	}
	void agregarDer(ArbolBin *&temp, int dato){
		ArbolBin *nuevo;
		nuevo = new ArbolBin;
		nuevo->dato = dato;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		temp->der = nuevo;
	}
	void crearArbol(ArbolBin *&raiz){
		ArbolBin *temp1, *temp2;
		int dato = 666;
		while (dato != -1)
		{
			cout << "Dato > ";
			cin >> dato;
			if (dato != -1){
				if (!raiz){
					crearRaiz(raiz, dato);
				}else{
					temp1 = temp2 = raiz;
					while (temp2 && temp1->dato != dato){
						temp1 = temp2;
						if (dato < temp1->dato)
							temp2 = temp2->izq;
						else
							temp2 = temp2->der;
					}
					if (temp1->dato == dato){
						cout << "Numero repetido" << endl;
					}else{
						if (dato < temp1->dato)
							agregarIzq(temp1, dato);
						else
							agregarDer(temp1, dato);
					}
				}
			}
		}
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
			cout << "Dato = " << temp->dato << endl;
			temp = temp->der;
			while (temp)
			{
				obj_pila.agregarPila(aux, temp);
				temp = temp->izq;
			}
		}
	}
	void mostrarArbol(ArbolBin *raiz, int contador){
		if (raiz != NULL)
		{
			mostrarArbol(raiz->der, contador + 1);
			for (int i = 0; i < contador; i++)
			{
				cout << "  ";
			}
			cout << raiz->dato << endl;
			mostrarArbol(raiz->izq, contador + 1);
		}
	}
	void preOrden(ArbolBin *raiz){
		if(raiz){
			cout<<raiz->dato<<"-";
			preOrden(raiz->izq);
			preOrden(raiz->der);
		}
	}
	void posOrden(ArbolBin *raiz){
		if(raiz){
			posOrden(raiz->izq);
			posOrden(raiz->der);
			cout <<raiz->dato<<"-";
		}
	}
	ArbolBin *buscar(ArbolBin *raiz,int dato){
		Pila *aux, obj_pila;
		ArbolBin *temp = raiz;
		obj_pila.iniciarPila(aux);
		while(temp){
			obj_pila.agregarPila(aux,temp);
			temp=temp->izq;
		}
		while(!obj_pila.pilaVacia(aux)){
			temp = obj_pila.retirarPila(aux);
			if(temp->dato==dato)
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
	void nodosEspeciales(ArbolBin *raiz,int ord){
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
			if(ord==0){
				if(calcularNivel(temp)==ord){
					cout<<"Nodo Hoja > "<<temp->dato<<endl;
				}
			}else{
				if(calcularNivel(temp)!=0){
					cout<<"Nodo No Terminal > "<<temp->dato<<endl;
				}
			}
			temp = temp->der;
			while (temp)
			{
				obj_pila.agregarPila(aux, temp);
				temp = temp->izq;
			}
		}
	}
	int pesoNodo(ArbolBin *raiz,int dato){
		int peso=-1;
		ArbolBin *temp;
		temp=buscar(raiz,dato);
		if(temp){
			Pila *aux, obj_pila;
			obj_pila.iniciarPila(aux);
			while (temp)
			{
				obj_pila.agregarPila(aux, temp);
				temp = temp->izq;
			}
			while (!obj_pila.pilaVacia(aux))
			{
				temp = obj_pila.retirarPila(aux);
				peso++;
				temp = temp->der;
				while (temp)
				{
					obj_pila.agregarPila(aux, temp);
					temp = temp->izq;
				}
			}
		}else{
			cout<<"Nodo no encontrado"<<endl;
		}
		return peso;
	}
	int alturaNodo(ArbolBin *raiz){
		int altura=0,x=-1,y=-1;
		if(calcularNivel(raiz)!=0){
			if(raiz->der!=NULL)
				x=alturaNodo(raiz->der);
			if(raiz->izq!=NULL)
				y=alturaNodo(raiz->izq);
		}	
		return 1+max(x,y);
	}
    ArbolBin *padre(ArbolBin *raiz,int dato){
        ArbolBin *aux,*aux2,*aux3;
        aux2=aux=raiz;
        aux3=buscar(raiz,dato);
        if(raiz->dato==dato){
            aux2=aux=NULL   ;
        }else{  
            while(aux2->dato!=dato){
                aux=aux2;
                if(aux2->dato>dato)
                    aux2=aux2->izq;
                else
                    aux2=aux2->der;
            }
            if(!aux3->der&&!aux3->izq){
                while(aux2->der||aux2->izq){
                aux=aux2;
                if(aux2->dato>dato)
                    aux2=aux2->izq;
                else
                    aux2=aux2->der;
                }
            }
        }
        return aux;
    }
    void eliminarVehiculo(ArbolBin *&raiz,int dato){
        ArbolBin *aux,*aux2,*aux3;
        cout<<"Bandera 1"<<endl;
        aux=buscar(raiz,dato);
        cout<<"Bandera 2"<<endl;
        aux2=padre(raiz,dato);
        cout<<"Bandera 3"<<endl;
        if(aux){//AUX EXISTE ENTONCES==EXITSE DATO
            cout<<"Bandera 4"<<endl;
                if(dato==raiz->dato){//BORRA RAIZ
                cout<<"Bandera 5"<<endl;
                    if(raiz->der){
                        aux2=raiz->der;//SI NUEVA RAIZ ES LA DERECHA-> MUEVE AUX A LA DER
                        while(aux2->izq)//DETECTA SI EN LA PARTE IZQ DEL ARBOL EXITE UN NODO---REPITE HASTA NO EXITIR PERO NO SE UBICA EN NULLO
                            aux2=aux2->izq;
                        aux2->izq=raiz->izq;//CONECTA AUX IZQ CON LA RAIZ IZQ, PARA GUARDAR LA PARTE IZQ DE LA RAIZ Y NO BORRARLA
                        aux2=raiz->der;
                    }else{
                        aux2=raiz->izq;
                    }
                    aux=raiz;
                    raiz=aux2;
                    //fin de aislar raiz
                    cout<<"Raiz eliminada con exito... :)"<<endl;
            }else if(aux->der||aux->izq){//BORRA NODO NO TERMINALES
                cout<<"Bandera 5 nodo no terminal"<<endl;
                if(aux->der&&aux->izq){//Nodo a eliminar tiene dos hijos
                    cout<<"Bandera 6 nodo de dos hijos"<<endl;
                    if(raiz->dato>dato){//Nodo a eliminar esta por izquierda a la raiz
                        aux3=aux->izq;//Establece el sucesor

                        while(aux3->der)
                            aux3=aux->der;
                        aux3->der=aux->der;
                        
                        if(aux2->izq==aux){
                            aux2->izq=aux3;
                        }else
                            aux2->der=aux3;

                    }else{//Nodo a eliminar este por derecha a la raiz
                        aux3=aux->der;
                        while(aux3->der)
							aux3=aux->der;
                        aux3->izq=aux->izq;

                        if(aux2->izq==aux){
                            aux2->izq=aux3;
                        }else
                            aux2->der=aux3;

                    }
                    cout<<"bandera"<< endl;
                }else{//Nodo a eliminar tiene solo un hijo
                    cout<<"Bandera 6 nodo solo un hijo"<<endl;
                    if(aux->izq&&!aux->der){//Nodo a eliminar tiene hijo por izquierda
                        aux2->izq=aux->izq;
                    }else{
                        aux2->der=aux->der; 
                    }
                }
            }else{//BORRA NODOS TERMINALES
                cout<<"Bandera 5 nodo terminal"<<endl;  
                if(aux2->der==aux){//Hijo por derecha
                    cout<<"BANDERA DETECTA NODO HIJO POR DERECHA"<<endl;
                    aux2->der=NULL;
                }else{//Hijo de papa por iquierda
                    cout<<"BANDERA DETECTA NODO HIJO POR IZQUIERDA"<<endl;
                    aux2->izq=NULL;
                }
            }
            aux->der=aux->izq=NULL;
            delete aux;
            cout<<"Nodo eliminado con exito... :)"<<endl;
        }else
            cout<<"Nodo no existir ...  :("<<endl;
        fflush;
    }
    void conocerPadre(ArbolBin *raiz,int dato){
        ArbolBin *aux;
        aux=padre(raiz,dato);
        cout<<"Padre >"<<aux->dato<<endl;
    }
};
void menu(){
	cout << "Menu de opciones" << endl;
	cout << "[1].Mostrar Inorden" << endl;
	cout << "[2].ELIMINAR VEHICULO" << endl;
	cout << "[3].Mostrar Posorden" << endl;
	cout << "[4].Mostrar nodos no terminales" << endl; 
	cout << "[5].Mostrar nodos terminales" << endl; 
	cout << "[6].SUCESOR PADRE Y NODO" << endl; 
	cout << "[7].Altura del arbol" << endl; 
	cout << "[8].Eliminar DATO" << endl; 
	cout << "[9].CONOCER A PAPA" << endl;
	cout << "[10].Cual es la longitud entre dos nodos" << endl;
	cout << "[11].Buscar y mostrar nivel" << endl;
	cout << "[12].Mostrar Arbol" << endl;
	cout << "[13].Salir" << endl;
}
int main(){
	ArbolBin *raiz = NULL, obj_arbol,*aux;
	cout<<"8-3-1-6-4-7-10-14-13"<<endl;
	obj_arbol.crearArbol(raiz);
	int opt,dato;
	do{
		fflush;
		system("cls");
		menu();
		cin >> opt;
		switch (opt){
		case 1: // MOSTRAR INORDEN
			obj_arbol.inorden(raiz);
			system("pause");
			break;
		case 2: // MOSTRAR PREORDEN
            fflush;
            cin>>dato;
			obj_arbol.eliminarVehiculo(raiz,dato);
			system("pause");
			break;
		case 3: // MOSTRAR POSORDEN
			obj_arbol.posOrden(raiz);
			system("pause");
			break;
		case 4: // MOSTRAR NODOS NO TERMINALES EN INORDEN
			obj_arbol.nodosEspeciales(raiz,1);
			system("pause");
			break;
		case 5: // MOSTRAR NODOS TERMINALES
			obj_arbol.nodosEspeciales(raiz,0);
			system("pause");
			break;
		case 6: // MOSTRAR PESO DEL NODO
			system("pause");
			break;
		case 7: // ALTURA DEL ARBOL
			dato=obj_arbol.alturaNodo(raiz);
			cout<<"Altura >"<<dato<<endl;
			system("pause");
			break;
		case 8: // DETERMINAR CAMINO ENTRE NODOS
			fflush(stdin);
			system("pause");
			break;
		case 9: // DETERMINE LA LONGITUD DEL NODO
			cin>>dato;
			obj_arbol.conocerPadre(raiz,dato);  
			system("pause");
			break;
		case 10: // DETERMINE LA LONGITUD ENTRE NODOS
			break;
		case 11://BUSCAR Y MOSTRAR EL NIVEL
			cout<<"Digite el dato que quiere buscar > ";
			cin>>dato;
			aux=obj_arbol.buscar(raiz,dato);
			if(aux){
				dato=obj_arbol.calcularNivel(aux);
				cout<<"**Nodo encontrado**\nNivel del nodo >"<<dato<<endl;
			}else{
				cout<<"No se encontro el dato en el arbol"<<endl;
			}
			system("pause");
			dato=0;
			break;
		case 12: //MOSTRAR ARBOL
			obj_arbol.mostrarArbol(raiz, 0);
			system("pause");
			break;
		case 13: //SALIR DEL PROGRAMA
			break;
		default: // ERROR EN OPCION
			cout << "Intentelo denuevo" << endl;
			system("pause");
			break;
		}
	} while (opt != 13);
	return 0;
}
