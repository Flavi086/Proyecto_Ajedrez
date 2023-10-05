

#include <iostream>

enum Pieza {
    VACIO,
    PEON,
    TORRE,
    CABALLO,
    ALFIL,
    REINA,
    REY,
    peon,
    torre,
    caballo,
    alfil,
    reina,
    rey
};

const int TAMANIO_TABLERO = 8;

class Tablero {
public:
    Tablero() {
        InicializarTablero();
    }

    void InicializarTablero() {
        turnoBlancas = true;
        for (int fila = 0; fila < TAMANIO_TABLERO; fila++) {
            for (int columna = 0; columna < TAMANIO_TABLERO; columna++) {
                tablero[fila][columna] = VACIO;
            }
        }
    }

    void SetPieza(int fila, int columna, Pieza pieza) {
        tablero[fila][columna] = pieza;
    }

    void MoverPieza(int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino) {
        // Validar el turno antes de realizar el movimiento
        if ((turnoBlancas && tablero[filaOrigen][columnaOrigen] >= PEON && tablero[filaOrigen][columnaOrigen] <= REY) ||
            (!turnoBlancas && tablero[filaOrigen][columnaOrigen] >= peon && tablero[filaOrigen][columnaOrigen] <= rey)) {
            
            tablero[filaDestino][columnaDestino] = tablero[filaOrigen][columnaOrigen];
            tablero[filaOrigen][columnaOrigen] = VACIO;
            
            CambiarTurno(); // Cambiar el turno después del movimiento
        } else {
            std::cout << "Movimiento no válido. No puedes mover una pieza del otro jugador en este turno." << std::endl;
        }
    }

    void MostrarTablero() {
        char caracteresPiezas[] = ".PTCARKptcark"; // Usar minúsculas para piezas negras

        // Muestra las coordenadas de las columnas
        std::cout << "  0 1 2 3 4 5 6 7" << std::endl;
       
        for (int fila = 0; fila < TAMANIO_TABLERO; fila++) {
            // Muestra las coordenadas de las filas
            std::cout << fila << " ";
            
            for (int columna = 0; columna < TAMANIO_TABLERO; columna++) {
                std::cout << caracteresPiezas[tablero[fila][columna]] << ' ';
            }
            std::cout << fila << std::endl;
        }

        // Muestra las coordenadas de las columnas nuevamente
        std::cout <<"  0 1 2 3 4 5 6 7"<< std::endl;
    }

    bool EsTurnoBlancas() {
        return turnoBlancas;
    }

    void CambiarTurno() {
        turnoBlancas = !turnoBlancas; 
    }

private:
    Pieza tablero[TAMANIO_TABLERO][TAMANIO_TABLERO];
    bool turnoBlancas;
};
 