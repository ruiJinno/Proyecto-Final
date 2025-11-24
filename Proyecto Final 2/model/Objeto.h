//
// Created by Elian on 22/11/2025.
//

#ifndef PROYECTO_FINAL_OBJETO_H
#define PROYECTO_FINAL_OBJETO_H
#include "Entidad.h"
#include <string>

class Jugador;

class Objeto {
private:
    std::string nombre;
    std::string descripcion;
    int posX = -1;
    int posY = -1;
    char simbolo = 'O';

public:

    // Constructor
    Objeto(const std::string& nombre, const std::string& descripcion, char simbolo = 'O');

    // Destructor
    virtual ~Objeto() = default;

    // Getter y Setters
    std::string getNombre() const;
    std::string getDescripcion() const;
    char getSimbolo() const;

    // Metodos
    void fijarPos(int x, int y);
    int getPosX() const;
    int getPosY() const;

    // Abstractos
    virtual void usar(Jugador& jugador) = 0;
    virtual bool esConsumible() const = 0;
    virtual bool esEquipable() const = 0;
};

#endif //PROYECTO_FINAL_OBJETO_H