
#include "Persona.h"

Persona::Persona(string id, string nombre) {
    this->id = id;
    this->nombre = nombre;
}

Persona::~Persona() {

}

string Persona::getId() {
    return id;
}

string Persona::getNombre() {
    return nombre;
}