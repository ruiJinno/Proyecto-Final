//
// Created by Elian on 23/11/2025.
//

#ifndef PROYECTO_FINAL_COMBATE_H
#define PROYECTO_FINAL_COMBATE_H
#include "../model/Combatiente.h"
#include "../model/Habitacion.h"

class Mapa;

class Combate {
public:
    static void iniciarCombate(Combatiente& jugador, Combatiente& enemigo,Habitacion* habitacion, Mapa* mapa);
};


#endif //PROYECTO_FINAL_COMBATE_H