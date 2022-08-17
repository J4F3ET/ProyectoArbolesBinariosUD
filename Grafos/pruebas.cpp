#include <iostream>
#include <string.h>
using namespace std;
class Lector{
    Lector *sig;
    char *dato;
    char *letra;
    public:
    void cabNueva(Lector *&cab,char *datos,char *letras){
        cab = new Lector;
        strcpy(cab->dato,datos);
        strcpy(cab->letra,letras);
        cout<<"Lista > "<<cab->dato<<endl;
        cout<<"Lista > "<<cab->letra<<endl;
    }
    void agregarnodo(Lector *&cab,char *datos){

    }
};
int main(){
    Lector obj,*cab=NULL;
    int size=20;
    char *dato=new char[size],p[]={"Privada"},opi[]={"PUBLICA"},op;
    strcpy(dato,p);
    cout<<"  >  "<<dato<<endl;
    obj.cabNueva(cab,dato,dato);
    cout<<"\t Modalidad de la universdiad:\n\t[1].Publica\n\t[2].Privada\n";
    cin>>op;
    if(op=='1'){
        strcpy(dato,opi);
    }else if(op=='2'){
        strcpy(dato,p);
    }
    if(strcmp(dato,opi)){
        cout<<"SI SI SON DISTINTOS"<<dato<<endl;
    }else{

    }
    cout<<" w >  "<<dato<<endl;
    delete [] dato;
    return 0;
}
