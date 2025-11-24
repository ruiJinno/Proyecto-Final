//
// Created by Elian on 24/11/2025.
//

#ifndef PROYECTO_FINAL_MAPA_H
#define PROYECTO_FINAL_MAPA_H
#include <vector>
#include "Habitacion.h"
#include "Jugador.h"
#include "../controller/Combate.h"

class Mapa {
private:
    std::vector<Habitacion*> habitaciones;
    int indexHabActual;
    Jugador* jugador;

public:
    Mapa();
    ~Mapa();

    void setJugador(Jugador* jugador);
    Jugador* getJugador() const;

    void agregarHabitacion(Habitacion* habitacion);
    Habitacion* getHabitacion() const;

    void moverJugador(char tecla);
    void ir_A_sig();
};


#endif //PROYECTO_FINAL_MAPA_H