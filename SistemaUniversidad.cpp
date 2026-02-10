
#include "SistemaUniversidad.h"
#include <iostream>
#include <sstream>

SistemaUniversidad::SistemaUniversidad()
    : horario(5,6) {
    estudiantes.cargarDesdeArchivo("estudiantes.txt");
    profesores.cargarDesdeArchivo("profesores.txt");
    cursos.cargarDesdeArchivo("cursos.txt", profesores);
    horario.cargarDesdeArchivo("horario.txt", cursos);
}

void SistemaUniversidad::mostrarSistema() {
    std:: cout << "\n--- Estudiantes ---\n";
    estudiantes.mostrar();

    std:: cout << "\n--- Profesores ---\n";
    profesores.mostrar();

    std:: cout << "\n--- Cursos ---\n";
    cursos.mostrar();

    std:: cout << "\n--- Horario ---\n";
    horario.mostrar();
}

bool SistemaUniversidad::registrarProfesor(string id, string nombre) {
    Profesor* prof = new Profesor(id, nombre);

    if (!profesores.insertar(prof)) {
        delete prof;
        return false;
    }
    return true;
}

bool SistemaUniversidad::registrarEstudiante(string id, string nombre) {
    Estudiante* est = new Estudiante(id, nombre);

    if (!estudiantes.insertar(est)) {
        delete est;
        return false;
    }
    return true;
}

bool SistemaUniversidad::registrarCurso(string codigo, string nombre, string idProfesor) {
    Profesor* prof = profesores.buscar(idProfesor);
    if (prof == nullptr)
        return false;

    Curso* curso = new Curso(codigo, nombre, prof);
    if (!cursos.insertar(curso)) {
        delete curso;
        return false;
    }
    return true;
}

void SistemaUniversidad::menuSistema() {
    int opcion;

    do {
        stringstream ss;
        ss << "\n--- Sistema Universidad ---\n";
        ss << "1. Registrar profesor\n";
        ss << "2. Registrar estudiante\n";
        ss << "3. Registrar curso\n";
        ss << "4. Mostrar todo\n";
        ss << "0. Salir\n";
        ss << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string id, nombre;
            cout << "ID: ";
            getline(cin, id);
            cout << "Nombre: ";
            getline(cin, nombre);

            if (!registrarProfesor(id, nombre))
                cout << "No se pudo registrar.\n";
        }

        else if (opcion == 2) {
            string id, nombre;
            cout << "ID: ";
            getline(cin, id);
            cout << "Nombre: ";
            getline(cin, nombre);

            if (!registrarEstudiante(id, nombre))
                cout << "No se pudo registrar.\n";
        }

        else if (opcion == 3) {
            string cod, nom, prof;
            cout << "Codigo: ";
            getline(cin, cod);
            cout << "Nombre: ";
            getline(cin, nom);
            cout << "ID Profesor: ";
            getline(cin, prof);

            if (!registrarCurso(cod, nom, prof))
                cout << "Curso invalido.\n";
        }

        else if (opcion == 4) {
            mostrarSistema();
        }

        else if (opcion == 5) {
            string codigo;
            int dia, hora;
            cout << "Codigo curso: ";
            getline(cin, codigo);
            cout << "Dia (0 = Lunes ...): ";
            cin >> dia;
            cout << "Hora (0 = primer bloque ...): ";
            cin >> hora;
            cin.ignore();

            if (!asignarCursoHorario(codigo, dia, hora))
                cout << "No se pudo asignar.\n";
        }

        else if (opcion == 0) {
            guardarDatos();
        }


    } while (opcion != 0);

}

bool SistemaUniversidad::asignarCursoHorario(string codigoCurso, int dia, int hora) {
    Curso* curso = cursos.buscar(codigoCurso);
    if (curso == nullptr)
        return false;

    return horario.asignarCurso(dia, hora, curso);
}

void SistemaUniversidad::guardarDatos() {
    estudiantes.guardarEnArchivo("estudiantes.txt");
    profesores.guardarEnArchivo("profesores.txt");
    cursos.guardarEnArchivo("cursos.txt");
    horario.guardarEnArchivo("horario.txt");
}
