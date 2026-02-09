
#ifndef PROYECTOPROGRAI_NODOESTUDIANTE_H
#define PROYECTOPROGRAI_NODOESTUDIANTE_H
#include "Estudiante.h"

class NodoEstudiante {
public:
    Estudiante* dato;
    NodoEstudiante* siguiente;

    NodoEstudiante(Estudiante* dato) {
        this->dato = dato;
        this->siguiente = nullptr;
    }

};

#endif //PROYECTOPROGRAI_NODOESTUDIANTE_H