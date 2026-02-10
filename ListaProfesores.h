
#ifndef PROYECTOPROGRAI_LISTAPROFESORES_H
#define PROYECTOPROGRAI_LISTAPROFESORES_H
#include "NodoProfesor.h"

class ListaProfesores {
private:
    NodoProfesor* head;

public:
    ListaProfesores();
    ~ListaProfesores();
    bool insertar(Profesor* prof);
    Profesor* buscar(string id);
    bool eliminar(string id);
    void mostrar();
    void guardarEnArchivo(string nombreArchivo);
    void cargarDesdeArchivo(string nombreArchivo);
};

#endif //PROYECTOPROGRAI_LISTAPROFESORES_H