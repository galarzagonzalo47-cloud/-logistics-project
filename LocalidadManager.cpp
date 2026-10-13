#include <iostream>
#include <string>
#include "LocalidadManager.h"

using namespace std;

void LocalidadManager::cargarLocalidad(){
    Localidad reg;
    Zonas zona;
    int idlocalidad, idZonaPadre;
    std::string nombrelocalidad; 
    bool estadolocalidad;
    bool zonaEncontrada;
    float valorPorPaquete, baseMinima;

    cout<<"INGRESE LOS SIGUIENTES DATOS DE LA ZONA A AGREGAR"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"ID DE LA LOCALIDAD: ";
    cin>>idlocalidad;
    reg.setIdLocalidada(idlocalidad);
    cout<<endl;
    cout<<"INRESE LA ID DE LA ZONA PADRE: ";
    
    cin>>idZonaPadre;
    reg.setIdZonaPadre(idZonaPadre);
    
    zonaEncontrada = false;
    int cantidadZonas = _archivoZona.getCantidadZonas();

    for(int i = 0; i < cantidadZonas; i++){
        zona = _archivoZona.leer(i);

        if(zona.getIdZonas() == idZonaPadre && zona.getEstadoZonas() == true){
            zona.mostrarId();
            zonaEncontrada = true;
            break;
        }
    }

    if(zonaEncontrada == false){
        cout << "LA ZONA NO EXISTE O ESTA INACTIVA" << endl;
        return;
    }
    cout<<"----------------------------------------------"<<endl;
    cout<<"NOMBRE DE LA LOCALIDAD: ";
    cin.ignore();
    getline(cin,nombrelocalidad);
    reg.setNombreLocalidada(nombrelocalidad);
    cout<<endl;
    cout<<"VALOR DEL PAQUETE: ";
    cin>>valorPorPaquete;
    reg.setValorPorPaquete(valorPorPaquete);
    cout<<endl;
    cout<<"BASE MINIMA DE LA LOCALIDAD: ";
    cin>>baseMinima;
    reg.setBaseMinima(baseMinima);
    cout<<endl;
    reg.setEstado(true);
    if(_archivo.cargarLocalidad(reg)){
        cout<<"LOCALIDAD CARGADA CON EXITO"<<endl;
    }
    else{
        cout<<"ERROR A CARGAR LA LOCALIDAD"<<endl;
    }
    cout<<"----------------------------------------------"<<endl;
}

void LocalidadManager::listarLocalidad(){

    Localidad reg;
    bool verficacion = false;
    int cantidad=_archivo.getCantidadLocalidad();

    cout<<"MOSTRANDO TODAS LaS LOCALIDADES CARGADAS "<<endl;

    for(int i=0; i<cantidad; i++){
        reg = _archivo.leer(i);

        if(cantidad>0){
            verficacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DE LA LOCALIDAD: "<<reg.getIdLocalidad()<<endl;
            cout<<"ID DE ZONA PADRE: "<<reg.getIdZonaPadre()<<endl;
            cout<<"NOMBRE DE LA LOCALIDAD: "<<reg.getNombreLocalidad()<<endl;
            cout<<"VALOR DEL PAQUETE: "<<reg.getValorPorPaquete()<<endl;
            cout<<"BASE MINIMA: "<<reg.getBaseMinima()<<endl;

            if(reg.getEstado()==true){
                cout<<"ESTADO -> ACTIVO"<<endl;
            }
            else{
                cout<<"ESTADO -> INACTIVO"<<endl;
            }
            cout<<endl;
            cout<<"----------------------------------------------"<<endl;
        }
      
    }
    if(verficacion == false){
        cout<<"NO SE ENCONTRARON LOCALIDADES"<<endl;
    }

}

void LocalidadManager::buscarPorIDLocalidad(){

    Localidad reg;
    bool verficiacion;
    int cantidad = _archivo.getCantidadLocalidad();
    int id;

    cout<<"INGRESE LA ID DE LOCALIDAD QUE DESEAR BUSCAR: ";
    cin>>id;
    cout<<endl;

    for(int i = 0; i<cantidad; i++){
        reg = _archivo.leer(i);

        if (id == reg.getIdLocalidad()){
            verficiacion=true;
            cout<<"ID ENCONTRADA"<<endl;
            reg.mostrarId();
            break;
        }   
    }
    if(verficiacion == false){
        cout<<"ID NO ENCOTRADA"<<endl;
    }
}

void LocalidadManager::ListarLocalidadActivos(){
    Localidad reg;
    bool verficacion = false;
    int cantidad=_archivo.getCantidadLocalidad();

    cout<<"MOSTRANDO TODOS LOS ZONAS CARGADOS "<<endl;

    for(int i=0; i<cantidad; i++){
        reg = _archivo.leer(i);

        if(reg.getEstado()==true){
            verficacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DE LA LOCALIDAD: "<<reg.getIdLocalidad()<<endl;
            cout<<"NOMBRE DE LA LOCALIDAD: "<<reg.getNombreLocalidad()<<endl;
            cout<<"VALOR DEL PAQUETE: "<<reg.getValorPorPaquete()<<endl;
            cout<<"BASE MINIMA: "<<reg.getBaseMinima()<<endl;
            cout<<endl;
            cout<<"----------------------------------------------"<<endl;
        }
    }
    if(verficacion == false){
        cout<<"NO SE ENCONTRARON LOCALIDADES"<<endl;
    }
}

void LocalidadManager::DarDeBajaoAltaLocalidad(){
    Localidad reg;
    int id, opcion;
    int cantidad = _archivo.getCantidadLocalidad();
    bool verificacion = false;
    cout<<"INGRESE LA ID QUE DESEAS BUSCAR PARA DAR DE ALTA O BAJA: "<<endl;
    cin>>id; 
    for(int i = 0; i<cantidad; i++){
        reg =_archivo.leer(i);
        if(id == reg.getIdLocalidad()){
            verificacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<"ID ENCONTRADA"<<endl;
            reg.mostrarId();
            cout<<"----------------------------------------------"<<endl;
            do{
            cout<<"ELEGI LA OPCION DESEADA"<<endl;
            cout<<"1. DAR DE ALTA "<<endl;
            cout<<"2. DAR DE BAJA "<<endl;
            cout<<"0. SALIR"<<endl;
            cin>>opcion;
            switch (opcion)
            {
            system("cls");
            case 1: cout<<"VERIFICANDO ESTADO"<<endl;
            cout<<"----------------------------------------------"<<endl;
            if(reg.getEstado()==false){
                cout<<"LOCALIDAD ACTUALMENTE INACTIVA"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"PROCESANDO EL ALTA DE LA LOCALIDAD"<<endl;
                cout<<"----------------------------------------------"<<endl;
                reg.setEstado(true);
                if(_archivo.modificar(reg, i)){
                    cout<<"ALTA REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                else{
                    cout<<"ERROR AL DAR EL ALTA LA ZONA"<<endl;
                }
            }
            else{
                cout<<"LA ZONA SE ENCUENTRA DADA DE ALTA"<<endl;
            }
            system("pause");
            break;
            system("cls");
            case 2: cout<<"VERIFICANDO ESTADO"<<endl;
            cout<<"----------------------------------------------"<<endl;
            if(reg.getEstado()==true){
                cout<<"LOCALIDAD ACTUALMENTE ACTIVA"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"PROCESANDO LA BAJA DE LA LOCALIDAD"<<endl;
                cout<<"----------------------------------------------"<<endl;
                reg.setEstado(false);
                if(_archivo.modificar(reg, i)){
                    cout<<"BAJA REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                else{
                    cout<<"ERROR AL DAR LA BAJA DE LA LOCALIDAD"<<endl;
                }
            }
            else{
                cout<<"LA LOCALIDAD SE ENCUENTRA DADA DE BAJA"<<endl;
            }
            system("pause");
            break;             
            default:
                break;
            }
            }while(opcion != 0);          
        }
    }
    if(verificacion == false){
        cout<<"ID NO ENCONTRADA"<<endl;
    }

}

void LocalidadManager::ModificarLocalidad(){
    Localidad reg;
    int opcion, id, idzonapadre;
    float valor, base;
    std::string nombre;
    int cantidad= _archivo.getCantidadLocalidad();
    bool verificacion=false;

    cout<<"INGRESE LA ID DEL VEHICULO QUE DESEA MODIFICAR: ";
    cin>>id;
    cout<<endl;
        for(int i = 0; i<cantidad; i++){
        reg =_archivo.leer(i);
        if(id == reg.getIdLocalidad()){
            verificacion=true;
            cout<<"ID ENCONTRADA"<<endl;
            cout<<"----------------------------------------------"<<endl;
            reg.mostrarId();
            do{
                cout<<endl;
                cout<<endl;
            cout<<"QUE DESEA MODIFICAR: "<<endl;
            cout<<"1. MODIFICAR NOMBRE"<<endl;
            cout<<"2. MODIFICAR VALOR DE PAQUETE"<<endl;
            cout<<"3. MODIFICAR BASE MINIMA"<<endl;
            cout<<"4. MODIFICAR ID ZONA PADRE"<<endl;
            cout<<"0. SALIR"<<endl;
            cin>>opcion;
            switch(opcion){
                case 1:cout<<"INGRESE EL NUEVO NOMBRE: ";
                cin>>nombre;
                reg.setNombreLocalidada(nombre);
                if(_archivo.modificar(reg, i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 2:cout<<"INGRESE EL NUEVO VALOR DE PAQUETE: ";
                cin>>valor;
                reg.setValorPorPaquete(valor);
                if(_archivo.modificar(reg, i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 3:cout<<"INGRESE LA NUEVA BASE MINIMA: ";
                cin>>base;
                reg.setBaseMinima(base);
                if(_archivo.modificar(reg, i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 4: cout<<"INGRESE EL NUEVO ID DE ZONA PADRE"<<endl;
                cin>>idzonapadre;
                reg.setIdZonaPadre(idzonapadre);
                if(_archivo.modificar(reg, i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                default:
                break;
                }
                }while (opcion != 0);
            }
        }           
    if(verificacion == false){
        cout<<"ID NO ENCONTRADA"<<endl;
    }
    }
    
void LocalidadManager::ListasZonasYLocalidades(){
    Zonas zona;
    Localidad loc;
    bool tieneLocalidades = false;

    int cantidadZonas = _archivoZona.getCantidadZonas();
    int cantidadLocalidades = _archivo.getCantidadLocalidad();

    for(int i = 0; i < cantidadZonas; i++){
        zona = _archivoZona.leer(i);

        if(zona.getEstadoZonas() == true){

            cout << "======================================" << endl;
            cout << "ZONA: " << zona.getNombreZona() << endl;
            cout << "ID ZONA: " << zona.getIdZonas() << endl;
            cout << "======================================" << endl;

            for(int j = 0; j < cantidadLocalidades; j++){
                loc = _archivo.leer(j);

                if(loc.getIdZonaPadre() == zona.getIdZonas()){

                    tieneLocalidades = true;

                    cout << "  ID LOCALIDAD: " << loc.getIdLocalidad() << endl;
                    cout << "  LOCALIDAD: " << loc.getNombreLocalidad() << endl;
                    cout << "  VALOR PAQUETE: $" << loc.getValorPorPaquete() << endl;
                    cout << "  BASE MINIMA: $" << loc.getBaseMinima() << endl;
                    cout << "  --------------------------------" << endl;
                }
            }

            if(tieneLocalidades == false){
                cout << "  NO HAY LOCALIDADES ACTIVAS PARA ESTA ZONA" << endl;
            }

            cout << endl;
        }
    }
}


/*
    int _idLocalidad;
    char _nombreLocalidad[40];
    float _valorPorPaquete;
    float _baseMinima;
    bool _estado;

*/
