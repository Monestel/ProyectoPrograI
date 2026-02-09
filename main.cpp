#include <iostream>
#include "Estudiante.h"
#include "Profesor.h"
#include "ListaEstudiantes.h"
#include "Curso.h"

int main() {

    Estudiante e("E01", "David");
    Profesor p("P01", "Jonathan");

    cout << e.toString() << endl;
    cout << p.toString() << endl;

    ListaEstudiantes lista;

    lista.insertar(new Estudiante("E02", "Keilor"));
    lista.insertar(new Estudiante("E03", "Billy"));
    lista.mostrar();

    lista.eliminar("E01");
    lista.eliminar("E02");

    cout << "Despues de eliminar: " << endl;
    lista.mostrar();

    Profesor* prof = new Profesor("P02", "Oscar Benavides");
    Curso c("EIF200", "Fundamentos de Informatica", prof);

    cout << c.toString() << endl;

    return 0;
}