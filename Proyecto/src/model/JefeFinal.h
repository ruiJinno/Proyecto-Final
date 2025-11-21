#ifndef PROYECTO_JEFEFINAL_H
#define PROYECTO_JEFEFINAL_H

#include "Jefe.h"

class JefeFinal : public Jefe {
private:
    int fase;

public:
    JefeFinal(const std::string& nombre, int x, int y, int vida, int ataque);

    void atacar(Jugador& objetivo) override;

    void ataqueEspecial(Jugador& objetivo);
    void cambiarFase();
};

#endif
