#include "Jugador.h"
#include "Mapa.h"
#include "Objeto.h"
#include "Consumible.h"
#include "NPC.h"
#include "Jefe.h"
#include "JefeNormal.h"
#include "JefeFinal.h"
#include <iostream>
#include <cstdlib>

Jugador::Jugador(const std::string& nombre, int x, int y, int vida, int ataque, Mapa* mapa_)
    : Combatiente(nombre, x, y, vida, ataque), mapa(mapa_), vidaMaxima(vida) {}

void Jugador::setMapa(Mapa* m) { mapa = m; }
Mapa* Jugador::getMapa() const { return mapa; }

int Jugador::getVida() const { return vida; }
void Jugador::setVida(int nuevaVida) {
    if (nuevaVida > vidaMaxima)
        vida = vidaMaxima;
    else if (nuevaVida < 0)
        vida = 0;
    else
        vida = nuevaVida;
}
int Jugador::getVidaMaxima() const { return vidaMaxima; }

const std::vector<Objeto*>& Jugador::getInventario() const { return inventario; }
void Jugador::agregarItem(Objeto* item) { inventario.push_back(item); }
void Jugador::mostrarInventario() const {
    if (inventario.empty()) {
        std::cout << "El inventario está vacío.\n";
        return;
    }
    std::cout << "Inventario:\n";
    for (const auto& obj : inventario)
        std::cout << "- " << obj->getNombre() << "\n";
}

void Jugador::mover(char tecla) {
    if (!mapa) return;
    Habitacion* hab = mapa->getHabitacionActual();
    if (!hab) return;

    int x = getPosX();
    int y = getPosY();
    int nx = x;
    int ny = y;

    switch (tecla) {
        case 'w': case 'W': nx = x - 1; break;
        case 's': case 'S': nx = x + 1; break;
        case 'a': case 'A': ny = y - 1; break;
        case 'd': case 'D': ny = y + 1; break;
        default: std::cout << "Tecla no válida. Usa WASD.\n"; return;
    }

    if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) {
        std::cout << "No puedes moverte fuera de la habitación.\n";
        return;
    }

    hab->limpiarPos(x, y);
    hab->colocarEntidad(this, nx, ny);
    setPos(nx, ny);

    interactuar();

    std::cout << "Jugador movido a (" << nx << "," << ny << ") en habitación: "
              << hab->getNombre() << "\n";
}

void Jugador::interactuar() {
    if (!mapa) return;
    Habitacion* hab = mapa->getHabitacionActual();
    if (!hab) return;

    int x = getPosX();
    int y = getPosY();
    Entidad* entidad = hab->obtenerEntidad(x, y);
    if (!entidad) return;

    if (Objeto* obj = dynamic_cast<Objeto*>(entidad)) {
        std::cout << "Has encontrado un objeto: " << obj->getNombre() << "!\n";
        obj->usar();
        agregarItem(obj);
        hab->limpiarPos(x, y);
    }
    else if (NPC* npc = dynamic_cast<NPC*>(entidad)) {
        npc->interactuar();
    }
    else if (Jefe* jefe = dynamic_cast<Jefe*>(entidad)) {
        std::cout << "¡Has encontrado al jefe " << jefe->getNombre() << "! Comienza el combate.\n";
        bool combateActivo = true;
        while (combateActivo) {
            std::cout << "Turno del jugador: atacando...\n";
            jefe->recibirDano(getAtaque());
            std::cout << "Vida del jefe: " << dynamic_cast<Combatiente*>(jefe)->getVida() << "\n";

            if (dynamic_cast<Combatiente*>(jefe)->getVida() <= 0) {
                std::cout << "¡Jefe derrotado!\n";
                hab->marcarJefeDerrotado();
                hab->limpiarPos(x, y);
                combateActivo = false;
                mapa->irASiguienteHabitacion();
                break;
            }

            if (JefeFinal* jefeFinal = dynamic_cast<JefeFinal*>(jefe)) {
                jefeFinal->cambiarFase();
                jefeFinal->atacar(*this);
            } else {
                jefe->atacar(*this);
            }

            std::cout << "Vida del jugador: " << getVida() << "\n";

            if (getVida() <= 0) {
                std::cout << "¡Has sido derrotado! Fin del juego.\n";
                exit(0);
            }
        }
    }
}
