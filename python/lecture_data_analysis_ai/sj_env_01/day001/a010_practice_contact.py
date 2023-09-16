class Contact:
    def __init__(self):
        self.name = []
        self.age = []
        self.area = []

    def inputInt(self, prompt):
        while True:
            print(prompt, end = "")
            age = input()

            try:
                return int(age)
            except ValueError:
                print("잘못된 값을 입력했습니다")

    def inputContact(self):
        print("이름을 입력하세요: ", end = "")
        name = input()

        age = self.inputInt("나이를 입력하세요: ")

        print("주소를 입력하세요: ", end = "")
        area = input()

        return (name, age, area)

    def getIndexOfNameInput(self, prompt):
        while True:
            print(prompt + "(돌아가려면 빈 값을 입력하세요) ", end = "")
            name = input()

            if name == "":
                print("메뉴 화면으로 돌아갑니다")
                return -1
                
            try:
                index = self.name.index(name)
                break
            except ValueError:
                print("검색하고자 하는 이름이 존재하지 않습니다. 다시 입력해 주세요!")

        return index

    def printByIndex(self, index):
        if 0 <= index < len(self.name):
            print('{{ "이름": "{}", "나이": "{}", "지역": "{}" }}'.format(self.name[index], self.age[index], self.area[index]))
        else:
            print("검색하고자 하는 이름이 존재하지 않습니다!")

    def add(self):
        (name, age, area) = self.inputContact()

        self.name.append(name)
        self.age.append(age)
        self.area.append(area)

        print("추가되었습니다.")

    def update(self):
        index = self.getIndexOfNameInput("수정할 이름을 입력하세요: ")

        if index == -1:
            return

        (name, age, area) = self.inputContact()

        self.name[index] = name
        self.age[index] = age
        self.area[index] = area

        print("수정되었습니다.")

    def delete(self):
        index = self.getIndexOfNameInput("삭제할 이름을 입력하세요: ")

        if index == -1:
            return

        del self.name[index]
        del self.age[index]
        del self.area[index]

        print("삭제되었습니다.")

    def search(self):
        index = self.getIndexOfNameInput("검색할 이름을 입력하세요: ")

        if index == -1:
            return

        self.printByIndex(index)

    def searchAll(self):
        index = 0
        while index < len(self.name):
            self.printByIndex(index)
            index += 1

contact = Contact()

while True:
    print("아래 번호 중에 하나를 선택해 주세요(번호로 입력하세요!): ")
    print("  1. 리스트에 값 추가(이름, 나이, 주소 각각의 값 추가")
    print("  2. 수정(특정 이름에 대한 이름, 나이, 주소 중에 하나 수정")
    print("  3. 삭제(특정 이름에 대한 이름, 나이, 주소 값 삭제")
    print("  4. 검색(특정 이름에 대한 이름, 나이, 주소 값 출력")
    print("  5. 전체검색(모든 이름, 나이, 주소 값 출력")
    print("  6. 종료(반복 종료)")

    try:
        input_line = input()
    except EOFError:
        print("<C-D> 종료합니다")
        break

    try:
        number = int(input_line)

        if number == 1:
            contact.add()
        elif number == 2:
            contact.update()
        elif number == 3:
            contact.delete()
        elif number == 4:
            contact.search()
        elif number == 5:
            contact.searchAll()
        elif number == 6:
            print("종료합니다")
            break
        else:
            print("잘못된 숫자를 입력했습니다")
    except ValueError:
        print("잘못된 값을 입력했습니다")
    except EOFError:
        print("<C-D> 종료합니다")
        break

    print()
