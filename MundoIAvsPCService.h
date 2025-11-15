#pragma once
#include "Alfredo.h"
#include "Aliado.h"
#include "Mundo.h"
#include "IA.h"
#include "DialogoService.h"
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

	DialogoService* gestorDialogos;
public:
	MundoIAvsPCService(int ancho, int alto, int vidasIniciales);
	~MundoIAvsPCService();
	void cargarSpriteAlfredo(char* ruta, int filas, int columnas);
	void moverAlfredo(Direccion tecla);
	Alfredo* getAlfredo() { return alfredo; }

	//aliado
	void generarAliado(int cantAliados);
	//colisiones
	Aliado* verificarColisionesAlfredoAliado();

	//dialogos
	void iniciarDialogo(Aliado* aliado, int capturados);
	bool actualizarDialogo(String^& textoDialogo);

	void dibujarTodo(Graphics^ canvas)override;
};

