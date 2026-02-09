
#ifndef PROYECTOPROGRAI_LISTAESTUDIANTES_H
#define PROYECTOPROGRAI_LISTAESTUDIANTES_H
#include "NodoEstudiante.h"

class ListaEstudiantes {
private:
    NodoEstudiante* head;

public:
    ListaEstudiantes();
    ~ListaEstudiantes();
    bool insertar(Estudiante* estu);
    Estudiante* buscar(string id);
    bool eliminar(string id);
    void mostrar();

};

#endif //PROYECTOPROGRAI_LISTAESTUDIANTES_H