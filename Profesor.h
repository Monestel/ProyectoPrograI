
#ifndef PROYECTOPROGRAI_PROFESOR_H
#define PROYECTOPROGRAI_PROFESOR_H
#include "Persona.h"

class Profesor : public Persona {
public:

    Profesor(string id, string nombre);
    string toString();

};

#endif //PROYECTOPROGRAI_PROFESOR_H