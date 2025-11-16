#include "MundoIAvsPCService.h"
#include <cstdlib>
#include <ctime>

MundoIAvsPCService::MundoIAvsPCService(int ancho, int alto, int vidasIniciales) :Mundo(ancho, alto, vidasIniciales) {
	alfredo = new Alfredo(300, 300);
	//agregar aliado ia tmb
	srand(time(NULL));

	gestorDialogos = new DialogoService();
	aliadoActual = nullptr;

}
MundoIAvsPCService::~MundoIAvsPCService() {
	delete alfredo;
	for (int i = 0; i < aliados.size(); i++) {
		delete aliados[i];
	}
	aliados.clear();
	//delete vector de enemigos
}
void MundoIAvsPCService::cargarSpriteAlfredo(char* ruta, int filas, int columnas) {
	alfredo->cargarImagen(ruta, filas, columnas);
}
void MundoIAvsPCService::moverAlfredo(Direccion tecla) {
	alfredo->mover(tecla, anchoPanel, altoPanel);
}
void MundoIAvsPCService::generarAliado(int cantAliados) {
	char rutaIA[] = "robotIAxd.png";
	

	for (int i = 0; i < cantAliados; i++) {
		IA* ia = new IA(700, 150, 1);

		ia->cargarImagen(rutaIA, 4, 4);

		aliados.push_back(ia);
	}
}
void MundoIAvsPCService::generarEnemigos(int cantEnemigos) {

	char rutaGuardian[] = "guardian.png";

	for (int i = 0; i < cantEnemigos; i++) {
		int x = rand() % (anchoPanel - 100);
		int y = rand() % (altoPanel - 200);

		Guardian* guardian = new Guardian(x, y, 0);

		guardian->cargarImagen(rutaGuardian, 4, 9);

		enemigos.push_back(guardian);
	}
}
void MundoIAvsPCService::moverEnemigos() {
	for (int i = 0; i < enemigos.size(); i++) {
		if (enemigos[i]->getActivo()) {
			enemigos[i]->mover(Direccion::Ninguno, anchoPanel, altoPanel);
		}
	}
}
//dialogos
void MundoIAvsPCService::iniciarDialogo(Aliado* aliado, int capturados) {
	aliadoActual = aliado;
	juegoEnPausa = true;
	//obtener dialogoActual usando el indice de capturados
	std::string textoDialogo = gestorDialogos->obtenerDialogo(capturados);

	//iniciar dialogo
	Dialogo* dialogoActual = gestorDialogos->getDialogoActual();
	dialogoActual->iniciar(textoDialogo);
}
bool MundoIAvsPCService::actualizarDialogo(String^& textoDialogo) {
	Dialogo* dialogoActual = gestorDialogos->getDialogoActual();
	if (!dialogoActual->estaEnProgreso()) {
		return false; //no está en progreso el dialogo
	}
	bool continuar = dialogoActual->actualizar();
	std::string textoStr = dialogoActual->getTextoActual();
	textoDialogo = gcnew String(textoStr.c_str());

	return continuar; //true si el dialogo continua, false si terminó
}

//xd

//colisiones
Aliado* MundoIAvsPCService::verificarColisionesAlfredoAliado() {

	Rectangle rectAlfredo = alfredo->getRectangle();

	for (int i = 0; i < aliados.size(); i++) {
		if (!aliados[i]->getActivo()) continue;

		Rectangle rectAliado = aliados[i]->getRectangle();
		if (rectAlfredo.IntersectsWith(rectAliado)) {
			return aliados[i];
		}

		return nullptr;

	}
}
//colision enemigo
Enemigo* MundoIAvsPCService::verificarColisionALfredoEnemigo() {
	Rectangle rectAlfredo = alfredo->getRectangle();
	for (int i = 0; i < enemigos.size(); i++) {
		if (!enemigos[i]->getActivo()) continue;

		Rectangle rectEnemigo = enemigos[i]->getRectangle();
		if (rectAlfredo.IntersectsWith(rectEnemigo)) {
			return enemigos[i];
		}
	}
	return nullptr;
}
void MundoIAvsPCService::dibujarTodo(Graphics^ canvas) {
	//dibujar fondo primero
	fondo->dibujar(canvas);

	//dibujar alfredo
	alfredo->dibujar(canvas);

	//dibujar todos los aliados
	for (int i = 0; i < aliados.size(); i++) {
		if (aliados[i]->getActivo()) {
			aliados[i]->dibujar(canvas);
		}
	}

	//dibujar todos los enemigos
	for (int i = 0; i < enemigos.size(); i++) {
		if (enemigos[i]->getActivo()) {
			enemigos[i]->dibujar(canvas);
		}
	}

}
