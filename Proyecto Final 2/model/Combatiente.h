//
// Created by Elian on 22/11/2025.
//

#ifndef PROYECTO_FINAL_COMBATIENTE_H
#define PROYECTO_FINAL_COMBATIENTE_H

#include "Entidad.h"
#include "Objeto.h"

class Combatiente : public Entidad {
protected:
    int vida, vidaMax;
    int ataque, defensa;
    char simbolo;

public:
    Combatiente(const std::string& nombre,char simbolo,int vida,int ataque,int defensa);

    virtual ~Combatiente() = default;

    // Getters
    int getVida() const;
    int getVidaMax() const;
    int getAtaque() const;
    int getDefensa() const;
    char getSimbolo() const {
        return simbolo;
    }


    // Comprobacion para ver si está vivo
    bool estaVivo() const {
        return vida > 0;
    };

    // Setters
    void setVida(int v);
    void setVidaMax(int vm);
    void setAtaque(int a);
    void setDefensa(int d);
    void restaurarVida();

    // Mejoras de stats
    void mejorarAtaque(int cant);
    void mejorarDefensa(int cant);
    void mejorarVida(int cant);
    void mejorarVidaMax(int cant);

    // Combate
    virtual void recibirDano(int cantidad);
    virtual void atacar(Combatiente& objetivo);
    virtual void recibirObjeto(Objeto* obj) = 0;
    virtual Objeto* soltarObjeto() {
        return nullptr;
    };

    // Turno
    virtual void realizarTurno(Combatiente& objetivo) = 0;
};

#endif

