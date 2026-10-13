#include "HojaDeRutaManager.h"

void HojaDeRutaManager::cargarHojaDeRuta(){
HojaDeRuta hoja;
Localidad loc;
Zonas zona;
Repartidor repa;
Vehiculo vec;
Fecha fechaI, FechaF, HoraI, HoraF;
bool verificarIDrepa = false, verificarIDvehi = false, verificarZona = false, verificarLocalidad = false;
int id, idRepartidor, idVehiculo, idZona, IdLocalidad;
    int cantidadR = _archivoRepartidor.getCantidadPersonas();
    int cantidadV = _archivoVehiculos.getCantidadVehiculos();
    int cantidadZ = _archivoZonas.getCantidadZonas();
    int cantidadL = _archivoLocalidad.getCantidadLocalidad();

cout<<"INGRESE EL ID DE RUTA: ";
cin>>id;
cout<<endl;
hoja.setIdHojaDeRuta(id);
cout<<"-----------------------------------------------"<<endl;
cout<<"ASIGNE UN REPARTIDOR A LA HOJA DE RUTA"<<endl;
cout<<"-----------------------------------------------"<<endl;
_managerRepartidor.ListarActivos();

cin>>idRepartidor;

for(int i=0; i<cantidadR;i++){
    repa=_archivoRepartidor.leer(i);
if(idRepartidor == repa.getIdPersona()){
verificarIDrepa=true;
hoja.setIdRepartidor(idRepartidor);
cout<<endl;
break;
}
}


if(verificarIDrepa == false){
    cout<<"NO HAY NINGUN REPARTIDOR CON ESA ID"<<endl;
    return ;
}


cout<<"INGRESE EL VEHICULO QUE UTILIZARA ESTE REPARTIDOR"<<endl;
cout<<"-----------------------------------------------"<<endl;
_managerVehiculos.ListarVehiculoActivos();
cin>>idVehiculo;

for(int v=0; v<cantidadV;v++){
vec=_archivoVehiculos.leer(v);
if(idVehiculo == vec.getIdVehiculo()){
verificarIDvehi =true;
hoja.setIdVehiculo(idVehiculo);
cout<<endl;
break;
}
}
if(verificarIDvehi == false){
    cout<<"NO HAY NINGUN VEHICULO CON ESA ID"<<endl;
    return ;
}
cout<<"INGRESE LA ZONA QUE DESEA HACER"<<endl;
cout<<"-----------------------------------------------"<<endl;
_managerZonas.ListarZonasActivos();
cin>>idZona;

for(int z=0; z<cantidadZ; z++){
    zona=_archivoZonas.leer(z);
if(idZona == zona.getIdZonas()){
    verificarZona=true;
    hoja.setIdZona(idZona);
    cout<<endl;
    break;
}

}
if(verificarZona==false){
    cout<<"NO HAT NINGUNA ZONA CON ESA ID"<<endl;
    return ;
}

cout<<"INGRESE LA LOCALIDAD DE LA ZONA ELEGIDA"<<endl;

int cantidadLa = _archivoLocalidad.getCantidadLocalidad();

for(int i =0; i <cantidadLa; i++){
    loc = _archivoLocalidad.leer(i);

    if(idZona==loc.getIdZonaPadre() && loc.getEstado() == true){
        verificarLocalidad=true;
        loc.mostrarId();
    }

}
cin>>IdLocalidad;
hoja.setIdLocalidad(IdLocalidad);


if(verificarLocalidad==false){
    cout<<"NO HAY LOCALIDADES CON ESA ID"<<endl;
    return;
}

cout<<"-----------------------------------------------"<<endl;
cout<<"CANTIDAD DE PAQUETES ASIGNADOS SEGUN RUTA "<<endl;

int paquetes;
cin>>paquetes;
hoja.setCantidadPaquetes(paquetes);
cout<<endl;
cout<<"CANTIDAD DE PESO TOTAL: ";
int peso;
cin>>peso;
hoja.setPesoTotal(peso);
cout<<endl;
cout<<"-----------------------------------------------"<<endl;
cout<<"FECHA DE INICIO"<<endl;
fechaI.cargarFecha();
hoja.setFechaInicio(fechaI);

cout<<"HORA DE INICIO"<<endl;
HoraI.cargarHora();
hoja.setHoraInicio(HoraI);


cout<<"-----------------------------------------------"<<endl;
cout<<"FECHA DE FINALIZACION"<<endl;
FechaF.cargarFecha();
hoja.setFechaFinalizacion(FechaF);


cout<<"HORA DE FINALIZACION"<<endl;;
HoraF.cargarHora();
hoja.setHoraFinalizacion(HoraF);


hoja.setEstado(true);
hoja.setFinalizada(false);

if(_archivo.cargarHoja(hoja)){
    cout<<"HOJA DE RUTA CARGADA CON EXITO"<<endl;
}
else{
    cout<<"NO SE PUDO CARGAR LA HOJA DE RUTA"<<endl;
}

}

void HojaDeRutaManager::listarHojaDeRuta(){
    HojaDeRuta hoja;
    Repartidor rep;
    Vehiculo vec;
    Zonas zon;
    Localidad loc;

    int cantidad = _archivo.getCantidadHoja();
    int cantidadR = _archivoRepartidor.getCantidadPersonas();
    int cantidadV = _archivoVehiculos.getCantidadVehiculos();
    int cantidadZ = _archivoZonas.getCantidadZonas();
    int cantidadL = _archivoLocalidad.getCantidadLocalidad();
    
    for(int i = 0; i < cantidad ; i++){

        hoja = _archivo.leer(i);

            cout<<"IDENTIFICADOR DE RUTA: "<<hoja.getIdHojaDeRuta()<<endl;
            for(int r = 0; r<cantidadR; r++){

                rep = _archivoRepartidor.leer(r);

                if(hoja.getIdRepartidor() == rep.getIdPersona()){
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<"DATOS DEL REPARTIDOR: "<<endl;
                    rep.mostrarPorId();
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<endl;
                    break;
                }
            }




            for(int v=0; v<cantidadV ; v++){
                vec = _archivoVehiculos.leer(v);
                if(hoja.getIdVehiculo()==vec.getIdVehiculo()){
                    cout<<endl; 
                    cout<<"DATOS DEL VEHICULO: "<<endl;
                    vec.mostrarID();                 
                    cout<<endl;
                    break;
                }
            }


            for(int z = 0; z<cantidadZ; z++){
                zon = _archivoZonas.leer(z);
                if(hoja.getIdZona()==zon.getIdZonas()){
                cout<<"DATOS DE LA ZONA";
                zon.mostrarId();
                cout<<endl;
                break;
                }
            }


            for(int l = 0; l<cantidadL; l++){
                loc = _archivoLocalidad.leer(l);
                if(hoja.getIdLocalidad()==loc.getIdLocalidad()){
                cout<<"LOCALIDAD";
                loc.mostrarId();
                cout<<endl;
                break;
            }
            }

            cout<<"CANTIDAD DE PAQUETES : "<<hoja.getCantidadPaquetes()<<endl;
            cout<<"PESO TOTAL: "<<hoja.getPesoTotal()<<endl;
            if(hoja.getPesoTotal() > vec.getPesoMaximo()){
                cout<<"*EL PESO PASO EL LIMITE DEL VEHICULO"<<endl;
                cout<<"SE QUITARAN 5 PAQUETES"<<endl;
                float pesoaux=vec.getPesoMaximo();
                float pesonuevo = pesoaux - 50;
                int paquetesaux = hoja.getCantidadPaquetes();
                int paquetesnuevo = paquetesaux - 5; 
                hoja.setPesoTotal(pesonuevo);
                hoja.setCantidadPaquetes(paquetesnuevo);
                cout<<endl;
                cout<<"CANTIDAD DE PAQUETES ACTUALIZADA: "<<hoja.getCantidadPaquetes()<<endl;
                cout<<"PESO TOTA ACTUALIZADO: "<<hoja.getPesoTotal()<<endl;


                if(hoja.getPesoTotal() > vec.getPesoMaximo()){
                cout<<"*EL PESO PASO EL LIMITE DEL VEHICULO"<<endl;
                cout<<"SE QUITARAN 5 PAQUETES"<<endl;
                float pesoaux=vec.getPesoMaximo();
                float pesonuevo = pesoaux - 50;
                int paquetesaux = hoja.getCantidadPaquetes();
                int paquetesnuevo = paquetesaux - 5; 
                hoja.setPesoTotal(pesonuevo);
                hoja.setCantidadPaquetes(paquetesnuevo);
                cout<<endl;
                cout<<"CANTIDAD DE PAQUETES ACTUALIZADA: "<<hoja.getCantidadPaquetes()<<endl;
                cout<<"PESO TOTA ACTUALIZADO: "<<hoja.getPesoTotal()<<endl;
                }   
            }
            

            cout<<"-----------------------------------------------"<<endl;
            cout<<"FECHA Y HORA DE INICIO: "<<endl;
            hoja.getFechaInicio().mostrarFecha();
            cout<<" - ";
            hoja.getHoraInicio().mostrarHora();
            cout<<endl;
            cout<<"-----------------------------------------------"<<endl;
            cout<<"FECHA Y HORA DE FINALIZACION: "<<endl;
            hoja.getFechaFinalizacion().mostrarFecha();
            cout<<" - ";
            hoja.getHoraFinalizacion().mostrarHora();
            cout<<endl;
            cout<<"-----------------------------------------------"<<endl;
            cout<<"INGRESO DEL DIA"<<endl;
            int valor = loc.getValorPorPaquete();
            int paquetes = hoja.getCantidadPaquetes();
            float ganancia = valor * paquetes;
            cout<<"$ "<<ganancia<<endl;
            hoja.setValorRuta(ganancia);
            cout<<"-----------------------------------------------"<<endl;
            cout<<"ESTADO DE RUTA FINALIZADO"<<endl;
            hoja.setFinalizada(true);
        }

    }

/*
NUMERO DE RUTA: 1001 - HECHO.
REPARTIDOR:
ID: 1
Nombre: Gonzalo Galarza
DNI: ...
Teléfono: ...

VEHÍCULO:
ID: 2
Patente: AB123CD
Marca: Renault
Modelo: Kangoo
Peso máximo: 650 kg

ZONA:
Zona Norte

LOCALIDAD:
Vicente López

PAQUETES:
Cantidad: 45
Peso total: 320 kg

FECHA Y HORA DE INICIO:
08/06/2026 - 13:30

FECHA Y HORA DE FINALIZACIÓN:
08/06/2026 - 19:45

INGRESO DEL DÍA:
$126.000

ESTADO DE RUTA:
FINALIZADA
*/



