#pragma once
#include "Dialogo.h"
#include <vector>

using namespace std;

class DialogoService {
private:
    Dialogo* dialogoActual;
    vector<string> dialogos;

public:
    DialogoService();
    ~DialogoService();

    void inicializarDialogos();
    string obtenerDialogo(int indice);
    Dialogo* getDialogoActual();
};
