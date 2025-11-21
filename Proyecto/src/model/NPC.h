#ifndef NPC_H
#define NPC_H

#include "Entidad.h"
#include <string>

class NPC : public Entidad {
protected:
    std::string dialogo;

public:
    NPC(const std::string& nombre, const std::string& dialogo, int x, int y);
    virtual ~NPC();

    virtual void interactuar() const;
    virtual void mostrarInfo() const override;
};

#endif
