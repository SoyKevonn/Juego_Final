#pragma once
#include "Sprite.h"

class Aliado:public Sprite
{
protected:
	int velocidad;
	bool activo;
	int tipoMovimiento; //0 = horizontal, 1= vertical, 2=diagonal
public:
	Aliado();
	Aliado(int x, int y, int velocidad, int tipoMovimiento);
	~Aliado();

	virtual void mover(Direccion tecla, int limiteAncho, int limiteAlto) = 0;

	void dibujar(Graphics^ canvas)override;

	int getVelocidad();
	bool getActivo();
	void setVelocidad(int velocidad);
	void setActivo(bool activo);
};

