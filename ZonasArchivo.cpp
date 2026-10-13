#include "ZonasArchivo.h"


ZonasArchivo::ZonasArchivo(){
    _archivo="zonas.dat";
}

int ZonasArchivo::getCantidadZonas(){
    FILE *p = fopen(_archivo.c_str(),"rb");

    if( p == NULL){
        cout<<"ERROR AL CONTAR ZONAS"<<endl;
        return 0;
    }

    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Zonas);
}

bool ZonasArchivo::cargarZona(Zonas reg){
    FILE *p = fopen (_archivo.c_str(), "ab");


        if( p == NULL){
        cout<<"ERROR AL GUARDAR ZONAS"<<endl;
        return false;
    }

    bool seguardo = fwrite(&reg, sizeof(Zonas), 1 , p);
    fclose(p);

    return seguardo;
}

Zonas ZonasArchivo::leer(int nroRegistro){
    Zonas aux;
    FILE *p = fopen ( _archivo.c_str(), "rb");

    if (p == NULL ){
        cout<<"ERROR AL LEER ZONAS"<<endl;
        return aux;
    }

    fseek(p,nroRegistro * sizeof(Zonas), SEEK_SET);
    fread(&aux, sizeof(Zonas), 1, p);
    fclose(p);

    return aux;

}

bool ZonasArchivo::modificar(Zonas reg, int nroRegistro){
    FILE *p = fopen ( _archivo.c_str(),"rb+");

    if (p == NULL){
        cout<<"ERROR AL MODIFICAR LA ZONA"<<endl;
        return false;
    }


    fseek(p, nroRegistro * sizeof(Zonas), SEEK_SET);
    bool seguardo = fwrite(&reg, sizeof(Zonas), 1, p);
    fclose(p);

    return seguardo;

}

/*
    public:
    ZonasArchivo();
    int getCantidadZonas();
    bool cargarZona(Zonas reg);
    Zonas leer(int nroRegistro);
    bool modificarZona(Zonas reg, int nroRegistro);
*/