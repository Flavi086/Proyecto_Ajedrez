#include <iostream>
#include "Tablero.h"
using namespace std;
int main() {
    Tablero tablero;

    tablero.SetPieza(0, 0, TORRE);
    tablero.SetPieza(0, 7, TORRE);
    tablero.SetPieza(7, 0, torre);
    tablero.SetPieza(7, 7, torre);
    tablero.SetPieza(0, 1, CABALLO);
    tablero.SetPieza(0, 6, CABALLO);
    tablero.SetPieza(7, 1, caballo);
    tablero.SetPieza(7, 6, caballo);
    tablero.SetPieza(0, 2, ALFIL);
    tablero.SetPieza(0, 5, ALFIL);
    tablero.SetPieza(7, 2, alfil);
    tablero.SetPieza(7, 5, alfil);
    tablero.SetPieza(0, 3, REINA);
    tablero.SetPieza(0, 4, REY);
    tablero.SetPieza(7, 3, reina);
    tablero.SetPieza(7, 4, rey);

    for (int i = 0; i < TAMANIO_TABLERO; i++) {
        tablero.SetPieza(1, i, PEON);
        tablero.SetPieza(6, i, PEON);
    }

    while (true) {
        tablero.MostrarTablero();
        if (tablero.EsTurnoBlancas()) {
            std::cout << "Turno de las blancas." << std::endl;
        } 
        else {
            std::cout << "Turno de las negras." << std::endl;
        }

        int filaOrigen, columnaOrigen, filaDestino, columnaDestino;
        std::cout << "Ingrese fila y columna de origen (ejemplo: 0 0): ";
        std::cin >> filaOrigen >> columnaOrigen;

        std::cout << "Ingrese fila y columna de destino (ejemplo: 3 3): ";
        std::cin >> filaDestino >> columnaDestino;

        tablero.MoverPieza(filaOrigen, columnaOrigen, filaDestino, columnaDestino);

        std::cout << "\nTablero después del movimiento:" << std::endl;
    }

    return 0;
}