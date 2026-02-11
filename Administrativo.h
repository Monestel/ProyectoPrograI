
#ifndef PROYECTOPROGRAI_ADMINISTRATIVO_H
#define PROYECTOPROGRAI_ADMINISTRATIVO_H
#include "Persona.h"

class Administrativo : public Persona {
public:
    Administrativo(string id, string nombre)
        : Persona(id, nombre) {
    }

    string toString() override {
        return "Administrativo: " + " - " + nombre;
    }
};

#endif //PROYECTOPROGRAI_ADMINISTRATIVO_H