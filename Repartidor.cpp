#include "Repartidor.h"


Repartidor::Repartidor(){
    _idPersona = 0;
    _dni = 0;
    _edad = 0;
    strcpy(_nombre,"");
    strcpy(_apellido,"");
    strcpy(_telefono,"");
    strcpy(_licencia,"");
    _estado = false;
};
int Repartidor::getIdPersona(){
    return _idPersona;
}
int Repartidor::getDni(){
    return _dni;
}
int Repartidor::getEdad(){
    return _edad;
}
std::string Repartidor::getNombre(){
    return _nombre;
}
std::string Repartidor::getApellido(){
    return _apellido;
}
std::string Repartidor::getTelefono(){
    return _telefono;
}
std::string Repartidor::getLicencia(){
    return _licencia;
}
bool Repartidor::getEstado(){
    return _estado;
}

void Repartidor::setIdPersona(int idpersona){
    _idPersona=idpersona;
}
void Repartidor::setDni(int dni){
    _dni=dni;
}
void Repartidor::setEdad(int edad){
    _edad=edad;
}
void Repartidor::setNombre(std::string nombre){
    strcpy(_nombre,nombre.c_str());
}
void Repartidor::setApellido(std::string apellido){
    strcpy(_apellido,apellido.c_str());
}
void Repartidor::setTelefono(std::string telefono){
    strcpy(_telefono, telefono.c_str());
}
void Repartidor::setLicencia(std::string licencia){
    strcpy(_licencia,licencia.c_str());
}
void Repartidor::setEstado(bool estado){
    _estado=estado;
}

void Repartidor::mostrarPorId(){
    cout << "ID DEL REPARTIDOR: " << getIdPersona() << endl;
    cout << "DNI DEL REPARTIDOR: " << getDni() << endl;
    cout << "EDAD DEL REPARTIDOR: " << getEdad() << endl;
    cout << "NOMBRE DEL REPARTIDOR: " << getNombre() << endl;
    cout << "APELLIDO DEL REPARTIDOR: " << getApellido() << endl;
    cout << "TELEFONO DEL REPARTIDOR: " << getTelefono() << endl;
    cout << "TIPO DE LICENCIA DEL REPARTIDOR: " << getLicencia() << endl;

    if(getEstado()){
        cout << "ESTADO -> ACTIVO" << endl;
    }
    else{
        cout << "ESTADO -> INACTIVO" << endl;
    }
}

/*
    protected:
    int _idPersona, _dni;
    char _nombre[50], _apellido[50], _telefono[50];
    bool _estado;
    public:
    Persona();

    int getIdPersona();
    int getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getTelefono();
    bool getEstado();

    void setIdPersona(int idPersona);
    void setDni(int dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apelldio);
    void setTelefono(std::string telefono);
    void setEstado(bool estado);
*/