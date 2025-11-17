#pragma once
#include "Alfredo.h"
#include "Aliado.h"
#include "Mundo.h"
#include "IA.h"
#include "DialogoService.h"
#include "Enemigo.h"
#include "Guardian.h"
#include <vector>

using namespace System;
using namespace System::Drawing;
using namespace std;

class MundoIAvsPCService:public Mundo
{
private:
	Alfredo* alfredo;
	/*Aliado* aliadoIA;*/
	vector<Aliado*> aliados;
	Aliado* aliadoActual;
	//falta el vector de los enemigos
	vector<Enemigo*> enemigos;
	DialogoService* gestorDialogos;
	vector<Rectangle> zonasRestringidas;
public:
	MundoIAvsPCService(int ancho, int alto, int vidasIniciales);
	~MundoIAvsPCService();
	void cargarSpriteAlfredo(char* ruta, int filas, int columnas);
	void moverAlfredo(Direccion tecla);
	Alfredo* getAlfredo() { return alfredo; }

	//aliado
	void generarAliado(int cantAliados);
	//colisiones aliados
	Aliado* verificarColisionesAlfredoAliado();
	//enemigos
	void generarEnemigos(int cantEnemigos);
	Enemigo* verificarColisionALfredoEnemigo();
	void moverEnemigos();
	//dialogos
	void iniciarDialogo(Aliado* aliado, int capturados);
	bool actualizarDialogo(String^& textoDialogo);

	void dibujarTodo(Graphics^ canvas)override;

	//colisiones para parar
	void registrarZonaRestringida(Rectangle zona);
};

