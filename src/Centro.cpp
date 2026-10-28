
#include "Centro.h"
#include <iostream>
using namespace std;
Centro::Centro() {
    codigo="";
    nombre="";
    provincia="";
    direccion="";
    telefono="";
    clientes=nullptr;
    colaboradores=nullptr;
    bodegas=nullptr;
    paquetes=nullptr;
    solicitudes=nullptr;
    despachos=nullptr;
}
Centro::Centro(string cod, string nom, string prov,string dir, string tel) {
    codigo=cod;
    nombre=nom;
    provincia=prov;
    direccion=dir;
    telefono=tel;
    clientes=nullptr;
    colaboradores=nullptr;
    bodegas=nullptr;
    paquetes=nullptr;
    solicitudes=nullptr;
    despachos=nullptr;
}
Centro::~Centro() {
  
}
string Centro::getCodigo() const {
    return codigo;
}
string Centro::getNombre() const {
    return nombre;
}
string Centro::getProvincia() const {
    return provincia;
}
string Centro::getDireccion() const {
    return direccion;
}
string Centro::getTelefono() const {
    return telefono;
}
void Centro::setNombre(string nom) {
    nombre=nom;
}
void Centro::setProvincia(string prov) {
    provincia=prov;
}
void Centro::setDireccion(string dir) {
    direccion=dir;
}
void Centro::setTelefono(string tel) {
    telefono=tel;
}
bool Centro::datosValidos() const {
    if (codigo == "" || nombre == "" || provincia == "" || direccion == "" ||telefono == "") {
        return false;
    }
    return true;
}
void Centro::mostrar() const {
    cout<< "******************* CENTRO DE DISTRIBUCION **************************";
    cout<<"Codigo: "<<codigo<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Provincia: "<<provincia<<endl;
    cout<<"Direccion: "<<direccion<<endl;
    cout<<"Telefono: "<<telefono<<endl;
}
