#ifndef PROYECTO_JEFENORMAL_H
#define PROYECTO_JEFENORMAL_H

#include "Jefe.h"

class JefeNormal : public Jefe {
public:
    JefeNormal(const std::string& nombre, int x, int y, int vida, int ataque);

    void atacar(Jugador& objetivo) override;
    void habilidadEspecial(Jugador& objetivo);
};

#endif
