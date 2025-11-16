#pragma once
#include "Sprite.h"

class Enemigo :public Sprite
{
protected:
	int velocidad;
	bool activo;
	int tipoMovimiento;
public:
	Enemigo();
	Enemigo(int x, int y, int velocidad, int tipoMovimento);
	~Enemigo();

	virtual void mover(Direccion tecla, int limiteAncho, int limiteAlto) = 0;

	void dibujar(Graphics^ canvas)override;
	int getVelocidad();
	bool getActivo();
	void setVelocidad(int velocidad);
	void setActivo(bool activo);

};

