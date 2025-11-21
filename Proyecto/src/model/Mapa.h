#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include "Habitacion.h"

class Jugador;

class Mapa {
private:
    std::vector<Habitacion*> habitaciones;
    int indexHabitacionActual;
    Jugador* jugador;

    bool validaIndexHabitacion(int idx) const;

public:
    Mapa();
    ~Mapa();

    void setJugador(Jugador* j);
    Jugador* getJugador() const;

    void agregarHabitacion(Habitacion* h);
    Habitacion* getHabitacionActual() const;
    int getIndexHabitacionActual() const;

    void moverJugador(char tecla);
    bool irASiguienteHabitacion();
    bool irAHabitacionAnterior();
};

#endif
