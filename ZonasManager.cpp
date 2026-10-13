#include "ZonasManager.h"

void ZonasManager::cargarZonas(){
    Zonas reg;
    int idZona;
    std::string nombrezona; 
    bool estadozona;


    cout<<"INGRESE LOS SIGUIENTES DATOS DE LA ZONA A AGREGAR"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"ID DE ZONA: ";
    cin>>idZona;
    reg.setIdZonas(idZona);
    cin.ignore();
    cout<<endl;
    cout<<"NOMBRE DE LA ZONA: ";
    getline(cin,nombrezona);
    reg.setNombreZona(nombrezona);
    cout<<endl;
    reg.setEstadoZonas(true);
    if(_archivo.cargarZona(reg)){
        cout<<"ZONA CARGADA CON EXITO"<<endl;
    }
    else{
        cout<<"ERROR A CARGAR LA ZONA"<<endl;
    }
    cout<<"----------------------------------------------"<<endl;
}

void ZonasManager::listarZonas(){
    Zonas reg;
    bool verficacion = false;
    int cantidad=_archivo.getCantidadZonas();

    cout<<"MOSTRANDO TODAS LOS ZONAS CARGADOS "<<endl;

    for(int i=0; i<cantidad; i++){
        reg = _archivo.leer(i);

        if(cantidad>0){
            verficacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DE LA ZONA: "<<reg.getIdZonas()<<endl;
            cout<<"NOMBRE DE LA ZONA: "<<reg.getNombreZona()<<endl;
            if(reg.getEstadoZonas()==true){
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
        cout<<"NO SE ENCONTRARON ZONAS"<<endl;
    }

}

void ZonasManager::buscarPorIDZona(){
    Zonas reg;
    bool verficiacion;
    int cantidad = _archivo.getCantidadZonas();
    int id;

    cout<<"INGRESE LA ID DE ZONA QUE DESEAR BUSCAR: ";
    cin>>id;
    cout<<endl;

    for(int i = 0; i<cantidad; i++){
        reg = _archivo.leer(i);

        if (id == reg.getIdZonas()){
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

void ZonasManager::ListarZonasActivos(){
    Zonas reg;
    bool verficacion = false;
    int cantidad=_archivo.getCantidadZonas();

    cout<<"MOSTRANDO TODOS LOS ZONAS CARGADOS "<<endl;

    for(int i=0; i<cantidad; i++){
        reg = _archivo.leer(i);

        if(reg.getEstadoZonas()==true){
            verficacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DE LA ZONA: "<<reg.getIdZonas()<<endl;
            cout<<"NOMBRE DE LA ZONA: "<<reg.getNombreZona()<<endl;
            cout<<"ESTADO -> ACTIVO"<<endl;
            cout<<endl;
            cout<<"----------------------------------------------"<<endl;
        }
    }
    if(verficacion == false){
        cout<<"NO SE ENCONTRARON ZONAS"<<endl;
    }
}

void ZonasManager::DarDeBajaoAltaZonas(){
    Zonas reg;
    int id, opcion;
    int cantidad = _archivo.getCantidadZonas();
    bool verificacion = false;
    cout<<"INGRESE LA ID QUE DESEAS BUSCAR PARA DAR DE ALTA O BAJA: "<<endl;
    cin>>id; 
    for(int i = 0; i<cantidad; i++){
        reg =_archivo.leer(i);
        if(id == reg.getIdZonas()){
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
            if(reg.getEstadoZonas()==false){
                cout<<"ZONA ACTUALMENTE INACTIVA"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"PROCESANDO EL ALTA DE LA ZONA"<<endl;
                cout<<"----------------------------------------------"<<endl;
                reg.setEstadoZonas(true);
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
            if(reg.getEstadoZonas()==true){
                cout<<"ZONA ACTUALMENTE ACTIVA"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"PROCESANDO LA BAJA DE LA ZONA"<<endl;
                cout<<"----------------------------------------------"<<endl;
                reg.setEstadoZonas(false);
                if(_archivo.modificar(reg, i)){
                    cout<<"BAJA REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                else{
                    cout<<"ERROR AL DAR LA BAJA DE LA ZONA"<<endl;
                }
            }
            else{
                cout<<"LA ZONA SE ENCUENTRA DADA DE BAJA"<<endl;
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

void ZonasManager::ModificarZonas(){
    Zonas reg;
    int opcion, id;
    std::string nombre;
    int cantidad= _archivo.getCantidadZonas();
    bool verificacion=false;

    cout<<"INGRESE LA ID DEL VEHICULO QUE DESEA MODIFICAR: ";
    cin>>id;
    cout<<endl;
        for(int i = 0; i<cantidad; i++){
        reg =_archivo.leer(i);
        if(id == reg.getIdZonas()){
            verificacion=true;
            cout<<"ID ENCONTRADA"<<endl;
            cout<<"----------------------------------------------"<<endl;
            reg.mostrarId();
            do{
                cout<<endl;
                cout<<endl;
            cout<<"QUE DESEA MODIFICAR: "<<endl;
            cout<<"1. MODIFICAR NOMBRE"<<endl;
            cout<<"0. SALIR"<<endl;
            cin>>opcion;
            switch(opcion){
                case 1:cout<<"INGRESE LA NUEVA MARCA: ";
                cin>>nombre;
                reg.setNombreZona(nombre);
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
    



