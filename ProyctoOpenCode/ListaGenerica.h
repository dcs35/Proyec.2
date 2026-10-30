#ifndef LISTA_GENERICA_H
#define LISTA_GENERICA_H
#include <iostream>
using namespace std;

// Lista enlazada simple propia. No usa contenedores de la STL.
// El dueno de los objetos es el Centro; la lista solo administra los nodos.
template <class T>
class ListaGenerica {
private:
    struct Nodo {
        T* dato;
        Nodo* siguiente;
        Nodo(T* d) {
            dato = d;
            siguiente = nullptr;
        }
    };
    Nodo* primero;
    int cantidad;

public:
    ListaGenerica() {
        primero = nullptr;
        cantidad = 0;
    }

    ~ListaGenerica() {
        Nodo* actual = primero;
        while (actual != nullptr) {
            Nodo* temporal = actual;
            actual = actual->siguiente;
            delete temporal;
        }
        primero = nullptr;
    }

    bool agregar(T* dato) {
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

    bool estaVacia() const {
        return primero == nullptr;
    }

    int tamanio() const {
        return cantidad;
    }

    T* obtener(int indice) const {
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

    bool contiene(T* dato) const {
        Nodo* actual = primero;
        while (actual != nullptr) {
            if (actual->dato == dato) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    bool eliminar(T* dato) {
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

    void mostrar() const {
        Nodo* actual = primero;
        while (actual != nullptr) {
            actual->dato->mostrar();
            actual = actual->siguiente;
        }
    }
};

#endif
