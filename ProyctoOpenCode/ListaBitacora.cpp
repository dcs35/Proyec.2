#include "ListaBitacora.h"
#include "Colaborador.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

ListaBitacora::ListaBitacora() {
    primero = nullptr;
}

ListaBitacora::~ListaBitacora() {
    RegistroBitacora* actual = primero;
    while (actual != nullptr) {
        RegistroBitacora* temporal = actual;
        actual = actual->siguiente;
        delete temporal;
    }
    primero = nullptr;
}

void ListaBitacora::agregar(int anterior, int nuevo, string fecha, Colaborador* responsable) {
    RegistroBitacora* registro = new RegistroBitacora(anterior, nuevo, fecha, responsable);
    if (primero == nullptr) {
        primero = registro;
    } else {
        RegistroBitacora* actual = primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = registro;
    }
}

bool ListaBitacora::estaVacia() const {
    return primero == nullptr;
}

bool ListaBitacora::contieneColaborador(Colaborador* colaborador) const {
    RegistroBitacora* actual = primero;
    while (actual != nullptr) {
        if (actual->responsable == colaborador) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void ListaBitacora::mostrar() const {
    if (primero == nullptr) {
        cout << "   (Sin registros en la bitacora)" << endl;
        return;
    }
    cout << "   " << rellenar("Estado anterior", 20) << rellenar("Nuevo estado", 20)
         << rellenar("Fecha", 14) << "Responsable" << endl;
    RegistroBitacora* actual = primero;
    while (actual != nullptr) {
        string nombreResponsable = "(sin responsable)";
        if (actual->responsable != nullptr) {
            nombreResponsable = actual->responsable->getNombre();
        }
        cout << "   " << rellenar(nombreEstadoPaquete(actual->estadoAnterior), 20)
             << rellenar(nombreEstadoPaquete(actual->estadoNuevo), 20)
             << rellenar(actual->fecha, 14) << nombreResponsable << endl;
        actual = actual->siguiente;
    }
}
