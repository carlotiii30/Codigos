/**
 * @file gasolina.cpp
 * @author Carlota de la Vega
 * @brief Programa que calcula el precio de la gasolina por persona.
 * @version 0.1
 * @date 2023-08-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Función que calcula los litros que se gastan en un viaje.
 *
 * @param km Kilómetros totales del trayecto.
 * @param litroskm Litros que gasta el coche por kilómetro.
 * @return float litros totales.
 */
float calcularLitros(float km, float litroskm) {
    return km * litroskm;
}

/**
 * @brief Función que calcula el precio total de la gasolina.
 *
 * @param litros Litros gastados en el viaje.
 * @param precio Precio de la gasolina.
 * @return float precio total.
 */
float calcularPrecio(float litros, float precio) {
    return litros * precio;
}

/**
 * @brief Función que calcula el precio por persona.
 *
 * @param precio Precio total de la gasolina.
 * @param personas Personas que viajan.
 * @return float precio por persona.
 */
float precioPersona (float precio, int personas) {
    return precio / personas;
}

int main() {
    float precio, litros, personas, km;

    cout << "Ingrese la distancia total del viaje en km: ";
    cin >> km;
    cout << "Ingrese el precio de la gasolina: ";
    cin >> precio;
    cout << "Ingrese la cantidad de litros que gasta por kilómetro: ";
    cin >> litros;
    cout << "Infrese la cantidad de personas que viajan: ";
    cin >> personas;

    float litrosTotales = calcularLitros(km, litros);
    float precioTotal = calcularPrecio(litrosTotales, precio);
    float precioPersonaTotal = precioPersona(precioTotal, personas);

    cout << "El total a pagar por persona es: " << precioPersonaTotal << endl;

    return 0;
}