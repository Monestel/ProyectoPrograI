
#ifndef PROYECTOPROGRAI_LISTACURSOS_H
#define PROYECTOPROGRAI_LISTACURSOS_H
#include "NodoCurso.h"

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

};

#endif //PROYECTOPROGRAI_LISTACURSOS_H