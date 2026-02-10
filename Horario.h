
#ifndef PROYECTOPROGRAI_HORARIO_H
#define PROYECTOPROGRAI_HORARIO_H
#include "Curso.h"
#include "ListaCursos.h"

class Horario {
private:
    Curso*** matriz;
    int dias, horas;
    string* nombresDias;
    string* nombresHoras;

public:
    Horario(int dias, int horas);
    ~Horario();
    bool asignarCurso(int dia, int hora, Curso* curso);
    void mostrar();
    void guardarEnArchivo(string nombreArchivo);
    void cargarDesdeArchivo(string nombreArchivo, ListaCursos& cursos);
};

#endif //PROYECTOPROGRAI_HORARIO_H