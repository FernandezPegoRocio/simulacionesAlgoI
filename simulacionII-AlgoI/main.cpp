#include <iostream>
#include <iomanip>
#include "../include/Figura.h"
#include "../include/Circulo.h"
#include "../include/Cuadrado.h"

using namespace std;

void mostrarMenuFiguras();
Figura* crearFigura(int tipoFigura);
void solicitarFiguras(Figura* arregloFiguras[], int cantidad);
void procesarFiguras(Figura* arregloFiguras[], int cantidad);
void mostrarCalculosGeometricos(Figura* arregloFiguras[], int cantidad);
void liberarRecursos(Figura* arregloFiguras[], int cantidad);

int main() {
    cout << "========================================" << endl;
    cout << "   SISTEMA DE CALCULO GEOMETRICO" << endl;
    cout << "      FIGURAS GEOMETRICAS" << endl;
    cout << "========================================" << endl;
    
    const int CANTIDAD_FIGURAS = 3;
    
    Figura** figuras = new Figura*[CANTIDAD_FIGURAS];
    
    for (int i = 0; i < CANTIDAD_FIGURAS; i++) {
        figuras[i] = nullptr;
    }
    
    solicitarFiguras(figuras, CANTIDAD_FIGURAS);
    
    cout << "\n*** PROCESAMIENTO DE FIGURAS ***" << endl;
    
    procesarFiguras(figuras, CANTIDAD_FIGURAS);
    
    mostrarCalculosGeometricos(figuras, CANTIDAD_FIGURAS);

    liberarRecursos(figuras, CANTIDAD_FIGURAS);
    

    delete[] figuras;
    
    cout << "\n*** PROGRAMA FINALIZADO EXITOSAMENTE ***" << endl;
    
    return 0;
}

void mostrarMenuFiguras() {
    cout << "\nSeleccione el tipo de figura:" << endl;
    cout << "1. Circulo" << endl;
    cout << "2. Cuadrado" << endl;
    cout << "Opcion: ";
}

Figura* crearFigura(int tipoFigura) {
    Figura* nuevaFigura = nullptr;
    float valor;
    
    switch(tipoFigura) {
        case 1:
            cout << "Ingrese el radio del circulo: ";
            cin >> valor;
            nuevaFigura = new Circulo(valor);
            break;
            
        case 2:
            cout << "Ingrese el lado del cuadrado: ";
            cin >> valor;
            nuevaFigura = new Cuadrado(valor);
            break;
            
        default:
            cout << "Opcion invalida. Creando circulo por defecto." << endl;
            cout << "Ingrese el radio del circulo: ";
            cin >> valor;
            nuevaFigura = new Circulo(valor);
            break;
    }
    
    return nuevaFigura;
}

void solicitarFiguras(Figura* arregloFiguras[], int cantidad) {
    cout << "\n*** REGISTRO DE FIGURAS GEOMETRICAS ***" << endl;
    cout << "Debe registrar " << cantidad << " figuras en el sistema" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        cout << "\n========== Figura " << (i + 1) << " de " 
             << cantidad << " ==========" << endl;
        
        mostrarMenuFiguras();
        
        int opcion;
        cin >> opcion;
        
        arregloFiguras[i] = crearFigura(opcion);
        
        cout << "Figura registrada correctamente!" << endl;
    }
}

void procesarFiguras(Figura* arregloFiguras[], int cantidad) {
    cout << "\n========================================" << endl;
    cout << "   PROCESAMIENTO DE TODAS LAS FIGURAS" << endl;
    cout << "========================================" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        if (arregloFiguras[i] != nullptr) {
            cout << "\n*** Figura #" << (i + 1) << " ***" << endl;
            
            arregloFiguras[i]->mostrarInformacion();
        }
    }
}

void mostrarCalculosGeometricos(Figura* arregloFiguras[], int cantidad) {
    cout << "\n========================================" << endl;
    cout << "    RESUMEN DE CALCULOS GEOMETRICOS" << endl;
    cout << "========================================" << endl;
    
    float sumaPerimetros = 0;
    float sumaAreas = 0;
    int cantidadCirculos = 0;
    int cantidadCuadrados = 0;
    
    cout << fixed << setprecision(2);
    
    for (int i = 0; i < cantidad; i++) {
        if (arregloFiguras[i] != nullptr) {
            cout << "\nFigura " << (i + 1) << " - " 
                 << arregloFiguras[i]->obtenerTipo() << ":" << endl;
            cout << "  Perimetro: " << arregloFiguras[i]->Perimetro() << endl;
            cout << "  Area: " << arregloFiguras[i]->Area() << endl;
            
            sumaPerimetros += arregloFiguras[i]->Perimetro();
            sumaAreas += arregloFiguras[i]->Area();
            
            if (dynamic_cast<Circulo*>(arregloFiguras[i]) != nullptr) {
                cantidadCirculos++;
            } else if (dynamic_cast<Cuadrado*>(arregloFiguras[i]) != nullptr) {
                cantidadCuadrados++;
            }
        }
    }
    
    cout << "\n----------------------------------------" << endl;
    cout << "ESTADISTICAS GENERALES:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Total de figuras: " << cantidad << endl;
    cout << "  - Circulos: " << cantidadCirculos << endl;
    cout << "  - Cuadrados: " << cantidadCuadrados << endl;
    cout << "Suma total de perimetros: " << sumaPerimetros << endl;
    cout << "Suma total de areas: " << sumaAreas << endl;
    cout << "Promedio de perimetros: " << (sumaPerimetros / cantidad) << endl;
    cout << "Promedio de areas: " << (sumaAreas / cantidad) << endl;
    cout << "========================================" << endl;
}

void liberarRecursos(Figura* arregloFiguras[], int cantidad) {
    cout << "\n*** Liberando recursos del sistema ***" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        if (arregloFiguras[i] != nullptr) {
            delete arregloFiguras[i];
            arregloFiguras[i] = nullptr;
        }
    }
    
    cout << "Recursos liberados correctamente." << endl;
}