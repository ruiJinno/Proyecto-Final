#ifndef CONSUMIBLE_H
#define CONSUMIBLE_H

#include "Objeto.h"
#include <iostream>

class Jugador;

class Consumible : public Objeto {
private:
    int cantidadVida;

public:
    Consumible(int x, int y, const std::string& nombre, int vida): Objeto(x, y, nombre), cantidadVida(vida) {}


    void usar() override;
    void mostrarInfo() const override;
};

#endif
