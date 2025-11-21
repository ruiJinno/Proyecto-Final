#include <iostream>
#include "src/model/Jugador.h"
#include "src/model/Mapa.h"
#include "src/model/Habitacion.h"
#include "src/view/vistaJuego.h"
#include "src/controller/Controlador.h"
#include "src/model/Consumible.h"
#include "src/model/JefeNormal.h"
#include "src/model/JefeFinal.h"
#include "src/model/NPC.h"

int main() {
    Mapa mapa;

    Habitacion* hab1 = new Habitacion("Sala Inicial");
    Habitacion* hab2 = new Habitacion("Sala Intermedia");
    Habitacion* hab3 = new Habitacion("Sala Final");

    mapa.agregarHabitacion(hab1);
    mapa.agregarHabitacion(hab2);
    mapa.agregarHabitacion(hab3);

    Jugador jugador("Naylo", 0, 0, 200, 20, &mapa);
    mapa.setJugador(&jugador);

    Consumible* pocion1 = new Consumible(1, 1, "Pocion de Vida", 30);
    hab1->colocarEntidad(pocion1, 1, 1);

    Consumible* pocion2 = new Consumible(2, 0, "Pocion de Vida", 30);
    hab2->colocarEntidad(pocion2, 2, 0);

    JefeNormal* jefe1 = new JefeNormal("Thyriel", 2, 2, 80, 15);
    hab1->colocarEntidad(jefe1, 2, 1);

    JefeNormal* jefe2 = new JefeNormal("Vaelion", 1, 2, 100, 20);
    hab2->colocarEntidad(jefe2, 2, 1);

    JefeFinal* jefeFinal = new JefeFinal("Vharos", 1, 1, 200, 25);
    hab3->colocarEntidad(jefeFinal, 2, 1);

    //NPC* npc1 = new NPC("Piril", "El reino de Lysara causo por la gema. Tres lideres la quisieron y todo termino en oscuridad. Sigue los fragmentos si quieres salvarlo.", 0, 2);
    //PC* npc2 = new NPC("Ruler", "El Bosque Umbrio esta lleno de espiritus perdidos. El Vigia del Umbral guarda uno de los fragmentos. Ten cuidado con lo que enfrentas.", 2, 0);
    //NPC* npc3 = new NPC("Duro", "El Heraldo Marchito consume todo a su paso. Para restaurar Lysara tendras que vencerlo. Muchos ya lo intentaron y cayeron.", 0, 1);
    //NPC* npc4 = new NPC("Trash", "Vharos, el Ultimo Lamento, fue un heroe atrapado por su dolor. No luchas contra un monstruo, luchas contra un hombre perdido.", 2, 2);

    //hab1->colocarEntidad(npc1, 0, 2);
    //hab1->colocarEntidad(npc2, 2, 0);
    //hab2->colocarEntidad(npc3, 0, 1);
    //hab3->colocarEntidad(npc4, 2, 2);

    Controlador controlador(&jugador, &mapa);
    controlador.iniciarJuego();

    char tecla;
    bool jugando = true;

    while (jugando) {
        std::cout << "\nMover (W/A/S/D) o Q para salir: ";
        std::cin >> tecla;
        tecla = toupper(tecla);

        if (tecla == 'Q') {
            jugando = false;
            std::cout << "Saliendo del juego...\n";
        } else {
            controlador.entrada(tecla);
        }
    }

    return 0;
}
