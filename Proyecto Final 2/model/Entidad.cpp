#include "Entidad.h"

// Constructor
Entidad::Entidad(const std::string& nombre,char simbolo)
: nombre(nombre), simbolo(simbolo), posX(-1), posY(-1) {}

// Metodos
void Entidad::setNombre(const std::string& n) {
    nombre = n;
}

std::string Entidad::getNombre() const {
    return nombre;
}

void Entidad::fijarPos(int x, int y) {
    posX = x;
    posY = y;
}

int Entidad::getPosX() const {
    return posX;
}

int Entidad::getPosY() const {
    return posY;
}
