#include "Mapa.h"
#include "Jugador.h"
#include <iostream>

Mapa::Mapa() : indexHabitacionActual(0), jugador(nullptr) {}

Mapa::~Mapa() {
    for (auto h : habitaciones) delete h;
}

void Mapa::setJugador(Jugador* j) {
    jugador = j;
}

Jugador* Mapa::getJugador() const { return jugador; }

void Mapa::agregarHabitacion(Habitacion* h) {
    habitaciones.push_back(h);
}

bool Mapa::validaIndexHabitacion(int idx) const {
    return idx >= 0 && idx < static_cast<int>(habitaciones.size());
}

Habitacion* Mapa::getHabitacionActual() const {
    if (!validaIndexHabitacion(indexHabitacionActual)) return nullptr;
    return habitaciones[indexHabitacionActual];
}

int Mapa::getIndexHabitacionActual() const { return indexHabitacionActual; }

void Mapa::moverJugador(char tecla) {
    if (!jugador) return;

    Habitacion* hab = getHabitacionActual();
    if (!hab) return;

    int x = jugador->getPosX();
    int y = jugador->getPosY();
    int nx = x;
    int ny = y;

    switch (tecla) {
        case 'w': case 'W': nx = x - 1; break;
        case 's': case 'S': nx = x + 1; break;
        case 'a': case 'A': ny = y - 1; break;
        case 'd': case 'D': ny = y + 1; break;
        default:
            std::cout << "Tecla no válida. Usa WASD.\n";
            return;
    }

    if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) {
        std::cout << "No puedes moverte fuera de la habitacion.\n";
        return;
    }

    hab->limpiarPos(x, y);
    hab->colocarEntidad(jugador, nx, ny);
    jugador->setPos(nx, ny);

    std::cout << "Jugador movido a (" << nx << "," << ny << ") en habitacion: "
              << hab->getNombre() << "\n";

    jugador->interactuar();
}

bool Mapa::irASiguienteHabitacion() {
    Habitacion* actual = getHabitacionActual();
    if (!actual) return false;

    if (!actual->estadoJefe()) {
        std::cout << "Debes derrotar al jefe de esta habitacion antes de avanzar.\n";
        return false;
    }

    int siguiente = indexHabitacionActual + 1;
    if (!validaIndexHabitacion(siguiente)) {
        std::cout << "No hay habitacion siguiente.\n";
        return false;
    }

    Habitacion* nueva = habitaciones[siguiente];
    indexHabitacionActual = siguiente;
    nueva->colocarEntidad(jugador, 1, 1);
    jugador->setPos(1, 1);
    std::cout << "Has avanzado a: " << nueva->getNombre() << "\n";
    return true;
}

bool Mapa::irAHabitacionAnterior() {
    if (indexHabitacionActual == 0) {
        std::cout << "No hay habitacion anterior.\n";
        return false;
    }

    int anterior = indexHabitacionActual - 1;
    Habitacion* dest = habitaciones[anterior];
    indexHabitacionActual = anterior;
    dest->colocarEntidad(jugador, 1, 1);
    jugador->setPos(1, 1);
    std::cout << "Has retrocedido a: " << dest->getNombre() << "\n";
    return true;
}
