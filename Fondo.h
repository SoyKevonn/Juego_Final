#pragma once
using namespace System;
using namespace System::Drawing;

class Fondo {
private:
    char* rutaImagen;
    int ancho;
    int alto;

public:
    Fondo();
    Fondo(char* ruta, int ancho, int alto);
    ~Fondo();

    void cargarImagen(char* ruta, int ancho, int alto);
    void dibujar(Graphics^ canvas);

    char* getRutaImagen();
    int getAncho();
    int getAlto();
};

