
#ifndef PROYECTOPROGRAI_CURSO_H
#define PROYECTOPROGRAI_CURSO_H
#include "Profesor.h"

class Curso {
private:
    string codigo, nombre;
    Profesor* profesor;

public:
    Curso(string codigo, string nombre, Profesor* profesor);
    string getCodigo();
    string getNombre();
    Profesor* getProfesor();
    string toString();
    string getProfesorId();

};

#endif //PROYECTOPROGRAI_CURSO_H