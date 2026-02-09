
#ifndef PROYECTOPROGRAI_NODOCURSO_H
#define PROYECTOPROGRAI_NODOCURSO_H
#include "Curso.h"

class NodoCurso {
public:
    Curso* dato;
    NodoCurso* siguiente;

    NodoCurso(Curso* cur) {
        dato = cur;
        siguiente = nullptr;
    }

};

#endif //PROYECTOPROGRAI_NODOCURSO_H