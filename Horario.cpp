
#include "Horario.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

    nombresDias = new string[dias] {
        "Lunes", "Martes", "Miercoles", "Jueves", "Viernes"
    };

    nombresHoras = new string[horas] {
        "8-10", "10-12", "12-14", "14-16", "16-18", "18-20"
    };
}

Horario::~Horario() {
    for (int i = 0; i < dias; i++) {
        delete[] matriz[i];
        delete[] matriz;

        delete[] nombresDias;
        delete[] nombresHoras;
    }
}

bool Horario::asignarCurso(int dia, int hora, Curso* curso) {
    if (curso == nullptr)
        return false;

    if (dia < 0 || dia >= dias || hora < 0 || hora >= horas)
        return false;

    if (matriz[dia][hora] != nullptr)
        return false;

    matriz[dia][hora] = curso;
    return true;
}

void Horario::mostrar() {
    cout << "        ";
    for (int h = 0; h < horas; h++)
        cout << nombresHoras[h] << "   ";
        cout << "\n";

    for (int i = 0; i < dias; i++) {
        cout << nombresDias[i] << "   ";

        for (int j = 0; j < horas; j++) {
            if (matriz[i][j] == nullptr)
                cout << " ---  ";
            else
                cout << matriz[i][j]->getCodigo() << "   ";
        }
        cout << "\n";
    }
}

void Horario::guardarEnArchivo(string nombreArchivo) {
    ofstream archivo(nombreArchivo);

    for (int i = 0; i < dias; i++) {
        for (int j = 0; j < horas; j++) {
            if (matriz[i][j] != nullptr) {
                archivo << i << "," << j << "," << matriz[i][j]->getCodigo() << "\n";
            }
        }
    }
    archivo.close();
}

void Horario::cargarDesdeArchivo(string nombreArchivo, ListaCursos &cursos) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open())
        return;

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty())
            continue;

        stringstream ss(linea);
        string sDia, sHora, codigo;
        if (!getline(ss, sDia, ','))
            continue;
        if (!getline(ss, sHora, ','))
            continue;
        if (!getline(ss, codigo))
            continue;

        int dia, hora;
        stringstream sd(sDia);
        sd >> dia;
        stringstream sh(sHora);
        sh >> hora;

        Curso* curso = cursos.buscar(codigo);
        if (curso == nullptr)
            asignarCurso(dia, hora, curso);
    }
    archivo.close();
}
