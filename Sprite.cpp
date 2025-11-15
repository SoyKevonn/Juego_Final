#include "Sprite.h"
#include <cstring>
Sprite::Sprite() : x(0), y(0), dx(0), dy(0), indiceX(0), indiceY(0),
ancho(0), alto(0), filas(0), columnas(0) {
    image = new char[100];
}

Sprite::Sprite(int x, int y) : x(x), y(y), dx(0), dy(0), indiceX(0), indiceY(0),
ancho(0), alto(0), filas(0), columnas(0) {
    image = new char[100];
}

Sprite::~Sprite() {
    if (image != nullptr) {
        delete[] image;
    }
}

void Sprite::cargarImagen(char* ruta, int filas, int columnas) {
    strcpy_s(image, 100, ruta);
    this->filas = filas;
    this->columnas = columnas;

    System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(gcnew System::String(image));
    ancho = bitmap->Width / columnas;
    alto = bitmap->Height / filas;
    delete bitmap;
}

int Sprite::getX() { return x; }
int Sprite::getY() { return y; }
int Sprite::getAncho() { return ancho; }
int Sprite::getAlto() { return alto; }
void Sprite::setX(int x) { this->x = x; }
void Sprite::setY(int y) { this->y = y; }

Rectangle Sprite::getRectangle() {
    // Reducir el área de colisión al 60% del tamaño del sprite para detectar colisiones más precisas
    // Esto evita colisiones con espacios transparentes del spritesheet
    int anchoColision = (int)(ancho * 0.6);
    int altoColision = (int)(alto * 0.6);

    // Centrar el área de colisión en el sprite
    int desplazamientoX = (ancho - anchoColision) / 2;
    int desplazamientoY = (alto - altoColision) / 2;

    return Rectangle(x + desplazamientoX, y + desplazamientoY, anchoColision, altoColision);
}
