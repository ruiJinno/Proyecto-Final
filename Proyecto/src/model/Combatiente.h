#ifndef COMBATIENTE_H
#define COMBATIENTE_H

#include "Entidad.h"
#include <string>
#include <iostream>

class Combatiente : public Entidad {
protected:
    int vida;
    int ataque;

public:
    Combatiente(const std::string &nombre, int x, int y, int vida, int ataque);
    virtual ~Combatiente();

    int getVida() const;
    void setVida(int v);
    int getAtaque() const;
    int atacar() const;
    void recibirDano(int cantidad);

    virtual void mostrarInfo() const;
};

#endif
