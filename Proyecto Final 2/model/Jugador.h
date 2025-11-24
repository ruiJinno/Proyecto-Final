//
// Created by Elian on 22/11/2025.
//

#ifndef PROYECTO_FINAL_JUGADOR_H
#define PROYECTO_FINAL_JUGADOR_H

#include <vector>
#include "Combatiente.h"
#include "Objeto.h"

class Jugador : public Combatiente {
private:
    std::vector<Objeto*> inventario;

public:
    Jugador(int vida, int ataque, int defensa);

    void agregarObjeto(Objeto* objeto);
    void mostrarInventario() const;
    void usarObjeto(int indice);
    void equiparObjeto(int indice);
    void recibirCuracion(int cant);

    virtual void Interactuar() const override;
    void realizarTurno(Combatiente& enemigo) override;
    void recibirObjeto(Objeto* obj) override;
    char getSimbolo() const;


    ~Jugador() override;
};

#endif //PROYECTO_FINAL_JUGADOR_H