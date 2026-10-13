#include "VehiculoManager.h"


void VehiculoManager::cargarVehiculo(){
    Vehiculo reg;
    int idvehiculo, anio;
    std::string marca, modelo, patente, tipoDeVehiculo;
    float pesoMaximo;
    bool estado;

    cout<<"INGRESE LOS SIGUIENTES DATOS DEL VEHICULO"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"ID DE VEHICULO: ";
    cin>>idvehiculo;
    reg.setIdVehiculo(idvehiculo);
    cin.ignore();
    cout<<endl;
    cout<<"MARCA DEL VEHICULO: ";
    getline(cin,marca);
    reg.setMarca(marca);
    cout<<endl;
    cout<<"MODELO DEL VEHICULO: ";
    getline(cin, modelo);
    reg.setModelo(modelo);
    cout<<endl;
    cout<<"PATENTE DEL VEHICULO: ";
    getline(cin, patente);
    reg.setPatente(patente);
    cout<<endl;
    cout<<"TIPO DE VEHICULO: ";
    getline(cin, tipoDeVehiculo);
    reg.setTipoDeVehiculo(tipoDeVehiculo);
    cout<<endl;
    cout<<"ANIO DEL VEHICULO: ";
    cin>>anio;
    reg.setAnio(anio);
    cout<<endl;
    cout<<"PESO MAXIMO DE CARGA: ";
    cin>>pesoMaximo;
    reg.setPesoMaximo(pesoMaximo);
    cout<<endl;
    reg.setEstado(true);

    if(_archivo.cargarVehiculo(reg)){
        cout<<"VEHICULO CARGADO CON EXITO"<<endl;
    }
    else{
        cout<<"ERROR A CARGAR EL VEHICULO"<<endl;
    }
    cout<<"----------------------------------------------"<<endl;
}
void VehiculoManager::listarVehiculo(){
    Vehiculo reg;
    bool verficacion = false;
    int cantidad=_archivo.getCantidadVehiculos();

    cout<<"MOSTRANDO TODOS LOS VEHICULOS CARGADOS "<<endl;

    for(int i=0; i<cantidad; i++){
        reg = _archivo.leer(i);

        if(cantidad>0){
            verficacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DEL VEHICULO: "<<reg.getIdVehiculo()<<endl;
            cout<<"MARCA DEL VEHICULO: "<<reg.getMarca()<<endl;
            cout<<"MODELO DEL VEHICULO: "<<reg.getModelo()<<endl;
            cout<<"PATENTE DEL VEHICULO: "<<reg.getPatente()<<endl;
            cout<<"TIPO DE VEHICULO: "<<reg.getTipoDeVehiculo()<<endl;
            cout<<"ANIO DEL VEHICULO: "<<reg.getAnio()<<endl;
            cout<<"PESO MAXIMO DEL VEHICULO: "<<reg.getPesoMaximo()<<endl;

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
        cout<<"NO SE ENCONTRARON REPARTIDORES"<<endl;
    }

}
void VehiculoManager::buscarPorID(){
    Vehiculo reg;
    bool verficiacion;
    int cantidad = _archivo.getCantidadVehiculos();
    int id;

    cout<<"INGRESE LA ID DEL VEHICULO DESEA BUSCAR: ";
    cin>>id;
    cout<<endl;

    for(int i = 0; i<cantidad; i++){
        reg = _archivo.leer(i);

        if (id == reg.getIdVehiculo()){
            verficiacion=true;
            cout<<"ID ENCONTRADA"<<endl;
            reg.mostrarID();
            break;
        }
    }
    if(verficiacion == false){
        cout<<"ID NO ENCOTRADA"<<endl;
    }
}
void VehiculoManager::ListarVehiculoActivos(){
    Vehiculo reg;
    bool verficacion = false;
    int cantidad=_archivo.getCantidadVehiculos();

    cout<<"MOSTRANDO TODOS LOS VEHICULOS CARGADOS "<<endl;

    for(int i=0; i<cantidad; i++){
        reg = _archivo.leer(i);

        if(reg.getEstado()==true){
            verficacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DEL VEHICULO: "<<reg.getIdVehiculo()<<endl;
            cout<<"MARCA DEL VEHICULO: "<<reg.getMarca()<<endl;
            cout<<"MODELO DEL VEHICULO: "<<reg.getModelo()<<endl;
            cout<<"PATENTE DEL VEHICULO: "<<reg.getPatente()<<endl;
            cout<<"TIPO DE VEHICULO: "<<reg.getTipoDeVehiculo()<<endl;
            cout<<"ANIO DEL VEHICULO: "<<reg.getAnio()<<endl;
            cout<<"PESO MAXIMO DEL VEHICULO: "<<reg.getPesoMaximo()<<endl;
            cout<<"ESTADO -> ACTIVO"<<endl;
            cout<<endl;
            cout<<"----------------------------------------------"<<endl;
        }
    }
    if(verficacion == false){
        cout<<"NO SE ENCONTRARON REPARTIDORES"<<endl;
    }
}
void VehiculoManager::DarDeBajaoAlta(){
    Vehiculo reg;
    int id, opcion;
    int cantidad = _archivo.getCantidadVehiculos();
    bool verificacion = false;
    cout<<"INGRESE LA ID QUE DESEAS BUSCAR PARA DAR DE ALTA O BAJA: "<<endl;
    cin>>id; 
    for(int i = 0; i<cantidad; i++){
        reg =_archivo.leer(i);
        if(id == reg.getIdVehiculo()){
            verificacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<"ID ENCONTRADA"<<endl;
            reg.mostrarID();
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
                cout<<"VEHICULO ACTUALMENTE INACTIVO"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"PROCESANDO EL ALTA DEL VEHICULO"<<endl;
                cout<<"----------------------------------------------"<<endl;
                reg.setEstado(true);
                if(_archivo.modificarVehiculo(reg, i)){
                    cout<<"ALTA REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                else{
                    cout<<"ERROR AL DAR EL ALTA DEL VEHICULO"<<endl;
                }
            }
            else{
                cout<<"EL VEHICULO SE ENCUENTRA DADO DE ALTA"<<endl;
            }
            system("pause");
            break;
            system("cls");
            case 2: cout<<"VERIFICANDO ESTADO"<<endl;
            cout<<"----------------------------------------------"<<endl;
            if(reg.getEstado()==true){
                cout<<"VEHICULO ACTUALMENTE ACTIVO"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"PROCESANDO LA BAJA DEL VEHICULO"<<endl;
                cout<<"----------------------------------------------"<<endl;
                reg.setEstado(false);
                if(_archivo.modificarVehiculo(reg, i)){
                    cout<<"BAJA REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                else{
                    cout<<"ERROR AL DAR LA BAJA DEL VEHICULO"<<endl;
                }
            }
            else{
                cout<<"EL VEHICULO SE ENCUENTRA DADO DE BAJA"<<endl;
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
void VehiculoManager::ModificarVehiculo(){
    Vehiculo reg;
    int anio, id, opcion;
    std::string marca, modelo, patente, tipoDeVehiculo;
    float pesoMaximo;
    bool estado;
    int cantidad= _archivo.getCantidadVehiculos();
    bool verificacion=false;

    cout<<"INGRESE LA ID DEL VEHICULO QUE DESEA MODIFICAR: ";
    cin>>id;
    cout<<endl;
        for(int i = 0; i<cantidad; i++){
        reg =_archivo.leer(i);
        if(id == reg.getIdVehiculo()){
            verificacion=true;
            cout<<"ID ENCONTRADA"<<endl;
            cout<<"----------------------------------------------"<<endl;
            reg.mostrarID();
            do{
                cout<<endl;
                cout<<endl;
            cout<<"QUE DESEA MODIFICAR: "<<endl;
            cout<<"1. MODIFICAR MARCA"<<endl;
            cout<<"2. MODIFICAR MODELO"<<endl;
            cout<<"3. MODIFICAR PATENTE"<<endl;
            cout<<"4. MODIFICAR TIPO DE VEHICULO"<<endl;
            cout<<"5. MODIFICAR ANIO"<<endl;
            cout<<"6. MODIFICAR PESO MAXIMO"<<endl;
            cout<<"7. MODIFICAR TODO"<<endl;
            cout<<"0. SALIR"<<endl;
            cin>>opcion;
            switch(opcion){
                case 1:cout<<"INGRESE LA NUEVA MARCA: ";
                cin>>marca;
                reg.setMarca(marca);
                if(_archivo.modificarVehiculo(reg, i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 2: cout<<"INGRESE EL NUEVO MODELO: ";
                cin>>modelo;
                reg.setModelo(modelo);
                if(_archivo.modificarVehiculo(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 3: cout<<"INGRESE LA NUEVA PATENTE: ";
                cin>>patente;
                reg.setPatente(patente);
                if(_archivo.modificarVehiculo(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 4: cout<<"INGRESE EL TIPO DE VEHICULO:  ";
                cin>>tipoDeVehiculo;
                reg.setTipoDeVehiculo(tipoDeVehiculo);
                if(_archivo.modificarVehiculo(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 5: cout<<"INGRESE EL NUEVO ANIO: ";
                cin>>anio;
                reg.setAnio(anio);
                if(_archivo.modificarVehiculo(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 6: cout<<"INGRESE EL NUEVO PESO MAXIMO ";
                cin>>pesoMaximo;
                reg.setPesoMaximo(pesoMaximo);
                if(_archivo.modificarVehiculo(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 7: 
                cout<<"INGRESE TODOS LOS DATOS DE NUEVO "<<endl;
                cout<<"MARCA DEL VEHICULO: ";
                cin>>marca;
                reg.setMarca(marca);
                cout<<endl;
                cout<<"MODELO DEL VEHICULO: ";
                cin>>modelo;
                reg.setModelo(modelo);
                cin.ignore();
                cout<<endl;
                cout<<"PATENTE DEL VEHICULO: ";
                getline(cin, patente);
                reg.setPatente(patente);
                cout<<endl;
                cout<<"TIPO DE VEHICULO: ";
                getline(cin, tipoDeVehiculo);   
                reg.setTipoDeVehiculo(tipoDeVehiculo);
                cout<<endl;
                cout<<"ANIO DEL VEHICULO: ";
                cin>>anio;   
                reg.setAnio(anio);
                cout<<endl;
                cout<<"PESO MAXIMO DEL VEHICULO: ";
                cin>>pesoMaximo;
                reg.setPesoMaximo(pesoMaximo);
                cout<<endl;
                if(_archivo.modificarVehiculo(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 0:
                cout << "SALIENDO DEL MENU DE MODIFICACION..." << endl;
                break;
                default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
            }
            }while(opcion != 0);
            
        }
    }
    if(verificacion == false){
        cout<<"ID NO ENCONTRADA"<<endl;
    }


}