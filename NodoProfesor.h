
#ifndef PROYECTOPROGRAI_NODOPROFESOR_H
#define PROYECTOPROGRAI_NODOPROFESOR_H
#include "Profesor.h"

class NodoProfesor {
public:
    Profesor* dato;
    NodoProfesor* siguiente;

    NodoProfesor(Profesor* prof) {
        dato = prof;
        siguiente = nullptr;
    }
};

#endif //PROYECTOPROGRAI_NODOPROFESOR_H