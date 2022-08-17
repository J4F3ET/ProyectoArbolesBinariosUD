#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
class Adyacente{
    int dato;
	Adyacente *sig;
	public:
		void crearCabAdyacente(Adyacente *&,int);
		void agregarAdyacente(Adyacente *&,int);
		void mostrarAdyacente(Adyacente *);
        void crearAdyacente(Adyacente *&);
		void eliminarDato(Adyacente *&,int);
		int buscarDato(Adyacente *,int);
};
class Vertice{
    char letra;
	Adyacente *frente;
	Vertice *sig;
	public:
		void crearCabVertice(Vertice *&,char);
		void agregarVerice(Vertice *&,char);
        void agregarAdyacenteVertice(Vertice *&,char);
        void crearVertice(Vertice *&);
		void mostrar(Vertice *);
        Vertice* buscar(Vertice *,char);
		void mostrarAdyacente(Vertice *,char);
		void eliminarAdyacente(Vertice *&,char);
		void eliminarVertice(Vertice *&,char);
		int buscarLetra(Vertice *,char);
};
void Vertice::crearCabVertice(Vertice *&cab,char letra){
	cab = new Vertice;
    cab->letra = letra;
	cab->frente=NULL;
	cab->sig = NULL;
}
void Vertice::agregarVerice(Vertice *&cab,char letra){
	Vertice *aux = cab;
	while(aux->sig){
		aux=aux->sig;
	}
	aux->sig = new Vertice;
	aux=aux->sig;
    aux->letra=letra;
	aux->frente=NULL;
	aux->sig=NULL; 
}
void Vertice::crearVertice(Vertice *&cab){
	char letra= 'A',opt;
	cout<<"Creandor de la Vertice(para finalizar escriba [*])"<<endl;
	cout<<"----------"<<endl;
	while (letra!='*'){
		cout<<"Vertice > ";
		cin>>letra;
		if(letra!='*'){
			if(!cab){
				crearCabVertice(cab,letra);
			}else{
				agregarVerice(cab,letra);
			}
		}
	}
}
Vertice* Vertice::buscar(Vertice *cab,char letra){
	Vertice *aux = cab;
	while(aux){
		if(aux->letra==letra)
			return aux;
		aux=aux->sig;
	}
    return aux;
}
void Vertice::agregarAdyacenteVertice(Vertice *&cabV,char letra){
    Vertice *auxV;
    Adyacente obj;
	auxV=buscar(cabV,letra);
	if(auxV){
		if(!auxV->frente){
			obj.crearAdyacente(auxV->frente);
		}else{
			int dato=666;
			cout<<"Creando adyacente(para finalizar escriba [-1])"<<endl;
			cout<<"----------"<<endl;						
			while(dato!=-1){
				cout<<"Adyacente > ";
				cin>>dato;
				if(dato!=-1){
					obj.agregarAdyacente(auxV->frente,dato);
				}
			}
		}
	}else{
		cout<<"Vertice no encontrado..."<<endl;
	}
    
}
void Vertice::mostrar(Vertice *cab){
	Vertice*aux=cab;
	cout<<"--------------"<<endl;
	cout<<"Vertices =>|";
	while(aux){
		cout<<aux->letra<<"|";
		aux=aux->sig;
	}
	cout<<"\n--------------"<<endl;
}
void Vertice::mostrarAdyacente(Vertice *cab,char letra){
	Vertice *aux;
	aux=buscar(cab,letra);
	if(aux)
		aux->frente->mostrarAdyacente(aux->frente);
	else
		cout<<"Vertice no encontrado..."<<endl;

}
int Vertice::buscarLetra(Vertice *cab,char letra){
	int busqueda=0;
        Vertice *aux=cab;
        while(aux){
            if(aux->letra==letra)
                busqueda++;
            aux= aux->sig;
        }
        return busqueda;
}
void Vertice::eliminarAdyacente(Vertice *&cab,char letra){
	Vertice *aux;
	aux=buscar(cab,letra);
	if(aux){
		int dato;
		cout<<"Escriba el dato que decea eliminar del vertice"<<endl;
		cin>>dato;
		aux->frente->eliminarDato(aux->frente,dato);
	}else
		cout<<"Vertice no encontrado..."<<endl;
}
void Vertice::eliminarVertice(Vertice *&cab,char letra){
	Vertice *aux,*aux1;
	int busqueda;
	busqueda=buscarLetra(cab,letra);
	if(busqueda!=0){//Si la busqueda tiene resultados entonces borrara
		for(int i=0;i<busqueda;i++){//Se van aborrar la cantidad de nodos hasta que no se encuentren
			aux1=aux=cab;//auxiliares en la cabeza
			while(aux->letra!=letra){//Si el auxiliar se encuentra en un nodo donde no es el letra va seguir avanzando hasta tener el letra
				aux1=aux;
				aux= aux->sig;
			}
			if(aux->frente)
				aux->frente=NULL;
			if(aux->letra==letra&&aux!=cab){//Filtro, para confirmar que aux esta en el letra Y aux no es la cabeza
				aux1->sig=aux->sig;//Enlazamos el auxliar anterior(aux1) a la parte siguiente del auxiliar actual(aux)
			}else{//En el caso de que el letra sea la cabeza o el ultimo nodo
				if(aux->letra==letra&&aux==cab){//Si, letra esta en la cabeza Y aux esta en la cabeza
					cab=aux->sig;//Moveos la cabeza
				}else{
					if (aux->sig==cab&&aux->letra==letra){//Si, es el ultimo nodo
						aux1->sig=NULL;//Enlazamos el ante penultimo nodo con la cabeza  ->
					}
				}
			}
		}
		delete aux;
		cout<<"Vertice: "<<letra<<" eliminado exitosamente."<<endl;
	}else{//La busqueda dio 0, etonces no existe el dato en la lista
		cout<<"Este dato no se encuentra en la lista"<<endl;
	}
}
void Adyacente::crearCabAdyacente(Adyacente *&cab,int dato){
	cab = new Adyacente;
    cab->dato = dato;
	cab->sig = NULL;
}
void Adyacente::agregarAdyacente(Adyacente *&cab,int dato){
	Adyacente *aux = cab;
	while(aux->sig){
		aux=aux->sig;
	}
	aux->sig = new Adyacente;
	aux=aux->sig;
    aux->dato=dato;
	aux->sig=NULL; 
}
void Adyacente::crearAdyacente(Adyacente *&cab){
	int dato = 666;
	cout<<"Creando adyacente(para finalizar escriba [-1])"<<endl;
	cout<<"----------"<<endl;
	while(dato!=-1){
		cout<<"Adyacente > ";
		cin>>dato;
		if(dato!=-1){			
			if(!cab){
				crearCabAdyacente(cab,dato);
			}else{
				agregarAdyacente(cab,dato);
			}
		}
	}
}
void Adyacente::mostrarAdyacente(Adyacente *cab){
	Adyacente*aux=cab;
	cout<<"--------------"<<endl;
	while(aux){
		cout<<"Adyacente = "<<aux->dato<<endl;
		aux=aux->sig;
	}
	cout<<"--------------"<<endl;
}
int Adyacente::buscarDato(Adyacente *cab,int dato){
	int busqueda=0;
        Adyacente *aux=cab;
        while(aux){
            if(aux->dato==dato)
                busqueda++;
            aux= aux->sig;
        }
        return busqueda;
}
void Adyacente::eliminarDato(Adyacente *&cab,int dato){
	Adyacente *aux1,*aux;
	int busqueda;
	busqueda=buscarDato(cab,dato);
	if(busqueda!=0){//Si la busqueda tiene resultados entonces borrara
		for(int i=0;i<busqueda;i++){//Se van aborrar la cantidad de nodos hasta que no se encuentren
			aux1=aux=cab;//auxiliares en la cabeza
			while(aux->dato!=dato){//Si el auxiliar se encuentra en un nodo donde no es el dato va seguir avanzando hasta tener el dato
				aux1=aux;
				aux= aux->sig;
			}
			if(aux->dato==dato&&aux!=cab){//Filtro, para confirmar que aux esta en el dato Y aux no es la cabeza
				aux1->sig=aux->sig;//Enlazamos el auxliar anterior(aux1) a la parte siguiente del auxiliar actual(aux)
			}else{//En el caso de que el dato sea la cabeza o el ultimo nodo
				if(aux->dato==dato&&aux==cab){//Si, dato esta en la cabeza Y aux esta en la cabeza
					cab=aux->sig;//Moveos la cabeza
				}else{
					if (aux->sig==cab&&aux->dato==dato){//Si, es el ultimo nodo
						aux1->sig=NULL;//Enlazamos el ante penultimo nodo con la cabeza  ->
					}
				}
			}
		}
		delete aux;
		cout<<"Dato: "<<dato<<" eliminado exitosamente."<<endl;
	}else{//La busqueda dio 0, etonces no existe el dato en la lista
		cout<<"Este dato no se encuentra en la lista"<<endl;
	}
}
void letrero(){
	cout<<"*---------------------------------------*"<<endl;
	cout<<"*---------------Bienvenido--------------*"<<endl;
	cout<<"*---------------------------------------*"<<endl;
}
void finDelPrograma(){
	cout<<"*---------------------------------------*"<<endl;
	cout<<"*-----------Fin del programa------------*"<<endl;
	cout<<"*---------------------------------------*"<<endl;
}
int menu(int opt){
	cout<<"Escoja una opcion\n [1].Agregar vertice \n [2].Agregar adyacente\n [3].Mostrar Vertice\n [4].Mostrar Adyacente\n [5].Eliminar Vertice\n [6].Eliminar Adyacente\n [7].Salir\n->";
	cin>>opt;
	return opt;
}
int main(){
// INICIO DEL PROGRAMA
	letrero();
    setlocale(LC_ALL, "");
	Vertice objetoV, *cab=NULL;
	objetoV.crearVertice(cab);
	int opt,aux;
    char letra;
// SECCION DE APLICACION
	do{
		fflush;
		system("cls");
		opt=menu(opt);
		switch (opt){
		case 1://[1].Agregar vertice
		cout<<"Digite la letra del vertice"<<endl;
			cin>>letra;
			objetoV.agregarVerice(cab,letra);
			system("pause");
			break;
		case 2://[2].Agregar adyacente
			cout<<"Digite el vertice al cual quiere agregar adyacentes"<<endl;
			objetoV.mostrar(cab);
			cin>>letra;
			objetoV.agregarAdyacenteVertice(cab,letra);
            system("pause");
			break;
		case 3://[3].Mostrar Vertice
            objetoV.mostrar(cab);
            system("pause");
			break;
		case 4://[4].Mostrar Adyacente
			cout<<"Digite el vertice al cual quiere mostrar su adyacente"<<endl;
			objetoV.mostrar(cab);
			cin>>letra;
			objetoV.mostrarAdyacente(cab,letra);
            system("pause");
			break;
		case 5://[5].Eliminar Vertice
			cout<<"Digite el vertice que quiere eliminar"<<endl;
			objetoV.mostrar(cab);
			cin>>letra;
			objetoV.eliminarVertice(cab,letra);
            system("pause");
			break;
		case 6://[6].Eliminar Adyacente
			cout<<"Digite el vertice al cual quiere eliminar su dato adyacente"<<endl;
			objetoV.mostrar(cab);
			cin>>letra;
			objetoV.eliminarAdyacente(cab,letra);
            system("pause");
			break;
		case 7://[7].Salir
            system("pause");
			break;
		default:
			cout<<"Opcion incorrecta\nPor favor intentelo denuevo."<<endl;
			opt=4;
			system("pause");
			break;
		}
	}while(opt!=7);
// FIN DE SECCION DE APLICACION
    finDelPrograma();//FIN DEL PROGRAMA :V
}