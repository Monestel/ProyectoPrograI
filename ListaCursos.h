
#ifndef PROYECTOPROGRAI_LISTACURSOS_H
#define PROYECTOPROGRAI_LISTACURSOS_H
#include "NodoCurso.h"
#include "ListaProfesores.h"

class ListaCursos {
private:
    NodoCurso* head;

public:
    ListaCursos();
    ~ListaCursos();
    bool insertar(Curso* cur);
    Curso* buscar(string codigo);
    bool eliminar(string codigo);
    void mostrar();
    void guardarEnArchivo(string nombreArchivo);
    void cargarDesdeArchivo(string nombreArchivo, ListaProfesores& profesores);

};

#endif //PROYECTOPROGRAI_LISTACURSOS_H