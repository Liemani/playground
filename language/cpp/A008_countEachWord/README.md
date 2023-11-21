결과:
```
% time ./main.out mainBook.cpp > .temp
./main.out mainBook.cpp > .temp  0.00s user 0.00s system 70% cpu 0.004 total
% time ./mainBook.out mainBook.cpp > .temp
./main.out mainBook.cpp > .temp  0.00s user 0.00s system 70% cpu 0.006 total
% time ./a.out /Users/jeonpark/Library/Mobile\ Documents/com~apple~CloudDocs/Downloads/책/수정본/cppPrimerPlus\(5thEdition\).txt > .temp 
./a.out  > .temp  0.94s user 0.01s system 99% cpu 0.950 total
% time ./a.out /Users/jeonpark/Library/Mobile\ Documents/com~apple~CloudDocs/Downloads/책/수정본/cppPrimerPlus\(5thEdition\).txt > .temp
^C
./a.out  > .temp  75.36s user 0.03s system 99% cpu 1:15.41 total
%
```
책에 나온 코드는 역시 매 set element마다 vector.count()를 호출하기 때문에 O(N^2)의 complexity를 가져서 큰 파일일수록 굉장히 느려졌다.
