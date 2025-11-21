#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../model/Jugador.h"
#include "../model/Mapa.h"
#include "../view/vistaJuego.h"

class Controlador {
private:
    Jugador* jugador;
    Mapa* mapa;
    Vista vista;

public:
    Controlador(Jugador* j, Mapa* m);

    void iniciarJuego();
    void entrada(char tecla);
    void actualizarVista();
};

#endif
