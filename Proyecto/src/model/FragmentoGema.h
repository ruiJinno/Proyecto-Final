// FragmentoGema.h
#ifndef FRAGMENTOGEMA_H
#define FRAGMENTOGEMA_H

#include "Objeto.h"
#include <iostream>

class Jugador;

class FragmentoGema : public Objeto {
public:
    FragmentoGema(int x, int y, const std::string& nombre) : Objeto(x, y, nombre) {}

    void usar() override {
        std::cout << "Has recogido un fragmento de gema." << std::endl;
    }

    void mostrarInfo() const override {
        std::cout << "Fragmento de gema: " << nombre << " en (" << posX << "," << posY << ")" << std::endl;
    }
};

#endif
