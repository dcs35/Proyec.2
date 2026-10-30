#ifndef CELDA_H
#define CELDA_H

class Paquete;

class Celda {
private:
    Paquete* paquete;
public:
    Celda();
    bool estaLibre() const;
    Paquete* getPaquete() const;
    void ocupar(Paquete* p);
    void liberar();
};

#endif
