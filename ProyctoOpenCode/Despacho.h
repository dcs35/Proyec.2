#ifndef DESPACHO_H
#define DESPACHO_H
#include <string>
using namespace std;

class Solicitud;
class Paquete;
class Cliente;
class Colaborador;
class Centro;

class Despacho {
private:
    string codigo;
    Solicitud* solicitud;
    Paquete* paquete;
    Cliente* cliente;
    Colaborador* responsable;
    Centro* centroOrigen;
    string destino;
    string fecha;
    string hora;
    int estado;             // 1 En proceso, 2 Finalizado

public:
    Despacho();
    Despacho(string, Solicitud*, Paquete*, Cliente*, Colaborador*, Centro*, string, string, string);
    string getCodigo() const;
    Solicitud* getSolicitud() const;
    Paquete* getPaquete() const;
    Cliente* getCliente() const;
    Colaborador* getResponsable() const;
    Centro* getCentroOrigen() const;
    string getDestino() const;
    string getFecha() const;
    string getHora() const;
    int getEstado() const;
    bool datosValidos() const;
    bool finalizar();
    void mostrar() const;
};

#endif
