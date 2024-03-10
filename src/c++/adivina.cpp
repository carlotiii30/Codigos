// Juego: debes adivinar el número que ha pensado el programa.
// Versión 1: Las coincidencias solo comprueban si el dígito está en la posición correcta.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

/**
 * @brief Genera un número aleatorio de n cifras.
 *
 * @param cifras Cantidad de cifras del número.
 * @return int Número aleatorio.
 */
int generarAleatorio(int cifras)
{
    return rand() % (int)pow(10, cifras);
}

/**
 * @brief Crea un array con las cifras de un número.
 *
 * @param aleatorio Número del que se quieren obtener las cifras.
 * @param cifras Cantidad de cifras del número.
 * @return int* Array con las cifras del número.
 */
int *cifrasAleatorio(int aleatorio, int cifras)
{
    int *cifrasAleatorio = new int[cifras];
    for (int i = 0; i < cifras; i++)
    {
        cifrasAleatorio[i] = aleatorio / (int)pow(10, cifras - i - 1);
        aleatorio = aleatorio % (int)pow(10, cifras - i - 1);
    }
    return cifrasAleatorio;
}

/**
 * @brief Crea un array con las cifras de un número.
 *
 * @param numero Número del que se quieren obtener las cifras.
 * @param cifras Cantidad de cifras del número.
 * @return int* Array con las cifras del número.
 */
int *cifrasNumero(int numero, int cifras)
{
    int *cifrasNumero = new int[cifras];
    for (int i = 0; i < cifras; i++)
    {
        cifrasNumero[i] = numero / (int)pow(10, cifras - i - 1);
        numero = numero % (int)pow(10, cifras - i - 1);
    }
    return cifrasNumero;
}

/**
 * @brief Comprueba las coincidencias entre dos arrays.
 *
 * @param arrayAleatorio Array con las cifras del número aleatorio.
 * @param arrayNumero Array con las cifras del número introducido.
 * @param cifras Cantidad de cifras del número.
 * @return int Cantidad de coincidencias.
 */
int comprobarCoincidencias(int *arrayAleatorio, int *arrayNumero, int cifras)
{
    int coincidencias = 0;
    for (int i = 0; i < cifras; i++)
    {
        if (arrayAleatorio[i] == arrayNumero[i])
        {
            coincidencias++;
        }
    }
    return coincidencias;
}

int main()
{
    int numero, aleatorio, cifras, coincidencias, intentos = 0;
    int *arrayAleatorio, *arrayNumero;

    srand(time(0)); // Inicializar la semilla de números aleatorios

    cout << "¿Cuántas cifras quieres que tenga el número?\n";
    cin >> cifras;

    aleatorio = generarAleatorio(cifras);
    arrayAleatorio = cifrasAleatorio(aleatorio, cifras);

    while (coincidencias != cifras)
    {
        coincidencias = 0;

        cout << "Adivina el número que he pensado:\n";
        cin >> numero;

        arrayNumero = cifrasNumero(numero, cifras);

        // Comprobar coincidencias
        coincidencias = comprobarCoincidencias(arrayAleatorio, arrayNumero, cifras);

        if (coincidencias != cifras)
        {
            cout << "Coinciden: " << coincidencias << " cifras. Inténtalo de nuevo.\n";
        }
        intentos++;
    }

    cout << "CORRECTO: " << numero << endl;
    cout << "Numero de intentos: " << intentos << endl;
}