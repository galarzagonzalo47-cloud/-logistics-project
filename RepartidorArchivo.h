#pragma once
#include "Repartidor.h"

class RepartidorArchivo{
    private:
    std::string _archivo;
    public:
    RepartidorArchivo();
    int getCantidadPersonas();
    bool cargar(Repartidor reg);
    Repartidor leer(int nroRegistro);
    bool modificar(Repartidor reg, int nroRegistro);
};