#include "lista.h"
#include<string>
#include "Concesionaria.h"
#include "Auto.h"
#include <cstddef>
using namespace std;

template <typename T>
lista<T>::lista(){
    primero=NULL;
    //ctor
}
template <typename T>
lista<T>::~lista(){
    //Tenemos que eliminar todos los punteros al heap con un while
    //dtor
}

template <typename T>
void lista<T>::agregar_principio(const T & elemento){
    Nodo * nuevo = new Nodo();
    nuevo->elemento=elemento;
    nuevo->sig=primero;
    primero= nuevo;
}

template <typename T>
void lista<T>::agregar_elemento(int posicion,const T & nuevo_elemento){
    //la lista esta vacia
    if(posicion == 1)
        agregar_principio(nuevo_elemento);
    //la lista tiene elementos
    else{
        if(primero != NULL){
            if(cantidad_elementos()+1 >= posicion){
                int contador=2;//empieza en 2 porque me hace ir un nodo atrasado y puedo insertar bien
                Nodo * aux = primero;
                while((aux->sig!=NULL)and(contador<posicion)){
                    aux=aux->sig;
                    contador++;
                }
                Nodo*aux2=new Nodo();
                aux2->elemento=nuevo_elemento;
                aux2->sig=aux->sig;
                aux->sig=aux2;
            }
        }
    }
}

template <typename T>
bool lista<T>::listavacia(){
    if (primero == NULL)
        return true;
    else
        return false;
}

template <typename T>
int lista<T>::cantidad_elementos(){
    if(primero!=NULL){
        Nodo*aux = NULL;
        aux=primero;
        int contador=0;
        while(aux!=NULL){
            contador++;
            aux=aux->sig;
        }
        return contador;
    }
    else
        return 0;
}

template class lista<string>;
template class lista<Concesionaria>;
template class lista<Auto>;
