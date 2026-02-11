
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
        ss << "5. Asignar un curso\n";
        ss << "6. Mostrar horario\n";
        ss << "0. Salir\n";
        ss << "Opcion: ";
        cout << ss.str();
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = -1;
        } else {
            cin.ignore();
        }

        if (opcion == 1) {
            string id, nombre;
            cout << "ID: ";
            getline(cin, id);
            cout << "Nombre: ";
            getline(cin, nombre);
            if (id.empty() || nombre.empty()) {
                cout << "Error: ID y nombre no pueden estar vacios.\n";
            }else if (!registrarProfesor(id, nombre))
                cout << "No se pudo registrar(ya existe).\n";
        }

        else if (opcion == 2) {
            string id, nombre;
            cout << "ID: ";
            getline(cin, id);
            cout << "Nombre: ";
            getline(cin, nombre);
            if (id.empty() || nombre.empty()) {
                cout << "Error: codigo, nombre y profesor no pueden estar vacios.\n";
            }else if (!registrarEstudiante(id, nombre))
                cout << "No se pudo registrar(ya existe).\n";
        }

        else if (opcion == 3) {
            string cod, nom, prof;
            cout << "Codigo: ";
            getline(cin, cod);
            cout << "Nombre: ";
            getline(cin, nom);
            cout << "ID Profesor: ";
            getline(cin, prof);
            if (cod.empty() || nom.empty() || prof.empty()) {
                cout << "Error: ID y nombre no pueden estar vacios.\n";
            }else if (!registrarCurso(cod, nom, prof))
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
            cout << "Dia (1 = Lunes, 2 = Martes, 3 = Miercoles, 4 = Jueves, 5 = Viernes): ";
            if (!(cin >> dia)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Eror: ingrese un numero.\n";
                continue;
            }
            cout << "Hora (1 = primer bloque, 2 = segundo bloque, 3 = tercer bloque, "
                    "4 = cuarto bloque, 5 = quinto bloque, 6 = sexto bloque): ";
            if (!(cin >> hora)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error, ingrese un numero";
            continue;
            }
            cin.ignore();
            dia--;
            hora--;

            if (!asignarCursoHorario(codigo, dia, hora))
                cout << "No se pudo asignar.\n";
        }

        else if (opcion == 6) {
            horario.mostrar();
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
