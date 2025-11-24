#ifndef PROYECTO_FINAL_CONSUMIBLE_H
#define PROYECTO_FINAL_CONSUMIBLE_H

#include "Objeto.h"
#include "Jugador.h"
#include <iostream>

class Consumible : public Objeto {
private:
    int cantidad; // Cantidad de curación

public:
    Consumible(const std::string& nombre, const std::string& descripcion, int cantidad);

    void usar(Jugador& jugador) override;
    bool esConsumible() const override {
        return true;
    }
    bool esEquipable() const override {
        return false;
    }

    int getCantidad() const {
        return cantidad;
    }
};

#endif // PROYECTO_FINAL_CONSUMIBLE_H
