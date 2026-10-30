#include "Centro.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

Centro::Centro() {
    codigo = "";
    nombre = "";
    provincia = "";
    direccion = "";
    telefono = "";
    clientes = new ListaClientes();
    colaboradores = new ListaColaboradores();
    bodegas = new ListaBodegas();
    paquetes = new ListaPaquetes();
    solicitudes = new ListaSolicitudes();
    despachos = new ListaDespachos();
}

Centro::Centro(string cod, string nom, string prov, string dir, string tel) {
    codigo = cod;
    nombre = nom;
    provincia = prov;
    direccion = dir;
    telefono = tel;
    clientes = new ListaClientes();
    colaboradores = new ListaColaboradores();
    bodegas = new ListaBodegas();
    paquetes = new ListaPaquetes();
    solicitudes = new ListaSolicitudes();
    despachos = new ListaDespachos();
}

Centro::~Centro() {
    for (int i = 0; i < clientes->tamanio(); i++) delete clientes->obtener(i);
    for (int i = 0; i < colaboradores->tamanio(); i++) delete colaboradores->obtener(i);
    for (int i = 0; i < bodegas->tamanio(); i++) delete bodegas->obtener(i);
    for (int i = 0; i < paquetes->tamanio(); i++) delete paquetes->obtener(i);
    for (int i = 0; i < solicitudes->tamanio(); i++) delete solicitudes->obtener(i);
    for (int i = 0; i < despachos->tamanio(); i++) delete despachos->obtener(i);
    delete clientes;
    delete colaboradores;
    delete bodegas;
    delete paquetes;
    delete solicitudes;
    delete despachos;
}

string Centro::getCodigo() const { return codigo; }
string Centro::getNombre() const { return nombre; }
string Centro::getProvincia() const { return provincia; }
string Centro::getDireccion() const { return direccion; }
string Centro::getTelefono() const { return telefono; }
void Centro::setNombre(string nom) { nombre = nom; }
void Centro::setProvincia(string prov) { provincia = prov; }
void Centro::setDireccion(string dir) { direccion = dir; }
void Centro::setTelefono(string tel) { telefono = tel; }

bool Centro::datosValidos() const {
    return codigo != "" && nombre != "" && provincia != "" && direccion != "" && telefono != "";
}

void Centro::mostrar() const {
    cout << "******************* CENTRO DE DISTRIBUCION **************************" << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Provincia: " << provincia << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
}

bool Centro::tieneDatosAsociados() const {
    return !clientes->estaVacia() || !colaboradores->estaVacia() || !bodegas->estaVacia()
           || !paquetes->estaVacia() || !solicitudes->estaVacia() || !despachos->estaVacia();
}

ListaClientes* Centro::getClientes() const { return clientes; }
ListaColaboradores* Centro::getColaboradores() const { return colaboradores; }
ListaBodegas* Centro::getBodegas() const { return bodegas; }
ListaPaquetes* Centro::getPaquetes() const { return paquetes; }
ListaSolicitudes* Centro::getSolicitudes() const { return solicitudes; }
ListaDespachos* Centro::getDespachos() const { return despachos; }

// ---------------- Clientes ----------------
bool Centro::registrarCliente(Cliente* cliente) {
    if (cliente == nullptr || !cliente->datosValidos()) {
        cout << "Datos del cliente invalidos." << endl;
        return false;
    }
    if (buscarCliente(cliente->getIdentificacion()) != nullptr) {
        cout << "Ya existe un cliente con esa identificacion en el centro." << endl;
        return false;
    }
    clientes->agregar(cliente);
    cout << "Cliente registrado correctamente." << endl;
    return true;
}

Cliente* Centro::buscarCliente(string identificacion) const {
    for (int i = 0; i < clientes->tamanio(); i++) {
        Cliente* c = clientes->obtener(i);
        if (c->getIdentificacion() == identificacion) {
            return c;
        }
    }
    return nullptr;
}

bool Centro::eliminarCliente(string identificacion) {
    Cliente* cliente = buscarCliente(identificacion);
    if (cliente == nullptr) {
        cout << "Cliente no encontrado." << endl;
        return false;
    }
    for (int i = 0; i < paquetes->tamanio(); i++) {
        if (paquetes->obtener(i)->getPropietario() == cliente) {
            cout << "No se puede eliminar: el cliente tiene paquetes asociados." << endl;
            return false;
        }
    }
    for (int i = 0; i < solicitudes->tamanio(); i++) {
        if (solicitudes->obtener(i)->getCliente() == cliente) {
            cout << "No se puede eliminar: el cliente tiene solicitudes asociadas." << endl;
            return false;
        }
    }
    for (int i = 0; i < despachos->tamanio(); i++) {
        if (despachos->obtener(i)->getCliente() == cliente) {
            cout << "No se puede eliminar: el cliente tiene despachos asociados." << endl;
            return false;
        }
    }
    clientes->eliminar(cliente);
    delete cliente;
    cout << "Cliente eliminado correctamente." << endl;
    return true;
}

void Centro::mostrarClientes() const {
    if (clientes->estaVacia()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }
    for (int i = 0; i < clientes->tamanio(); i++) {
        clientes->obtener(i)->mostrar();
    }
}

// ---------------- Colaboradores ----------------
bool Centro::registrarColaborador(Colaborador* colaborador) {
    if (colaborador == nullptr || !colaborador->datosValidos()) {
        cout << "Datos del colaborador invalidos." << endl;
        return false;
    }
    if (buscarColaborador(colaborador->getIdentificacion()) != nullptr) {
        cout << "Ya existe un colaborador con esa identificacion en el centro." << endl;
        return false;
    }
    colaboradores->agregar(colaborador);
    cout << "Colaborador registrado correctamente." << endl;
    return true;
}

Colaborador* Centro::buscarColaborador(string identificacion) const {
    for (int i = 0; i < colaboradores->tamanio(); i++) {
        Colaborador* c = colaboradores->obtener(i);
        if (c->getIdentificacion() == identificacion) {
            return c;
        }
    }
    return nullptr;
}

bool Centro::eliminarColaborador(string identificacion) {
    Colaborador* colaborador = buscarColaborador(identificacion);
    if (colaborador == nullptr) {
        cout << "Colaborador no encontrado." << endl;
        return false;
    }
    for (int i = 0; i < solicitudes->tamanio(); i++) {
        if (solicitudes->obtener(i)->getResponsable() == colaborador) {
            cout << "No se puede eliminar: el colaborador es responsable de solicitudes." << endl;
            return false;
        }
    }
    for (int i = 0; i < despachos->tamanio(); i++) {
        if (despachos->obtener(i)->getResponsable() == colaborador) {
            cout << "No se puede eliminar: el colaborador es responsable de despachos." << endl;
            return false;
        }
    }
    for (int i = 0; i < paquetes->tamanio(); i++) {
        if (paquetes->obtener(i)->tieneBitacoraDe(colaborador)) {
            cout << "No se puede eliminar: el colaborador aparece en una bitacora." << endl;
            return false;
        }
    }
    colaboradores->eliminar(colaborador);
    delete colaborador;
    cout << "Colaborador eliminado correctamente." << endl;
    return true;
}

void Centro::mostrarColaboradores() const {
    if (colaboradores->estaVacia()) {
        cout << "No hay colaboradores registrados." << endl;
        return;
    }
    for (int i = 0; i < colaboradores->tamanio(); i++) {
        colaboradores->obtener(i)->mostrar();
    }
}

// ---------------- Bodegas ----------------
bool Centro::registrarBodega(Bodega* bodega) {
    if (bodega == nullptr || !bodega->datosValidos()) {
        cout << "Datos de la bodega invalidos." << endl;
        return false;
    }
    if (buscarBodega(bodega->getCodigo()) != nullptr) {
        cout << "Ya existe una bodega con ese codigo en el centro." << endl;
        return false;
    }
    bodegas->agregar(bodega);
    cout << "Bodega registrada correctamente." << endl;
    return true;
}

Bodega* Centro::buscarBodega(string codigoBodega) const {
    for (int i = 0; i < bodegas->tamanio(); i++) {
        Bodega* b = bodegas->obtener(i);
        if (b->getCodigo() == codigoBodega) {
            return b;
        }
    }
    return nullptr;
}

bool Centro::eliminarBodega(string codigoBodega) {
    Bodega* bodega = buscarBodega(codigoBodega);
    if (bodega == nullptr) {
        cout << "Bodega no encontrada." << endl;
        return false;
    }
    if (!bodega->estaVacia()) {
        cout << "No se puede eliminar: la bodega tiene celdas ocupadas." << endl;
        return false;
    }
    for (int i = 0; i < paquetes->tamanio(); i++) {
        if (paquetes->obtener(i)->getBodega() == bodega) {
            cout << "No se puede eliminar: hay paquetes asignados a la bodega." << endl;
            return false;
        }
    }
    bodegas->eliminar(bodega);
    delete bodega;
    cout << "Bodega eliminada correctamente." << endl;
    return true;
}

void Centro::mostrarBodegas() const {
    if (bodegas->estaVacia()) {
        cout << "No hay bodegas registradas." << endl;
        return;
    }
    for (int i = 0; i < bodegas->tamanio(); i++) {
        bodegas->obtener(i)->mostrar();
    }
}

void Centro::mostrarMatrices() const {
    if (bodegas->estaVacia()) {
        cout << "No hay bodegas registradas." << endl;
        return;
    }
    for (int i = 0; i < bodegas->tamanio(); i++) {
        bodegas->obtener(i)->mostrarMatriz();
    }
}

// ---------------- Paquetes ----------------
bool Centro::registrarPaquete(Paquete* paquete) {
    if (paquete == nullptr || !paquete->datosValidos()) {
        cout << "Datos del paquete invalidos." << endl;
        return false;
    }
    if (buscarPaquete(paquete->getCodigo()) != nullptr) {
        cout << "Ya existe un paquete con ese codigo en el centro." << endl;
        return false;
    }
    if (paquete->getCentro() != this) {
        cout << "El paquete no pertenece a este centro." << endl;
        return false;
    }
    if (buscarCliente(paquete->getPropietario()->getIdentificacion()) == nullptr) {
        cout << "El cliente propietario no pertenece a este centro." << endl;
        return false;
    }
    paquetes->agregar(paquete);
    cout << "Paquete registrado correctamente." << endl;
    return true;
}

Paquete* Centro::buscarPaquete(string codigoPaquete) const {
    for (int i = 0; i < paquetes->tamanio(); i++) {
        Paquete* p = paquetes->obtener(i);
        if (p->getCodigo() == codigoPaquete) {
            return p;
        }
    }
    return nullptr;
}

bool Centro::eliminarPaquete(string codigoPaquete) {
    Paquete* paquete = buscarPaquete(codigoPaquete);
    if (paquete == nullptr) {
        cout << "Paquete no encontrado." << endl;
        return false;
    }
    if (paquete->getEstado() != 1) {
        cout << "No se puede eliminar: el paquete no esta en estado Recibido." << endl;
        return false;
    }
    if (paquete->tieneUbicacion()) {
        cout << "No se puede eliminar: el paquete tiene una celda asignada." << endl;
        return false;
    }
    for (int i = 0; i < solicitudes->tamanio(); i++) {
        if (solicitudes->obtener(i)->getPaquete() == paquete) {
            cout << "No se puede eliminar: el paquete tiene solicitudes asociadas." << endl;
            return false;
        }
    }
    for (int i = 0; i < despachos->tamanio(); i++) {
        if (despachos->obtener(i)->getPaquete() == paquete) {
            cout << "No se puede eliminar: el paquete tiene despachos asociados." << endl;
            return false;
        }
    }
    paquetes->eliminar(paquete);
    delete paquete;
    cout << "Paquete eliminado correctamente." << endl;
    return true;
}

void Centro::mostrarPaquetes() const {
    if (paquetes->estaVacia()) {
        cout << "No hay paquetes registrados." << endl;
        return;
    }
    for (int i = 0; i < paquetes->tamanio(); i++) {
        paquetes->obtener(i)->mostrar();
    }
}

// ---------------- Solicitudes ----------------
bool Centro::crearSolicitud(Solicitud* solicitud) {
    if (solicitud == nullptr || !solicitud->datosValidos()) {
        cout << "Datos de la solicitud invalidos." << endl;
        return false;
    }
    if (buscarSolicitud(solicitud->getCodigo()) != nullptr) {
        cout << "Ya existe una solicitud con ese codigo en el centro." << endl;
        return false;
    }
    if (solicitud->getCentroOrigen() != this) {
        cout << "La solicitud no pertenece a este centro." << endl;
        return false;
    }
    Paquete* paquete = solicitud->getPaquete();
    if (buscarPaquete(paquete->getCodigo()) != paquete) {
        cout << "El paquete no pertenece a este centro." << endl;
        return false;
    }
    if (paquete->getEstado() != 2) {
        cout << "Solo se puede crear una solicitud para un paquete Almacenado." << endl;
        return false;
    }
    if (solicitud->getCliente() != paquete->getPropietario()) {
        cout << "El cliente debe ser el propietario del paquete." << endl;
        return false;
    }
    if (buscarColaborador(solicitud->getResponsable()->getIdentificacion()) != solicitud->getResponsable()) {
        cout << "El colaborador responsable no pertenece a este centro." << endl;
        return false;
    }
    for (int i = 0; i < solicitudes->tamanio(); i++) {
        Solicitud* s = solicitudes->obtener(i);
        if (s->getPaquete() == paquete) {
            if (s->getEstado() == 1) {
                cout << "Ya existe una solicitud Pendiente para ese paquete." << endl;
                return false;
            }
            if (s->getEstado() == 2) {
                cout << "El paquete ya tiene una solicitud Aprobada y no admite nuevas." << endl;
                return false;
            }
        }
    }
    for (int i = 0; i < despachos->tamanio(); i++) {
        if (despachos->obtener(i)->getPaquete() == paquete) {
            cout << "El paquete ya tiene un despacho asociado." << endl;
            return false;
        }
    }
    solicitudes->agregar(solicitud);
    cout << "Solicitud creada correctamente." << endl;
    return true;
}

Solicitud* Centro::buscarSolicitud(string codigoSolicitud) const {
    for (int i = 0; i < solicitudes->tamanio(); i++) {
        Solicitud* s = solicitudes->obtener(i);
        if (s->getCodigo() == codigoSolicitud) {
            return s;
        }
    }
    return nullptr;
}

bool Centro::aprobarSolicitud(string codigoSolicitud, string fecha, string codigoDespacho, string hora) {
    Solicitud* solicitud = buscarSolicitud(codigoSolicitud);
    if (solicitud == nullptr) {
        cout << "Solicitud no encontrada." << endl;
        return false;
    }
    if (solicitud->getEstado() != 1) {
        cout << "Solo se puede aprobar una solicitud Pendiente." << endl;
        return false;
    }
    Paquete* paquete = solicitud->getPaquete();
    if (paquete->getEstado() != 2) {
        cout << "El paquete debe estar Almacenado para aprobar la solicitud." << endl;
        return false;
    }
    if (buscarDespachoPorPaquete(paquete) != nullptr) {
        cout << "El paquete ya tiene un despacho asociado." << endl;
        return false;
    }
    if (buscarDespacho(codigoDespacho) != nullptr) {
        cout << "Ya existe un despacho con ese codigo." << endl;
        return false;
    }
    if (paquete->tieneUbicacion()) {
        paquete->getBodega()->liberarPosicion(paquete->getFila(), paquete->getColumna());
        paquete->liberarUbicacion();
    }
    paquete->cambiarEstado(3, fecha, solicitud->getResponsable());
    solicitud->cambiarEstado(2);
    Despacho* despacho = new Despacho(codigoDespacho, solicitud, paquete, solicitud->getCliente(),
                                      solicitud->getResponsable(), this, solicitud->getDestino(), fecha, hora);
    despachos->agregar(despacho);
    cout << "Solicitud aprobada y despacho creado correctamente." << endl;
    return true;
}

bool Centro::rechazarSolicitud(string codigoSolicitud) {
    Solicitud* solicitud = buscarSolicitud(codigoSolicitud);
    if (solicitud == nullptr || solicitud->getEstado() != 1) {
        cout << "Solicitud no encontrada o no esta Pendiente." << endl;
        return false;
    }
    solicitud->cambiarEstado(3);
    cout << "Solicitud rechazada." << endl;
    return true;
}

bool Centro::anularSolicitud(string codigoSolicitud) {
    Solicitud* solicitud = buscarSolicitud(codigoSolicitud);
    if (solicitud == nullptr || solicitud->getEstado() != 1) {
        cout << "Solicitud no encontrada o no esta Pendiente." << endl;
        return false;
    }
    solicitud->cambiarEstado(4);
    cout << "Solicitud anulada." << endl;
    return true;
}

void Centro::mostrarSolicitudes() const {
    if (solicitudes->estaVacia()) {
        cout << "No hay solicitudes registradas." << endl;
        return;
    }
    for (int i = 0; i < solicitudes->tamanio(); i++) {
        solicitudes->obtener(i)->mostrar();
    }
}

// ---------------- Despachos ----------------
Despacho* Centro::buscarDespacho(string codigoDespacho) const {
    for (int i = 0; i < despachos->tamanio(); i++) {
        Despacho* d = despachos->obtener(i);
        if (d->getCodigo() == codigoDespacho) {
            return d;
        }
    }
    return nullptr;
}

Despacho* Centro::buscarDespachoPorPaquete(Paquete* paquete) const {
    for (int i = 0; i < despachos->tamanio(); i++) {
        if (despachos->obtener(i)->getPaquete() == paquete) {
            return despachos->obtener(i);
        }
    }
    return nullptr;
}

bool Centro::finalizarDespacho(string codigoDespacho, string fecha) {
    Despacho* despacho = buscarDespacho(codigoDespacho);
    if (despacho == nullptr) {
        cout << "Despacho no encontrado." << endl;
        return false;
    }
    if (despacho->getEstado() != 1) {
        cout << "El despacho ya esta finalizado." << endl;
        return false;
    }
    if (despacho->getPaquete()->getEstado() != 3) {
        cout << "El paquete debe estar En transito para finalizar la entrega." << endl;
        return false;
    }
    despacho->getPaquete()->cambiarEstado(4, fecha, despacho->getResponsable());
    despacho->finalizar();
    cout << "Despacho finalizado. Paquete entregado." << endl;
    return true;
}

void Centro::mostrarDespachos() const {
    if (despachos->estaVacia()) {
        cout << "No hay despachos registrados." << endl;
        return;
    }
    for (int i = 0; i < despachos->tamanio(); i++) {
        despachos->obtener(i)->mostrar();
    }
}

// ---------------- Almacenamiento ----------------
bool Centro::almacenarPaquete(string codigoPaquete, string codigoBodega, int fila, int columna,
                              string fecha, Colaborador* responsable) {
    Paquete* paquete = buscarPaquete(codigoPaquete);
    if (paquete == nullptr) {
        cout << "Paquete no encontrado." << endl;
        return false;
    }
    if (paquete->getEstado() != 1 && paquete->getEstado() != 5) {
        cout << "Solo se puede almacenar un paquete Recibido o en Incidencia sin ubicacion." << endl;
        return false;
    }
    if (paquete->tieneUbicacion()) {
        cout << "El paquete ya tiene una ubicacion asignada." << endl;
        return false;
    }
    if (buscarDespachoPorPaquete(paquete) != nullptr) {
        cout << "El paquete tiene un despacho asociado; no puede almacenarse." << endl;
        return false;
    }
    Bodega* bodega = buscarBodega(codigoBodega);
    if (bodega == nullptr) {
        cout << "Bodega no encontrada." << endl;
        return false;
    }
    if (bodega->getTipo() != paquete->getCategoria()) {
        cout << "La bodega no es compatible con la categoria del paquete." << endl;
        return false;
    }
    if (!bodega->posicionValida(fila, columna) || !bodega->estaLibre(fila, columna)) {
        cout << "La celda indicada no existe o no esta disponible." << endl;
        return false;
    }
    if (!bodega->asignarPaquete(fila, columna, paquete)) {
        cout << "No fue posible asignar la celda." << endl;
        return false;
    }
    paquete->asignarUbicacion(bodega, fila, columna);
    if (!paquete->cambiarEstado(2, fecha, responsable)) {
        bodega->liberarPosicion(fila, columna);
        paquete->liberarUbicacion();
        cout << "No fue posible cambiar el estado del paquete." << endl;
        return false;
    }
    cout << "Paquete almacenado en " << bodega->codigoCelda(fila, columna) << "." << endl;
    return true;
}

bool Centro::reubicarPaquete(string codigoPaquete, string codigoBodega, int fila, int columna) {
    Paquete* paquete = buscarPaquete(codigoPaquete);
    if (paquete == nullptr) {
        cout << "Paquete no encontrado." << endl;
        return false;
    }
    if (paquete->getEstado() != 2 || !paquete->tieneUbicacion()) {
        cout << "Solo se puede reubicar un paquete Almacenado con ubicacion." << endl;
        return false;
    }
    Bodega* nueva = buscarBodega(codigoBodega);
    if (nueva == nullptr) {
        cout << "Bodega destino no encontrada." << endl;
        return false;
    }
    if (nueva->getTipo() != paquete->getCategoria()) {
        cout << "La bodega destino no es compatible con la categoria del paquete." << endl;
        return false;
    }
    if (!nueva->posicionValida(fila, columna) || !nueva->estaLibre(fila, columna)) {
        cout << "La celda destino no existe o no esta disponible." << endl;
        return false;
    }
    if (nueva == paquete->getBodega() && fila == paquete->getFila() && columna == paquete->getColumna()) {
        cout << "El paquete ya se encuentra en esa celda." << endl;
        return true;
    }
    Bodega* anterior = paquete->getBodega();
    int filaAnterior = paquete->getFila();
    int columnaAnterior = paquete->getColumna();
    // Primero se reserva el destino; si falla, no se libera el origen.
    if (!nueva->asignarPaquete(fila, columna, paquete)) {
        cout << "No fue posible reservar la celda destino." << endl;
        return false;
    }
    anterior->liberarPosicion(filaAnterior, columnaAnterior);
    paquete->asignarUbicacion(nueva, fila, columna);
    cout << "Paquete reubicado a " << nueva->codigoCelda(fila, columna) << "." << endl;
    return true;
}

bool Centro::resolverIncidencia(string codigoPaquete, int nuevoEstado, string fecha, Colaborador* responsable) {
    Paquete* paquete = buscarPaquete(codigoPaquete);
    if (paquete == nullptr || paquete->getEstado() != 5) {
        cout << "El paquete no esta en estado Incidencia." << endl;
        return false;
    }
    if (nuevoEstado != 3) {
        cout << "Para volver a Almacenado use la opcion de almacenar el paquete." << endl;
        return false;
    }
    Despacho* despacho = buscarDespachoPorPaquete(paquete);
    if (despacho == nullptr || despacho->getEstado() != 1) {
        cout << "Solo se puede volver a En transito si existe un despacho En proceso." << endl;
        return false;
    }
    if (!paquete->cambiarEstado(3, fecha, responsable)) {
        cout << "Transicion no permitida." << endl;
        return false;
    }
    cout << "Incidencia resuelta. El paquete vuelve a En transito." << endl;
    return true;
}

Bodega* Centro::recomendarBodega(int categoria) const {
    Bodega* mejor = nullptr;
    for (int i = 0; i < bodegas->tamanio(); i++) {
        Bodega* b = bodegas->obtener(i);
        if (b->getTipo() == categoria && b->celdasLibres() > 0) {
            if (mejor == nullptr || b->porcentajeDisponible() > mejor->porcentajeDisponible()) {
                mejor = b;
            }
        }
    }
    return mejor;
}

// ---------------- Reportes ----------------
void Centro::reporteHistorialCliente(string identificacion) const {
    Cliente* cliente = buscarCliente(identificacion);
    if (cliente == nullptr) {
        cout << "Cliente no encontrado." << endl;
        return;
    }
    cout << "===== HISTORIAL DEL CLIENTE " << cliente->getNombre() << " =====" << endl;
    cout << "-- Solicitudes --" << endl;
    bool haySolicitudes = false;
    for (int i = 0; i < solicitudes->tamanio(); i++) {
        Solicitud* s = solicitudes->obtener(i);
        if (s->getCliente() == cliente) {
            cout << "Codigo: " << rellenar(s->getCodigo(), 10)
                 << " Paquete: " << rellenar(s->getPaquete()->getCodigo(), 10)
                 << " Fecha: " << rellenar(s->getFecha(), 12)
                 << " Estado: " << nombreEstadoSolicitud(s->getEstado()) << endl;
            haySolicitudes = true;
        }
    }
    if (!haySolicitudes) {
        cout << "   (Sin solicitudes)" << endl;
    }
    cout << "-- Despachos --" << endl;
    bool hayDespachos = false;
    for (int i = 0; i < despachos->tamanio(); i++) {
        Despacho* d = despachos->obtener(i);
        if (d->getCliente() == cliente) {
            cout << "Codigo: " << rellenar(d->getCodigo(), 10)
                 << " Paquete: " << rellenar(d->getPaquete()->getCodigo(), 10)
                 << " Fecha: " << rellenar(d->getFecha(), 12)
                 << " Estado: " << nombreEstadoDespacho(d->getEstado()) << endl;
            hayDespachos = true;
        }
    }
    if (!hayDespachos) {
        cout << "   (Sin despachos)" << endl;
    }
}

void Centro::reporteClientesPorEnvios() const {
    int n = clientes->tamanio();
    if (n == 0) {
        cout << "No hay clientes registrados." << endl;
        return;
    }
    // Arreglos dinamicos y ordenamiento por insercion (estable, sin STL).
    Cliente** arreglo = new Cliente*[n];
    int* conteo = new int[n];
    for (int i = 0; i < n; i++) {
        arreglo[i] = clientes->obtener(i);
        conteo[i] = 0;
    }
    for (int i = 0; i < despachos->tamanio(); i++) {
        Despacho* d = despachos->obtener(i);
        if (d->getEstado() != 2) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (arreglo[j] == d->getCliente()) {
                conteo[j]++;
                break;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        Cliente* claveCliente = arreglo[i];
        int claveConteo = conteo[i];
        int j = i - 1;
        while (j >= 0 && conteo[j] < claveConteo) {
            arreglo[j + 1] = arreglo[j];
            conteo[j + 1] = conteo[j];
            j--;
        }
        arreglo[j + 1] = claveCliente;
        conteo[j + 1] = claveConteo;
    }
    cout << "===== CLIENTES POR CANTIDAD DE ENVIOS FINALIZADOS =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << rellenar(arreglo[i]->getIdentificacion(), 14)
             << rellenar(arreglo[i]->getNombre(), 28)
             << "Despachos finalizados: " << conteo[i] << endl;
    }
    delete[] arreglo;
    delete[] conteo;
}

void Centro::reporteBitacoraPaquete(string codigoPaquete) const {
    Paquete* paquete = buscarPaquete(codigoPaquete);
    if (paquete == nullptr) {
        cout << "Paquete no encontrado." << endl;
        return;
    }
    paquete->mostrarBitacora();
}

void Centro::reporteDespachoDePaquete(string codigoPaquete) const {
    Paquete* paquete = buscarPaquete(codigoPaquete);
    if (paquete == nullptr) {
        cout << "Paquete no encontrado." << endl;
        return;
    }
    cout << "===== DESPACHO DEL PAQUETE " << codigoPaquete << " =====" << endl;
    Solicitud* aprobada = nullptr;
    for (int i = 0; i < solicitudes->tamanio(); i++) {
        Solicitud* s = solicitudes->obtener(i);
        if (s->getPaquete() == paquete && s->getEstado() == 2) {
            aprobada = s;
            break;
        }
    }
    if (aprobada != nullptr) {
        cout << "Solicitud aprobada: " << aprobada->getCodigo()
             << " | Fecha: " << aprobada->getFecha()
             << " | Estado: " << nombreEstadoSolicitud(aprobada->getEstado()) << endl;
    } else {
        cout << "Solicitud aprobada: no existe" << endl;
    }
    Despacho* despacho = buscarDespachoPorPaquete(paquete);
    if (despacho != nullptr) {
        cout << "Despacho: " << despacho->getCodigo()
             << " | Fecha: " << despacho->getFecha()
             << " | Hora: " << despacho->getHora()
             << " | Estado: " << nombreEstadoDespacho(despacho->getEstado()) << endl;
    } else {
        cout << "Despacho: el paquete no posee despacho." << endl;
    }
}

void Centro::reporteOcupacion() const {
    cout << "===== REPORTE DE OCUPACION =====" << endl;
    if (bodegas->estaVacia()) {
        cout << "No hay bodegas registradas." << endl;
        return;
    }
    for (int i = 0; i < bodegas->tamanio(); i++) {
        bodegas->obtener(i)->mostrarOcupacion();
    }
}

void Centro::reporteDespachosPorColaborador(string identificacion) const {
    Colaborador* colaborador = buscarColaborador(identificacion);
    if (colaborador == nullptr) {
        cout << "Colaborador no encontrado." << endl;
        return;
    }
    cout << "===== DESPACHOS DEL COLABORADOR " << colaborador->getNombre() << " =====" << endl;
    bool hay = false;
    for (int i = 0; i < despachos->tamanio(); i++) {
        Despacho* d = despachos->obtener(i);
        if (d->getResponsable() == colaborador) {
            cout << "Codigo: " << rellenar(d->getCodigo(), 10)
                 << " Paquete: " << rellenar(d->getPaquete()->getCodigo(), 10)
                 << " Fecha: " << rellenar(d->getFecha(), 12)
                 << " Estado: " << nombreEstadoDespacho(d->getEstado()) << endl;
            hay = true;
        }
    }
    if (!hay) {
        cout << "   (Sin despachos)" << endl;
    }
}

void Centro::reportePaquetesPorEstado() const {
    cout << "===== PAQUETES POR ESTADO =====" << endl;
    int conteo[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < paquetes->tamanio(); i++) {
        int estado = paquetes->obtener(i)->getEstado();
        if (estado >= 1 && estado <= 5) {
            conteo[estado]++;
        }
    }
    for (int e = 1; e <= 5; e++) {
        cout << rellenar(nombreEstadoPaquete(e), 16) << ": " << conteo[e] << endl;
    }
    cout << "Total de paquetes: " << paquetes->tamanio() << endl;
}
