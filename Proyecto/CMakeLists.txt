cmake_minimum_required(VERSION 4.0)
project(Proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto
        main.cpp
        src/model/Entidad.cpp
        src/model/Combatiente.cpp
        src/model/Habitacion.cpp
        src/model/Jugador.cpp
        src/model/Mapa.cpp
        src/model/NPC.cpp
        src/model/Consumible.cpp
        src/model/Jefe.cpp
        src/model/JefeNormal.cpp
        src/model/JefeFinal.cpp
        src/view/vistaJuego.cpp
        src/controller/Controlador.cpp
)
