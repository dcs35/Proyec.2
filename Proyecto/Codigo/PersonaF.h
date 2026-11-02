#ifndef PERSONA_F_H
#define PERSONA_F_H
#include "Cliente.h"
class PersonaF : public Cliente {
public:
    PersonaF();
    PersonaF(string, string, string, string);
    void mostrar() const ;
};
#endif
