#ifndef LISTA_CENTROS_H
#define LISTA_CENTROS_H
#include "Centro.h"

class ListaCentros {
private:
    struct Nodo {
        Centro* centro;
        Nodo* siguiente;
        Nodo(Centro* c) {
            centro = c;
            siguiente = nullptr;
        }
    };
    Nodo* primero;
public:
    ListaCentros();
    ~ListaCentros();
    bool registrar(Centro* centro);
    Centro* buscar(string codigo) const;
    void mostrarTodos() const;
    bool estaVacia() const;
};
#endif
