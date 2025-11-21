#ifndef JUGADOR_H
#define JUGADOR_H

#include "Combatiente.h"
#include "Objeto.h"
#include <vector>
#include <string>

class Mapa;
class Habitacion;
class Jefe;

class Jugador : public Combatiente {
private:
    std::vector<Objeto*> inventario;
    Mapa* mapa;
    int vidaMaxima;

public:
    Jugador(const std::string& nombre, int x, int y, int vida, int ataque, Mapa* mapa = nullptr);

    const std::vector<Objeto*>& getInventario() const;
    void setMapa(Mapa* m);
    Mapa* getMapa() const;

    int getVida() const;
    void setVida(int nuevaVida);
    int getVidaMaxima() const;

    void mover(char tecla);
    void interactuar();

    void agregarItem(Objeto* item);
    void mostrarInventario() const;

private:
    void combatir(Jefe* jefe);
};

#endif
