#include <iostream>
#include <vector>
#include <string>
#include "include/Vehiculo.h"
#include "include/Coche.h"
#include "include/Moto.h"
#include "include/Taller.h"

using namespace std;

void mostrarMenuPrincipal();
void mostrarMenuVehiculos();
void registrarVehiculos(Taller* taller, vector<Vehiculo*>& vehiculosRegistrados);
Vehiculo* crearNuevoVehiculo(int tipoVehiculo);
void ejecutarOperacionesTaller(Taller* taller);
void gestionarRecursos(vector<Vehiculo*>& vehiculosRegistrados, Taller* taller);
void probarFuncionalidad(vector<Vehiculo*>& vehiculosRegistrados);

int main() {
    cout << "========================================" << endl;
    cout << "    SISTEMA DE GESTION DE TALLER" << endl;
    cout << "      MECANICA AUTOMOTRIZ" << endl;
    cout << "========================================" << endl;
    
    Taller* tallerPrincipal = new Taller(10);
    
    vector<Vehiculo*> vehiculosRegistrados;
    
    registrarVehiculos(tallerPrincipal, vehiculosRegistrados);
    
    ejecutarOperacionesTaller(tallerPrincipal);
    
    probarFuncionalidad(vehiculosRegistrados);
    
    gestionarRecursos(vehiculosRegistrados, tallerPrincipal);
    
    cout << "\n*** PROGRAMA FINALIZADO EXITOSAMENTE ***" << endl;
    
    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n=== MENU DE OPERACIONES DEL TALLER ===" << endl;
    cout << "1. Arreglar TODOS los vehiculos" << endl;
    cout << "2. Arreglar SOLO coches" << endl;
    cout << "3. Arreglar SOLO motos" << endl;
    cout << "4. Listar vehiculos en taller" << endl;
    cout << "5. Mostrar estadisticas" << endl;
    cout << "6. Salir" << endl;
    cout << "Opcion: ";
}

void mostrarMenuVehiculos() {
    cout << "\nTipo de vehiculo a ingresar:" << endl;
    cout << "1. Coche" << endl;
    cout << "2. Moto" << endl;
    cout << "Opcion: ";
}

Vehiculo* crearNuevoVehiculo(int tipoVehiculo) {
    string marca, color;
    
    cout << "\n--- Datos del vehiculo ---" << endl;
    cout << "Marca: ";
    cin >> marca;
    cout << "Color: ";
    cin >> color;
    
    Vehiculo* nuevoVehiculo = nullptr;
    
    if (tipoVehiculo == 1) {
        int motor;
        cout << "Numero de cilindros del motor: ";
        cin >> motor;
        nuevoVehiculo = new Coche(color, marca, motor);
    } else if (tipoVehiculo == 2) {
        int cilindrada;
        cout << "Cilindrada (cc): ";
        cin >> cilindrada;
        nuevoVehiculo = new Moto(color, marca, cilindrada);
    }
    
    return nuevoVehiculo;
}

void registrarVehiculos(Taller* taller, vector<Vehiculo*>& vehiculosRegistrados) {
    cout << "\n*** REGISTRO DE VEHICULOS EN EL TALLER ***" << endl;
    
    int numeroVehiculos;
    cout << "Cuantos vehiculos desea ingresar al taller? (max 10): ";
    cin >> numeroVehiculos;
    
    if (numeroVehiculos > 10) {
        numeroVehiculos = 10;
        cout << "Limitado a 10 vehiculos maximo." << endl;
    }
    
    for (int i = 0; i < numeroVehiculos; i++) {
        cout << "\n========== Vehiculo " << (i + 1) << " de " 
             << numeroVehiculos << " ==========" << endl;
        
        mostrarMenuVehiculos();
        int opcion;
        cin >> opcion;
        
        Vehiculo* vehiculo = crearNuevoVehiculo(opcion);
        
        if (vehiculo != nullptr) {
            taller->meter(vehiculo);
            vehiculosRegistrados.push_back(vehiculo);
        }
    }
}

void ejecutarOperacionesTaller(Taller* taller) {
    bool continuar = true;
    
    while (continuar) {
        mostrarMenuPrincipal();
        int opcion;
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                taller->arreglarVehiculos();
                break;
            case 2:
                taller->arreglarCoches();
                break;
            case 3:
                taller->arreglarMotos();
                break;
            case 4:
                taller->listarVehiculos();
                break;
            case 5:
                taller->mostrarEstadisticasTaller();
                break;
            case 6:
                continuar = false;
                cout << "\nSaliendo del sistema de gestion..." << endl;
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente." << endl;
        }
    }
}

void probarFuncionalidad(vector<Vehiculo*>& vehiculosRegistrados) {
    cout << "\n========================================" << endl;
    cout << "    PRUEBA DE FUNCIONALIDAD DE VEHICULOS" << endl;
    cout << "========================================" << endl;
    
    if (vehiculosRegistrados.empty()) {
        cout << "No hay vehiculos registrados para la prueba de funcionalidad." << endl;
        return;
    }
    
    cout << "\nCada vehiculo ejecuta sus operaciones especificas:" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    for (size_t i = 0; i < vehiculosRegistrados.size(); i++) {
        cout << "\n*** Vehiculo " << (i + 1) << " ***" << endl;
        
        vehiculosRegistrados[i]->mostrarInformacion();
        
        cout << "\nEjecutando operaciones especificas:" << endl;
        
        vehiculosRegistrados[i]->arrancar();
        cout << endl;
        vehiculosRegistrados[i]->repostar();
        cout << endl;
        vehiculosRegistrados[i]->parar();
        
        cout << "\n----------------------------------------" << endl;
    }
    
    cout << "\n*** FIN DE PRUEBA DE FUNCIONALIDAD ***" << std::endl;
}

void gestionarRecursos(vector<Vehiculo*>& vehiculosRegistrados, Taller* taller) {
    cout << "\n*** Finalizacion de gestion de recursos ***" << endl;
    
    for (Vehiculo* vehiculo : vehiculosRegistrados) {
        delete vehiculo;
    }
    vehiculosRegistrados.clear();
    
    delete taller;
    
    cout << "Recursos liberados correctamente." << endl;
}