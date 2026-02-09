
#include "Curso.h"

Curso::Curso(string codigo, string nombre, Profesor *profesor) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->profesor = profesor;
}

string Curso::getCodigo() {
    return codigo;
}

string Curso::getNombre() {
    return nombre;
}

Profesor* Curso::getProfesor() {
    return profesor;
}

string Curso::toString() {
    return codigo + " - " + nombre +
            " | Profesor: " + profesor->getNombre();
}
