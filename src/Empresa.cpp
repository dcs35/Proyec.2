#include "Empresa.h"
#include <iostream>
using namespace std;
Empresa::Empresa(): Cliente() {
    actividadEconomica="";
    porcentajeDescuento=0;
}
Empresa::Empresa(string id, string nom, string tel, string corr, string actividad, double descuento): Cliente(id, nom, tel, corr) {
    actividadEconomica=actividad;
  
    if (descuento >= 0 && descuento <= 100) {
        porcentajeDescuento=descuento;
    } else {
      porcentajeDescuento=0;
    }
}
string Empresa::getActividadEconomica() const {
    return actividadEconomica;
}
double Empresa::getPorcentajeDescuento() const {
    return porcentajeDescuento;
}
void Empresa::setActividadEconomica(string actividad) {
    actividadEconomica=actividad;
}
bool Empresa::setPorcentajeDescuento(double descuento) {
    if (descuento >= 0 && descuento <= 100) {
        porcentajeDescuento = descuento;
        return true;
    }
    return false;
}
void Empresa::mostrar() const {
    cout << "*********** EMPRESA ************";
    Cliente::mostrar();
    cout<<"Actividad economica: "<<actividadEconomica<<endl;

    cout<<"Descuento autorizado: "<<porcentajeDescuento<<"%"<<endl;
}
