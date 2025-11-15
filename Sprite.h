#pragma once
//clase padre
using namespace System::Drawing;

enum Direccion { Arriba, Abajo, Derecha, Izquierda, Ninguno };
class Sprite
{
protected:
    int x, y;
    int dx, dy;
    char* image;
    int indiceX, indiceY;
    int ancho, alto;
    int filas, columnas;
public:
    Sprite();
    Sprite(int x, int y);
    ~Sprite();

    void cargarImagen(char* ruta, int filas, int columnas);
    virtual void mover(Direccion tecla, int limiteAncho, int limiteAlto) = 0;
    virtual void dibujar(Graphics^ canvas) = 0;

    int getX();
    int getY();
    int getAncho();
    int getAlto();
    void setX(int x);
    void setY(int y);
    Rectangle getRectangle();
};

