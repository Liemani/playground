# - arguments:
#   - mode: + - * /
def getMath(mode, a, b):
    result = 0

    if mode == "+":
        result = a + b
    elif mode == "-":
        result = a - b
    elif mode == "*":
        result = a * b
    elif mode == "/":
        result = a / b

    return result

print(getMath("+", 10, 2))
print(getMath("-", 10, 2))
print(getMath("*", 10, 2))
print(getMath("/", 10, 2))
