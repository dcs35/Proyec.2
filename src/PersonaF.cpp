#include "PersonaF.h"
#include <iostream>
using namespace std;
PersonaF::PersonaF() : Cliente() {
}
PersonaFisica::PersonaFisica(string id, string nom, string tel, string corr): Cliente(id, nom, tel, corr) {
}
void PersonaFisica::mostrar() const {
    cout<<"************** CLIENTE: PERSONA FISICA *******************";
    Cliente::mostrar();
}
