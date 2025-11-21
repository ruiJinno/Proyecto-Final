#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>

struct Posicion {
    int x;
    int y;
};

class Entidad {

protected:
    std::string nombre;
    int posX;
    int posY;

public:
    Entidad(const std::string& nombre = "", int x = 0, int y = 0);
    virtual ~Entidad();
    void fijarPos(int x, int y);
    Posicion obtenerPos() const;
    int getPosX() const;
    int getPosY() const;
    void setPos(int x, int y);
    const std::string& getNombre() const;
    void setNombre(const std::string& nuevoNombre);
    virtual void mostrarInfo() const = 0;
};

#endif // ENTIDAD_H
