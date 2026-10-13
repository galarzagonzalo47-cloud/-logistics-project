#pragma once
#include "HojaDeRutaArchivo.h"
#include "Fecha.h"
#include "LocalidadManager.h"
#include "ZonasManager.h"
#include "VehiculoManager.h"
#include "RepartidorManager.h"




class HojaDeRutaManager{
    private:
    HojaDeRutaArchivo _archivo;
    Fecha _archivoFecha;
    LocalidadManager managerLocalidad;
    LocalidadArchivo _archivoLocalidad;
    LocalidadManager _managerLocalidad;
    ZonasManager _managerZonas;
    ZonasArchivo _archivoZonas;
    VehiculoManager _managerVehiculos;
    VehiculoArchivo _archivoVehiculos;
    RepartidorManager _managerRepartidor;
    RepartidorArchivo _archivoRepartidor;

    public:
    void cargarHojaDeRuta();
    void listarHojaDeRuta();
    void buscarPorIDHojaDeRuta();
    void ModificarHojaDeRuta();
    void DarDeBajaoAltaHojaDeRuta();
    void ListarHojaDeRutaActivos();
};  