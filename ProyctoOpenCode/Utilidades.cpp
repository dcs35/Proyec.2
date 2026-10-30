#include "Utilidades.h"
#include <sstream>
#include <iostream>
using namespace std;

string aTexto(int valor) {
    stringstream ss;
    ss << valor;
    return ss.str();
}

string aTextoDecimal(double valor) {
    // Redondeo a dos decimales sin usar <iomanip>.
    double redondeado = (int)(valor * 100 + 0.5) / 100.0;
    stringstream ss;
    ss << redondeado;
    return ss.str();
}

string rellenar(string texto, int ancho) {
    string resultado = texto;
    while ((int)resultado.length() < ancho) {
        resultado += " ";
    }
    if ((int)resultado.length() > ancho) {
        resultado = resultado.substr(0, ancho);
    }
    return resultado;
}

string repetir(char caracter, int cantidad) {
    string resultado = "";
    for (int i = 0; i < cantidad; i++) {
        resultado += caracter;
    }
    return resultado;
}

string aMayusculas(string texto) {
    for (int i = 0; i < (int)texto.length(); i++) {
        if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = texto[i] - 'a' + 'A';
        }
    }
    return texto;
}

string aMinusculas(string texto) {
    for (int i = 0; i < (int)texto.length(); i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = texto[i] - 'A' + 'a';
        }
    }
    return texto;
}

string quitarEspacios(string texto) {
    int inicio = 0;
    int fin = (int)texto.length() - 1;
    while (inicio <= fin && (texto[inicio] == ' ' || texto[inicio] == '\t' || texto[inicio] == '\r')) {
        inicio++;
    }
    while (fin >= inicio && (texto[fin] == ' ' || texto[fin] == '\t' || texto[fin] == '\r')) {
        fin--;
    }
    return texto.substr(inicio, fin - inicio + 1);
}

int aEntero(string texto, int porDefecto) {
    stringstream ss(texto);
    int valor;
    if (ss >> valor) {
        return valor;
    }
    return porDefecto;
}

double aDecimal(string texto, double porDefecto) {
    stringstream ss(texto);
    double valor;
    if (ss >> valor) {
        return valor;
    }
    return porDefecto;
}

string nombreEstadoPaquete(int estado) {
    switch (estado) {
        case 1: return "Recibido";
        case 2: return "Almacenado";
        case 3: return "En transito";
        case 4: return "Entregado";
        case 5: return "Incidencia";
    }
    return "Desconocido";
}

string nombreCategoriaPaquete(int categoria) {
    switch (categoria) {
        case 1: return "General";
        case 2: return "Fragil";
        case 3: return "Tecnologia";
        case 4: return "Documentos";
    }
    return "Desconocida";
}

string nombreEstadoSolicitud(int estado) {
    switch (estado) {
        case 1: return "Pendiente";
        case 2: return "Aprobada";
        case 3: return "Rechazada";
        case 4: return "Anulada";
    }
    return "Desconocido";
}

string nombreEstadoDespacho(int estado) {
    switch (estado) {
        case 1: return "En proceso";
        case 2: return "Finalizado";
    }
    return "Desconocido";
}

void limpiarPantalla() {
    // Secuencia ANSI: borra la pantalla y coloca el cursor arriba.
    cout << "\033[2J\033[3J\033[H";
    cout.flush();
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cout.flush();
    string linea;
    getline(cin, linea);
}
