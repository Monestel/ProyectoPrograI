
#ifndef PROYECTOPROGRAI_PERSONA_H
#define PROYECTOPROGRAI_PERSONA_H
#include <string>
using namespace std;

class Persona {
protected:
    string id, nombre;

public:
    Persona(string id, string nombre);
    virtual ~Persona();
    string getId();
    string getNombre();
    virtual string toString() = 0;
};

#endif //PROYECTOPROGRAI_PERSONA_H