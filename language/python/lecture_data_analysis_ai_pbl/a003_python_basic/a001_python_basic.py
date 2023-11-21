c = 10
print(c)

a = 1.5
print(a)

s = "안녕하세요"
print(s)

t = True
f = False
print(t, f)

# int, float, str, bool
# list, dict, tuple, set
print(type(c))
print(type(a))
print(type(s))
print(type(t))

total = a + c
print(total)

print(10 % 3)
print(10 // 3)
print(-10 % 3)

if a > c:
    print("a is greater than c")
elif a == c:
    print("a is equal to c")
else:
    print("a is less than c")

start = 0
end = 4

for i in range(start, end, 1):
    print(i)

sum = 0
for i in range(1, 11, 1):
    sum += i
print(sum)

sum = 0
for i in range(1, 11, 1):
    if i <= 5:
        sum += i
print(sum)

sum = 0
for i in range(1, 11, 1):
    sum += i

    if i == 5:
        break
print("1 부터 {}까지의 총합 = {}".format(i, sum))

sum = 0
for i in range(1, 11, 1):
    if i % 2 == 0:
        sum += i
#     if i % 2 != 0:
#         continue

print("1 부터 {} 까지 짝수의 총합: {}".format(i, sum))
