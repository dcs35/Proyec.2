#ifndef LISTA_BITACORA_H
#define LISTA_BITACORA_H
using namespace std;

class Colaborador;

struct RegistroBitacora {
    int estadoAnterior;
    int estadoNuevo;
    string fecha;
    Colaborador* responsable;
    RegistroBitacora* siguiente;
    RegistroBitacora(int anterior, int nuevo, string f, Colaborador* r) {
        estadoAnterior = anterior;
        estadoNuevo = nuevo;
        fecha = f;
        responsable = r;
        siguiente = nullptr;
    }
};

class ListaBitacora {
private:
    RegistroBitacora* primero;
public:
    ListaBitacora();
    ~ListaBitacora();
    void agregar(int anterior, int nuevo, string fecha, Colaborador* responsable);
    bool estaVacia() const;
    bool contieneColaborador(Colaborador* colaborador) const;
    void mostrar() const;
};

#endif
