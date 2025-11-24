//
// Created by Elian on 24/11/2025.
//

#ifndef PROYECTO_FINAL_VIEW_H
#define PROYECTO_FINAL_VIEW_H

#include "../model/Mapa.h"

class View {
private:
    Mapa* mapa;

public:
    View(Mapa* m);
    void mostrarMapa();
    void mostrarOpciones();
    char obtenerInput();
    void actualizar();
};

#endif