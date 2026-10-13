#include "Zonas.h"


Zonas::Zonas(){
    _idZonas=0;
    strcpy(_nombreZona,"");
    _estadoZonas = false;
}
int Zonas::getIdZonas(){
    return _idZonas;
}

std::string Zonas::getNombreZona(){
    return _nombreZona;
}

bool Zonas::getEstadoZonas(){
    return _estadoZonas;
}

void Zonas::setIdZonas(int idzonas){
    _idZonas = idzonas;
}
void Zonas::setNombreZona(std::string nombrezona){
    strcpy(_nombreZona, nombrezona.c_str());
}

void Zonas::setEstadoZonas(bool estadozonas){
    _estadoZonas = estadozonas;
}



void Zonas::mostrarId(){
         cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DE LA ZONA: "<<getIdZonas()<<endl;
            cout<<"NOMBRE DE LA ZONA: "<<getNombreZona()<<endl;
        
            if(getEstadoZonas()==true){
                cout<<"ESTADO -> ACTIVO"<<endl;
            }
            else{
                cout<<"ESTADO -> INACTIVO"<<endl;
            }
            cout<<endl;
            cout<<"----------------------------------------------"<<endl;
   
}