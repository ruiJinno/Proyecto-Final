//
// Created by Elian on 22/11/2025.
//

#include "Objeto.h"

// Constructor
Objeto::Objeto(const std::string& nombre,const std::string& descripcion,char simbolo)
: nombre(nombre), descripcion(descripcion), posX(-1), posY(-1),simbolo(simbolo) {}

// Getters
std::string Objeto::getNombre() const {
    return nombre;
}

std::string Objeto::getDescripcion() const {
    return descripcion;
}

char Objeto::getSimbolo() const {
    return simbolo;
}

void Objeto::fijarPos(int x, int y) {
    posX = x;
    posY = y;
}

int Objeto::getPosX() const {
    return posX;
}

int Objeto::getPosY() const {
    return posY;
}