//
// Created by Elian on 23/11/2025.
//

#ifndef PROYECTO_FINAL_ENEMIGO_H
#define PROYECTO_FINAL_ENEMIGO_H
#include "Combatiente.h"
#include "Objeto.h"

class Enemigo : public Combatiente {
protected:
    Objeto* drop;

public:
    Enemigo(const std::string& nombre,char simbolo,int vida, int ataque, int defensa,Objeto* drop);

    Objeto* soltarObjeto() override;
    void recibirObjeto(Objeto* obj) override;
    void Interactuar() const override {}

    void realizarTurno(Combatiente& objetivo) override;
};


#endif //PROYECTO_FINAL_ENEMIGO_H