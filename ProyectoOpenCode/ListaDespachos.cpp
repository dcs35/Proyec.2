#include "ListaDespachos.h"
#include "Despacho.h"

ListaDespachos::ListaDespachos() {
    primero = nullptr;
    cantidad = 0;
}

ListaDespachos::~ListaDespachos() {
    Nodo* actual = primero;
    while (actual != nullptr) {
        Nodo* temporal = actual;
        actual = actual->siguiente;
        delete temporal;
    }
    primero = nullptr;
}

bool ListaDespachos::agregar(Despacho* dato) {
    if (dato == nullptr) {
        return false;
    }
    Nodo* nuevo = new Nodo(dato);
    if (primero == nullptr) {
        primero = nuevo;
    } else {
        Nodo* actual = primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    cantidad++;
    return true;
}

bool ListaDespachos::estaVacia() const {
    return primero == nullptr;
}

int ListaDespachos::tamanio() const {
    return cantidad;
}

Despacho* ListaDespachos::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        return nullptr;
    }
    Nodo* actual = primero;
    int i = 0;
    while (actual != nullptr) {
        if (i == indice) {
            return actual->dato;
        }
        actual = actual->siguiente;
        i++;
    }
    return nullptr;
}

bool ListaDespachos::contiene(Despacho* dato) const {
    Nodo* actual = primero;
    while (actual != nullptr) {
        if (actual->dato == dato) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

bool ListaDespachos::eliminar(Despacho* dato) {
    Nodo* actual = primero;
    Nodo* anterior = nullptr;
    while (actual != nullptr) {
        if (actual->dato == dato) {
            if (anterior == nullptr) {
                primero = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            cantidad--;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false;
}

void ListaDespachos::mostrar() const {
    Nodo* actual = primero;
    while (actual != nullptr) {
        actual->dato->mostrar();
        actual = actual->siguiente;
    }
}
