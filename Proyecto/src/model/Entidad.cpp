#include "Entidad.h"

Entidad::Entidad(const std::string& nombre, int x, int y)
    : nombre(nombre), posX(x), posY(y) {}

Entidad::~Entidad() {}

void Entidad::fijarPos(int x, int y) {
    posX = x;
    posY = y;
}

Posicion Entidad::obtenerPos() const {
    return { posX, posY };
}

int Entidad::getPosX() const {
    return posX;
}

int Entidad::getPosY() const {
    return posY;
}

void Entidad::setPos(int x, int y) {
    fijarPos(x, y);
}

const std::string& Entidad::getNombre() const {
    return nombre;
}
void Entidad::setNombre(const std::string& nuevoNombre) {
    nombre = nuevoNombre;
}
