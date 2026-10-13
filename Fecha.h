#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Fecha{
    private:
    int _dia;
    int _mes;
    int _anio;
    char _hora[20];
    public:
    Fecha();
    void cargarFecha();
    void mostrarFecha();
    void cargarHora();
    void mostrarHora();

    int getDia();
    int getMes();
    int getAnio();
    std::string getHora();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void setHora(std::string hora);
};