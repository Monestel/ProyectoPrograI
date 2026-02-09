
#include "ListaProfesores.h"
#include <iostream>

ListaProfesores::ListaProfesores() {
    head = nullptr;
}

ListaProfesores::~ListaProfesores() {
    NodoProfesor* actual = head;

    while (actual != nullptr) {
        NodoProfesor* temp = actual;
        actual = actual->siguiente;
        delete temp->dato;
        delete temp;
    }
}

bool ListaProfesores::insertar(Profesor* prof) {
    if (buscar(prof->getId()) != nullptr)
        return false;

    NodoProfesor* nuevo = new NodoProfesor(prof);
    nuevo->siguiente = head;
    head = nuevo;
    return true;
}

Profesor* ListaProfesores::buscar(string id) {
    NodoProfesor* actual = head;

    while (actual != nullptr) {
        if (actual->dato->getId() == id)
            return actual->dato;
        actual = actual->siguiente;
    }
    return nullptr;
}

bool ListaProfesores::eliminar(string id) {
    NodoProfesor* actual = head;
    NodoProfesor* anterior = nullptr;

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

void ListaProfesores::mostrar() {
    NodoProfesor* actual = head;

    while (actual != nullptr) {
        std::cout << actual->dato->toString() << std::endl;
    }
}
