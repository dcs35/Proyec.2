#ifndef LISTA_CENTROS_H
#define LISTA_CENTROS_H
#include <string>
#include "Centro.h"
using namespace std;

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
    int cantidad;
public:
    ListaCentros();
    ~ListaCentros();
    bool registrar(Centro* centro);
    Centro* buscar(string codigo) const;
    bool eliminar(string codigo);
    Centro* obtener(int indice) const;
    int tamanio() const;
    void mostrarTodos() const;
    bool estaVacia() const;
};
#endif
