#ifndef CENTRO_H
#define CENTRO_H
#include <string>
#include "Listas.h"
using namespace std;

class Centro {
private:
    string codigo;
    string nombre;
    string provincia;
    string direccion;
    string telefono;
    ListaClientes* clientes;
    ListaColaboradores* colaboradores;
    ListaBodegas* bodegas;
    ListaPaquetes* paquetes;
    ListaSolicitudes* solicitudes;
    ListaDespachos* despachos;

public:
    Centro();
    Centro(string, string, string, string, string);
    ~Centro();
    string getCodigo() const;
    string getNombre() const;
    string getProvincia() const;
    string getDireccion() const;
    string getTelefono() const;
    void setNombre(string);
    void setProvincia(string);
    void setDireccion(string);
    void setTelefono(string);
    bool datosValidos() const;
    void mostrar() const;
    bool tieneDatosAsociados() const;

    ListaClientes* getClientes() const;
    ListaColaboradores* getColaboradores() const;
    ListaBodegas* getBodegas() const;
    ListaPaquetes* getPaquetes() const;
    ListaSolicitudes* getSolicitudes() const;
    ListaDespachos* getDespachos() const;

    // Clientes
    bool registrarCliente(Cliente*);
    Cliente* buscarCliente(string) const;
    bool eliminarCliente(string);
    void mostrarClientes() const;

    // Colaboradores
    bool registrarColaborador(Colaborador*);
    Colaborador* buscarColaborador(string) const;
    bool eliminarColaborador(string);
    void mostrarColaboradores() const;

    // Bodegas
    bool registrarBodega(Bodega*);
    Bodega* buscarBodega(string) const;
    bool eliminarBodega(string);
    void mostrarBodegas() const;
    void mostrarMatrices() const;

    // Paquetes
    bool registrarPaquete(Paquete*);
    Paquete* buscarPaquete(string) const;
    bool eliminarPaquete(string);
    void mostrarPaquetes() const;

    // Solicitudes
    bool crearSolicitud(Solicitud*);
    Solicitud* buscarSolicitud(string) const;
    bool aprobarSolicitud(string, string, string, string);
    bool rechazarSolicitud(string);
    bool anularSolicitud(string);
    void mostrarSolicitudes() const;

    // Despachos
    Despacho* buscarDespacho(string) const;
    Despacho* buscarDespachoPorPaquete(Paquete*) const;
    bool finalizarDespacho(string, string);
    void mostrarDespachos() const;

    // Almacenamiento
    bool almacenarPaquete(string, string, int, int, string, Colaborador*);
    bool reubicarPaquete(string, string, int, int);
    bool resolverIncidencia(string, int, string, Colaborador*);
    Bodega* recomendarBodega(int) const;

    // Reportes
    void reporteHistorialCliente(string) const;
    void reporteClientesPorEnvios() const;
    void reporteBitacoraPaquete(string) const;
    void reporteDespachoDePaquete(string) const;
    void reporteOcupacion() const;
    void reporteDespachosPorColaborador(string) const;
    void reportePaquetesPorEstado() const;
};

#endif
