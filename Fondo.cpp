#include "Fondo.h"
#include <cstring>

Fondo::Fondo() {
    rutaImagen = new char[100];
    rutaImagen[0] = '\0';
    ancho = 0;
    alto = 0;
}

Fondo::Fondo(char* ruta, int ancho, int alto) {
    rutaImagen = new char[100];
    strcpy_s(rutaImagen, 100, ruta);
    this->ancho = ancho;
    this->alto = alto;
}

Fondo::~Fondo() {
    if (rutaImagen != nullptr) {
        delete[] rutaImagen;
    }
}

void Fondo::cargarImagen(char* ruta, int ancho, int alto) {
    strcpy_s(rutaImagen, 100, ruta);
    this->ancho = ancho;
    this->alto = alto;
}

void Fondo::dibujar(Graphics^ canvas) {
    if (ancho == 0 || alto == 0) return;
    if (rutaImagen == nullptr || strlen(rutaImagen) == 0) return;

    System::String^ ruta = gcnew System::String(rutaImagen);

    Bitmap^ bitmap = gcnew Bitmap(ruta);
    canvas->DrawImage(bitmap, 0, 0, ancho, alto);
    delete bitmap;

}

char* Fondo::getRutaImagen() {
    return rutaImagen;
}

int Fondo::getAncho() {
    return ancho;
}

int Fondo::getAlto() {
    return alto;
} 