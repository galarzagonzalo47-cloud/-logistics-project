#pragma once
#include "Localidad.h"

class  LocalidadArchivo{
    private:
    std::string _archivo;
    public:
    LocalidadArchivo();
    int getCantidadLocalidad();
    bool cargarLocalidad(Localidad reg);
    Localidad leer(int nroRegistro);
    bool modificar(Localidad reg, int nroRegistro);
};