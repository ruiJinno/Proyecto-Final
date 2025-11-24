//
// Created by Elian on 23/11/2025.
//

#include "Mejora.h"
#include "Jugador.h"

Mejora::Mejora(const std::string &nombre, const std::string &descripcion, TipoMejora tipo, int cantidad)
: Objeto(nombre, descripcion), tipo(tipo), cantidad(cantidad) {}

void Mejora::usar(Jugador &jugador) {
    switch (tipo) {
        case TipoMejora::VIDA:
            jugador.mejorarVida(cantidad);
            break;
        case TipoMejora::ATAQUE:
            jugador.mejorarAtaque(cantidad);
            break;
        case TipoMejora::DEFENSA:
            jugador.mejorarDefensa(cantidad);
            break;
    }

    std::cout << jugador.getNombre() << " aplica " << getNombre() << " y aumenta ";
    if (tipo == TipoMejora::VIDA) std::cout << "vida máxima";
    else if (tipo == TipoMejora::ATAQUE) std::cout << "ataque";
    else if (tipo == TipoMejora::DEFENSA) std::cout << "defensa";
    std::cout << " en " << cantidad << "\n";
}
