# -*- coding: utf-8 -*-
"""
Created on Sat Sep 27 12:23:39 2025

@author: andyb
"""
import matplotlib.pyplot as plt

contador = 0

def f(n):
    global contador
    if n > 1:
        print("Hola")
        contador += 1
        f(n // 2)
        f(n // 2)

valores_n = [2**i for i in range(0, 11)]  # n = 1, 2, 4, ..., 1024
resultados = []

for n in valores_n:
    contador = 0
    f(n)
    resultados.append(contador)

print("Valores de n:", valores_n)
print("Número de veces que se imprime 'Hola':", resultados)

plt.figure(figsize=(10, 6))
plt.plot(valores_n, resultados, marker='o', linestyle='-', color='blue')
plt.title("Número de veces que se imprime 'Hola' según n")
plt.xlabel("Valor de n")
plt.ylabel("Número de impresiones")
plt.grid(True)
plt.show()