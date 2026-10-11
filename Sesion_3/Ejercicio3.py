# -*- coding: utf-8 -*-
"""
Created on Sat Sep 27 13:20:10 2025

@author: andyb
"""
import matplotlib.pyplot as plt

# Contador global
contador_h = 0

def h(n):
    global contador_h
    i = 1
    while i < n:
        i *= 2
        for j in range(n):
            h(n // 2)
            print("soy el algoritmo 3")
            contador_h += 1

valores_n = [2**i for i in range(0, 4)]
resultados_h = []

for n in valores_n:
    contador_h = 0
    print(f"\nEjecutando h({n}):")
    h(n)
    print(f"Total de impresiones para n = {n}: {contador_h}")
    resultados_h.append(contador_h)

plt.figure(figsize=(10, 6))
plt.plot(valores_n, resultados_h, marker='o', linestyle='-', color='red')
plt.title("Número de veces 'soy el algoritmo 3'")
plt.xlabel("Valor de n")
plt.ylabel("Número de impresiones")
plt.grid(True)
plt.tight_layout()
plt.show()