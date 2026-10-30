#ifndef PAQUETE_H
#define PAQUETE_H

#include "ListaBitacora.h"
using namespace std;

class Cliente;
class Centro;
class Bodega;
class Colaborador;

class Paquete {
private:
    string codigo;
    string descripcion;
    double peso;
    int categoria;          // 1 General, 2 Fragil, 3 Tecnologia, 4 Documentos
    Cliente* propietario;
    Centro* centro;
    int estado;             // 1 Recibido, 2 Almacenado, 3 En transito, 4 Entregado, 5 Incidencia
    Bodega* bodega;
    int fila;
    int columna;
    ListaBitacora bitacora;

public:
    Paquete();
    Paquete(string, string, double, int, Cliente*, Centro*);
    string getCodigo() const;
    string getDescripcion() const;
    double getPeso() const;
    int getCategoria() const;
    Cliente* getPropietario() const;
    Centro* getCentro() const;
    int getEstado() const;
    Bodega* getBodega() const;
    int getFila() const;
    int getColumna() const;
    bool tieneUbicacion() const;
    void setDescripcion(string);
    void setPeso(double);
    void setCategoria(int);
    bool datosValidos() const;
    static bool categoriaValida(int);
    static bool transicionPermitida(int, int);
    bool cambiarEstado(int nuevoEstado, string fecha, Colaborador* responsable);
    void asignarUbicacion(Bodega*, int, int);
    void liberarUbicacion();
    bool tieneBitacoraDe(Colaborador*) const;
    void mostrar() const;
    void mostrarBitacora() const;
};

#endif
