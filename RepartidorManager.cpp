#include "RepartidorManager.h"

void RepartidorManager::cargar(){   
    Repartidor reg;
    int _idPersona, _dni, _edad;
    std::string _nombre, _apellido, _telefono, _licencia;
    bool _estado;

    cout<<"ID DEL REPARTIDOR: ";
    cin>>_idPersona;
    reg.setIdPersona(_idPersona);
    cout<<endl;
    cout<<"DNI DEL REPARTIDOR: ";
    cin>>_dni;
    reg.setDni(_dni);
    cout<<endl;
    cout<<"EDAD DEL REPARTIDOR: ";
    cin>>_edad;
    reg.setEdad(_edad);
    cin.ignore();
    cout<<endl;
    cout<<"NOMBRE DEL REPARTIDOR: ";
    getline(cin, _nombre);
    reg.setNombre(_nombre);
    cout<<endl;
    cout<<"APELLIDO DEL REPARTIDOR: ";
    getline(cin, _apellido);   
    reg.setApellido(_apellido);
    cout<<endl;
    cout<<"TELEFONO DEL REPARTIDOR: ";
    getline(cin, _telefono);   
    reg.setTelefono(_telefono);
    cout<<endl;
    cout<<"TIPO DE LICENCIA DEL REPARTIDOR: ";
    getline(cin, _licencia);
    reg.setLicencia(_licencia);
    cout<<endl;
    reg.setEstado(true);
    if(_archivo.cargar(reg)){
        cout<<"REPARTIDOR CARGADO CORRECTAMENTE"<<endl;
    }
    else{
        cout<<"ERROR A CARGAR AL REPARTIDOR"<<endl;
    }
}
void RepartidorManager::listar(){
    Repartidor reg;
    bool verificacion=false;
    int cantidad = _archivo.getCantidadPersonas();

    for(int i=0; i<cantidad; i++){
        reg = _archivo.leer(i);
        
            if(cantidad>0){
            verificacion=true;         
            cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DEL REPARTIDOR: "<<reg.getIdPersona()<<endl;
            cout<<"DNI DEL REPARTIDOR: "<<reg.getDni()<<endl;
            cout<<"EDAD DEL REPARTIDOR: "<<reg.getEdad()<<endl;
            cout<<"NOMBRE DEL REPARTIDOR: "<<reg.getNombre()<<endl;
            cout<<"APELLIDO DEL REPARTIDOR: "<<reg.getApellido()<<endl;
            cout<<"TELEFONO DEL REPARTIDOR: "<<reg.getTelefono()<<endl;
            cout<<"TIPO DE LICENCIA DEL REPARTIDOR: "<<reg.getLicencia()<<endl;
            if(reg.getEstado()){
            cout<<"ESTADO -> ACTIVO "<<endl;
            }
            else{
                cout<<"ESTADO -> INACTIVO "<<endl;
            }
            cout<<endl;
            cout<<"----------------------------------------------"<<endl;
            }
    }
    if(verificacion==false){
        cout<<"NO SE ENCONTRARON REPARTIDORES"<<endl;
    }
    
}
void RepartidorManager::ListarActivos(){
    Repartidor reg;
    bool verificacion=false;
    int cantidad = _archivo.getCantidadPersonas();

    for(int i=0; i<cantidad; i++){
        reg = _archivo.leer(i);  
        if(reg.getEstado()==true){
            verificacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DEL REPARTIDOR: "<<reg.getIdPersona()<<endl;
            cout<<"DNI DEL REPARTIDOR: "<<reg.getDni()<<endl;
            cout<<"EDAD DEL REPARTIDOR: "<<reg.getEdad()<<endl;
            cout<<"NOMBRE DEL REPARTIDOR: "<<reg.getNombre()<<endl;
            cout<<"APELLIDO DEL REPARTIDOR: "<<reg.getApellido()<<endl;
            cout<<"TELEFONO DEL REPARTIDOR: "<<reg.getTelefono()<<endl;
            cout<<"TIPO DE LICENCIA DEL REPARTIDOR: "<<reg.getLicencia()<<endl;
            cout<<"ESTADO -> ACTIVO "<<endl;
            cout<<endl;
            cout<<"----------------------------------------------"<<endl;
        }
    }
    if(verificacion=false){
        cout<<"NO SE ENCONTRARON REPARTIDORES ACTIVOS"<<endl;
    }
}
void RepartidorManager::buscarPorID(){
    Repartidor reg;
    int id;
    int cantidad = _archivo.getCantidadPersonas();
    bool verificacion = false;
    cout<<"INGRESE LA ID QUE DESEAS BUSCAR: "<<endl;
    cin>>id;
    

    for(int i = 0; i<cantidad; i++){
        reg =_archivo.leer(i);
        if(id == reg.getIdPersona()){
            verificacion=true;
            cout<<"ID ENCONTRADA"<<endl;
            reg.mostrarPorId();
            break;
        }
    }
    if(verificacion == false){
        cout<<"ID NO ENCONTRADA"<<endl;
    }
}
void RepartidorManager::DarDeBajaoAlta(){
    Repartidor reg;
    int id, opcion;
    int cantidad = _archivo.getCantidadPersonas();
    bool verificacion = false;
    cout<<"INGRESE LA ID QUE DESEAS BUSCAR PARA DAR DE ALTA O BAJA: "<<endl;
    cin>>id; 
    for(int i = 0; i<cantidad; i++){
        reg =_archivo.leer(i);
        if(id == reg.getIdPersona()){
            verificacion=true;
            cout<<"----------------------------------------------"<<endl;
            cout<<"ID ENCONTRADA"<<endl;
            reg.mostrarPorId();
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
                cout<<"REPARTIDOR ACTUALMENTE INACTIVO"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"PROCESANDO EL ALTA DEL REPARTIDOR"<<endl;
                cout<<"----------------------------------------------"<<endl;
                reg.setEstado(true);
                if(_archivo.modificar(reg, i)){
                    cout<<"ALTA REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                else{
                    cout<<"ERROR AL DAR EL ALTA DEL REPARTIDOR"<<endl;
                }
            }
            else{
                cout<<"EL REPARTIDOR SE ENCUENTRA DADO DE ALTA"<<endl;
            }
            system("pause");
            break;
            system("cls");
            case 2: cout<<"VERIFICANDO ESTADO"<<endl;
            cout<<"----------------------------------------------"<<endl;
            if(reg.getEstado()==true){
                cout<<"REPARTIDOR ACTUALMENTE ACTIVO"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"PROCESANDO LA BAJA DEL REAPRTIDOR"<<endl;
                cout<<"----------------------------------------------"<<endl;
                reg.setEstado(false);
                if(_archivo.modificar(reg, i)){
                    cout<<"BAJA REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                else{
                    cout<<"ERROR AL DAR LA BAJA DEL REPARTIDOR"<<endl;
                }
            }
            else{
                cout<<"EL REPARTIDOR SE ENCUENTRA DADO DE BAJA"<<endl;
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
void RepartidorManager::Modificar(){
    Repartidor reg;
    int id, opcion, dni, edad;
    std::string nombre,apellido,telefono,licencia;
    int cantidad= _archivo.getCantidadPersonas();
    bool verificacion=false;

    cout<<"INGRESE LA ID QUE DESEA MODIFICAR: ";
    cin>>id;
    cout<<endl;
        for(int i = 0; i<cantidad; i++){
        reg =_archivo.leer(i);
        if(id == reg.getIdPersona()){
            verificacion=true;
            cout<<"ID ENCONTRADA"<<endl;
            cout<<"----------------------------------------------"<<endl;
            reg.mostrarPorId();
            do{
                cout<<endl;
                cout<<endl;
            cout<<"QUE DESEA MODIFICAR: "<<endl;
            cout<<"1. MODIFICAR DNI"<<endl;
            cout<<"2. MODIFICAR EDAD"<<endl;
            cout<<"3. MODIFICAR NOMBRE"<<endl;
            cout<<"4. MODIFICAR APELLIDO"<<endl;
            cout<<"5. MODIFICAR TELEFONO"<<endl;
            cout<<"6. MODIFICAR TIPO DE LICENCIA"<<endl;
            cout<<"7. MODIFICAR TODO"<<endl;
            cout<<"0. SALIR"<<endl;
            cin>>opcion;
            switch(opcion){
                case 1:cout<<"INGRESE EL NUEVO DNI: ";
                cin>>dni;
                reg.setDni(dni);
                if(_archivo.modificar(reg, i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 2: cout<<"INGRESE LA NUEVA EDAD: ";
                cin>>edad;
                reg.setEdad(edad);
                if(_archivo.modificar(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 3: cout<<"INGRESE EL NUEVO NOMBRE: ";
                cin>>nombre;
                reg.setNombre(nombre);
                if(_archivo.modificar(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 4: cout<<"INGRESE EL NUEVO APELLIDO: ";
                cin>>apellido;
                reg.setApellido(apellido);
                if(_archivo.modificar(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 5: cout<<"INGRESE EL NUEVO TELEFONO: ";
                cin>>telefono;
                reg.setTelefono(telefono);
                if(_archivo.modificar(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 6: cout<<"INGRESE EL NUEVO TIPO DE LICENCIA: ";
                cin>>licencia;
                reg.setLicencia(licencia);
                if(_archivo.modificar(reg,i)){
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                }
                break;
                case 7: 
                cout<<"INGRESE TODOS LOS DATOS DE NUEVO "<<endl;
                cout<<"DNI DEL REPARTIDOR: ";
                cin>>dni;
                reg.setDni(dni);
                cout<<endl;
                cout<<"EDAD DEL REPARTIDOR: ";
                cin>>edad;
                reg.setEdad(edad);
                cin.ignore();
                cout<<endl;
                cout<<"NOMBRE DEL REPARTIDOR: ";
                getline(cin, nombre);
                reg.setNombre(nombre);
                cout<<endl;
                cout<<"APELLIDO DEL REPARTIDOR: ";
                getline(cin, apellido);   
                reg.setApellido(apellido);
                cout<<endl;
                cout<<"TELEFONO DEL REPARTIDOR: ";
                getline(cin, telefono);   
                reg.setTelefono(telefono);
                cout<<endl;
                cout<<"TIPO DE LICENCIA DEL REPARTIDOR: ";
                getline(cin, licencia);
                reg.setLicencia(licencia);
                cout<<endl;
                if(_archivo.modificar(reg,i)){
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