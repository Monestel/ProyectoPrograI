
#include "Profesor.h"

Profesor::Profesor(string id, string nombre)
    : Persona(id, nombre) {


}

string Profesor::toString() {
    return "Profesor: " + id + " - " + nombre;
}