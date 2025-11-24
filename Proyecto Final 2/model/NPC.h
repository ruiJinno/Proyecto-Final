//
// Created by Elian on 22/11/2025.
//

#ifndef PROYECTO_FINAL_NPC_H
#define PROYECTO_FINAL_NPC_H
#include <string>
#include "Entidad.h"

class NPC : public Entidad {
private:
    std::string dialogo;

public:
    NPC(const std::string& nombre, const std::string& dialogo);

    //Setters y Getters
    void setDialogo(const std::string& dialogo);
    std::string getDialogo() const;
    char getSimbolo() const;


    // Metodo abstracto

    void Interactuar() const override;

};

#endif//PROYECTO_FINAL_NPC_H