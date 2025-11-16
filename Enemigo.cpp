#include "Enemigo.h"
#include <cstdlib>
#include <ctime>
using namespace System::Drawing;
Enemigo::Enemigo() {
    velocidad = 5;
    activo = true;
    tipoMovimiento = 2;
    dx = 0;
    dy = 1;
}
Enemigo::Enemigo(int x, int y, int velocidad, int tipoMovimiento) :Sprite(x, y) {
    this->velocidad = velocidad;
    this->activo = true;
    this->tipoMovimiento = tipoMovimiento;

    //Configurar movimiento segun tipo
    if (tipoMovimiento == 0) {
        // Solo horizontal
        dx = 1;
        dy = 0;
        indiceY = 3;  // Derecha
    }
    else if (tipoMovimiento == 1) {
        // Solo vertical
        dx = 0;
        dy = 1;
        indiceY = 2;  // Abajo
    }
    else {
        // Diagonal
        dx = 1;
        dy = 1;
    }
}
Enemigo::~Enemigo() {

}
void Enemigo::dibujar(Graphics^ canvas) {
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
int Enemigo::getVelocidad() { return velocidad; }
bool Enemigo::getActivo() { return activo; }
void Enemigo::setVelocidad(int velocidad) { this->velocidad = velocidad; }
void Enemigo::setActivo(bool activo) { this->activo = activo; }

