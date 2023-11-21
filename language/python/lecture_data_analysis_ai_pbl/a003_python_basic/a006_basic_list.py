name_list = [1, "Hello, world!", 4.2]
print(name_list)

for element in name_list:
    print(element)

for index in range(-len(name_list), len(name_list), 1):
    print("[{}] {}".format(index, name_list[index]))

for index in range(0, len(name_list), 1):
    print(name_list[index])

iterator = iter(name_list)
for element in iterator:
    print(element)

print("-")
[print(name_list[i]) for i in range(0, len(name_list), 1)]
[print(v) for v in name_list]

print("--")

name_list[2] = "this is third element"
name_list.append("this is the last element")
[print(v) for v in name_list]

print("---")

name_list.clear()
[print(v) for v in name_list]
