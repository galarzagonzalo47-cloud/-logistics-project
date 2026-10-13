#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

class Repartidor{
    private:
    int _idPersona, _dni, _edad;
    char _nombre[50], _apellido[50], _telefono[50], _licencia[30];
    bool _estado;
    public:
    Repartidor();

    void mostrarPorId();
    int getIdPersona();
    int getDni();
    int getEdad();
    std::string getNombre();
    std::string getApellido();
    std::string getTelefono();
    std::string getLicencia();
    bool getEstado();

    void setIdPersona(int idPersona);
    void setDni(int dni);
    void setEdad(int edad);
    void setNombre(std::string nombre);
    void setApellido(std::string apelldio);
    void setTelefono(std::string telefono);
    void setLicencia(std::string licencia);
    void setEstado(bool estado);
};