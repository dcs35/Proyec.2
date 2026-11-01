#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>
using namespace std;

string aTexto(int valor);
string aTextoDecimal(double valor);
string rellenar(string texto, int ancho);
string repetir(char caracter, int cantidad);
string aMayusculas(string texto);
string aMinusculas(string texto);
string quitarEspacios(string texto);
int aEntero(string texto, int porDefecto);
double aDecimal(string texto, double porDefecto);

string nombreEstadoPaquete(int estado);
string nombreCategoriaPaquete(int categoria);
string nombreEstadoSolicitud(int estado);
string nombreEstadoDespacho(int estado);

void limpiarPantalla();
void pausar();

#endif
