
#include "Estudiante.h"

Estudiante::Estudiante(string id, string nombre)
    : Persona(id, nombre) {

}

string Estudiante::toString() {
    return "Estudiante: " + id + " - " + nombre;
}