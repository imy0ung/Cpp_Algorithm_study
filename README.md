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

기본적인 큐 sql

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

> 너비를 우선으로 하여 탐색하는 알고리즘 (큐를 사용)

1. 큐에서 하나의 노드를 꺼내고, 그 노드에 인접한 노드를 살펴본다.

2. 해당 노드를 방문처리 해주고, 그 노드에 인접한 노드를 큐에 넣어준다.

## DFS ( 깊이 우선 탐색 )

> 깊이를 우선으로 하여 탐색하는 알고리즘 (스택 사용)

1. 최상단 노드를 살펴본다.

2. 가장 인접한 노드를 방문처리해주고, 해당 노드를 스택에 넣어준다.

## Union find

> 그래프 상에서 서로 연결되어있는지 확인하는 알고리즘

1. 배열을 이용하여, 각 노드에 부모를 저장해준다. 이때, 아무것도 연결되어있지 않다면, 자기 자신을 가르친다.

2. getParent함수를 이용하여, 부모 노드를 찾아줄 수 있다. (기본적으로 더 작은 값을 가지는 노드가 부모가 된다.

```c
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]); // 뿌리노드까지 가는 개념
}
```

3. unionParent 함수를 이용하여, 서로 다른 두 노드를 연결해줄 수 있다.

```c
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a; // 두 노드의 부모 중 가장 작은 값이 부모
	else parent[a] = b;
}
```

4. findParent함수를 이용하여, 서로 연결되어있는지 확인할 수 있다.

```c
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}
```
