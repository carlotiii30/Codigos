# Calcular precio de gasolina por persona - Python

def calcularLitros(km, litroskm):
    litros = km / litroskm
    return litros

def calcularPrecio(litros, precio):
    total = litros * precio
    return total

def precioPersona(total, personas):
    precio = total / personas
    return precio

def main():
    km = float(input("Kilometros recorridos: "))
    litroskm = float(input("Litros por kilometro: "))
    litros = calcularLitros(km, litroskm)
    precio = float(input("Precio del litro: "))
    total = calcularPrecio(litros, precio)
    personas = int(input("Numero de personas: "))
    precio = precioPersona(total, personas)
    print("Precio por persona: ", precio)