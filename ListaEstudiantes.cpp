
#include "ListaEstudiantes.h"

#include <iostream>
using namespace std;

ListaEstudiantes::ListaEstudiantes() {
    head = nullptr;
}

ListaEstudiantes::~ListaEstudiantes() {
    NodoEstudiante* actual = head;

    while (actual != nullptr) {
        NodoEstudiante* temp = actual;
        actual = actual->siguiente;
        delete temp->dato;
        delete temp;
    }
}

bool ListaEstudiantes::insertar(Estudiante* e) {
    if (buscar(e->getId()) != nullptr)
        return false;

    NodoEstudiante* nuevo = new NodoEstudiante(e);
    nuevo->siguiente = head;
    head = nuevo;

    return true;
}

Estudiante* ListaEstudiantes::buscar(string id) {
    NodoEstudiante* actual = head;

    while (actual != nullptr) {
        if (actual->dato->getId() == id)
            return actual->dato;
        actual = actual->siguiente;
    }
    return nullptr;
}

bool ListaEstudiantes::eliminar(string id) {
    NodoEstudiante* actual = head;
    NodoEstudiante* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->dato->getId() == id) {
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

void ListaEstudiantes::mostrar() {
    NodoEstudiante* actual = head;

    while (actual != nullptr) {
        cout << actual->dato->toString() << endl;
        actual = actual->siguiente;
    }
}


