//
// Created by Elian on 23/11/2025.
//

#ifndef PROYECTO_FINAL_MEJORA_H
#define PROYECTO_FINAL_MEJORA_H

#include "Objeto.h"
#include "Jugador.h"
#include <iostream>

enum class TipoMejora { VIDA, ATAQUE, DEFENSA };

class Mejora : public Objeto {
private:
    TipoMejora tipo;
    int cantidad;

public:
    Mejora(const std::string& nombre, const std::string& descripcion, TipoMejora tipo, int cantidad);

    void usar(Jugador& jugador) override;

    bool esConsumible() const override {
        return false;
    }
    bool esEquipable() const override {
        return true;
    }

    TipoMejora getTipo() const {
        return tipo;
    }

    int getCantidad() const {
        return cantidad;
    }
};

#endif // PROYECTO_FINAL_MEJORA_H
