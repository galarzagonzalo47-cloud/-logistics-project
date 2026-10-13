#pragma once 
#include "ZonasManager.h"
#include "LocalidadArchivo.h"

class LocalidadManager{
    private:
    ZonasArchivo _archivoZona;
    LocalidadArchivo _archivo;
    public:
    void cargarLocalidad();
    void listarLocalidad();
    void buscarPorIDLocalidad();
    void ModificarLocalidad();
    void DarDeBajaoAltaLocalidad();
    void ListarLocalidadActivos();
    void ListasZonasYLocalidades();
};