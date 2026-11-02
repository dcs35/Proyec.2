#ifndef LISTA_DESPACHOS_H
#define LISTA_DESPACHOS_H
class Despacho;
class ListaDespachos{
private:
    struct Nodo{
        Despacho* dato;
        Nodo* siguiente;
        Nodo(Despacho* d){
            dato = d;
            siguiente = nullptr;
        }
    };
    Nodo* primero;
    int cantidad;
public:
    ListaDespachos();
    ~ListaDespachos();
    bool agregar(Despacho* dato);
    bool estaVacia() const;
    int tamanio() const;
    Despacho* obtener(int indice) const;
    bool contiene(Despacho* dato) const;
    bool eliminar(Despacho* dato);
    void mostrar() const;
};
#endif
