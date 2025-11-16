#include "Aliado.h"
#include <cstdlib>
#include <ctime>

using namespace System::Drawing;

Aliado::Aliado() : Sprite() {
    velocidad = 5;
    activo = true;
    tipoMovimiento = 2;  // Diagonal por defecto
    dx = 1;
    dy = 1;
}

Aliado::Aliado(int x, int y, int velocidad, int tipoMovimiento) : Sprite(x, y) {
    this->velocidad = velocidad;
    this->activo = true;
    this->tipoMovimiento = tipoMovimiento;
}

Aliado::~Aliado() {
}

void Aliado::dibujar(Graphics^ canvas) {
    if (activo && image != nullptr && ancho > 0 && alto > 0) {
        Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));

        Rectangle cuadroOrigen = Rectangle(
            indiceX * ancho,
            indiceY * alto,
            ancho,
            alto
        );

        Rectangle cuadroDestino = Rectangle(
            x,
            y,
            ancho * 1.5,
            alto * 1.5
        );

        canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
        delete bitmap;
    }
}

int Aliado::getVelocidad() { return velocidad; }
bool Aliado::getActivo() { return activo; }
void Aliado::setVelocidad(int velocidad) { this->velocidad = velocidad; }
void Aliado::setActivo(bool activo) { this->activo = activo; }
