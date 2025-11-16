#include "Guardian.h"
#include <cstdlib>
Guardian::Guardian() :Enemigo() {
	dx = 0;
	dy = 0;
}
Guardian::Guardian(int x, int y, int tipoMovimiento) :Enemigo(x, y, 3, tipoMovimiento) {
	//en el constructor de enemigo ya inicializa dx y dy segun tipoMovmiento
}
Guardian::~Guardian() {

}
void Guardian::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
	indiceX++;
	if (indiceX >= columnas) indiceX = 0;
	x += dx * velocidad;
	y += dy * velocidad;
	//rebotar bordes horizontales

	if (x <= 0) {
		x = 0;
		dx = 1;
		indiceY = 3; //derecha
	}
	if (x >= limiteAncho - ancho) {
		x = limiteAncho - ancho;
		dx = -1;
		indiceY = 1; //izquierda
	}
	//rebotes bordes techo
	if (y <= 0) {
		y = 0;
		dy = 1;
		indiceY = 2;//arriba
	}
	if (y >= limiteAlto - alto) {
		y = limiteAlto - alto;
		dy = -1;
		indiceY = 0; //abajo
	}
}

