#include "ListaCentros.h"
#include <iostream>
using namespace std;
ListaCentros::ListaCentros() {
    primero=nullptr;
}
ListaCentros::~ListaCentros() {
    Nodo* actual=primero;
  
    while (actual != nullptr) {
        Nodo* temporal=actual;
        actual=actual->siguiente;
        delete temporal->centro;
        delete temporal;
    }
    primero=nullptr;
}
bool ListaCentros::registrar(Centro* centro) {
    if (centro == nullptr || !centro->datosValidos()) {
        cout << "Datos del centro invalidos";
        return false;
    }
    if (buscar(centro->getCodigo()) != nullptr) {
        cout << "Ya existe un centro con ese codigo";
        return false;
    }
    Nodo* nuevo=new Nodo(centro);

    if (primero == nullptr) {
        primero=nuevo;
    } else {
        Nodo* actual=primero;
      
        while (actual->siguiente != nullptr) {
            actual=actual->siguiente;
        }
        actual->siguiente=nuevo;
    }
    cout << "Centro registrado correctamente";
    return true;
}
Centro* ListaCentros::buscar(string codigo) const {
    Nodo* actual=primero;

    while (actual != nullptr) {
        if (actual->centro->getCodigo() == codigo) {
            return actual->centro;
        }
        actual=actual->siguiente;
    }
    return nullptr;
}
void ListaCentros::mostrarTodos() const {
    if (primero == nullptr) {
        cout << "No hay centros registrados";
        return;
    }
    Nodo* actual=primero;

    while (actual != nullptr) {
        actual->centro->mostrar();
        actual=actual->siguiente;
    }
}
bool ListaCentros::estaVacia() const {
    return primero == nullptr;
}
