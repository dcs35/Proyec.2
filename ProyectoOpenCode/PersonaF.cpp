#include "PersonaF.h"
#include <iostream>
using namespace std;
PersonaF::PersonaF() : Cliente() {
}
PersonaF::PersonaF(string id, string nom, string tel, string corr): Cliente(id, nom, tel, corr) {
}
void PersonaF::mostrar() const {
    cout<<"************** CLIENTE: PERSONA FISICA *******************";
    Cliente::mostrar();
}
