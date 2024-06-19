import multiprocessing

def fibonacci_secuencia(n):
    """ Función para calcular los primeros n términos de la secuencia de Fibonacci. """
    fib = [0, 1]
    for i in range(2, n):
        fib.append(fib[-1] + fib[-2])
    return fib

def calcular_fibonacci_parte(inicio, fin):
    """ Función para calcular una parte de la secuencia de Fibonacci desde inicio hasta fin. """
    fib_parte = fibonacci_secuencia(fin)
    return fib_parte[inicio:fin]

if __name__ == '__main__':
    num_terminos = 1000
    num_procesadores = multiprocessing.cpu_count()

    # Calcular cuántos términos cada proceso calculará dinámicamente
    terminos_por_proceso = num_terminos // num_procesadores
    tareas = []

    # Configurar el pool de procesos
    with multiprocessing.Pool(processes=num_procesadores) as pool:
        for i in range(num_procesadores):
            inicio = i * terminos_por_proceso
            fin = min((i + 1) * terminos_por_proceso, num_terminos)
            tarea = pool.apply_async(calcular_fibonacci_parte, args=(inicio, fin))
            tareas.append(tarea)

        # Recopilar los resultados de cada proceso
        resultados = [tarea.get() for tarea in tareas]

    # Combinar los resultados de los procesos en una lista única de Fibonacci
    fibonacci_completo = []
    for resultado in resultados:
        fibonacci_completo.extend(resultado)

    # Imprimir los primeros 1000 términos de Fibonacci
    print(f"Los primeros {num_terminos} términos de la secuencia de Fibonacci:")
    print(fibonacci_completo[:num_terminos])
