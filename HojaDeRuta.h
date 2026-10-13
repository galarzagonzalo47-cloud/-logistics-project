#pragma once
#include "LocalidadManager.h"
#include "RepartidorManager.h"
#include "VehiculoManager.h"
#include "ZonasManager.h"
#include "Fecha.h"

using namespace std;

class HojaDeRuta{
private:
    int _idHojaDeRuta;
    int _numeroRuta;

    int _idRepartidor;
    int _idVehiculo;

    int _idZona;
    int _idLocalidad;

    int _cantidadPaquetes;
    float _pesoTotal;
    float _valorRuta;

    Fecha _fechaInicio;
    Fecha _horaInicio;

    Fecha _fechaFinalizacion;
    Fecha _horaFinalizacion;


    bool _finalizada;
    bool _estado;

public:
    HojaDeRuta();

    void setIdHojaDeRuta(int id);
    void setNumeroRuta(int numero);

    void setIdRepartidor(int id);
    void setIdVehiculo(int id);

    void setIdZona(int id);
    void setIdLocalidad(int id);

    void setCantidadPaquetes(int cantidad);
    void setPesoTotal(float peso);
    void setValorRuta(float valor);

    void setFechaInicio(Fecha fecha);
    void setHoraInicio(Fecha hora);;

    void setFechaFinalizacion(Fecha fecha);
    void setHoraFinalizacion(Fecha hora);


    void setFinalizada(bool finalizada);
    void setEstado(bool estado);

    int getIdHojaDeRuta();
    int getNumeroRuta();

    int getIdRepartidor();
    int getIdVehiculo();

    int getIdZona();
    int getIdLocalidad();

    int getCantidadPaquetes();
    float getPesoTotal();
    float getValorRuta();

    Fecha getFechaInicio();
    Fecha getHoraInicio();


    Fecha getFechaFinalizacion();
    Fecha getHoraFinalizacion();
  

    bool getFinalizada();
    bool getEstado();
};

/*
idHojaDeRuta
numeroRuta

idRepartidor
idVehiculo

idZona
idLocalidad

cantidadPaquetes
pesoTotal
valorRuta

fechaInicio
horaInicio
minutoInicio

fechaFinalizacion
horaFinalizacion
minutoFinalizacion

finalizada
estado
*/