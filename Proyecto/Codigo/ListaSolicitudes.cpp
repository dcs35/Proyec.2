#include "ListaSolicitudes.h"
#include "Solicitud.h"
ListaSolicitudes::ListaSolicitudes(){
    primero=nullptr;
    cantidad=0;
}
ListaSolicitudes::~ListaSolicitudes(){
    Nodo* actual=primero;
    while(actual!=nullptr){
        Nodo* temporal=actual;
        actual=actual->siguiente;
        delete temporal;
    }
    primero=nullptr;
}
bool ListaSolicitudes::agregar(Solicitud* dato){
    if(dato==nullptr){
        return false;
    }
    Nodo* nuevo=new Nodo(dato);
    if(primero==nullptr){
        primero=nuevo;
    }else{
        Nodo* actual=primero;
        while(actual->siguiente!=nullptr){
            actual=actual->siguiente;
        }
        actual->siguiente=nuevo;
    }
    cantidad++;
    return true;
}
bool ListaSolicitudes::estaVacia() const{
    return primero==nullptr;
}
int ListaSolicitudes::tamanio() const{
    return cantidad;
}
Solicitud* ListaSolicitudes::obtener(int indice) const{
    if(indice<0 || indice>=cantidad){
        return nullptr;
    }
    Nodo* actual=primero;
    int i=0;
    while(actual!=nullptr){
        if(i==indice){
            return actual->dato;
        }
        actual=actual->siguiente;
        i++;
    }
    return nullptr;
}

bool ListaSolicitudes::contiene(Solicitud* dato) const{
    Nodo* actual=primero;
    while(actual!=nullptr){
        if(actual->dato==dato){
            return true;
        }
        actual=actual->siguiente;
    }
    return false;
}
bool ListaSolicitudes::eliminar(Solicitud* dato){
    Nodo* actual=primero;
    Nodo* anterior=nullptr;
    while(actual!=nullptr){
        if(actual->dato==dato){
            if(anterior==nullptr){
                primero=actual->siguiente;
            }else{
                anterior->siguiente=actual->siguiente;
            }
            delete actual;
            cantidad--;
            return true;
        }
        anterior=actual;
        actual=actual->siguiente;
    }
    return false;
}
void ListaSolicitudes::mostrar() const{
    Nodo* actual=primero;
    while(actual!=nullptr){
        actual->dato->mostrar();
        actual=actual->siguiente;
    }
}
