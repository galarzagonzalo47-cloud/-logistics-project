#include "HojaDeRuta.h"

HojaDeRuta::HojaDeRuta(){
    _idHojaDeRuta=0;
    _numeroRuta=0;
    _idRepartidor=0;
    _idVehiculo=0;
    _idZona=0;
    _idLocalidad=0;
    _cantidadPaquetes=0;
    _pesoTotal=0;
    _valorRuta=0;
    Fecha _fechaInicio;
    Fecha _fechaFinalizacion;
    Fecha _horaInicio;
    Fecha _horaFinalizacion;
    _finalizada = false;
    _estado = false;
}

    void HojaDeRuta::setIdHojaDeRuta(int id){
        _idHojaDeRuta=id;
    }
    void HojaDeRuta::setNumeroRuta(int numero){
        _numeroRuta = numero;
    }
    void HojaDeRuta::setIdRepartidor(int id){
        _idRepartidor=id;
    }
    void HojaDeRuta::setIdVehiculo(int id){
        _idVehiculo=id;
    }
    void HojaDeRuta::setIdZona(int id){
        _idZona=id;
    }
    void HojaDeRuta::setIdLocalidad(int id){
        _idLocalidad=id;
    }
    void HojaDeRuta::setCantidadPaquetes(int cantidad){
        _cantidadPaquetes=cantidad;
    }
    void HojaDeRuta::setPesoTotal(float peso){
        _pesoTotal=peso;
    }
    void HojaDeRuta::setValorRuta(float valor){
        _valorRuta=valor;
    }
    void HojaDeRuta::setFechaInicio(Fecha fecha){
        _fechaInicio = fecha;
    }
    void HojaDeRuta::setHoraInicio(Fecha hora){
        _horaInicio=hora;
    }
    void HojaDeRuta::setFechaFinalizacion(Fecha fecha){
        _fechaFinalizacion=fecha;
    }
    void HojaDeRuta::setHoraFinalizacion(Fecha hora){
        _horaFinalizacion=hora;
    }
    void HojaDeRuta::setFinalizada(bool finalizada){
        _finalizada=finalizada;
    }
    void HojaDeRuta::setEstado(bool estado){
        _estado=estado;
    }

    int HojaDeRuta::getIdHojaDeRuta(){
        return _idHojaDeRuta;
    }
    int HojaDeRuta::getNumeroRuta(){
        return _numeroRuta;
    }
    int HojaDeRuta::getIdRepartidor(){
        return _idRepartidor;
    }
    int HojaDeRuta::getIdVehiculo(){
        return _idVehiculo;
    }
    int HojaDeRuta::getIdZona(){
        return _idZona;
    }
    int HojaDeRuta::getIdLocalidad(){
        return _idLocalidad;
    }
    int HojaDeRuta::getCantidadPaquetes(){
        return _cantidadPaquetes;
    }
    float HojaDeRuta::getPesoTotal(){
        return _pesoTotal;
    }
    float HojaDeRuta::getValorRuta(){
        return _valorRuta;
    }
    Fecha HojaDeRuta::getFechaInicio(){
        return _fechaInicio;
    }
    Fecha HojaDeRuta::getHoraInicio(){
        return _horaInicio;
    }
    Fecha HojaDeRuta::getFechaFinalizacion(){
        return _fechaFinalizacion;
    }
    Fecha HojaDeRuta::getHoraFinalizacion(){
        return _horaFinalizacion;
    }
   
    bool HojaDeRuta::getFinalizada(){
        return _finalizada;
    }
    bool HojaDeRuta::getEstado(){
        return _estado;    }

/*

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
    void setHoraInicio(int hora);
    void setMinutoInicio(int minuto);

    void setFechaFinalizacion(Fecha fecha);
    void setHoraFinalizacion(int hora);
    void setMinutoFinalizacion(int minuto);

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
    int getHoraInicio();
    int getMinutoInicio();

    Fecha getFechaFinalizacion();
    int getHoraFinalizacion();
    int getMinutoFinalizacion();

    bool getFinalizada();
    bool getEstado();
};

*/