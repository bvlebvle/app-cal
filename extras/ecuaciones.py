from sympy import symbols, Eq, solve

# Definir la variable simbólica
x = symbols('x')

# Definir ecuaciones de una sola incógnita
ecuaciones = [
    Eq(2*x + 3, 7),
    Eq(4*x - 5, 11),
    Eq(x*2 + 3*x - 4, 0)
]

# Resolver y mostrar las soluciones
for ecuacion in ecuaciones:
    soluciones = solve(ecuacion, x)
    print(f"Ecuación: {ecuacion}")
    print(f"Soluciones: {soluciones}")
    print()
