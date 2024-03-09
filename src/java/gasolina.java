// Calcular el precio de la gasolina - Java

package java;

import java.util.Scanner;

public class gasolina {

    /**
     * Calcula los litros que se gastan en un viaje
     *
     * @param km       Kilómetros del viaje
     * @param litroskm Litros que gasta el coche por kilómetro
     * @return Litros que gastará en el viaje
     */
    static float calcularLitros(float km, float litroskm) {
        return km * litroskm;
    }

    /**
     * Calcula el precio de la gasolina
     *
     * @param litros Litros que se gastan
     * @param precio Precio de la gasolina
     * @return Precio del viaje
     */
    static float calcularPrecio(float litros, float precio) {
        return litros * precio;
    }

    /**
     * Calcula el precio por persona
     *
     * @param precio   Precio del viaje
     * @param personas Número de personas
     * @return Precio por persona
     */
    static float precioPersona(float precio, int personas) {
        return precio / personas;
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            float precio, km, litroskm;
            int personas;

            System.out.println("Introduce los kilómetros del viaje: ");
            km = scanner.nextFloat();
            System.out.println("Introduce los litros que gasta el coche por kilómetro: ");
            litroskm = scanner.nextFloat();
            System.out.println("Introduce el precio de la gasolina: ");
            precio = scanner.nextFloat();
            System.out.println("Introduce el número de personas: ");
            personas = scanner.nextInt();

            float litros = calcularLitros(km, litroskm);
            float precioTotal = calcularPrecio(litros, precio);
            float precioPersona = precioPersona(precioTotal, personas);

            System.out.println("El precio total del viaje es de " + precioTotal + "€");
            System.out.println("El precio por persona es de " + precioPersona + "€");
        }
    }

}