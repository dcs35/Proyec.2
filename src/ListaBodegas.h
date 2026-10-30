#ifndef LISTA_BODEGAS_H
#define LISTA_BODEGAS_H
#include <string>
#include "Bodega.h"
using namespace std;

class ListaBodegas {
private:
    struct Nodo {
        Bodega* bodega;
        Nodo* siguiente;
        Nodo(Bodega* b) {
            bodega = b;
            siguiente = nullptr;
        }
    };
    Nodo* primero;
    int cantidad;
public:
    ListaBodegas();
    ~ListaBodegas();
    ListaBodegas(const ListaBodegas&) = delete;
    ListaBodegas& operator=(const ListaBodegas&) = delete;

    bool registrar(Bodega* bodega);
    Bodega* buscar(string codigo) const;
    bool eliminar(string codigo);
    Bodega* obtenerEn(int posicion) const;
    int getCantidad() const;
    void mostrarTodos() const;
    bool estaVacia() const;
};
#endif