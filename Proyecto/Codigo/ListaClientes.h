#ifndef LISTA_CLIENTES_H
#define LISTA_CLIENTES_H

class Cliente;

class ListaClientes {
private:
    struct Nodo {
        Cliente* dato;
        Nodo* siguiente;
        Nodo(Cliente* d) {
            dato = d;
            siguiente = nullptr;
        }
    };
    Nodo* primero;
    int cantidad;

public:
    ListaClientes();
    ~ListaClientes();

    bool agregar(Cliente* dato);
    bool estaVacia() const;
    int tamanio() const;
    Cliente* obtener(int indice) const;
    bool contiene(Cliente* dato) const;
    bool eliminar(Cliente* dato);
    void mostrar() const;
};

#endif
