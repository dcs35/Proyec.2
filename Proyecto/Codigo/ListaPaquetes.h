#ifndef LISTA_PAQUETES_H
#define LISTA_PAQUETES_H

class Paquete;

class ListaPaquetes {
private:
    struct Nodo {
        Paquete* dato;
        Nodo* siguiente;
        Nodo(Paquete* d) {
            dato = d;
            siguiente = nullptr;
        }
    };
    Nodo* primero;
    int cantidad;

public:
    ListaPaquetes();
    ~ListaPaquetes();

    bool agregar(Paquete* dato);
    bool estaVacia() const;
    int tamanio() const;
    Paquete* obtener(int indice) const;
    bool contiene(Paquete* dato) const;
    bool eliminar(Paquete* dato);
    void mostrar() const;
};

#endif
