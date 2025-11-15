#include "Mundo.h"

Mundo::Mundo(int ancho, int alto, int vidasIniciales) {
    anchoPanel = ancho;
    altoPanel = alto;
    fondo = new Fondo();

    // Estado inicial
    juegoEnPausa = false;
    vidas = vidasIniciales;
}

Mundo::~Mundo() {
    if (fondo != nullptr) {
        delete fondo;
    }
}

void Mundo::cargarFondo(char* ruta) {
    fondo->cargarImagen(ruta, anchoPanel, altoPanel);
}

int Mundo::getAnchoPanel() {
    return anchoPanel;
}

int Mundo::getAltoPanel() {
    return altoPanel;
}

Fondo* Mundo::getFondo() {
    return fondo;
}