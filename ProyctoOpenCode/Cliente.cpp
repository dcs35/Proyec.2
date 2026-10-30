#include "Cliente.h"
#include <iostream>
using namespace std;
Cliente::Cliente() {
    identificacion="";
    nombre="";
    telefono="";
    correo="";
}
Cliente::Cliente(string id, string nom,string tel, string corr) {
    identificacion=id;
    nombre=nom;
    telefono=tel;
    correo=corr;
}
Cliente::~Cliente() {
}
string Cliente::getIdentificacion() const {
    return identificacion;
}
string Cliente::getNombre() const {
    return nombre;
}
string Cliente::getTelefono() const {
    return telefono;
}
string Cliente::getCorreo() const {
    return correo;
}
bool Cliente::datosValidos() const {
    return identificacion != "" && nombre != "" && telefono != "" && correo != "";
}
double Cliente::getDescuento() const {
    return 0;
}
void Cliente::setNombre(string nom) {
    nombre=nom;
}
void Cliente::setTelefono(string tel) {
    telefono=tel;
}
void Cliente::setCorreo(string corr) {
    correo=corr;
}
void Cliente::mostrar() const {
    cout<<"Identificacion: "<<identificacion<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Telefono: "<<telefono<<endl;
    cout<<"Correo: "<<correo<<endl;
}
