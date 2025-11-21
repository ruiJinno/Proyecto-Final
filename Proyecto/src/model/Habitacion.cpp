#include "Habitacion.h"

Habitacion::Habitacion(const std::string &nombre)
    : nombre(nombre), jefeDerrotado(false)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matriz[i][j] = nullptr;
}

bool Habitacion::CoordValida(int x, int y) const {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

const std::string& Habitacion::getNombre() const {
    return nombre;
}

bool Habitacion::estadoJefe() const {
    return jefeDerrotado;
}

void Habitacion::marcarJefeDerrotado() {
    jefeDerrotado = true;
}

void Habitacion::colocarEntidad(Entidad* e, int x, int y) {
    if (!CoordValida(x, y)) return;
    matriz[x][y] = e;
}

Entidad* Habitacion::obtenerEntidad(int x, int y) const {
    if (!CoordValida(x, y)) return nullptr;
    return matriz[x][y];
}

void Habitacion::limpiarPos(int x, int y) {
    if (!CoordValida(x, y)) return;
    matriz[x][y] = nullptr;
}
