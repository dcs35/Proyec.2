#include "Bodega.h"
#include "Paquete.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

Bodega::Bodega() {
    codigo = "";
    nombre = "";
    tipo = 0;
    filas = 0;
    columnas = 0;
    matriz = nullptr;
}
Bodega::Bodega(string cod, string nom, int tip, int fil, int col) {
    codigo = cod;
    nombre = nom;
    tipo = tip;
    matriz = nullptr;
    if (fil > 0 && col > 0) {
        filas = fil;
        columnas = col;
        reservarMatriz();
    } else {
        filas = 0;
        columnas = 0;
    }
}
Bodega::~Bodega() {
    liberarMatriz();
}
void Bodega::reservarMatriz() {
    matriz = new Celda*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new Celda[columnas];
    }
}
void Bodega::liberarMatriz() {
    if (matriz != nullptr) {
        for (int i = 0; i < filas; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
        matriz = nullptr;
    }
}
string Bodega::getCodigo() const {
    return codigo;
}
string Bodega::getNombre() const {
    return nombre;
}
int Bodega::getTipo() const {
    return tipo;
}
string Bodega::getNombreTipo() const {
    return nombreTipo(tipo);
}
int Bodega::getFilas() const {
    return filas;
}
int Bodega::getColumnas() const {
    return columnas;
}
string Bodega::nombreTipo(int t) {
    switch (t) {
        case 1: return "General";
        case 2: return "Fragil";
        case 3: return "Tecnologia";
        case 4: return "Documentos";
    }
    return "Desconocido";
}
bool Bodega::tipoValido(int t) {
    return t >= 1 && t <= 4;
}
bool Bodega::datosValidos() const {
    if (codigo == "" || nombre == "" || !tipoValido(tipo) || filas <= 0 || columnas <= 0 || matriz == nullptr) {
        return false;
    }
    return true;
}
bool Bodega::posicionValida(int f, int c) const {
    return matriz != nullptr && f >= 0 && f < filas && c >= 0 && c < columnas;
}
bool Bodega::estaLibre(int f, int c) const {
    if (!posicionValida(f, c)) {
        return false;
    }
    return matriz[f][c].estaLibre();
}
Paquete* Bodega::consultarPaquete(int f, int c) const {
    if (!posicionValida(f, c)) {
        return nullptr;
    }
    return matriz[f][c].getPaquete();
}
bool Bodega::asignarPaquete(int f, int c, Paquete* p) {
    if (p == nullptr || !posicionValida(f, c) || !matriz[f][c].estaLibre()) {
        return false;
    }
    matriz[f][c].ocupar(p);
    return true;
}
bool Bodega::liberarPosicion(int f, int c) {
    if (!posicionValida(f, c) || matriz[f][c].estaLibre()) {
        return false;
    }
    matriz[f][c].liberar();
    return true;
}
int Bodega::totalCeldas() const {
    return filas * columnas;
}
int Bodega::celdasOcupadas() const {
    int ocupadas = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (!matriz[i][j].estaLibre()) {
                ocupadas++;
            }
        }
    }
    return ocupadas;
}
int Bodega::celdasLibres() const {
    return totalCeldas() - celdasOcupadas();
}
double Bodega::porcentajeOcupacion() const {
    if (totalCeldas() == 0) {
        return 0;
    }
    return ((double)celdasOcupadas() / totalCeldas()) * 100;
}
double Bodega::porcentajeDisponible() const {
    if (totalCeldas() == 0) {
        return 0;
    }
    return ((double)celdasLibres() / totalCeldas()) * 100;
}
bool Bodega::primeraLibre(int& f, int& c) const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j].estaLibre()) {
                f = i;
                c = j;
                return true;
            }
        }
    }
    return false;
}
bool Bodega::estaVacia() const {
    return celdasOcupadas() == 0;
}
string Bodega::codigoCelda(int f, int c) const {
    // Con indices de un solo digito: A-12. Con dos o mas digitos se usa coma: A-12,3
    if (filas <= 10 && columnas <= 10) {
        return codigo + "-" + aTexto(f) + aTexto(c);
    }
    return codigo + "-" + aTexto(f) + "," + aTexto(c);
}
void Bodega::mostrar() const {
    cout << "************* BODEGA *************" << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << " - " << getNombreTipo() << endl;
    cout << "Distribucion: " << filas << " filas x " << columnas << " columnas" << endl;
    cout << "Celdas ocupadas: " << celdasOcupadas() << " de " << totalCeldas() << endl;
}
void Bodega::mostrarMatriz() const {
    if (matriz == nullptr) {
        cout << "La bodega no tiene matriz de almacenamiento." << endl;
        return;
    }
    // Calcular el ancho necesario para las celdas
    int ancho = 7;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int largoCodigo = (int)codigoCelda(i, j).length();
            if (largoCodigo > ancho) {
                ancho = largoCodigo;
            }
            if (!matriz[i][j].estaLibre()) {
                int largoPaquete = (int)matriz[i][j].getPaquete()->getCodigo().length() + 2;
                if (largoPaquete > ancho) {
                    ancho = largoPaquete;
                }
            }
        }
    }
    ancho = ancho + 2;
    string separador = "+";
    for (int j = 0; j < columnas; j++) {
        separador += repetir('-', ancho) + "+";
    }
    cout << "Bodega " << codigo << " - " << nombre << " (" << getNombreTipo() << ")  [LIBRE = disponible, [PKxxx] = ocupada]" << endl;
    for (int i = 0; i < filas; i++) {
        cout << separador << endl;
        cout << "|";
        for (int j = 0; j < columnas; j++) {
            cout << " " << rellenar(codigoCelda(i, j), ancho - 1) << "|";
        }
        cout << endl << "|";
        for (int j = 0; j < columnas; j++) {
            string contenido = "LIBRE";
            if (!matriz[i][j].estaLibre()) {
                contenido = "[" + matriz[i][j].getPaquete()->getCodigo() + "]";
            }
            cout << " " << rellenar(contenido, ancho - 1) << "|";
        }
        cout << endl;
    }
    cout << separador << endl;
    cout << "Total de celdas: " << totalCeldas() << " | Ocupadas: " << celdasOcupadas()
         << " | Libres: " << celdasLibres() << " | Ocupacion: " << aTextoDecimal(porcentajeOcupacion()) << "%" << endl;
}
void Bodega::mostrarCeldasLibres() const {
    int contador = 0;
    cout << "   Celdas disponibles: ";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j].estaLibre()) {
                if (contador % 10 == 0) {
                    cout << endl << "   ";
                }
                cout << codigoCelda(i, j) << "  ";
                contador++;
            }
        }
    }
    cout << endl;
}
void Bodega::mostrarOcupacion() const {
    cout << "  Bodega " << rellenar(codigo, 6) << " " << rellenar(nombre, 24)
         << " Total: " << rellenar(aTexto(totalCeldas()), 5)
         << " Ocupadas: " << rellenar(aTexto(celdasOcupadas()), 5)
         << " Disponibles: " << rellenar(aTexto(celdasLibres()), 5)
         << " Ocupacion: " << aTextoDecimal(porcentajeOcupacion()) << "%" << endl;
}
