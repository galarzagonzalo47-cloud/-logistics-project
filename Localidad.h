#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

class Localidad{
    private:
    int _idLocalidad, _idZonaPadre;
    char _nombreLocalidad[40];
    float _valorPorPaquete;
    float _baseMinima;
    bool _estado;

    public:
    Localidad();
    void mostrarId();
    int getIdZonaPadre();
    int getIdLocalidad();
    std::string getNombreLocalidad();
    float getValorPorPaquete();
    float getBaseMinima();
    bool getEstado();

    void setIdZonaPadre(int idzonpadre);
    void setIdLocalidada(int idlocalidad);
    void setNombreLocalidada(std::string nombrelocalidad);
    void setValorPorPaquete(float valorpaquete);
    void setBaseMinima(float baseminima);
    void setEstado(bool estado);

};

/*
Localidad
- idLocalidad
- nombreLocalidad
- idZona   // zona padre
- valorPorPaquete
- baseMinima
- estado
*/