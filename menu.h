#pragma once
#include <cstdlib>
#include "RepartidorManager.h"
#include "VehiculoManager.h"
#include "ZonasManager.h"
#include "LocalidadManager.h"
#include "HojaDeRutaManager.h"


class Menu{
    private:
    RepartidorManager _archivoRepartidor;
    VehiculoManager _archivoVehiculo;
    LocalidadManager _archivoLocalidad;
    ZonasManager _archivoZonas;
    HojaDeRutaManager _archivoHojaDeRuta;

    public:
    void mostarMenu();
    void menuRepartidores();
    void menuVehiculos();
    void menuZonasYLocalidades();
    void menuHojaDeRuta();
};