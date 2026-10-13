#include "Localidad.h"


Localidad::Localidad(){
    _idLocalidad = 0 ;
    strcpy(_nombreLocalidad, "");
    _valorPorPaquete = 0;
    _baseMinima = 0;
    _estado = false;
}
int Localidad::getIdZonaPadre(){
    return _idZonaPadre;
}
int Localidad::getIdLocalidad(){
    return _idLocalidad;
}
std::string Localidad::getNombreLocalidad(){
    return _nombreLocalidad;
}
float Localidad::getValorPorPaquete(){
    return _valorPorPaquete;
}
float Localidad::getBaseMinima(){
    return _baseMinima;
}
bool Localidad::getEstado(){
    return _estado;
}

void Localidad::setIdZonaPadre(int zonapadre){
    _idZonaPadre = zonapadre;
}
void Localidad::setIdLocalidada(int idlocalidad){
    _idLocalidad = idlocalidad;
}
void Localidad::setNombreLocalidada(std::string nombrelocalidad){
    strcpy(_nombreLocalidad, nombrelocalidad.c_str());
}
void Localidad::setValorPorPaquete(float valorpaquete){
    _valorPorPaquete = valorpaquete;
}
void Localidad::setBaseMinima(float baseminima){
    _baseMinima = baseminima;
}
void Localidad::setEstado(bool estado){
    _estado=estado;
}


void Localidad::mostrarId(){
            cout<<"----------------------------------------------"<<endl;
            cout<<"ID DE LA LOCALIDAD: "<<getIdLocalidad()<<endl;
            cout<<"ID DE ZONA PADRE: "<<getIdZonaPadre()<<endl;
            cout<<"NOMBRE DE LA LOCALIDAD: "<<getNombreLocalidad()<<endl;
            cout<<"VALOR DEL PAQUETE: "<<getValorPorPaquete()<<endl;
            cout<<"BASE MINIMA: "<<getBaseMinima()<<endl;

            if(getEstado()==true){
                cout<<"ESTADO -> ACTIVO"<<endl;
            }
            else{
                cout<<"ESTADO -> INACTIVO"<<endl;
            }
            cout<<"----------------------------------------------"<<endl;
}