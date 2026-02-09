
#ifndef PROYECTOPROGRAI_HORARIO_H
#define PROYECTOPROGRAI_HORARIO_H
#include "Curso.h"

class Horario {
private:
    Curso*** matriz;
    int dias, horas;

public:
    Horario(int dias, int horas);
    ~Horario();
    bool asignarCurso(int dia, int hora, Curso* curso);
    void mostrar();
};

#endif //PROYECTOPROGRAI_HORARIO_H