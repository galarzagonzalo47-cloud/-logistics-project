#include "LocalidadArchivo.h"

LocalidadArchivo::LocalidadArchivo(){
    _archivo="Localidad.dat";
}

int LocalidadArchivo::getCantidadLocalidad(){
    FILE *p = fopen(_archivo.c_str(),"rb");

    if( p == NULL){
        cout<<"ERROR AL CONTAR ZONAS"<<endl;
        return 0;
    }

    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Localidad);
}

bool LocalidadArchivo::cargarLocalidad(Localidad reg){
    FILE *p = fopen (_archivo.c_str(), "ab");


        if( p == NULL){
        cout<<"ERROR AL GUARDAR ZONAS"<<endl;
        return false;
    }

    bool seguardo = fwrite(&reg, sizeof(Localidad), 1 , p);
    fclose(p);

    return seguardo;
}

Localidad LocalidadArchivo::leer(int nroRegistro){
    Localidad aux;
    FILE *p = fopen ( _archivo.c_str(), "rb");

    if (p == NULL ){
        cout<<"ERROR AL LEER ZONAS"<<endl;
        return aux;
    }

    fseek(p,nroRegistro * sizeof(Localidad), SEEK_SET);
    fread(&aux, sizeof(Localidad), 1, p);
    fclose(p);

    return aux;

}

bool LocalidadArchivo::modificar(Localidad reg, int nroRegistro){
    FILE *p = fopen ( _archivo.c_str(),"rb+");

    if (p == NULL){
        cout<<"ERROR AL MODIFICAR LA ZONA"<<endl;
        return false;
    }

    fseek(p, nroRegistro * sizeof(Localidad), SEEK_SET);
    bool seguardo = fwrite(&reg, sizeof(Localidad), 1, p);
    fclose(p);
    return seguardo;

}
