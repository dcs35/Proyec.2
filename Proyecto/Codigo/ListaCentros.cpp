#include "ListaCentros.h"
#include <iostream>
using namespace std;

ListaCentros::ListaCentros() {
    primero = nullptr;
    cantidad = 0;
}

ListaCentros::~ListaCentros() {
    Nodo* actual = primero;
    while (actual != nullptr) {
        Nodo* temporal = actual;
        actual = actual->siguiente;
        delete temporal->centro;
        delete temporal;
    }
    primero = nullptr;
}

bool ListaCentros::registrar(Centro* centro) {
    if (centro == nullptr || !centro->datosValidos()) {
        cout << "Datos del centro invalidos." << endl;
        return false;
    }
    if (buscar(centro->getCodigo()) != nullptr) {
        cout << "Ya existe un centro con ese codigo." << endl;
        return false;
    }
    Nodo* nuevo = new Nodo(centro);
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
    cout << "Centro registrado correctamente." << endl;
    return true;
}

Centro* ListaCentros::buscar(string codigo) const {
    Nodo* actual = primero;
    while (actual != nullptr) {
        if (actual->centro->getCodigo() == codigo) {
            return actual->centro;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

bool ListaCentros::eliminar(string codigo) {
    Nodo* actual = primero;
    Nodo* anterior = nullptr;
    while (actual != nullptr) {
        if (actual->centro->getCodigo() == codigo) {
            if (actual->centro->tieneDatosAsociados()) {
                cout << "No se puede eliminar: el centro tiene datos asociados." << endl;
                return false;
            }
            if (anterior == nullptr) {
                primero = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual->centro;
            delete actual;
            cantidad--;
            cout << "Centro eliminado correctamente." << endl;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Centro no encontrado." << endl;
    return false;
}

Centro* ListaCentros::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        return nullptr;
    }
    Nodo* actual = primero;
    int i = 0;
    while (actual != nullptr) {
        if (i == indice) {
            return actual->centro;
        }
        actual = actual->siguiente;
        i++;
    }
    return nullptr;
}

int ListaCentros::tamanio() const {
    return cantidad;
}

void ListaCentros::mostrarTodos() const {
    if (primero == nullptr) {
        cout << "No hay centros registrados." << endl;
        return;
    }
    Nodo* actual = primero;
    while (actual != nullptr) {
        actual->centro->mostrar();
        actual = actual->siguiente;
    }
}

bool ListaCentros::estaVacia() const {
    return primero == nullptr;
}
