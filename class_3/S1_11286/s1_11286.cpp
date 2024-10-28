// 문제 : 11286 절댓값 힙
//       https://www.acmicpc.net/problem/11286
// 풀이 결과 : [1]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)

// 시간 복잡도 : O()
// 알고리즘 : 자료구조 (priority_queue)
// 풀이 방향 :
//    1. priority_queue 사용법과 구조체 정렬 문법 숙지

#include <iostream>
#include <queue>

using namespace std;

struct Data
{
    int absData;
    int realData;

    Data(int a, int b)
    {
        absData = a;
        realData = b;
    }

    bool operator<(const Data &b) const
    {
        if (absData == b.absData)
        {
            return realData > b.realData;
        }
        return absData > b.absData;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;

    priority_queue<Data> pQ;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;

        if (a == 0)
        {
            if (pQ.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << pQ.top().realData << '\n';
                pQ.pop();
            }
        }
        else
        {
            pQ.push(Data(abs(a), a));
        }
    }

    return 0;
}
