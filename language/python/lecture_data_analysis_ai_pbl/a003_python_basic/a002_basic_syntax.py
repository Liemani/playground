start = 0
end = 4
while start < end:
    print(start, end)
    start += 1

start = 0
end = 4
i = 0
while i < end:
    while start < end:
        print(i, start)
        start += 1

    if i == 5:
        break

    i += 1

start = 0
end = 11
sum = 0
while start < end:
    sum += start
    start += 1
print("{} 부터 {} 까지의 총 합은 {} 입니다".format(1, end - 1, sum))

sum = 0
i = 1
end = 6
while True:
    if i == end:
        break

    sum += i
    i += 1

print("{} 부터 {} 까지의 총 합은 {} 입니다".format(1, end - 1, sum))

i = 1
end = 11
sum = 0
while i < end:
    if i % 2 != 0:
        i += 1
        continue

    sum += i

    i += 1

print("{} 부터 {} 까지 짝수의 총 합은 {} 입니다".format(1, end - 1, sum))
