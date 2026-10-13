#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

class Vehiculo{
    private:
    int _idVehiculo, _anio;
    char _marca[50], _modelo[50],_patente[50],_tipoDeVehiculo[50];
    float _pesoMaximo;
    bool _estado; 
    public:
    Vehiculo();

    void mostrarID();

    int getIdVehiculo();
    int getAnio();
    std::string getMarca();
    std::string getModelo();
    std::string getPatente();
    std::string getTipoDeVehiculo();
    float getPesoMaximo();
    bool getEstado();

    void setIdVehiculo(int idvehiculo);
    void setAnio(int anio);
    void setMarca(std::string marca);
    void setModelo(std::string modelo);
    void setPatente(std::string patente);
    void setTipoDeVehiculo(std::string tipodevehiculo);
    void setPesoMaximo(float pesomaximo);
    void setEstado(bool estado);

};
