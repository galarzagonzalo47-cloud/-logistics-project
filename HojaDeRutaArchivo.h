#pragma once
#include "HojaDeRuta.h"


class HojaDeRutaArchivo{
    private:
    std::string _archivo;
    public:
    HojaDeRutaArchivo();
    int getCantidadHoja();
    bool cargarHoja(HojaDeRuta reg);
    HojaDeRuta leer(int nroRegistro);
    bool modificarHoja(HojaDeRuta reg, int nroRegistro);
};


/*
    void cargarZonas();
    void listarZonas();
    void buscarPorIDZona();
    void ModificarZonas();
    void DarDeBajaoAltaZonas();
    void ListarZonasActivos();
*/