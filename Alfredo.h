#pragma once
#include "Sprite.h"
using namespace System::Drawing;

class Alfredo:public Sprite
{
private:
	int vida;
	int velocidad;
public:
	Alfredo();
	Alfredo(int x, int y);
	~Alfredo();

	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
	void dibujar(Graphics^ canvas) override;
};

