
#ifndef PROYECTOPROGRAI_ESTUDIANTE_H
#define PROYECTOPROGRAI_ESTUDIANTE_H
#include "Persona.h"

class Estudiante : public Persona {
public:
    Estudiante(string id, string nombre);
    string toString();

};

#endif //PROYECTOPROGRAI_ESTUDIANTE_H