#ifndef LISTA_COLABORADORES_H
#define LISTA_COLABORADORES_H

class Colaborador;

class ListaColaboradores {
private:
    struct Nodo {
        Colaborador* dato;
        Nodo* siguiente;
        Nodo(Colaborador* d) {
            dato = d;
            siguiente = nullptr;
        }
    };
    Nodo* primero;
    int cantidad;

public:
    ListaColaboradores();
    ~ListaColaboradores();

    bool agregar(Colaborador* dato);
    bool estaVacia() const;
    int tamanio() const;
    Colaborador* obtener(int indice) const;
    bool contiene(Colaborador* dato) const;
    bool eliminar(Colaborador* dato);
    void mostrar() const;
};

#endif
