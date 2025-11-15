#include "DialogoService.h"

DialogoService::DialogoService() {
    dialogoActual = new Dialogo();
    inicializarDialogos();
}

DialogoService::~DialogoService() {
    delete dialogoActual;
    dialogos.clear();
}
void DialogoService::inicializarDialogos() {
    //aqui escribimos todos los dialogos pe
    dialogos.push_back("Holaaa uwu");

}
string DialogoService::obtenerDialogo(int indice) {
    if (indice >= 0 && indice < dialogos.size()) {
        return dialogos[indice];
    }
    return "Alto ahi!\n\nResponde esta pregunta para continuar...";
}

Dialogo* DialogoService::getDialogoActual() {
    return dialogoActual;
}