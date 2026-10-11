# -*- coding: utf-8 -*-
"""
Created on Sat Sep 27 12:52:00 2025

@author: andyb
"""
import matplotlib.pyplot as plt

contador_g = 0

def g(n):
    global contador_g
    i = 1
    while i < n:
        i *= 2
        g(n // 2)
        print("soy el algoritmo 2")
        contador_g += 1

valores_n = [2**i for i in range(0, 11)]
resultados_g = []

for n in valores_n:
    contador_g = 0
    print(f"\nEjecutando g({n}):")
    g(n)
    print(f"Total de impresiones para n = {n}: {contador_g}")
    resultados_g.append(contador_g)

plt.figure(figsize=(10, 6))
plt.plot(valores_n, resultados_g, marker='o', linestyle='-', color='blue')
plt.title("Número de veces 'soy el algoritmo 2'")
plt.xlabel("Valor de n")
plt.ylabel("Número de impresiones")
plt.grid(True)
plt.tight_layout()
plt.show()