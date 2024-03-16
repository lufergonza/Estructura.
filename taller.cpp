#include <iostream>
#include <malloc.h>
/* LUISA FERNANDA GONZALEZ DELGADO*/
using namespace std;

struct temperatura{

    char mes[60];
    char dia[60];
    char year[60];
    double man;
    double tar;
    double noc;    
    corredor *sig;
    
};

corredor *cabeza, *aux,  *aux2;

void registrar(){

    if(!cabeza){
        cabeza=(struct temperatura *)malloc(sizeof(struct temperatura));
          cout<<"REGISTRO DE TEMPERATURA EN DIFERENTES HORAS DEL DIA "<<endl;
        cout<<"dia  ";
        cin>>cabeza->dia;
        cout<<"mes  ";
        cin>>cabeza->mes;
         cout<<"year ";
        cin>>cabeza->year;
         cout<<" digite la temperatura de la mañana ";
         cin>>cabeza->man;
          cout<<" digite la temperatura de la tarde ";
          cin>>cabeza->tar;
          cout<<" digite la temperatura de la noche ";
          cin>>cabeza->noc;
          

        
        cabeza->sig=NULL;
    }else{
        aux=cabeza;
        while(aux->sig!=NULL){
            aux = aux->sig;
        }

        aux2=(struct temperatura *)malloc(sizeof(struct temperatura));
        
        cout<<"REGISTRO DE TEMPERATURA EN DIFERENTES HORAS DEL DIA "<<endl;
        cout<<"dia ";
        cin>>aux2->dia;
        cout<<"mes  ";
        cin>>aux2->mes;
        cout<<"year ";
        cin>>aux2->year;
         cout<<" digite la temperatura de la mañana ";
         cin>>aux2->man;
          cout<<" digite la temperatura de la tarde ";
          cin>>aux2->tar;
          cout<<" digite la temperatura de la noche ";
          cin>>aux2->noc;
     
        aux2->sig=NULL;
        aux->sig=aux2;
        aux=aux2=NULL;
        free(aux);
        free(aux2);

    }

}


void todos(){

    for(aux = cabeza; aux!=NULL; aux=aux->sig){
        cout<<"----------------------------------------"<<endl;
        cout<<"fecha :"<<aux->dia; cout<<"/"<< aux->mes ; cout<<"/" <<aux->year<<endl;
        cout<<"temperatura de la mañana: "<<aux->man<<endl;
        cout<<"temperatura de la tarde: "<<aux->tar<<endl;
        cout<<"temperatura de la noche: "<<aux->noc<<endl;
    }
    free(aux);

}

void promedio(){

    double total=0, promedio =0, cantidad=3;

    for(aux = cabeza; aux!=NULL; aux=aux->sig){
        
        total = aux->man +aux->tar+ aux->noc;
    
    }
  
    promedio=total/cantidad;

    cout<<"el promedio del dia oy"<< promedio <<endl;
}
void promediototal(){
double num=3,promediot=0, total1=0,total2=0,total3=0,promedio1=0, promedio2=0, promedio=0, cantidad1=0, cantidadt=0,cantidadn=0,promedio3=0;

        for(aux = cabeza; aux!=NULL; aux=aux->sig){
        
        total1 += aux->man  ; 
        cantidad1++;
        total1 += aux-> tar ; 
        cantidadt++;
        total1 += aux->noc  ; 
        cantidadn++;
        
    }
 
     promedio1=total1/cantidad1;
     promedio2=total2/cantidadt;
     promedio3=total3/cantidadn;
promedio =promedio2+promedio1+promedio3;
promediot= promedio /num;
    cout<<"el promedio de todas las temperaturas es de = "<<  promediot;

}
int main(){

    int opc=0;
    do{

    cout<<"menu"<<endl;
    cout<<"1.registrar temperatura"<<endl;
    cout<<"2 mostrar"<<endl;
    cout<<"3.promedio"<<endl;
    cout<<"4.promedio total"<<endl;
    cout<<"6.salir"<<endl;
    cin>>opc;

        switch (opc)
        {
        case 1:registrar();
            break;
        
        case 2:todos();
            break;

        case 3:promedio();
            break;
            case 4:promediototal();

        default: cout<<"gracias por usar el programa"<<endl;
            break;
        }

    }while (opc!=6);

    return 0;
}
