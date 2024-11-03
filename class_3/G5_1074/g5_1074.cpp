// 문제 : 1074 Z
//       https://www.acmicpc.net/problem/1074
// 풀이 결과 : [3]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//       https://simsimjae.tistory.com/191
// 시간 복잡도 : O(??)
// 알고리즘 : 재귀, 분할정복
// 풀이 방향 :
//    1. 한변의 길이가 N 인 정사각형일때 N-1크기로 4등분 하여 재귀 호출
//    2. N-1 호출시 r,c가 해당 위치에 있지 않으면 재귀를 호출하지 않고 (N-1)^2을 연산하여 바로 리턴 (시간 복잡도를 줄이는 핵심)
//    3. y,x 와 r, c가 일치할때 까지 N값을 1씩 줄여가며 재귀 호출

#include <iostream>
#include <math.h>
using namespace std;

int result = 0;
int N, r, c;

void recursion(int x, int y, int len)
{
    if (x == c && y == r)
    {
        cout << result;
        exit(0);
    }

    if (len == 1)
    {
        result++;
        return;
    }

    if (!(x <= c && c < x + len && y <= r && r < y + len))
    {
        result += len * len;
        return;
    }

    recursion(x, y, len / 2);
    recursion(x + (len / 2), y, len / 2);
    recursion(x, y + (len / 2), len / 2);
    recursion(x + (len / 2), y + (len / 2), len / 2);
}

int main()
{
    freopen("input.txt", "rt", stdin);

    cin >> N >> r >> c;

    recursion(0, 0, pow(2, N));

    return 0;
}