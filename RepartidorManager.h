#pragma once
#include "RepartidorArchivo.h"

class RepartidorManager{
    private:
    RepartidorArchivo _archivo;
    public:
    void cargar();
    void listar();
    void buscarPorID();
    void Modificar();
    void DarDeBajaoAlta();
    void ListarActivos();
};
