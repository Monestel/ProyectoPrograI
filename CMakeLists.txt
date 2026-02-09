cmake_minimum_required(VERSION 4.1)
project(ProyectoPrograI)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoPrograI main.cpp
        Persona.cpp
        Persona.h
        Estudiante.cpp
        Estudiante.h
        Profesor.cpp
        Profesor.h
        NodoEstudiante.h
        ListaEstudiantes.cpp
        ListaEstudiantes.h
        Curso.cpp
        Curso.h
        NodoCurso.h
        ListaCursos.cpp
        ListaCursos.h)
