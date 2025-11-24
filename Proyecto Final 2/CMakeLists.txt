cmake_minimum_required(VERSION 4.0)
project(Proyecto_Final)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_Final main.cpp
        model/Entidad.cpp
        model/Entidad.h
        model/NPC.cpp
        model/NPC.h
        model/Objeto.cpp
        model/Objeto.h
        model/Combatiente.cpp
        model/Combatiente.h
        model/Jugador.cpp
        model/Jugador.h
        model/Consumible.cpp
        model/Consumible.h
        model/Enemigo.cpp
        model/Enemigo.h
        model/Jefe.cpp
        model/Jefe.h
        model/mejora.cpp
        model/mejora.h
        controller/Combate.cpp
        controller/Combate.h
        model/Fragmento.h
        model/Habitacion.cpp
        model/Habitacion.h
        model/mapa.cpp
        model/mapa.h
        view/view.cpp
        view/view.h)
