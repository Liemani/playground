name_list = []

for i in range(1, 101, 1):
    name_list.append("홍길동{}".format(i))

# print(name_list)

# for i in range(1, 101, 1):
#     name_list.append("홍길동" + str(i))
# 
# print(name_list)

# new_list = []
# 
# for element in name_list:
#     number = int(element.removeprefix("홍길동"))
#     if number % 2 == 0:
#         new_list.append(element)
# 
# print(new_list)

# new_list = []
# 
# for element in name_list:
#     if int(element[3:]) % 2 == 0:
#         new_list.append(element)
# 
# print(new_list)

new_list3 = []
new_list5 = []
list1 = []

for element in name_list:
    if int(element[3:]) % 3 == 0:
        new_list3.append(element)

for element in name_list:
    if int(element[3:]) % 5 == 0:
        new_list5.append(element)

list1.append(new_list3)
list1.append(new_list5)

# print(list1)

n_list = []

for list in list1:
    for element in list:
        n_list.append(element)

# n_list = list[0] + list[1]

# for list in list1:
#     [n_list.append(element) for element in list]

print(n_list)
