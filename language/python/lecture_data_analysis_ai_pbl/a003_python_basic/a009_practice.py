name = ["홍길동", "이순신", "김유신"]
age = [18, 30, 50]
area = ["서울", "세종", "대전"]

# input_name = input()
# 
# input_index = -1
# for index in range(0, 3, 1):
#     if name[index] == input_name:
#         input_index = index
#         break
# 
# if input_index != -1:
#     print("{} / {} / {}".format(name[input_index], age[input_index], area[input_index]))
# else:
#     print("unknown")

while True:
    print("검색하고자 하는 이름을 입력하세요: ", end = "")

    try:
        input_line = input()
    except EOFError:
        print("<C-D> 종료합니다")
        break;

    if input_line == "x":
        print("[x] 종료합니다")
        break

    index = 0
    while index < len(name):
        if name[index] == input_line:
            break

        index += 1

    if index != len(name):
        print('{{ "이름": "{}", "나이": "{}", "지역": "{}" }}'.format(name[index], age[index], area[index]))
    else:
        print("검색하고자 하는 이름이 존재하지 않습니다. 다시 입력해 주세요!")
        print()

# if p_name in name:
