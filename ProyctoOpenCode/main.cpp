#include <iostream>
#include <string>
#include "Utilidades.h"
#include "PersonaF.h"
#include "Empresa.h"
#include "Colaborador.h"
#include "Bodega.h"
#include "Paquete.h"
#include "Solicitud.h"
#include "Despacho.h"
#include "Centro.h"
#include "ListaCentros.h"
using namespace std;

// ---------------- Entrada de datos ----------------
string leerLinea(string mensaje) {
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return quitarEspacios(valor);
}

int leerEntero(string mensaje, int minimo, int maximo) {
    while (true) {
        string texto = leerLinea(mensaje);
        int valor = aEntero(texto, minimo - 1);
        if (valor >= minimo && valor <= maximo) {
            return valor;
        }
        cout << "Valor invalido. Debe estar entre " << minimo << " y " << maximo << "." << endl;
    }
}

double leerDecimal(string mensaje) {
    while (true) {
        string texto = leerLinea(mensaje);
        double valor = aDecimal(texto, -1);
        if (valor > 0) {
            return valor;
        }
        cout << "Valor invalido. Debe ser mayor que cero." << endl;
    }
}

double leerPorcentaje(string mensaje) {
    while (true) {
        string texto = leerLinea(mensaje);
        double valor = aDecimal(texto, -1);
        if (valor >= 0 && valor <= 100) {
            return valor;
        }
        cout << "Valor invalido. Debe estar entre 0 y 100." << endl;
    }
}

// ---------------- Busquedas globales ----------------
bool existePaqueteGlobal(ListaCentros& centros, string codigo) {
    for (int i = 0; i < centros.tamanio(); i++) {
        Centro* c = centros.obtener(i);
        if (c->buscarPaquete(codigo) != nullptr) {
            return true;
        }
    }
    return false;
}

bool existeSolicitudGlobal(ListaCentros& centros, string codigo) {
    for (int i = 0; i < centros.tamanio(); i++) {
        Centro* c = centros.obtener(i);
        if (c->buscarSolicitud(codigo) != nullptr) {
            return true;
        }
    }
    return false;
}

bool existeDespachoGlobal(ListaCentros& centros, string codigo) {
    for (int i = 0; i < centros.tamanio(); i++) {
        Centro* c = centros.obtener(i);
        if (c->buscarDespacho(codigo) != nullptr) {
            return true;
        }
    }
    return false;
}

void menuBusquedasGlobales(ListaCentros& centros) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== BUSQUEDAS GLOBALES =====" << endl;
        cout << "1. Buscar paquete por codigo" << endl;
        cout << "2. Buscar solicitud por codigo" << endl;
        cout << "3. Buscar despacho por codigo" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ", 0, 3);

        if (opcion == 1) {
            string codigo = leerLinea("Codigo del paquete: ");
            bool encontrado = false;
            for (int i = 0; i < centros.tamanio() && !encontrado; i++) {
                Centro* c = centros.obtener(i);
                Paquete* paquete = c->buscarPaquete(codigo);
                if (paquete != nullptr) {
                    cout << "Centro: " << c->getCodigo() << " - " << c->getNombre() << endl;
                    paquete->mostrar();
                    encontrado = true;
                }
            }
            if (!encontrado) {
                cout << "Paquete no encontrado en el sistema." << endl;
            }
        } else if (opcion == 2) {
            string codigo = leerLinea("Codigo de la solicitud: ");
            bool encontrado = false;
            for (int i = 0; i < centros.tamanio() && !encontrado; i++) {
                Centro* c = centros.obtener(i);
                Solicitud* solicitud = c->buscarSolicitud(codigo);
                if (solicitud != nullptr) {
                    cout << "Centro: " << c->getCodigo() << " - " << c->getNombre() << endl;
                    solicitud->mostrar();
                    encontrado = true;
                }
            }
            if (!encontrado) {
                cout << "Solicitud no encontrada en el sistema." << endl;
            }
        } else if (opcion == 3) {
            string codigo = leerLinea("Codigo del despacho: ");
            bool encontrado = false;
            for (int i = 0; i < centros.tamanio() && !encontrado; i++) {
                Centro* c = centros.obtener(i);
                Despacho* despacho = c->buscarDespacho(codigo);
                if (despacho != nullptr) {
                    cout << "Centro: " << c->getCodigo() << " - " << c->getNombre() << endl;
                    despacho->mostrar();
                    encontrado = true;
                }
            }
            if (!encontrado) {
                cout << "Despacho no encontrado en el sistema." << endl;
            }
        }
        if (opcion != 0) {
            pausar();
        }
    } while (opcion != 0);
}

// ---------------- Submenus ----------------
void menuClientes(Centro* centro) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== CLIENTES =====" << endl;
        cout << "1. Registrar persona fisica" << endl;
        cout << "2. Registrar empresa" << endl;
        cout << "3. Buscar cliente" << endl;
        cout << "4. Mostrar todos" << endl;
        cout << "5. Eliminar cliente" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ", 0, 5);

        if (opcion == 1) {
            string id = leerLinea("Identificacion: ");
            string nom = leerLinea("Nombre: ");
            string tel = leerLinea("Telefono: ");
            string corr = leerLinea("Correo: ");
            PersonaF* cliente = new PersonaF(id, nom, tel, corr);
            if (!centro->registrarCliente(cliente)) {
                delete cliente;
            }
        } else if (opcion == 2) {
            string id = leerLinea("Identificacion: ");
            string nom = leerLinea("Nombre: ");
            string tel = leerLinea("Telefono: ");
            string corr = leerLinea("Correo: ");
            string actividad = leerLinea("Actividad economica: ");
            double descuento = leerPorcentaje("Porcentaje de descuento (0-100): ");
            Empresa* cliente = new Empresa(id, nom, tel, corr, actividad, descuento);
            if (!centro->registrarCliente(cliente)) {
                delete cliente;
            }
        } else if (opcion == 3) {
            string id = leerLinea("Identificacion a buscar: ");
            Cliente* cliente = centro->buscarCliente(id);
            if (cliente != nullptr) {
                cliente->mostrar();
            } else {
                cout << "Cliente no encontrado." << endl;
            }
        } else if (opcion == 4) {
            centro->mostrarClientes();
        } else if (opcion == 5) {
            string id = leerLinea("Identificacion a eliminar: ");
            centro->eliminarCliente(id);
        }
        if (opcion != 0) {
            pausar();
        }
    } while (opcion != 0);
}

void menuColaboradores(Centro* centro) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== COLABORADORES =====" << endl;
        cout << "1. Registrar colaborador" << endl;
        cout << "2. Buscar colaborador" << endl;
        cout << "3. Mostrar todos" << endl;
        cout << "4. Eliminar colaborador" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ", 0, 4);

        if (opcion == 1) {
            string id = leerLinea("Identificacion: ");
            string nom = leerLinea("Nombre completo: ");
            string fecha = leerLinea("Fecha de ingreso: ");
            string puesto = leerLinea("Puesto: ");
            Colaborador* colaborador = new Colaborador(id, nom, fecha, puesto);
            if (!centro->registrarColaborador(colaborador)) {
                delete colaborador;
            }
        } else if (opcion == 2) {
            string id = leerLinea("Identificacion a buscar: ");
            Colaborador* colaborador = centro->buscarColaborador(id);
            if (colaborador != nullptr) {
                colaborador->mostrar();
            } else {
                cout << "Colaborador no encontrado." << endl;
            }
        } else if (opcion == 3) {
            centro->mostrarColaboradores();
        } else if (opcion == 4) {
            string id = leerLinea("Identificacion a eliminar: ");
            centro->eliminarColaborador(id);
        }
        if (opcion != 0) {
            pausar();
        }
    } while (opcion != 0);
}

void menuBodegas(Centro* centro) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== BODEGAS =====" << endl;
        cout << "1. Registrar bodega" << endl;
        cout << "2. Buscar bodega" << endl;
        cout << "3. Mostrar bodegas" << endl;
        cout << "4. Consultar matrices" << endl;
        cout << "5. Eliminar bodega" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ", 0, 5);

        if (opcion == 1) {
            string codigo = leerLinea("Codigo de la bodega: ");
            string nombre = leerLinea("Nombre: ");
            cout << "Tipos: 1 General, 2 Fragil, 3 Tecnologia, 4 Documentos" << endl;
            int tipo = leerEntero("Tipo: ", 1, 4);
            int filas = leerEntero("Cantidad de filas: ", 1, 100);
            int columnas = leerEntero("Cantidad de columnas: ", 1, 100);
            Bodega* bodega = new Bodega(codigo, nombre, tipo, filas, columnas);
            if (!centro->registrarBodega(bodega)) {
                delete bodega;
            }
        } else if (opcion == 2) {
            string codigo = leerLinea("Codigo a buscar: ");
            Bodega* bodega = centro->buscarBodega(codigo);
            if (bodega != nullptr) {
                bodega->mostrar();
                bodega->mostrarCeldasLibres();
            } else {
                cout << "Bodega no encontrada." << endl;
            }
        } else if (opcion == 3) {
            centro->mostrarBodegas();
        } else if (opcion == 4) {
            centro->mostrarMatrices();
        } else if (opcion == 5) {
            string codigo = leerLinea("Codigo a eliminar: ");
            centro->eliminarBodega(codigo);
        }
        if (opcion != 0) {
            pausar();
        }
    } while (opcion != 0);
}

void registrarPaquete(Centro* centro, ListaCentros& centros) {
    string codigo = leerLinea("Codigo del paquete: ");
    if (existePaqueteGlobal(centros, codigo)) {
        cout << "Ya existe un paquete con ese codigo en el sistema." << endl;
        return;
    }
    string descripcion = leerLinea("Descripcion: ");
    double peso = leerDecimal("Peso en kg: ");
    cout << "Categorias: 1 General, 2 Fragil, 3 Tecnologia, 4 Documentos" << endl;
    int categoria = leerEntero("Categoria: ", 1, 4);
    string idCliente = leerLinea("Identificacion del cliente propietario: ");
    Cliente* cliente = centro->buscarCliente(idCliente);
    if (cliente == nullptr) {
        cout << "El cliente no existe en este centro." << endl;
        return;
    }
    Paquete* paquete = new Paquete(codigo, descripcion, peso, categoria, cliente, centro);
    if (!centro->registrarPaquete(paquete)) {
        delete paquete;
    }
}

void almacenarPaqueteConCodigo(Centro* centro, string codigo) {
    Paquete* paquete = centro->buscarPaquete(codigo);
    if (paquete == nullptr) {
        cout << "Paquete no encontrado." << endl;
        return;
    }
    Bodega* recomendada = centro->recomendarBodega(paquete->getCategoria());
    if (recomendada == nullptr) {
        cout << "No existe una bodega compatible con espacio disponible." << endl;
        return;
    }
    int fila = -1;
    int columna = -1;
    recomendada->primeraLibre(fila, columna);
    cout << "Recomendacion: bodega " << recomendada->getCodigo()
         << " celda " << recomendada->codigoCelda(fila, columna) << endl;
    int aceptar = leerEntero("Aceptar recomendacion? 1 Si / 2 Elegir otra: ", 1, 2);
    string codigoBodega = recomendada->getCodigo();
    if (aceptar == 2) {
        codigoBodega = leerLinea("Codigo de bodega compatible: ");
        Bodega* bodega = centro->buscarBodega(codigoBodega);
        if (bodega == nullptr) {
            cout << "Bodega no encontrada." << endl;
            return;
        }
        bodega->mostrarCeldasLibres();
        fila = leerEntero("Fila: ", 0, bodega->getFilas() - 1);
        columna = leerEntero("Columna: ", 0, bodega->getColumnas() - 1);
    }
    string idResponsable = leerLinea("Identificacion del colaborador responsable: ");
    Colaborador* responsable = centro->buscarColaborador(idResponsable);
    if (responsable == nullptr) {
        cout << "Colaborador no encontrado." << endl;
        return;
    }
    string fecha = leerLinea("Fecha del cambio: ");
    centro->almacenarPaquete(codigo, codigoBodega, fila, columna, fecha, responsable);
}

void almacenarPaquete(Centro* centro) {
    string codigo = leerLinea("Codigo del paquete: ");
    almacenarPaqueteConCodigo(centro, codigo);
}

void cambiarEstadoPaquete(Centro* centro) {
    cout << "\n1. Reportar incidencia" << endl;
    cout << "2. Resolver incidencia" << endl;
    cout << "0. Volver" << endl;
    int opcion = leerEntero("Opcion: ", 0, 2);
    if (opcion == 0) {
        return;
    }
    string codigo = leerLinea("Codigo del paquete: ");
    Paquete* paquete = centro->buscarPaquete(codigo);
    if (paquete == nullptr) {
        cout << "Paquete no encontrado." << endl;
        return;
    }
    string idResponsable = leerLinea("Identificacion del colaborador responsable: ");
    Colaborador* responsable = centro->buscarColaborador(idResponsable);
    if (responsable == nullptr) {
        cout << "Colaborador no encontrado." << endl;
        return;
    }
    string fecha = leerLinea("Fecha del cambio: ");
    if (opcion == 1) {
        if (paquete->cambiarEstado(5, fecha, responsable)) {
            cout << "Incidencia registrada." << endl;
        } else {
            cout << "El paquete no puede pasar a Incidencia desde su estado actual." << endl;
        }
    } else {
        if (paquete->getEstado() != 5) {
            cout << "El paquete no esta en Incidencia." << endl;
            return;
        }
        if (paquete->tieneUbicacion()) {
            cout << "El paquete conserva su celda. La incidencia se resuelve volviendo a Almacenado." << endl;
            if (paquete->cambiarEstado(2, fecha, responsable)) {
                cout << "Incidencia resuelta." << endl;
            }
        } else {
            Despacho* despacho = centro->buscarDespachoPorPaquete(paquete);
            bool despachoEnProceso = despacho != nullptr && despacho->getEstado() == 1;
            if (despachoEnProceso) {
                cout << "El paquete pertenece a un despacho En proceso; solo puede volver a En transito." << endl;
                centro->resolverIncidencia(codigo, 3, fecha, responsable);
            } else {
                cout << "El paquete no tiene ubicacion; debe almacenarse para volver a Almacenado." << endl;
                almacenarPaqueteConCodigo(centro, codigo);
            }
        }
    }
}

void menuPaquetes(Centro* centro, ListaCentros& centros) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== PAQUETES =====" << endl;
        cout << "1. Registrar paquete" << endl;
        cout << "2. Buscar paquete" << endl;
        cout << "3. Mostrar paquetes" << endl;
        cout << "4. Almacenar paquete" << endl;
        cout << "5. Reubicar paquete" << endl;
        cout << "6. Cambiar estado / incidencia" << endl;
        cout << "7. Ver bitacora" << endl;
        cout << "8. Eliminar paquete" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ", 0, 8);

        if (opcion == 1) {
            registrarPaquete(centro, centros);
        } else if (opcion == 2) {
            string codigo = leerLinea("Codigo a buscar: ");
            Paquete* paquete = centro->buscarPaquete(codigo);
            if (paquete != nullptr) {
                paquete->mostrar();
            } else {
                cout << "Paquete no encontrado." << endl;
            }
        } else if (opcion == 3) {
            centro->mostrarPaquetes();
        } else if (opcion == 4) {
            almacenarPaquete(centro);
        } else if (opcion == 5) {
            string codigo = leerLinea("Codigo del paquete: ");
            string codigoBodega = leerLinea("Codigo de bodega destino: ");
            Bodega* bodega = centro->buscarBodega(codigoBodega);
            if (bodega == nullptr) {
                cout << "Bodega no encontrada." << endl;
            } else {
                int fila = leerEntero("Fila: ", 0, bodega->getFilas() - 1);
                int columna = leerEntero("Columna: ", 0, bodega->getColumnas() - 1);
                centro->reubicarPaquete(codigo, codigoBodega, fila, columna);
            }
        } else if (opcion == 6) {
            cambiarEstadoPaquete(centro);
        } else if (opcion == 7) {
            string codigo = leerLinea("Codigo del paquete: ");
            Paquete* paquete = centro->buscarPaquete(codigo);
            if (paquete != nullptr) {
                paquete->mostrarBitacora();
            } else {
                cout << "Paquete no encontrado." << endl;
            }
        } else if (opcion == 8) {
            string codigo = leerLinea("Codigo a eliminar: ");
            centro->eliminarPaquete(codigo);
        }
        if (opcion != 0) {
            pausar();
        }
    } while (opcion != 0);
}

void menuSolicitudes(Centro* centro, ListaCentros& centros) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== SOLICITUDES =====" << endl;
        cout << "1. Crear solicitud" << endl;
        cout << "2. Buscar solicitud" << endl;
        cout << "3. Mostrar solicitudes" << endl;
        cout << "4. Aprobar solicitud" << endl;
        cout << "5. Rechazar solicitud" << endl;
        cout << "6. Anular solicitud" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ", 0, 6);

        if (opcion == 1) {
            string codigo = leerLinea("Codigo de la solicitud: ");
            if (existeSolicitudGlobal(centros, codigo)) {
                cout << "Ya existe una solicitud con ese codigo en el sistema." << endl;
            } else {
                string codigoPaquete = leerLinea("Codigo del paquete: ");
                Paquete* paquete = centro->buscarPaquete(codigoPaquete);
                if (paquete == nullptr) {
                    cout << "Paquete no encontrado." << endl;
                } else {
                    string idColaborador = leerLinea("Identificacion del colaborador responsable: ");
                    Colaborador* responsable = centro->buscarColaborador(idColaborador);
                    if (responsable == nullptr) {
                        cout << "Colaborador no encontrado." << endl;
                    } else {
                        string destino = leerLinea("Destino de entrega: ");
                        string fecha = leerLinea("Fecha de la solicitud: ");
                        Solicitud* solicitud = new Solicitud(codigo, paquete->getPropietario(),
                                                             paquete, responsable, centro, destino, fecha);
                        if (!centro->crearSolicitud(solicitud)) {
                            delete solicitud;
                        }
                    }
                }
            }
        } else if (opcion == 2) {
            string codigo = leerLinea("Codigo a buscar: ");
            Solicitud* solicitud = centro->buscarSolicitud(codigo);
            if (solicitud != nullptr) {
                solicitud->mostrar();
            } else {
                cout << "Solicitud no encontrada." << endl;
            }
        } else if (opcion == 3) {
            centro->mostrarSolicitudes();
        } else if (opcion == 4) {
            string codigo = leerLinea("Codigo de la solicitud: ");
            string fecha = leerLinea("Fecha de aprobacion: ");
            string codigoDespacho = leerLinea("Codigo del despacho a crear: ");
            if (existeDespachoGlobal(centros, codigoDespacho)) {
                cout << "Ya existe un despacho con ese codigo en el sistema." << endl;
            } else {
                string hora = leerLinea("Hora del despacho: ");
                centro->aprobarSolicitud(codigo, fecha, codigoDespacho, hora);
            }
        } else if (opcion == 5) {
            string codigo = leerLinea("Codigo de la solicitud: ");
            centro->rechazarSolicitud(codigo);
        } else if (opcion == 6) {
            string codigo = leerLinea("Codigo de la solicitud: ");
            centro->anularSolicitud(codigo);
        }
        if (opcion != 0) {
            pausar();
        }
    } while (opcion != 0);
}

void menuDespachos(Centro* centro) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== DESPACHOS =====" << endl;
        cout << "1. Buscar despacho" << endl;
        cout << "2. Mostrar despachos" << endl;
        cout << "3. Finalizar entrega" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ", 0, 3);

        if (opcion == 1) {
            string codigo = leerLinea("Codigo a buscar: ");
            Despacho* despacho = centro->buscarDespacho(codigo);
            if (despacho != nullptr) {
                despacho->mostrar();
            } else {
                cout << "Despacho no encontrado." << endl;
            }
        } else if (opcion == 2) {
            centro->mostrarDespachos();
        } else if (opcion == 3) {
            string codigo = leerLinea("Codigo del despacho: ");
            string fecha = leerLinea("Fecha de finalizacion: ");
            centro->finalizarDespacho(codigo, fecha);
        }
        if (opcion != 0) {
            pausar();
        }
    } while (opcion != 0);
}

void menuReportes(Centro* centro) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== REPORTES DEL CENTRO =====" << endl;
        cout << "1. Historial de un cliente" << endl;
        cout << "2. Clientes por cantidad de envios" << endl;
        cout << "3. Bitacora de un paquete" << endl;
        cout << "4. Consulta de despacho de un paquete" << endl;
        cout << "5. Ocupacion de bodegas" << endl;
        cout << "6. Despachos por colaborador" << endl;
        cout << "7. Paquetes por estado" << endl;
        cout << "8. Mostrar toda la informacion" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ", 0, 8);

        if (opcion == 1) {
            string id = leerLinea("Identificacion del cliente: ");
            centro->reporteHistorialCliente(id);
        } else if (opcion == 2) {
            centro->reporteClientesPorEnvios();
        } else if (opcion == 3) {
            string codigo = leerLinea("Codigo del paquete: ");
            centro->reporteBitacoraPaquete(codigo);
        } else if (opcion == 4) {
            string codigo = leerLinea("Codigo del paquete: ");
            centro->reporteDespachoDePaquete(codigo);
        } else if (opcion == 5) {
            centro->reporteOcupacion();
        } else if (opcion == 6) {
            string id = leerLinea("Identificacion del colaborador: ");
            centro->reporteDespachosPorColaborador(id);
        } else if (opcion == 7) {
            centro->reportePaquetesPorEstado();
        } else if (opcion == 8) {
            cout << "\n--- CLIENTES ---" << endl;
            centro->mostrarClientes();
            cout << "\n--- COLABORADORES ---" << endl;
            centro->mostrarColaboradores();
            cout << "\n--- BODEGAS ---" << endl;
            centro->mostrarBodegas();
            cout << "\n--- PAQUETES ---" << endl;
            centro->mostrarPaquetes();
            cout << "\n--- SOLICITUDES ---" << endl;
            centro->mostrarSolicitudes();
            cout << "\n--- DESPACHOS ---" << endl;
            centro->mostrarDespachos();
        }
        if (opcion != 0) {
            pausar();
        }
    } while (opcion != 0);
}

void menuCentro(Centro* centro, ListaCentros& centros) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== CENTRO " << centro->getCodigo() << " - " << centro->getNombre() << " =====" << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Colaboradores" << endl;
        cout << "3. Bodegas" << endl;
        cout << "4. Paquetes" << endl;
        cout << "5. Solicitudes" << endl;
        cout << "6. Despachos" << endl;
        cout << "7. Reportes" << endl;
        cout << "0. Volver al menu principal" << endl;
        opcion = leerEntero("Opcion: ", 0, 7);

        if (opcion == 1) {
            menuClientes(centro);
        } else if (opcion == 2) {
            menuColaboradores(centro);
        } else if (opcion == 3) {
            menuBodegas(centro);
        } else if (opcion == 4) {
            menuPaquetes(centro, centros);
        } else if (opcion == 5) {
            menuSolicitudes(centro, centros);
        } else if (opcion == 6) {
            menuDespachos(centro);
        } else if (opcion == 7) {
            menuReportes(centro);
        }
    } while (opcion != 0);
}

// ---------------- Programa principal ----------------
int main() {
    ListaCentros centros;
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n=====================================================" << endl;
        cout << "   TicoPack Logistics - Red de Centros de Distribucion" << endl;
        cout << "=====================================================" << endl;
        cout << "1. Registrar centro" << endl;
        cout << "2. Buscar centro" << endl;
        cout << "3. Mostrar centros" << endl;
        cout << "4. Eliminar centro" << endl;
        cout << "5. Seleccionar centro" << endl;
        cout << "6. Busquedas globales (paquete, solicitud, despacho)" << endl;
        cout << "0. Salir" << endl;
        opcion = leerEntero("Opcion: ", 0, 6);

        if (opcion == 1) {
            string codigo = leerLinea("Codigo del centro: ");
            string nombre = leerLinea("Nombre: ");
            string provincia = leerLinea("Provincia: ");
            string direccion = leerLinea("Direccion: ");
            string telefono = leerLinea("Telefono: ");
            Centro* centro = new Centro(codigo, nombre, provincia, direccion, telefono);
            if (!centros.registrar(centro)) {
                delete centro;
            }
        } else if (opcion == 2) {
            string codigo = leerLinea("Codigo a buscar: ");
            Centro* centro = centros.buscar(codigo);
            if (centro != nullptr) {
                centro->mostrar();
            } else {
                cout << "Centro no encontrado." << endl;
            }
        } else if (opcion == 3) {
            centros.mostrarTodos();
        } else if (opcion == 4) {
            string codigo = leerLinea("Codigo a eliminar: ");
            centros.eliminar(codigo);
        } else if (opcion == 5) {
            string codigo = leerLinea("Codigo del centro: ");
            Centro* centro = centros.buscar(codigo);
            if (centro != nullptr) {
                menuCentro(centro, centros);
            } else {
                cout << "Centro no encontrado." << endl;
                pausar();
            }
        } else if (opcion == 6) {
            menuBusquedasGlobales(centros);
        }
        if (opcion >= 1 && opcion <= 4) {
            pausar();
        }
    } while (opcion != 0);

    cout << "Gracias por usar TicoPack Logistics." << endl;
    return 0;
}
