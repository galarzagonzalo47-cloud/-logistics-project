#include "VehiculoArchivo.h"
VehiculoArchivo::VehiculoArchivo(){
    _archivo="Vehiculos.dat";
}

int VehiculoArchivo::getCantidadVehiculos(){
    FILE *p = fopen(_archivo.c_str(), "rb");

    if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO PARA CONTAR"<<endl;
        return 0;
    }

    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes/ sizeof(Vehiculo);
}
bool VehiculoArchivo::cargarVehiculo(Vehiculo reg){
    FILE *p = fopen(_archivo.c_str(),"ab");
    
    if(p == NULL){
        cout<<"ERROR AL ABRIR EL ARHIVO PARA GUARDAR VEHICULOS"<<endl;
        return false;
    }
    bool seGuardo = fwrite(&reg, sizeof(Vehiculo), 1, p);
    fclose(p);

    return seGuardo;
}

Vehiculo VehiculoArchivo::leer(int nroRegistro){
    Vehiculo aux;
    FILE *p = fopen(_archivo.c_str(), "rb");

    if (p == NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO DE LECTURA VEHICULOS"<<endl;
        return aux;
    }

    fseek(p, nroRegistro * sizeof(Vehiculo), SEEK_SET);
    fread(&aux, sizeof(Vehiculo), 1, p);
    fclose(p);

    return aux;
}

bool VehiculoArchivo::modificarVehiculo(Vehiculo reg, int nroRegistro){
    FILE *p = fopen(_archivo.c_str(),"rb+");

    if(p == NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO DE MODIFICACION"<<endl;
        return false;
    }

    fseek(p, nroRegistro * sizeof(Vehiculo), SEEK_SET);
    bool seguardo = fwrite(&reg, sizeof(Vehiculo), 1, p);
    fclose(p);

    return seguardo;
}