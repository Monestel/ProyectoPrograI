
#include "ListaCursos.h"
#include <iostream>
#include <fstream>
#include <sstream>

ListaCursos::ListaCursos() {
    head = nullptr;
}

ListaCursos::~ListaCursos() {
    NodoCurso* actual = head;

    while (actual != nullptr) {
        NodoCurso* temp = actual;
        actual = actual->siguiente;
        delete temp->dato;
        delete temp;
    }
}

bool ListaCursos::insertar(Curso* cur) {
    if (buscar(cur->getCodigo()) != nullptr)
        return false;

    NodoCurso* nuevo = new NodoCurso(cur);
    nuevo->siguiente = head;
    head = nuevo;
    return true;
}

Curso* ListaCursos::buscar(string codigo) {
    NodoCurso* actual = head;

    while (actual != nullptr) {
        if (actual->dato->getCodigo() == codigo)
            return actual->dato;
        actual = actual->siguiente;
    }
    return nullptr;
}

bool ListaCursos::eliminar(string codigo) {
    NodoCurso* actual = head;
    NodoCurso* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->dato->getCodigo() == codigo) {
            if (anterior == nullptr)
                head = actual->siguiente;
            else
                anterior->siguiente = actual->siguiente;
            delete actual->dato;
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false;
}

void ListaCursos::mostrar() {
    NodoCurso* actual = head;

    while (actual != nullptr) {
        cout << actual->dato->toString() << endl;
    }
}

void ListaCursos::guardarEnArchivo(string nombreArchivo) {
    ofstream archivo(nombreArchivo);

    NodoCurso* actual = head;
    while (actual != nullptr) {
        archivo << actual->dato->getCodigo() << "," << actual->dato->getNombre() << ","
        << actual->dato->getProfesor()->getId() << endl;
        actual = actual->siguiente;
    }
    archivo.close();
}

void ListaCursos::cargarDesdeArchivo(string nombreArchivo, ListaProfesores& profesores) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
        return;

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty())
            continue;

        stringstream ss(linea);
        string codigo, nombre, idProfesor;
        if (!getline(ss, codigo, ','))
            continue;
        if (!getline(ss, nombre, ','))
            continue;
        if (!getline(ss, idProfesor))
            continue;

        Profesor* prof = profesores.buscar(idProfesor);
        if (prof == nullptr)
            continue;

        Curso* curso = new Curso(codigo, nombre, prof);
        if (!insertar(curso))
            delete curso;
    }
    archivo.close();
}
