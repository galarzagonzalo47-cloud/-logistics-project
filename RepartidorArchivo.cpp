#include "RepartidorArchivo.h"


RepartidorArchivo::RepartidorArchivo(){
    _archivo="Repartidor.dat";
}
int RepartidorArchivo::getCantidadPersonas(){
    FILE *p = fopen(_archivo.c_str(), "rb");

    if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO PARA CONTAR"<<endl;
        return 0;
    }

    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes/ sizeof(Repartidor);
}
bool RepartidorArchivo::cargar(Repartidor reg){
    FILE *p=fopen(_archivo.c_str(),"ab");

    if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO PARA GUARDAR"<<endl;
        return false;
    }

    bool seGurado=fwrite(&reg, sizeof(Repartidor), 1, p);
    fclose(p);

    return seGurado;

}
Repartidor RepartidorArchivo::leer(int nroRegistro){
    Repartidor aux;
    FILE *p=fopen(_archivo.c_str(),"rb");

    if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO PARA LEER"<<endl;
        return aux;
    }

    fseek(p, nroRegistro * sizeof(Repartidor), SEEK_SET);
    fread(&aux, sizeof(Repartidor), 1 ,p);
    fclose(p);
    
    return aux;
}
bool RepartidorArchivo::modificar(Repartidor reg, int nroRegistro){
    FILE *p = fopen(_archivo.c_str(),"rb+");
    if(p == NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO PARA MODIFICAR"<<endl;
        return false;
    }
    fseek(p, nroRegistro*sizeof(Repartidor),SEEK_SET);
    bool seguardo=fwrite(&reg, sizeof(Repartidor),1, p);
    fclose(p);
    return seguardo;
}