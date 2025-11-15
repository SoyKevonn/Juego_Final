#pragma once
#include "Fondo.h"

using namespace System;
using namespace System::Drawing;

class Mundo {
protected:
    int anchoPanel;
    int altoPanel;
    Fondo* fondo;

    // Estado del juego (común a todos los modos)
    bool juegoEnPausa;
    int vidas;

public:
    Mundo(int ancho, int alto, int vidasIniciales);
    virtual ~Mundo();

    void cargarFondo(char* ruta);
    virtual void dibujarTodo(Graphics^ canvas) = 0;

    int getAnchoPanel();
    int getAltoPanel();
    Fondo* getFondo();

    // Estado del juego (común a todos los modos)
    bool estaEnPausa() { return juegoEnPausa; }
    void setPausa(bool pausa) { juegoEnPausa = pausa; }
    int getVidas() { return vidas; }
    void setVidas(int v) { vidas = v; }
};
