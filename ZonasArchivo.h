#pragma once
#include "Zonas.h"

class ZonasArchivo{
    private:
    std::string _archivo;
    public:
    ZonasArchivo();
    int getCantidadZonas();
    bool cargarZona(Zonas reg);
    Zonas leer(int nroRegistro);
    bool modificar(Zonas reg, int nroRegistro);
};