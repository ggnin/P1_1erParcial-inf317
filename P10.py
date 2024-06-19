import multiprocessing

M = 4  # Número de vectores (procesadores)
N = 10  # Número de términos en cada vector

def generar_serie(inicio, paso, num_terminos, resultados):
    """
    Función para generar una parte de la serie y guardarla en la lista compartida.
    """
    serie = []
    valor_actual = inicio
    for _ in range(num_terminos):
        serie.append(valor_actual)
        valor_actual += paso
    resultados.append(serie)

if __name__ == '__main__':
    # Lista compartida para almacenar los resultados
    manager = multiprocessing.Manager()
    resultados_compartidos = manager.list()

    # Lista de procesos
    procesos = []

    # Distribuir la tarea entre M procesos
    for i in range(M):
        proceso = multiprocessing.Process(target=generar_serie, args=(2 + i*2, 2*M, N, resultados_compartidos))
        procesos.append(proceso)
        proceso.start()

    # Esperar a que todos los procesos terminen
    for proceso in procesos:
        proceso.join()

    # Imprimir los vectores generados
    print("Vectores generados:")
    for idx, vector in enumerate(resultados_compartidos):
        print(f"Vector {idx + 1}: {vector}")
