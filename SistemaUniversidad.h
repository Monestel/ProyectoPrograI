
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
    bool registrarProfesor(string id, string nombre);
    bool registrarEstudiante(string id, string nombre);
    bool registrarCurso(string codigo, string nombre, string idProfesor);
    void menuSistema();
    bool asignarCursoHorario(string codigoCurso, int dia, int hora);
    void guardarDatos();
};

#endif //PROYECTOPROGRAI_SISTEMAUNIVERSIDAD_H