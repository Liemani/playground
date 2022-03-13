### $(<variable_identifier>:.c=.o)

- .c 를 발견하면 .o 로 치환한다
- make 는 암묵적인 규칙이 많이 있다
- 이 경우 .c 는 variable 의 element 에서 제일 마지막 '.' 을 탐색한 후 그 뒤에 'c' 가 있다면 이 때 'o' 로 바꾼다
