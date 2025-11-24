//
// Created by Elian on 23/11/2025.
//

#ifndef PROYECTO_FINAL_JEFE_H
#define PROYECTO_FINAL_JEFE_H
#include "Enemigo.h"

class Jefe : public Enemigo {
private:
    bool segundaFase;

public:
    // Constructor
    Jefe(const std::string& nombre,char simbolo,int vida, int ataque, int defensa, Objeto* drop);

    void activarSegundaFase();
    void recibirObjeto(Objeto* obj) override;
    void ataqueEspecial(Combatiente& objetivo);
    void realizarTurno(Combatiente& objetivo) override;
};


#endif //PROYECTO_FINAL_JEFE_H