#ifndef PROYECTO_ARMA_H
#define PROYECTO_ARMA_H
#include "Objeto.h"

class Arma : public Objeto {
private:
    int danoBase;

public:
    Arma(int x, int y, const std::string& nombre, int dano): Objeto(x, y, nombre), danoBase(dano) {}
    void usar() override;
};

#endif //PROYECTO_ARMA_H