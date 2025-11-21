#ifndef PROYECTO_VISTAJUEGO_H
#define PROYECTO_VISTAJUEGO_H

#include <string>
#include "../model/Jugador.h"
#include "../model/Habitacion.h"

class Vista {
public:
    void mostrarHabitacion(const Habitacion& habitacion, const Jugador& jugador);
    void mostrarJugador(const Jugador& jugador);
    void mostrarMensaje(const std::string& mensaje);
};

#endif
