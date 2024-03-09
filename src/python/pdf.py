# Descargar un PDF desde una URL

import requests
import os

def descargar_pdf_desde_url(url):
    # Obtener el nombre del archivo PDF desde la URL
    nombre_pdf = url.split('/')[-1]

    # Crear un directorio para almacenar los PDF si no existe
    if not os.path.exists('pdfs'):
        os.makedirs('pdfs')

    # Ruta donde se guardará el PDF
    pdf_path = os.path.join('pdfs', nombre_pdf)

    # Descargar el PDF desde la URL
    response = requests.get(url)
    if response.status_code == 200:
        with open(pdf_path, 'wb') as pdf_file:
            pdf_file.write(response.content)

        print(f"PDF descargado: {pdf_path}")
    else:
        print("No se pudo descargar el PDF.")

# Solicitar la URL al usuario
url = input("Por favor, ingresa la URL directa al PDF: ")
descargar_pdf_desde_url(url)