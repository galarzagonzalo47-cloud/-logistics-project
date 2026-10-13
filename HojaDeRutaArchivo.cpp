#include "HojaDeRutaArchivo.h"



HojaDeRutaArchivo::HojaDeRutaArchivo(){
    _archivo = "HojaDeRuta.dat";
}

int HojaDeRutaArchivo::getCantidadHoja(){
    FILE *p=fopen(_archivo.c_str(), "rb");

    if(p==NULL){
        cout<<"ERROR AL CONTAR LOS REGISTROS DE HOJAS DE RUTA"<<endl;
        return 0;
    }

    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(HojaDeRuta) ;
}

bool HojaDeRutaArchivo::cargarHoja(HojaDeRuta reg){
    FILE *p = fopen(_archivo.c_str(), "ab");
    if(p==NULL){
        cout<<"ERROR A CARGAR LA HOJA DE RUTA"<<endl;
        return false;
    }

    bool seGurado = fwrite(&reg, sizeof(HojaDeRuta), 1 ,p);
    fclose(p);

    return seGurado;
}

HojaDeRuta HojaDeRutaArchivo::leer(int nroRegistro){
    HojaDeRuta aux;
    FILE *p = fopen(_archivo.c_str(),"rb");

    if ( p==NULL ){
        cout<<"ERROR A LEER LAS HOJAS DE RUTA"<<endl;
        return aux;
    }

    fseek(p,nroRegistro * sizeof(HojaDeRuta),SEEK_SET);
    fread(&aux, sizeof(HojaDeRuta), 1, p);
    fclose(p);

    return aux;
}

bool HojaDeRutaArchivo::modificarHoja(HojaDeRuta reg, int nroRegistro){
    FILE *p = fopen (_archivo.c_str(), "rb+");

    if ( p == NULL){
        cout<<"ERROR AL MODIFICAR LA HOJA DE RUTA"<<endl;
        return false;
    }

    fseek(p, nroRegistro * sizeof(HojaDeRuta),SEEK_SET);
    bool seGurado = fwrite(&reg, sizeof(HojaDeRuta), 1 ,p);
    fclose(p);

    return seGurado;
}
