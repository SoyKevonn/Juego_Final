#include "Dialogo.h"

Dialogo::Dialogo() {
    textoCompleto = "";
    textoActual = "";
    indice = 0;
    contador = 0;
    enProgreso = false;
}

Dialogo::~Dialogo() {
}

void Dialogo::iniciar(string texto) {
    textoCompleto = texto;
    textoActual = "";
    indice = 0;
    contador = 0;
    enProgreso = true;
}

bool Dialogo::actualizar() {
    if (!enProgreso) return false;

    // Agregar 3 letras por frame para efecto rapido de escritura
    for (int i = 0; i < 3; i++) {
        if (indice < textoCompleto.length()) {
            textoActual += textoCompleto[indice];
            indice++;
        }
        else {
            enProgreso = false;
            return false;
        }
    }

    return true;
}

string Dialogo::getTextoActual() {
    return textoActual;
}

bool Dialogo::estaEnProgreso() {
    return enProgreso;
}

void Dialogo::detener() {
    enProgreso = false;
}
