#ifndef JEFE_H
#define JEFE_H

#include "Combatiente.h"
#include "FragmentoGema.h"
#include <string>

class Jugador;

class Jefe : public Combatiente {
public:
    Jefe(const std::string& nombre, int x, int y, int vida, int ataque);

    virtual ~Jefe() = default;

    virtual void atacar(Jugador& objetivo) = 0;

    virtual FragmentoGema* soltarFragmento();  // devuelve puntero a FragmentoGema
};

#endif
