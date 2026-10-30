#include "ListaBodegas.h"
#include <iostream>
using namespace std;

ListaBodegas::ListaBodegas() {
    primero = nullptr;
    cantidad = 0;
}

ListaBodegas::~ListaBodegas() {
    Nodo* actual = primero;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual->bodega;
        delete actual;
        actual = siguiente;
    }
}

bool ListaBodegas::registrar(Bodega* bodega) {
    if (bodega == nullptr || buscar(bodega->getCodigo()) != nullptr)
        return false;

    Nodo* nuevo = new Nodo(bodega);
    if (primero == nullptr) {
        primero = nuevo;
    } else {
        Nodo* actual = primero;
        while (actual->siguiente != nullptr)
            actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
    cantidad++;
    return true;
}

Bodega* ListaBodegas::buscar(string codigo) const {
    Nodo* actual = primero;
    while (actual != nullptr) {
        if (actual->bodega->getCodigo() == codigo)
            return actual->bodega;
        actual = actual->siguiente;
    }
    return nullptr;
}

bool ListaBodegas::eliminar(string codigo) {
    Nodo* anterior = nullptr;
    Nodo* actual = primero;
    while (actual != nullptr && actual->bodega->getCodigo() != codigo) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == nullptr) return false;
    if (!actual->bodega->estaVacia()) return false;

    if (anterior == nullptr) primero = actual->siguiente;
    else anterior->siguiente = actual->siguiente;

    delete actual->bodega;
    delete actual;
    cantidad--;
    return true;
}

Bodega* ListaBodegas::obtenerEn(int posicion) const {
    if (posicion < 0 || posicion >= cantidad) return nullptr;
    Nodo* actual = primero;
    for (int i = 0; i < posicion; i++)
        actual = actual->siguiente;
    return actual->bodega;
}

int ListaBodegas::getCantidad() const { return cantidad; }

void ListaBodegas::mostrarTodos() const {
    if (primero == nullptr) {
        cout << "No hay bodegas registradas." << endl;
        return;
    }
    Nodo* actual = primero;
    while (actual != nullptr) {
        actual->bodega->mostrarResumen();
        actual = actual->siguiente;
    }
}

bool ListaBodegas::estaVacia() const { return primero == nullptr; }