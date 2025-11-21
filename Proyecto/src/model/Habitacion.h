#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include "Entidad.h"

class Habitacion {
private:
    std::string nombre;
    Entidad* matriz[3][3];
    bool jefeDerrotado;
    bool CoordValida(int x, int y) const;

public:
    Habitacion(const std::string& nombre);
    ~Habitacion() = default;

    const std::string& getNombre() const;

    bool estadoJefe() const;
    void marcarJefeDerrotado();

    void colocarEntidad(Entidad* e, int x, int y);
    Entidad* obtenerEntidad(int x, int y) const;
    void limpiarPos(int x, int y);
};

#endif
