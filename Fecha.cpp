#include "Fecha.h"


Fecha::Fecha(){
    _dia=0;
    _mes=0;
    _anio=0;
    strcpy(_hora,"");
}

void Fecha::cargarFecha(){
    cout<<"INGRESE DIA: "; cin>>_dia; cout<<endl;
    cin.ignore();
    cout<<"INGRESE MES: "; cin>>_mes; cout<<endl;
    cin.ignore();
    cout<<"INGRESE ANIO: "; cin>>_anio; cout<<endl;
    cin.ignore();
}
void Fecha::mostrarFecha(){
    cout<<getDia()<<"/"<<getMes()<<"/"<<getAnio()<<"."<<endl;
}
void Fecha::cargarHora(){
    std::string hora;
    cout << "INGRESE HORA: ";
    cin >> hora;
    setHora(hora);
}
void Fecha::mostrarHora(){
    cout<<getHora()<<endl;
}
/*
 void cargarFecha();
    void mostrarFecha();
    void cargarHora();
    void mostrarHora();
*/
int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}
std::string Fecha::getHora(){
    return _hora;
} 

void Fecha::setDia(int dia){
    _dia=dia;
}
void Fecha::setMes(int mes){
    _mes=mes;
}
void Fecha::setAnio(int anio){
    _anio=anio;
}
void Fecha::setHora(std::string hora){
    strcpy(_hora, hora.c_str());
}
