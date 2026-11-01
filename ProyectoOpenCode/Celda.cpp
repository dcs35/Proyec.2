#include "Celda.h"

Celda::Celda() {
    paquete = nullptr;
}

bool Celda::estaLibre() const {
    return paquete == nullptr;
}

Paquete* Celda::getPaquete() const {
    return paquete;
}

void Celda::ocupar(Paquete* p) {
    paquete = p;
}

void Celda::liberar() {
    paquete = nullptr;
}
