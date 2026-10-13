#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;


class Zonas{
    private:
    int _idZonas;
    char _nombreZona[40]; 
    bool  _estadoZonas;
    public:
    Zonas();

    void mostrarId();


    int getIdZonas();
    std::string getNombreZona();
    bool getEstadoZonas();


    void setIdZonas(int idzona);
    void setNombreZona(std::string nombrezona);;
    void setEstadoZonas(bool estadozona);



};

