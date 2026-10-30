#ifndef CELDA_H
#define CELDA_H

class Paquete;

class Celda {
private:
    Paquete* paquete;   // nullptr = libre

public:
    Celda() : paquete(nullptr) {}
    bool estaLibre() const { return paquete == nullptr; }
    Paquete* getPaquete() const { return paquete; }
    void ocupar(Paquete* p) { paquete = p; }
    void liberar() { paquete = nullptr; }
};

#endif