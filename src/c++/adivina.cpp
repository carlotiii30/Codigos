// Juego: debes adivinar el número que ha pensado el programa.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    int numero, aleatorio, cifras, coincidencias, intentos = 0;

    cout << "¿Cuántas cifras quieres que tenga el número?\n";
    cin >> cifras;

    int cifrasAleatorio[cifras], cifrasNumero[cifras];

    // Generar número aleatorio
    srand(time(0));
    aleatorio = rand() % (int)pow(10, cifras);
    int copia = aleatorio;

    // Acceder a las cifras del número aleatorio
    for (int i = 0; i < cifras; i++)
    {
        cifrasAleatorio[i] = aleatorio / (int)pow(10, cifras - i - 1);
        aleatorio = aleatorio % (int)pow(10, cifras - i - 1);
    }

    while (coincidencias != cifras)
    {
        coincidencias = 0;

        cout << "Adivina el número que he pensado:\n";
        cin >> numero;

        // Acceder a las cifras del número introducido
        for (int i = 0; i < cifras; i++)
        {
            cifrasNumero[i] = numero / (int)pow(10, cifras - i - 1);
            numero = numero % (int)pow(10, cifras - i - 1);
        }

        // Comprobar coincidencias
        for (int i = 0; i < cifras; i++)
        {
            if (cifrasAleatorio[i] == cifrasNumero[i])
            {
                coincidencias++;
            }
        }

        if (coincidencias != cifras)
        {
            cout << "Coinciden: " << coincidencias << " cifras. Inténtalo de nuevo.\n";
        }
        intentos++;
    }

    cout << "CORRECTO: " << copia << endl;
    cout << "Numero de intentos: " << intentos << endl;
}