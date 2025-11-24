//
// Created by Elian on 23/11/2025.
//

#ifndef PROYECTO_FINAL_FRAGMENTO_H
#define PROYECTO_FINAL_FRAGMENTO_H


#include "Objeto.h"

class FragmentoGema : public Objeto {
public:
    FragmentoGema(const std::string & nombre, const std::string & descripcion)
    : Objeto(nombre, descripcion) {}

    void usar(Jugador&) override {}
    bool esConsumible() const override { return false; }
    bool esEquipable() const override { return false; }
};


#endif //PROYECTO_FINAL_FRAGMENTO_H