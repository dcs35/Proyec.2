#ifndef LISTA_SOLICITUDES_H
#define LISTA_SOLICITUDES_H
class Solicitud;
class ListaSolicitudes{
private:
    struct Nodo {
        Solicitud* dato;
        Nodo* siguiente;
        Nodo(Solicitud* d){
            dato=d;
            siguiente=nullptr;
        }
    };
    Nodo* primero;
    int cantidad;
public:
    ListaSolicitudes();
    ~ListaSolicitudes();
    bool agregar(Solicitud* dato);
    bool estaVacia() const;
    int tamanio() const;
    Solicitud* obtener(int indice) const;
    bool contiene(Solicitud* dato) const;
    bool eliminar(Solicitud* dato);
    void mostrar() const;
};
#endif
