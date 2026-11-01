#ifndef LISTA_BODEGAS_H
#define LISTA_BODEGAS_H

class Bodega;

class ListaBodegas {
private:
    struct Nodo {
        Bodega* dato;
        Nodo* siguiente;
        Nodo(Bodega* d) {
            dato = d;
            siguiente = nullptr;
        }
    };
    Nodo* primero;
    int cantidad;

public:
    ListaBodegas();
    ~ListaBodegas();

    bool agregar(Bodega* dato);
    bool estaVacia() const;
    int tamanio() const;
    Bodega* obtener(int indice) const;
    bool contiene(Bodega* dato) const;
    bool eliminar(Bodega* dato);
    void mostrar() const;
};

#endif
