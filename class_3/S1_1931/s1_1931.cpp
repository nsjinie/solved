// 문제 : 1931 회의실 배정
//       https://www.acmicpc.net/problem/1931
// 풀이 결과 : [2]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//
// 시간 복잡도 : O(NlogN)  <- sort 함수
// 알고리즘 : 구조체 정렬, 그리디
// 풀이 방향 :
//    1. 끝나는 시간으로 오름차순 정렬
//    2. 남은 데이터 중 가장 빨리 끝나는 회의를 선택하고 끝나는 시간 이전에 시작하는 회의는 포함하지 않는다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Meeting
{
    int start;
    int end;
    Meeting(int a, int b)
    {
        start = a;
        end = b;
    }

    bool operator<(const Meeting &b) const
    {
        if (end != b.end)
        {
            return end < b.end;
        }
        return start < b.start;
    }
};

int main()
{
    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;

    vector<Meeting> Meetings;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        Meetings.push_back(Meeting(a, b));
    }

    sort(Meetings.begin(), Meetings.end());

    int cnt = 1;
    int end = Meetings[0].end;

    for (int i = 1; i < N; i++)
    {
        if (Meetings[i].start < end)
            continue;
        cnt++;
        end = Meetings[i].end;
    }

    cout << cnt;

    return 0;
}
