#ifndef OBJETO_H
#define OBJETO_H

#include "Entidad.h"
#include <string>

class Objeto : public Entidad {
public:
    Objeto(int x, int y, const std::string& nombre)
        : Entidad(nombre, x, y) {}

    virtual ~Objeto() = default;

    virtual void usar() = 0;
};

#endif
