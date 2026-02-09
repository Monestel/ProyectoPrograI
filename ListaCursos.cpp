
#include "ListaCursos.h"
#include <iostream>
using namespace std;


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
