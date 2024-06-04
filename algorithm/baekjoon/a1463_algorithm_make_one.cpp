/// This solution failed for 572
///   572
///   571
///   570
///   190
///   189
///   63
///   21
///   7
///   6
///   2
///   1
/// - Input : 1 <= n <= 10^6
#include <stdio.h>

#define IS_NOT_POWER_OF_TWO -1

inline int bitIndex(int number) {
  return
    (((number & 0xffff0000) != 0) << 4)
    + (((number & 0xff00ff00) != 0) << 3)
    + (((number & 0xf0f0f0f0) != 0) << 2)
    + (((number & 0xcccccccc) != 0) << 1)
    + (((number & 0xaaaaaaaa) != 0) << 0);
}

inline int isPowerOf2(int number) {
  if ((number & (number - 1)) != 0)
    return IS_NOT_POWER_OF_TWO;

  return bitIndex(number);
}

inline int notPowerOf2(int number) {
  int count = 0;

  while (number != 1) {
    if (number % 3 == 0) {
      number /= 3;
      ++count;
    }
    else if ((number - 1) % 3 == 0) {
      --number;
      number /= 3;
      count += 2;
    }
    else if (number % 2 == 0) {
      number /= 2;
      ++count;
    }
    else {
      number -= 2;
      count += 2;
    }
  }

  return count;
}

inline void solution(int number) {
  int count;

  if ((count = isPowerOf2(number)) == IS_NOT_POWER_OF_TWO) {
    count = notPowerOf2(number);
  }

  printf("%d", count);
}

int main() {
  int number;

  scanf("%d", &number);

  solution(number);

  return 0;
}

/*
16
8
4
2
1

16
15
5
4
3
1

32
16
8
4
2
1

32
31
30
10
9
3
1

33
32
16
8
4
2
1

33
11
10
9
3
1

81
27
9
3
1

84
28
27
9
3
1


1234
1233
411
137

136
135
45
15
5
4
2
1

136
68
34
33
11
10
9
3
1


1234
617
616
308
154
77
76
38
19
18
6
2
1

[0]
1

[1]
2(1 + 1)
3(1 * 3)

[2]
4(3 + 1)
6(2 * 3)
9(3 * 3)

[3]
5(4 + 1)
7(6 + 1)
8(4 * 2)
10(9 + 1)
12(4 * 3)
18(6 * 3)
27(9 * 3)

[4]
11(10 + 1)
13(12 + 1)
14(7 * 2)
15(5 * 3)
16(8 * 2)
19(18 + 1)
20(10 * 2)
21(7 * 3)
24(8 * 3)
28(27 + 1)
36(12 * 3)
54(18 * 3)
81(27 * 3)

17
22
23
25
26
29(
30

1을 뺏더니 3으로 나누어지더라
2를 빼야 3으로 나누어지더라 -> 그런데 2로 나누어진다 -> 2로 나눔
2를 나눠서만 만들 수 있더라 -> 2로 나눔
비트에 1이 단 하나더라 -> 비트의 자릿수

아니면
if (n % 3 != 0 && (n - 1) % 3 != 0 &&


1
2
4
8

16
15
5
4
2
1

33
32
16
8
4
2
1

33
11
10
9
3
1

572
286
285
95
94
93
31
30
10
9
3
1

572
571
570
190
189
63
21
7
6
2
1

572
571
570
190
95
94
47

572
286
285
95
94
93
31
30
10
9
3
1

572




117
39
33
11
10
9
3
1
*/
