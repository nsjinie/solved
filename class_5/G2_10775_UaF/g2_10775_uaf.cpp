// 문제 : 10775
//       https://www.acmicpc.net/problem/10775
// 시간 복잡도 : ??
// 알고리즘 : union and find
// 풀이 방향 :
//          1. 비행기의 게이트 번호가 할당되면 할당된 게이트보다 작은 게이트에는 도킹 가능 (단 비행기가 없으면)
//          2. 할당받능 게이트 넘버 a를 Find 했을때 0이 나오면 종료.
//          3. 할당받은 게이트 a를 Find한 결과 a와 a-1을 Union 한다. 이때 unf[a] = a-1의 값은 넣는다.
//          4. 메모이제이션에 의해 비행기가 가득차면 할당받은 게이트 넘버로 Find 했을때 0이 리턴된다.

// 예제 입력 2번 경우 : 2 2 3 3 4 4
// unf 배열 변화
// 배행기 0대 :              [0, 1, 2, 3, 4, 5, 6]
// 첫번째 비행기 (게이트 2) : [0, 1, 1, 3, 4, 5, 6]
// 두번째 비행기 (게이트 2) : [0, 0, 1, 3, 4, 5, 6]
// 세번째 비행기 (게이트 3) : [0, 0, 0, 0, 4, 5, 6]
// 네번째 비행기 (게이트 3) : 도킹 불가

#include <iostream>
#include <unordered_map>
using namespace std;

int unf[100001];

int Find(int v)
{
    if (unf[v] == v)
        return v;
    else
        return unf[v] = Find(unf[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
        unf[a] = b;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    int G, P;
    cin >> G >> P;
    for (int i = 1; i <= G; i++)
    {
        unf[i] = i;
    }

    int a;
    int res = 0;
    for (int i = 1; i <= P; i++)
    {
        cin >> a;
        a = Find(a);
        if (a == 0)
            break;

        Union(a, a - 1);
        res++;
    }
    cout << res;

    return 0;
}