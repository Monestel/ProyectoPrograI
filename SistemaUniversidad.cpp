
#include "SistemaUniversidad.h"
#include <iostream>

SistemaUniversidad::SistemaUniversidad()
    : horario(5,6) {
}

void SistemaUniversidad::mostrarSistema() {
    std:: cout << "\n--- Estudiantes ---\n";
    estudiantes.mostrar();

    std:: cout << "\n--- Profesores ---\n";
    profesores.mostrar();

    std:: cout << "\n--- Cursos ---\n";
    cursos.mostrar();

    std:: cout << "\n--- Horario ---\n";
    horario.mostrar();
}
