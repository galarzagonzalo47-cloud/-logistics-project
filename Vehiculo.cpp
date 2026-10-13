#include "Vehiculo.h"

Vehiculo::Vehiculo(){
    _idVehiculo = 0 ;
    _anio = 0 ;
    strcpy(_marca,"");
    strcpy(_modelo,"");
    strcpy(_patente,"");
    strcpy(_tipoDeVehiculo,"");
    _estado = 0 ;
    _pesoMaximo = 0 ;
}

    int Vehiculo::getIdVehiculo(){
        return _idVehiculo;
    }    
    int Vehiculo::getAnio(){
        return _anio;
    }
    std::string Vehiculo::getMarca(){
        return _marca;
    }
    std::string Vehiculo::getModelo(){
        return _modelo;
    }
    std::string Vehiculo::getPatente(){
        return _patente;
    }
    std::string Vehiculo::getTipoDeVehiculo(){
        return _tipoDeVehiculo;
    }
    float Vehiculo::getPesoMaximo(){
        return _pesoMaximo;
    }
    bool Vehiculo::getEstado(){
        return _estado;
    }

    void Vehiculo::setIdVehiculo(int idvehiculo){
        _idVehiculo=idvehiculo;
    }
    void Vehiculo::setAnio(int anio){
        _anio=anio;
    }
    void Vehiculo::setMarca(std::string marca){
        strcpy(_marca,marca.c_str());
    }
    void Vehiculo::setModelo(std::string modelo){
        strcpy(_modelo,modelo.c_str());
    }
    void Vehiculo::setPatente(std::string patente){
        strcpy(_patente,patente.c_str());
    }
    void Vehiculo::setTipoDeVehiculo(std::string tipodevehiculo){
        strcpy(_tipoDeVehiculo,tipodevehiculo.c_str());
    }
    void Vehiculo::setPesoMaximo(float pesomaximo){
        _pesoMaximo=pesomaximo;
    }
    void Vehiculo::setEstado(bool estado){
        _estado=estado;
    }


    void Vehiculo::mostrarID(){
         cout<<"----------------------------------------------"<<endl;
            cout<<endl;
            cout<<"ID DEL VEHICULO: "<<getIdVehiculo()<<endl;
            cout<<"MARCA DEL VEHICULO: "<<getMarca()<<endl;
            cout<<"MODELO DEL VEHICULO: "<<getModelo()<<endl;
            cout<<"PATENTE DEL VEHICULO: "<<getPatente()<<endl;
            cout<<"TIPO DE VEHICULO: "<<getTipoDeVehiculo()<<endl;
            cout<<"ANIO DEL VEHICULO: "<<getAnio()<<endl;
            cout<<"PESO MAXIMO DEL VEHICULO: "<<getPesoMaximo()<<endl;

            if(getEstado()==true){
                cout<<"ESTADO -> ACTIVO"<<endl;
            }
            else{
                cout<<"ESTADO -> INACTIVO"<<endl;
            }
            cout<<endl;
            cout<<"----------------------------------------------"<<endl;
    }




/*
class Vehiculo{
    private:
    int _idVehiculo, _anio;
    char _marca[50], _modelo[50],_patente[50],_tipoDeVehiculo[50];
    float _pesoMaximo;
    bool _estado; 
    public:
    Vehiculo();

    int getIdVehiculo();
    int getAnio();
    std::string getMarca();
    std::string getModelo();
    std::string getPatente();
    std::string getTipoDeVehiculo();
    float getPesoMaximo();
    bool getEstado();

    void setIdVehiculo(int idvehiculo);
    void setAnio(int anio);
    void setMarca(std::string marca);
    void setModelo(std::string modelo);
    void setPatente(std::string patente);
    void setTipoDeVehiculo(std::string tipodevehiculo);
    void setPesoMaximo(float pesomaximo);
    void setEstado(bool estado);

};

*/