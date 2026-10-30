#ifndef LISTAS_H
#define LISTAS_H
#include "ListaGenerica.h"
#include "Cliente.h"
#include "Colaborador.h"
#include "Bodega.h"
#include "Paquete.h"
#include "Solicitud.h"
#include "Despacho.h"

typedef ListaGenerica<Cliente> ListaClientes;
typedef ListaGenerica<Colaborador> ListaColaboradores;
typedef ListaGenerica<Bodega> ListaBodegas;
typedef ListaGenerica<Paquete> ListaPaquetes;
typedef ListaGenerica<Solicitud> ListaSolicitudes;
typedef ListaGenerica<Despacho> ListaDespachos;

#endif
