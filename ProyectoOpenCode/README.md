# Proyecto 2 - TicoPack Logistics

Red de Centros de Distribucion implementada en C++ con listas enlazadas propias y
matrices dinamicas.

## Como compilar en Visual Studio Code

1. Abrir la carpeta `Proyecto2` en VS Code.
2. Tener instalado el compilador `g++` (MSYS2 / MinGW).
3. Presionar `Ctrl + Shift + B` y elegir **Compilar Proyecto2**.
4. Presionar `F5` para compilar y ejecutar con el depurador, o ejecutar
   `programa.exe` desde la terminal.

Tambien se puede compilar desde la terminal:

```bash
g++ -std=c++17 -Wall -Wextra *.cpp -o programa.exe
./programa.exe
```

## Archivos

| Archivo | Contenido |
|---|---|
| `main.cpp` | Menus y programa principal |
| `Utilidades.*` | Conversiones de texto, relleno y nombres de estados |
| `Cliente.*` | Clase base de clientes |
| `PersonaF.*` | Cliente persona fisica (herencia) |
| `Empresa.*` | Cliente empresa (herencia y descuento) |
| `Colaborador.*` | Colaboradores del centro |
| `Celda.*` | Celda de una bodega |
| `Bodega.*` | Bodega con matriz dinamica de celdas |
| `Paquete.*` | Paquete, estado y bitacora |
| `ListaBitacora.*` | Bitacora enlazada de cambios de estado |
| `Solicitud.*` | Solicitudes de envio y calculo de costo |
| `Despacho.*` | Despachos asociados a solicitudes |
| `Centro.*` | Centro de distribucion y sus colecciones |
| `ListaGenerica.h` | Lista enlazada simple reutilizable |
| `Listas.h` | Tipos de lista por entidad |
| `ListaCentros.*` | Lista enlazada de centros |

## Limpieza de pantalla

Cada vez que se vuelve a un menu, la consola se limpia automaticamente. Antes de
limpiar, el programa muestra `Presione Enter para continuar...` para que el usuario
pueda leer el resultado de la operacion.

La limpieza usa secuencias ANSI, por lo que funciona en la terminal integrada de
VS Code y en Windows Terminal. Si se ejecuta en una consola antigua que no soporta
ANSI, se verian caracteres de control; en ese caso se puede cambiar la limpieza por
`system("cls")` agregando `<cstdlib>`.

## Librerias utilizadas

- `<iostream>`: entrada y salida por consola.
- `<string>`: necesaria para usar `std::string` (todo el proyecto la usa).
- `<sstream>`: conversion entre texto y numeros en `Utilidades.cpp`.

No se usan `vector`, `list`, `map`, `array`, `deque` ni otras estructuras de la STL.
Tampoco se usan `<ctime>` ni `<iomanip>`: las fechas y horas se solicitan al usuario
y los decimales se redondean manualmente.

## Funcionalidades incluidas

- Registrar, buscar, mostrar y eliminar centros (con validacion de dependencias).
- Clientes persona fisica y empresa con herencia.
- Colaboradores por centro.
- Bodegas con tipo, filas y columnas; matriz dinamica y vista grafica.
- Paquetes con categoria, estado, ubicacion y bitacora enlazada.
- Almacenamiento con recomendacion de bodega por mayor porcentaje disponible.
- Reubicacion de paquetes validando el destino antes de liberar el origen.
- Solicitudes con calculo de costo por peso, categoria y descuento de empresa.
- Aprobacion de solicitudes, creacion de despachos y finalizacion de entregas.
- Incidencias y resolucion segun las transiciones permitidas.
- Reportes de ocupacion y paquetes por estado.

## Nota sobre fechas y horas

Para que el programa no dependa de librerias adicionales, la fecha y la hora se
piden por teclado. Si se desea usar la fecha/hora del sistema, se puede agregar
`<ctime>` y reemplazar los prompts correspondientes.
