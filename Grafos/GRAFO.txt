#include<iostream>
#include<string.h>
using namespace std;
int t=20;
void bandera(int i){
	cout<<"BANDERA  "<< i<<endl;
}
void menu(){
	cout<<"*---------------------------------------------------------------*"<<endl;
    cout<<"*---------------------------Bienvenido--------------------------*"<<endl;
	cout<<"*---------------------------------------------------------------*"<<endl;
	cout<<"[1].Agregar Universidad"<<endl;
	cout<<"[2].Agregar Programa"<<endl;
	cout<<"[3].Eliminar Universidad"<<endl;
	cout<<"[4].Eliminar Programa"<<endl;
	cout<<"[5].Mostrar Universidades"<<endl;
	cout<<"[6].Mostrar Universidad"<<endl;
	cout<<"[7].Mostrar Programas de la universdiad"<<endl;
	cout<<"[8].Consulta programa en todo el grafo"<<endl;
	cout<<"[9].Mostrar todas las universidades(Publica o Privada)"<<endl;
	cout<<"[10].Mostrar programa por modalidad(Presencial o Virtual)"<<endl;
	cout<<"[11].Salir"<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
}
class Programa{ //	PREGRADOS
	long int codigo;
	short int semestre;
	char *nombre,*modalidad;
	Programa *sig;
	
	public:
		void crearCabAd(Programa *&cab,long int codigo,char nombre[],char modalidad[],short int semestre){ //Crear la cabeza de Programa //pregrado
			cab=new Programa;
			cab->nombre=new char[t];
			cab->modalidad=new char[t];
			cab->codigo=codigo;
			cab->semestre=semestre;
			strcpy(cab->nombre,nombre);
			strcpy(cab->modalidad,modalidad);
			cab->sig=NULL;
		}
		void agregarNodoAdya(Programa *&cab,long int codigo,char nombre[],char modalidad[],short int semestre){
			Programa *aux=cab;
			while(aux->sig!=NULL)
				aux=aux->sig;
			aux->sig=new Programa;
			aux=aux->sig;
			aux->nombre=new char[t];
			aux->modalidad=new char[t];
			aux->codigo=codigo;
			aux->semestre=semestre;
			strcpy(aux->nombre,nombre);
			strcpy(aux->modalidad,modalidad);
			aux->sig=NULL;
		}
		Programa* buscarP(Programa *cab,long int codigo){
			Programa *aux=NULL,*aux2=cab;
			while(aux2){
				if(aux2->codigo==codigo)
					aux=aux2;
				aux2=aux2->sig;
			}
			return aux;
		}
		void crearPrograma(Programa *&cab){
			int op;
			long int codigo;
			short int semestre;
			char nombre[t],modalidad[t],vi[]={"Virtual"},pre[]={"Presencial"};
			cout<<"Registrando programas...\n";
			do{
				fflush(stdin);
				cout<<"Nombre del programa : ";
				gets(nombre);
				cout<<"Codigo del programa : ";
				cin>>codigo;
				cout<<"Semestre del programa: ";
				cin>>semestre;
				cout<<"Modalidad del programa:\n[1].Presencial\n[2].Virtual\n>";
				cin>>op;
				if(op==1){
					strcpy(modalidad,pre);
				}else{
					strcpy(modalidad,vi);
				}
				if(!cab){
					crearCabAd(cab,codigo,nombre,modalidad,semestre);
				}else{
					Programa *aux=cab;
					aux=buscarP(cab,codigo);
					if(!aux){
						agregarNodoAdya(cab,codigo,nombre,modalidad,semestre);
					}else{
						cout<<"	Codigo ya registrado... :("<<endl;
					}
				}
				cout<<endl<<"Desea seguir ingresando mas programas \n";
					cout<<"1) Si \n";
					cout<<"2) No \n";
					cin>>op;
					
			}while(op==1);
		}
		void mostrarAdy(Programa *cab){
			Programa *aux=cab;
			while(aux){
				cout<<"\t\t---------------------------------\n";
				cout<<"\t\t Nombre del programa : "<<aux->nombre<<endl;
				cout<<"\t\t Codigo del programa : "<<aux->codigo<<endl;
				cout<<"\t\t Semestre del programa : "<<aux->semestre<<endl;
				cout<<"\t\t Modalidad del programa : "<<aux->modalidad<<endl;
				cout<<"\t\t---------------------------------\n";				
				cout<<endl;
				aux=aux->sig;
			}
		}
		void eliminarProgramaALL(Programa *&cab){
			Programa *aux=cab;
			while(cab){
				aux=cab;
				cab=cab->sig;
				delete aux;
			}
		}
		void eliminarPrograma(Programa *&cab,long int codigo){
			Programa *aux=cab,*aux2=NULL;
			while(aux&&aux->codigo!=codigo){
				aux2=aux;
				aux=aux->sig;
			}
			if(aux){
				if(aux==cab){//CABEZA DE LA LISTA
					cab=aux->sig;
					aux->sig=NULL;
				}else if(aux->sig){//NODO MEDIO DE LA LISTA
					aux2->sig=aux->sig;
					aux->sig=NULL;
				}else{//COLA DE LA LISTA
					aux2->sig=NULL;
				}
				delete aux;
			}else
				cout<<"Codigo no encontrado... :("<<endl;
		}
};
class Universidad{ //UNIVERSIDADES
	char *nombre,*caracter;
	long int nit;
	Universidad *abajo;
	Programa *frente;
	public:
		void crearCabVer(Universidad *&cab,char nombre[],char caracter[],long int nit){
			cab=new Universidad;
			cab->nombre=new char[t];
			cab->caracter=new char[t];
			cab->nit = nit;
			strcpy(cab->nombre,nombre);
			strcpy(cab->caracter,caracter);
			cab->abajo=NULL;
			cab->frente=NULL;
			cout<<"NIT  "<<cab->nit<<endl;
			cout<<"nombre  "<<cab->nombre<<endl;
			cout<<"caracter  "<<cab->caracter<<endl;
		}
		void agregarNodoUniversidad(Universidad *&cab,char nombre[],char caracter[],long int nit){
			Universidad *aux=cab;
			while(aux->abajo){
				aux=aux->abajo;
			}
			aux->abajo=new Universidad;
			aux=aux->abajo;
			aux->nombre=new char[t];
			aux->caracter=new char[t];
			aux->nit=nit;
			strcpy(aux->nombre,nombre);
			strcpy(aux->caracter,caracter);
			aux->abajo=NULL;
			aux->frente=NULL;
		}
		Universidad* buscarU(Universidad *cab,long int nit){
			Universidad *aux=NULL,*aux2=cab;
			while(aux2){
				if(aux2->nit==nit)
					aux=aux2;
				aux2=aux2->abajo;
			}
			return aux;
		}
		void crearUniversidad(Universidad *&cab){
			int op;
			long int nit;
			char nombre[t];
			char caracter[t];
			fflush(stdin);
			cout<<"Escriba [.] en el nombre de la universidad para finalizar el registro\n";
			cout<<"Registrando universidades... \n";
			while(nombre[0]!='.'){
				cout<<"Nombre de la universdiad : ";
				cin.getline(nombre,t,'\n');
				if(nombre[0]!='.'){
					cout<<"Modalidad de la universdiad(publica o privada):\n[1].Publica\n[2].Privada\n>";
					cin>>op;
					if(op==1){
						char p[]="Publica";
						strcpy(caracter,p);
					}else{
						char p[]="Privada";
						strcpy(caracter,p);
					}
					cout<<"NIT de la universdiad : ";
					cin>>nit;
					if(!cab){
						crearCabVer(cab,nombre,caracter,nit);
					}else{
						Universidad *aux;
						aux=buscarU(cab,nit);
						if(!aux)
							agregarNodoUniversidad(cab,nombre,caracter,nit);
						else
							cout<<"NIT ya registrado... :("<<endl;
						system("pause");
					}
				}
				fflush(stdin);	
			}
		}
		void agregarAyacenteVer(Universidad *&cab,long int nit){ //Agregar un adyacente en el parte frente del Universidad
			Programa A1;
			Universidad *aux;
			aux=buscarU(cab,nit);
			if(!aux)
				cout<<"\t NIT no existir... :( \a"<<endl;
			else
				A1.crearPrograma(aux->frente);
		} 
		void mostrarUniversidades(Universidad *cab){
			Universidad *aux=cab;
			Programa A1;
			while(aux){
				cout<<"----------------------------------"<<endl;
				cout<<"Nombre : "<<aux->nombre<<endl;
				cout<<"NIT : "<<aux->nit<<endl;
				cout<<"Caracter : "<<aux->caracter<<endl;
				if(aux->frente){
					cout<<"-------------------"<<endl;
					cout<<"Programas : "<<endl;
					A1.mostrarAdy(aux->frente);
					cout<<"-------------------"<<endl;
				}else{
					cout<<"-------------------"<<endl;
					cout<<"No tiene programas "<<endl;
					cout<<"-------------------"<<endl;
				}
				cout<<"----------------------------------"<<endl;
				aux=aux->abajo;
			}
		}
		void eliminarUniversidad(Universidad *&cab,long int nit){
			Universidad *aux=cab,*aux2=NULL;
			Programa A1;
			while(aux&&aux->nit!=nit){
				aux2=aux;
				aux=aux->abajo;
			}
			if(aux){
				if(aux==cab){
					cab=aux->abajo;
					aux->abajo=NULL;
				}else if(aux->abajo){
					aux2->abajo=aux->abajo;
					aux->abajo=NULL;
				}else
					aux2->abajo=NULL;
				A1.eliminarProgramaALL(aux->frente);
				delete aux;
				cout<<"Universidad eliminada exitosamente... :)"<<endl;
			}else
				cout<<"NIT no encontrado... :("<<endl;
		}
		void eliminarPrograma(Universidad *&cab,long int nit,long int codigo){
			Universidad *aux;
			Programa A1;
			aux=buscarU(cab,nit);
			if(aux){
				A1.eliminarPrograma(aux->frente,codigo);
				cout<<"Programa eliminado exitosamente... :)"<<endl;
			}else
				cout<<"NIT no encontrado... :("<<endl;
		}
};
int main(){	
	int opt;
	long int nit,codigo;
	Universidad obj,*cab=NULL;
	obj.crearUniversidad(cab);
	do{
		system("cls");
		fflush(stdin);
		menu();
		cout<<">";
		cin>>opt;
		switch(opt){
		case 1://[1].Agregar Universidad
			obj.crearUniversidad(cab);
			system("pause");
			break;
		case 2://[2].Agregar Programa
			cout<<"Digite NIT de la universidad: ";
			cin>>nit;
			obj.agregarAyacenteVer(cab,nit);
			system("pause");
			break;
		case 3://[3].Eliminar Universidad
			cout<<"Digite NIT de la universidad: ";
			cin>>nit;
			obj.eliminarUniversidad(cab,nit);
			system("pause");
			break;
		case 4://[4].Eliminar Programa
			cout<<"Digite NIT de la universidad: ";
			cin>>nit;
			cout<<"Digite Codigo del programa: ";
			cin>>codigo;
			obj.eliminarPrograma(cab,nit,codigo);
			system("pause");
			break;
		case 5://[5].Mostrar Universidades
			obj.mostrarUniversidades(cab);
			system("pause");
			break;
		case 6://[6].Mostrar Universidad
			
			system("pause");
			break;
		case 7://[7].Mostrar Programas de la universdiad
			
			system("pause");
			break;
		case 8://[8].Consulta programa en todo el grafo
			
			system("pause");
			break;
		case 9://[9].Mostrar todas las universidades(Publica o Privada
			
			system("pause");
			break;
		case 10://[10].Mostrar programa por modalidad(Presencial o Virtual
			
			system("pause");
			break;
		case 11://[11].Salir
			break;
		default:
			break;
		}
	}while(opt!=11);
}
