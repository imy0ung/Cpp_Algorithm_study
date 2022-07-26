### Cpp_Algorithm_study

## Sort_Algorithm

* 1. Selection Sort

> 가장 적은 수를 선택해서 맨 앞으로 보내면서 정렬하면 어떨까?

* 2. Bubble Sort

> 옆에 있는 값과 비교해서 더 작은 값을 앞으로 보내면서 정렬

* 3. Insertion Sort

> 각 숫자를 적절한 위치에 삽입

* 4. Quick Sort

> 특정한 값(Pivot)를 기준으로 큰 숫자로 정렬된 그룹, 작은 숫자로 정렬된 그룹으로 나누면 어떨까?

* 5. Merge Sort

> 일단 반으로 나누고 나중에 합쳐서 정렬하면 어떨까?

* 6. Heap Sort

> 완전이진트리를 이용해서 정렬하면 어떨까?

* 7. Counting Sort
> 최대값의 범위가 정해져있다면, 먼저 숫자의 개수를 새고 정렬하면 어떨까?

## Stack

기본적인 스택 sql

```c
#include<stack>

s.push() // 스택 삽입

s.pop() // 스택 팝

s.top() // 스택에서 탑 값 가져오기
```

기본적인 스택 출력

```c
while(!s.empty()) { 
      cout << s.top() << ' ';
      s.pop();  
}
```
   
## Queue

```c
#include<queue>

s.push() // 큐 삽입

s.pop() // 큐 팝

s.front() // 큐 프론트 반환

s.back() // 큐 레어 반환
```

기본적인 큐 출력

```c
while(!q.empty()) {
      cout << q.front() << ' ';
      q.pop()
}
```

## BFS ( 너비 우선 탐색 )

> 너비를 우선으로 하여 탐색하는 알고리즘

1. 큐에서 하나의 노드를 꺼내고, 그 노드에 인접한 노드를 살펴본다.

2. 해당 노드를 방문처리 해주고, 그 노드에 인접한 노드를 큐에 넣어준다.

## DFS ( 깊이 우선 탐색
