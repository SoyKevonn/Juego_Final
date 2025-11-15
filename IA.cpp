#include "IA.h"
#include <cstdlib>

IA::IA() :Aliado() {
	//estatico
	dx = 0;	
	dy = 0;
}
IA::IA(int x, int y, int tipoMovimiento) :Aliado(x, y, 3, tipoMovimiento) {
	//no se mueve pe
}
IA::~IA() {
}
void IA::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
	//nada
}