
#include "ListaEstudiantes.h"
#include <fstream>
#include <iostream>
#include <sstream>

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

void ListaEstudiantes::guardarEnArchivo(string nombreArchivo) {
    ofstream archivo(nombreArchivo);

    NodoEstudiante* actual = head;
    while (actual != nullptr) {
        archivo << actual->dato->getId() << "," << actual->dato->getNombre() << endl;
        actual = actual->siguiente;
    }
    archivo.close();
}

void ListaEstudiantes::cargarDesdeArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open())
        return;

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty())
            continue;

        stringstream ss(linea);
        string id, nombre;
        if (!getline(ss, id, ','))
            continue;
        if (!getline(ss, nombre))
            continue;

        Estudiante* e = new Estudiante(id, nombre);
        if (!insertar(e))
            delete e;
    }
    archivo.close();
}


