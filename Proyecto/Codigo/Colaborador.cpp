#include "Colaborador.h"
#include <iostream>
using namespace std;

Colaborador::Colaborador() {
    identificacion="";
    nombre="";
    fechaIngreso="";
    puesto="";
}
Colaborador::Colaborador(string id, string nom,string fecha, string pue) {
    identificacion=id;
    nombre=nom;
    fechaIngreso=fecha;
    puesto=pue;
}
string Colaborador::getIdentificacion() const {
    return identificacion;
}
string Colaborador::getNombre() const {
    return nombre;
}
string Colaborador::getFechaIngreso() const {
    return fechaIngreso;
}
string Colaborador::getPuesto() const {
    return puesto;
}
void Colaborador::setNombre(string nom) {
    nombre=nom;
}
void Colaborador::setFechaIngreso(string fecha) {
    fechaIngreso=fecha;
}
void Colaborador::setPuesto(string pue) {
    puesto=pue;
}
bool Colaborador::datosValidos() const {
    if (identificacion == "" ||nombre == "" || fechaIngreso == "" || puesto == "") {
        return false;
    }
    return true;
}
void Colaborador::mostrar() const {
    cout<<"************* DATOS DEL COLABORADOR ***********";
    cout<<"Identificacion: "<< identificacion<<endl;
    cout<<"Nombre completo: "<<nombre<<endl;
    cout<<"Fecha de ingreso: "<<fechaIngreso<<endl;
    cout<<"Puesto: "<<puesto<<endl;
}
