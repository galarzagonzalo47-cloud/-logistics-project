#pragma once
#include "Vehiculo.h"

class VehiculoArchivo{
    private:
    std::string _archivo;
    public:
    VehiculoArchivo();
    int getCantidadVehiculos();
    bool cargarVehiculo(Vehiculo reg);
    Vehiculo leer(int nroRegistro);
    bool modificarVehiculo(Vehiculo reg, int nroRegistro);
};