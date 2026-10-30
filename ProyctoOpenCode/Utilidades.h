#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>
using namespace std;

// Conversiones y utilidades de texto.
string aTexto(int valor);
string aTextoDecimal(double valor);
string rellenar(string texto, int ancho);
string repetir(char caracter, int cantidad);
string aMayusculas(string texto);
string aMinusculas(string texto);
string quitarEspacios(string texto);
int aEntero(string texto, int porDefecto);
double aDecimal(string texto, double porDefecto);

// Nombres de estados y categorias de paquete.
string nombreEstadoPaquete(int estado);
string nombreCategoriaPaquete(int categoria);
string nombreEstadoSolicitud(int estado);
string nombreEstadoDespacho(int estado);

// Limpia la consola y espera Enter para continuar.
void limpiarPantalla();
void pausar();

#endif
