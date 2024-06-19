import random
import multiprocessing
import time

def calcular_pi(num_puntos):
    puntos_dentro_circulo = 0
    for _ in range(num_puntos):
        x = random.random()
        y = random.random()
        distancia = x**2 + y**2
        if distancia <= 1:
            puntos_dentro_circulo += 1
    return puntos_dentro_circulo

if __name__ == '__main__':
    num_puntos = 1000000  # Número total de puntos a generar
    num_procesos = 4  # Número de procesos a utilizar

    # Crear un pool de procesos
    pool = multiprocessing.Pool(processes=num_procesos)

    # Dividir el número total de puntos entre los procesos
    puntos_por_proceso = [num_puntos // num_procesos] * num_procesos

    # Ejecutar los cálculos de forma paralela
    resultados = pool.map(calcular_pi, puntos_por_proceso)

    # Cerrar el pool de procesos
    pool.close()
    pool.join()

    # Calcular el valor de Pi basado en los resultados
    puntos_totales = sum(resultados)
    pi_aproximado = (4.0 * puntos_totales) / num_puntos

    # Imprimir resultados
    print(f'Valor aproximado de Pi: {pi_aproximado}')
