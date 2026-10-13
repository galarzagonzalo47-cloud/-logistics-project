#include "menu.h"
#include <cstdlib>

void Menu::mostarMenu(){
    int opcion;
    do{
        ::system("cls");
    cout<<"BINVENIDO AL MENU DE LOGISTICA."<<endl;
    cout<<"SELECIONE ALGUNA DE LAS SIGUEITNE OPCIONES"<<endl;
    cout<<"1. HOJA DE RUTA"<<endl;
    cout<<"2. MENU DE REPARTIDORES"<<endl;
    cout<<"3. MENU DE VEHICULOS"<<endl;
    cout<<"4. MENU DE ZONAS Y LOCALIDADES"<<endl;
  
    cout<<"0. SALIR"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1: menuHojaDeRuta();
        break;
        case 2: menuRepartidores();
        break;
        case 3: menuVehiculos();
        break;
        case 4: menuZonasYLocalidades();
        break;
        default:
        cout<<"OPCION EQUIVOCADA"<<endl;
        break;
    }
    }while (opcion !=0);
}

void Menu::menuRepartidores(){
    ::system("cls");
    int opcion;
    do{
        ::system("cls");
        cout<<"BIENVENIDO AL MENU DE REPARTIDORES"<<endl;
        cout<<"SELECCIONE ALGUNAS DE LAS SIGUIENTE OPCIONES"<<endl;
        cout<<"1. CARGAR REPARTIDORES"<<endl;
        cout<<"2. LISTAR TODOS REPARTIDORES"<<endl;
        cout<<"3. LISTAR SOLO REPARTIDORES ACTIVOS"<<endl;
        cout<<"4. BUSCAR REPARTIDOR POR ID"<<endl;
        cout<<"5. MODIFICAR REPARTIDOR"<<endl;
        cout<<"6. DAR DE ALTA O BAJA A REPARTIDOR"<<endl;
        cout<<"0. SALIR"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1: _archivoRepartidor.cargar();
        ::system("pause");
            break;
        case 2: _archivoRepartidor.listar();
        ::system("pause");
        break;
        case 3: _archivoRepartidor.ListarActivos();
        ::system("pause");
        break;
        case 4:_archivoRepartidor.buscarPorID();
        ::system("pause");
        break;
        case 5: _archivoRepartidor.Modificar();
        ::system("pause");
        break;
        case 6: _archivoRepartidor.DarDeBajaoAlta();
        ::system("pause");
        break;
        default:
            break;
        }
    }while(opcion != 0);

}
void Menu::menuVehiculos(){
    ::system("cls");
    int opcion;
    do{
        system("cls");
        cout<<"BIENVENIDO AL MENU DE VEHICULOS"<<endl;
        cout<<"SELECCIONE ALGUNAS DE LAS SIGUIENTE OPCIONES"<<endl;
        cout<<"1. CARGAR VEHICULOS"<<endl;
        cout<<"2. LISTAR TODOS VEHICULOS"<<endl;
        cout<<"3. LISTAR SOLO VEHICULOS ACTIVOS"<<endl;
        cout<<"4. BUSCAR VEHICULOS POR ID"<<endl;
        cout<<"5. MODIFICAR VEHICULOS"<<endl;
        cout<<"6. DAR DE ALTA O BAJA A VEHICULOS"<<endl;
        cout<<"0. SALIR"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1: _archivoVehiculo.cargarVehiculo();
        system("pause");
        break;
        case 2: _archivoVehiculo.listarVehiculo();
        system("pause");
        break;
        case 3: _archivoVehiculo.ListarVehiculoActivos();
        system("pause");
        break;
        case 4:_archivoVehiculo.buscarPorID();
        system("pause");
        break;
        case 5: _archivoVehiculo.ModificarVehiculo();
        system("pause");
        break;
        case 6: _archivoVehiculo.DarDeBajaoAlta();
        system("pause");
        break;
        default:
            break;
        }
    }while(opcion != 0);
}

void Menu::menuZonasYLocalidades(){
    ::system("cls");
    int opcion;
    do{
        system("cls");
        cout << "BIENVENIDO AL MENU DE ZONAS Y LOCALIDADES" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. CARGAR ZONA" << endl;
        cout << "2. LISTAR TODAS LAS ZONAS" << endl;
        cout << "3. LISTAR ZONAS ACTIVAS" << endl;
        cout << "4. BUSCAR ZONA POR ID" << endl;
        cout << "5. MODIFICAR ZONA" << endl;
        cout << "6. DAR DE ALTA O BAJA ZONA" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "7. CARGAR LOCALIDAD" << endl;
        cout << "8. LISTAR TODAS LAS LOCALIDADES" << endl;
        cout << "9. LISTAR LOCALIDADES ACTIVAS" << endl;
        cout << "10. BUSCAR LOCALIDAD POR ID" << endl;
        cout << "11. MODIFICAR LOCALIDAD" << endl;
        cout << "12. DAR DE ALTA O BAJA LOCALIDAD" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "13. LISTAR ZONAS CON SUS LOCALIDADES" << endl;
        cout << "0. SALIR" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1: _archivoZonas.cargarZonas();
        system("pause");
        break;
        case 2: _archivoZonas.listarZonas();
        system("pause");
        break;
        case 3: _archivoZonas.ListarZonasActivos();
        system("pause");
        break;
        case 4:_archivoZonas.buscarPorIDZona();
        system("pause");
        break;
        case 5: _archivoZonas.ModificarZonas();
        system("pause");
        break;
        case 6: _archivoZonas.DarDeBajaoAltaZonas();
        system("pause");
        break;
        case 7: _archivoLocalidad.cargarLocalidad();
        system("pause");
        break;
        case 8: _archivoLocalidad.listarLocalidad();
        system("pause");
        break;
        case 9: _archivoLocalidad.ListarLocalidadActivos();
        system("pause");
        break;
        case 10:_archivoLocalidad.buscarPorIDLocalidad();
        system("pause");
        break;
        case 11: _archivoLocalidad.ModificarLocalidad();
        system("pause");
        break;
        case 12: _archivoLocalidad.DarDeBajaoAltaLocalidad();
        system("pause");
        break;
        case 13: _archivoLocalidad.ListasZonasYLocalidades();
        system("pause");
        break;
        default:
            break;
        }
    }while(opcion != 0);
}

void Menu::menuHojaDeRuta(){
    ::system("cls");
    int opcion;
    do{
        system("cls");
        cout<<"BIENVENIDO A LA HOJA DE RUTA"<<endl;
        cout<<"SELECCIONE ALGUNAS DE LAS SIGUIENTE OPCIONES"<<endl;
        cout<<"1. CARGAR RUTA"<<endl;
        cout<<"2. LISTAR TODAS LAS RUTAS"<<endl;
        cout<<"0. SALIR"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1: _archivoHojaDeRuta.cargarHojaDeRuta();
        system("pause");
        break;
        case 2: _archivoHojaDeRuta.listarHojaDeRuta();
        system("pause");
        break;
        default:
            break;
        }
    }while(opcion != 0);

}