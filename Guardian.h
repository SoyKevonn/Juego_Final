#pragma once
#include "Enemigo.h"

class Guardian:public Enemigo
{
public:
	Guardian();
	Guardian(int x, int y, int tipoMovimiento);
	~Guardian();

	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;

};

