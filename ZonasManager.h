#pragma once
#include "ZonasArchivo.h"


class ZonasManager{
    private:
    ZonasArchivo _archivo;
    public:
    void cargarZonas();
    void listarZonas();
    void buscarPorIDZona();
    void ModificarZonas();
    void DarDeBajaoAltaZonas();
    void ListarZonasActivos();
};