
#ifndef PROYECTOPROGRAI_SISTEMAUNIVERSIDAD_H
#define PROYECTOPROGRAI_SISTEMAUNIVERSIDAD_H
#include "ListaEstudiantes.h"
#include "ListaProfesores.h"
#include "ListaCursos.h"
#include"Horario.h"

class SistemaUniversidad {
private:
    ListaEstudiantes estudiantes;
    ListaProfesores profesores;
    ListaCursos cursos;
    Horario horario;

public:
    SistemaUniversidad();
    void mostrarSistema();
};

#endif //PROYECTOPROGRAI_SISTEMAUNIVERSIDAD_H