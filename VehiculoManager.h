#pragma once
#include "VehiculoArchivo.h"

class VehiculoManager{
    private:
    VehiculoArchivo _archivo;
    public:
    void cargarVehiculo();
    void listarVehiculo();
    void buscarPorID();
    void ModificarVehiculo();
    void DarDeBajaoAlta();
    void ListarVehiculoActivos();
};   