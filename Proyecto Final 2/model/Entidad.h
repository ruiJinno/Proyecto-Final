#ifndef PROYECTO_FINAL_ENTIDAD_H
#define PROYECTO_FINAL_ENTIDAD_H

#include <string>

class Entidad {
protected:
    std::string nombre;
    char simbolo;
    int posX = 0;
    int posY = 0;
public:

    // Constructor
    Entidad(const std::string& nombre,char simbolo);

    // Destructor virtual
    virtual ~Entidad() = default;

    // Setters y getters
    void setNombre(const std::string& nombre);
    std::string getNombre() const;
    char getSimbolo() const {
        return simbolo;
    }

    // Metodos
    virtual void Interactuar() const = 0;
    void fijarPos(int x, int y);
    int getPosX() const;
    int getPosY() const;
};

#endif
