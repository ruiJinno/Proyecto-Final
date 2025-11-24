#include "model/Jugador.h"
#include "model/Enemigo.h"
#include "model/Consumible.h"
#include "model/Mejora.h"
#include "controller/Combate.h"
#include "model/Fragmento.h"
#include "model/Mapa.h"
#include "model/NPC.h"
#include "controller/Combate.h"
#include "view/View.h"
#include "model/Jefe.h"

// Faltaron  cosas por mejorar e implementar :/ Sorry

int main() {

    std::cout << "=== Bienvenido al Reino Quebrado ===\n";
    std::cout << "Durante siglos, el Reino de Lysara prospero bajo el brillo de la Gema Soberana.\n";
    std::cout << "Tras su explosion, surgieron jefes corrompidos y sombras por todo el reino.\n";
    std::cout << "Tu mision: recuperar los fragmentos de la gema y restaurar la luz.\n\n";

    // Crear jugador

    Jugador *jugador = new Jugador(100, 40, 30);

    // NPCs
    NPC* piril = new NPC("Piril","Recuerda, Naylo, la gema es poderosa y peligrosa.");
    NPC* ruler = new NPC("Ruler", "No temas, yo te guiare en tu camino.");
    NPC* duro = new NPC("Duro", "Cada batalla te hara mas fuerte.");
    NPC* trash = new NPC("Trash", "Cuidado con los fragmentos corrompidos.");


    // fragmentos
    Objeto* fragThyriel = new FragmentoGema("Fragmento Thyriel","Un trozo brillante que vibra con energia del bosque.");
    Objeto* fragVaelion = new FragmentoGema("Fragmento Vaelion","Un trozo brillante que vibra con energia del bosque.");
    Objeto* fragVharos = new FragmentoGema("Fragmento Esmeralda","Un trozo brillante que vibra con energia del bosque.");

    // objetos
    Objeto* pocion = new Consumible("Pocion de vida", "Cura 30 HP", 30);
    Objeto* comida = new Consumible("Comida de la abuela", "Cura 30 HP", 15);
    Objeto* mejoraAtq =new Mejora("Gema afilada", "Aumenta ataque en +15", TipoMejora::ATAQUE, 15);
    Objeto* mejoraDef =new Mejora("Armadura del traidor", "Aumenta defensa en +25", TipoMejora::DEFENSA, 25);
    Objeto* mejoraVida = new Mejora("Elixir de la vida","Aumenta tu vida maxima en 100",TipoMejora::VIDA,100);

    // Enemigos
    Enemigo* thyriel = new Enemigo("Thyriel, el Vigia del Umbral",'*',100,35,15,fragThyriel);
    Enemigo* vaelion = new Enemigo("Vaelion, el Heraldo Marchito", '*', 100, 40, 15,fragVaelion);

    // Jefe final
    Jefe* vharos = new Jefe("Vharos, el Ultimo Lamento", 'V', 150, 35, 20,fragVharos);

    // Habitaciones
    Habitacion* hab1 = new Habitacion();
    Habitacion* hab2 = new Habitacion();
    Habitacion* hab3 = new Habitacion();

    // Agregar entidades y objetos
    hab1->colocarNPC(piril,1,1);
    hab1->colocarObjeto(comida,2,1);
    hab1->colocarEnemigo(thyriel,1,2);

    //
    hab2->colocarNPC(ruler,2,2);
    hab2->colocarObjeto(mejoraAtq,2,1);
    hab2->colocarEnemigo(vaelion,1,1);
    hab2->colocarNPC(duro,0,1);

    //
    hab3 ->colocarNPC(trash,1,1);
    hab3 ->colocarEnemigo(vharos,2,1);
    hab3 ->colocarObjeto(mejoraVida,0,1);
    hab3 ->colocarObjeto(pocion,0,2);

    // Mapa
    Mapa* mapa = new Mapa();
    mapa->agregarHabitacion(hab1);
    mapa->agregarHabitacion(hab2);
    mapa->agregarHabitacion(hab3);

    mapa->setJugador(jugador);

    // view
    View* view = new View(mapa);

    // Juego
    bool juegoActivo = true;
    while (juegoActivo) {
        view->actualizar();
        char accion = view->obtenerInput();
        switch (accion) {
            case 'w': case 'a': case 's': case 'd':
            case 'W': case 'A': case 'S': case 'D':
                mapa->moverJugador(accion);
                break;
            case 'i': case 'I':
                jugador->mostrarInventario();
                break;
            case 'u': case 'U':
                jugador->mostrarInventario();
                    int indice;
                    std::cout << "Ingresa el numero del objeto a USAR: "; // Mal implementado, revisar
                    if (std::cin >> indice) {
                        jugador->usarObjeto(indice - 1);
                    } else {
                        std::cout << "Entrada invalida. Volviendo al juego.\n";
                        std::cin.clear();
                    }
                break;
            case 'q': case 'Q':
                std::cout << "Saliendo del juego...\n";
                juegoActivo = false;
                break;
            default:
                std::cout << "Accion invalida.\n";
        }
        if (!jugador->estaVivo()) {
            std::cout << "\n--- EL REINO HA CAIDO. GAME OVER ---\n";
            juegoActivo = false;
        }
        Habitacion* actual = mapa->getHabitacion();
        if (actual->estaCompleta() && !vharos->estaVivo()) {
            std::cout << "\nHas derrotado al Ultimo Lamento!\n";
            std::cout << "La Gema Soberana se reconstruye en un estallido de luz pura.\n";
            std::cout << "El Reino de Lysara renace.\n";
            juegoActivo = false;
        }
    }

    delete view;
    delete mapa;
    delete jugador;
    return 0;
}