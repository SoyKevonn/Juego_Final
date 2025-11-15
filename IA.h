#pragma once

#include "Aliado.h"
//la plantilla es de pikachu del video de 2 horas
class IA:public Aliado
{
public:
	IA();
	IA(int x, int y, int tipoMovimiento);
	~IA();

	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
};

