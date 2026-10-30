#ifndef SOLICITUD_H
#define SOLICITUD_H
#include <string>
using namespace std;

class Cliente;
class Paquete;
class Colaborador;
class Centro;

class Solicitud {
private:
    string codigo;
    Cliente* cliente;
    Paquete* paquete;
    Colaborador* responsable;
    Centro* centroOrigen;
    string destino;
    string fecha;
    double costoEstimado;
    int estado;             // 1 Pendiente, 2 Aprobada, 3 Rechazada, 4 Anulada

    static double tarifas[4];

public:
    Solicitud();
    Solicitud(string, Cliente*, Paquete*, Colaborador*, Centro*, string, string);
    string getCodigo() const;
    Cliente* getCliente() const;
    Paquete* getPaquete() const;
    Colaborador* getResponsable() const;
    Centro* getCentroOrigen() const;
    string getDestino() const;
    string getFecha() const;
    double getCostoEstimado() const;
    int getEstado() const;
    bool datosValidos() const;
    static double tarifaPorCategoria(int);
    static double calcularCosto(Paquete*, Cliente*);
    bool esFinal() const;
    bool cambiarEstado(int nuevoEstado);
    void mostrar() const;
};

#endif
