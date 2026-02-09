
#include "Horario.h"
#include <iostream>

Horario::Horario(int dias, int horas) {
    this->dias = dias;
    this->horas = horas;
    matriz = new Curso**[dias];

    for (int i = 0; i < dias; i++) {
        matriz[i] = new Curso*[horas];
        for (int j = 0; j < horas; j++) {
            matriz[i][j] = nullptr;
        }
    }
}

Horario::~Horario() {
    for (int i = 0; i < dias; i++) {
        delete[] matriz[i];
        delete[] matriz;
    }
}

bool Horario::asignarCurso(int dia, int hora, Curso* curso) {
    if (dia < 0 || dia >= dias || hora < 0 || hora >= horas)
        return false;

    if (matriz[dia][hora] != nullptr)
        return false;

    matriz[dia][hora] = curso;
    return true;
}

void Horario::mostrar() {
    for (int i = 0; i < dias; i++) {
        for (int j = 0; j < horas; j++) {
            if (matriz[i][j] == nullptr)
                std::cout << "[ Libre ]";
            else
                std::cout << "[" << matriz[i][j]->getCodigo() << "]";
        }
        std::cout << std::endl;
    }
}

