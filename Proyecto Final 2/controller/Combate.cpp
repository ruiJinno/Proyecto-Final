//
// Created by Elian on 23/11/2025.
//

#include "Combate.h"
#include <iostream>
#include "../model/Jugador.h"
#include "../model/Enemigo.h"
#include "../model/Mapa.h"

void Combate::iniciarCombate(Combatiente &jugador, Combatiente &enemigo,Habitacion* habitacion, Mapa* mapa) {
    std::cout << "\n====================================\n";
    std::cout << "COMIENZA EL COMBATE contra " << enemigo.getNombre() << "!\n";
    while (jugador.estaVivo() && enemigo.estaVivo()) {

        jugador.realizarTurno(enemigo);

        if (!enemigo.estaVivo() && jugador.estaVivo()) {
            std::cout << "\nHas ganado el combate!\n";
            Objeto* drop = enemigo.soltarObjeto();
            if (drop != nullptr) {
                std::cout << "El enemigo solto: " << drop->getNombre() << "\n";
                jugador.recibirObjeto(drop);
            }
            if (habitacion) {
                habitacion->marcarCompletada();
                std::cout << "Habitacion completada!\n";
            }
            if (mapa) {
                mapa->ir_A_sig();
            }
            jugador.restaurarVida();
            std::cout << "Tu vida ha sido restaurada al maximo.\n";
            return;
        }
        enemigo.realizarTurno(jugador);

        if (enemigo.estaVivo() && !jugador.estaVivo()) {
            std::cout << "\n====================================\n";
            std::cout << "Has sido derrotado por " << enemigo.getNombre() << "!\n";
            std::cout << "====================================\n";
            jugador.setVida(0);
        }
    }
}


