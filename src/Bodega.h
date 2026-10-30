#ifndef BODEGA_H
#define BODEGA_H
#include <string>
#include "Celda.h"
using namespace std;

class Paquete;

class Bodega {
private:
    string codigo;
    string nombre;
    int tipo;          // 1 General, 2 Fragil, 3 Tecnologia, 4 Documentos
    int filas;
    int columnas;
    Celda** matriz;    // matriz dinamica

    string etiquetaCelda(int f, int c) const;

public:
    Bodega(string codigo, string nombre, int tipo, int filas, int columnas);
    ~Bodega();
    Bodega(const Bodega&) = delete;             // evita copia superficial
    Bodega& operator=(const Bodega&) = delete;

    string getCodigo() const;
    string getNombre() const;
    int getTipo() const;
    string getNombreTipo() const;
    int getFilas() const;
    int getColumnas() const;

    bool posicionValida(int f, int c) const;
    bool estaLibre(int f, int c) const;
    Paquete* getPaquete(int f, int c) const;
    bool asignarPaquete(int f, int c, Paquete* p);
    bool liberarPosicion(int f, int c);

    int totalCeldas() const;
    int celdasOcupadas() const;
    int celdasLibres() const;
    double porcentajeOcupacion() const;
    double porcentajeDisponible() const;
    bool estaVacia() const;

    void mostrarMatriz() const;
    void mostrarResumen() const;
};

#endif