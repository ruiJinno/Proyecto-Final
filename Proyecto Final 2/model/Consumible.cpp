#include "Consumible.h"
#include "Jugador.h"

Consumible::Consumible(const std::string &nombre, const std::string &descripcion, int cantidad)
: Objeto(nombre, descripcion), cantidad(cantidad) {}

void Consumible::usar(Jugador& jugador) {
    jugador.recibirCuracion(cantidad);
    std::cout << jugador.getNombre() << " usa " << getNombre() 
              << " y recupera " << cantidad << " de vida.\n";
}
