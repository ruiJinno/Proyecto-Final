#ifndef PROYECTO_FINAL_HABITACION_H
#define PROYECTO_FINAL_HABITACION_H

#include <vector>
#include "Jugador.h"
#include "Enemigo.h"
#include "NPC.h"
#include "Objeto.h"

class Habitacion {
private:
    static const int TAM = 3;
    std::vector<Objeto*> objetos;
    std::vector<Enemigo*> enemigos;
    std::vector<NPC*> npcs;

    bool completada;

public:
    Habitacion();
    int getTam() const {
        return TAM;
    }

    // Colocar elementos dentro de la habitación
    void colocarObjeto(Objeto* o, int x, int y);
    void colocarEnemigo(Enemigo* e, int x, int y);
    void colocarNPC(NPC* npc, int x, int y);
    void removerObjeto(int x, int y);

    // Obtener elementos por coordenadas
    Objeto* obtenerObjeto(int x, int y) const;
    Enemigo* obtenerEnemigo(int x, int y) const;
    NPC* obtenerNPC(int x, int y) const;

    // Estado
    bool estaCompleta() const;
    void marcarCompletada();
    void mostrar(const Jugador& jugador) const;
};

#endif
