def bmi(weight: float, height: float) -> float:
    return weight / ((height/100)**2)

def print_bmi(bmi: float) -> float:
    if bmi < 18.5: print("Underweight")
    elif bmi < 25.0: print("Normal")
    elif bmi < 30.0: print("Overweight")
    else: print("Obesity")

print("Вас приветствует программа вычисления индекса массы тела\n")
weight = float(input("Введите вес в килограммах: "))
height = float(input("Введите рост в сантиметрах: "))
print_bmi(bmi(weight, height))