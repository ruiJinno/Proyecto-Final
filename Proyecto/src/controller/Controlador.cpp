#include "Controlador.h"

Controlador::Controlador(Jugador* j, Mapa* m) : jugador(j), mapa(m) {}

void Controlador::iniciarJuego() {
    vista.mostrarMensaje("Bienvenido al juego!");
    actualizarVista();
}

void Controlador::entrada(char tecla) {
    jugador->mover(tecla);
    actualizarVista();
}

void Controlador::actualizarVista() {
    vista.mostrarHabitacion(*mapa->getHabitacionActual(), *jugador);
    vista.mostrarJugador(*jugador);
}
