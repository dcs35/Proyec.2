#ifndef BODEGA_H
#define BODEGA_H
#include <string>
#include "Celda.h"
using namespace std;

class Bodega {
private:
    string codigo;
    string nombre;
    int tipo;          // 1 General, 2 Fragil, 3 Tecnologia, 4 Documentos
    int filas;
    int columnas;
    Celda** matriz;    // matriz dinamica de celdas

    void reservarMatriz();
    void liberarMatriz();
    Bodega(const Bodega&);
    Bodega& operator=(const Bodega&);
public:
    Bodega();
    Bodega(string, string, int, int, int);
    ~Bodega();
    string getCodigo() const;
    string getNombre() const;
    int getTipo() const;
    string getNombreTipo() const;
    int getFilas() const;
    int getColumnas() const;
    static string nombreTipo(int);
    static bool tipoValido(int);
    bool datosValidos() const;
    bool posicionValida(int, int) const;
    bool estaLibre(int, int) const;
    Paquete* consultarPaquete(int, int) const;
    bool asignarPaquete(int, int, Paquete*);
    bool liberarPosicion(int, int);
    int totalCeldas() const;
    int celdasOcupadas() const;
    int celdasLibres() const;
    double porcentajeOcupacion() const;
    double porcentajeDisponible() const;
    bool primeraLibre(int&, int&) const;
    bool estaVacia() const;
    string codigoCelda(int, int) const;
    void mostrar() const;
    void mostrarMatriz() const;
    void mostrarCeldasLibres() const;
    void mostrarOcupacion() const;
};
#endif
