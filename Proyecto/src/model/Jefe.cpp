#include "Jefe.h"

Jefe::Jefe(const std::string& nombre, int x, int y, int vida, int ataque) : Combatiente(nombre, x, y, vida, ataque) {}

FragmentoGema* Jefe::soltarFragmento() {
    return new FragmentoGema(posX, posY, "Fragmento de Gema de " + nombre);
}
