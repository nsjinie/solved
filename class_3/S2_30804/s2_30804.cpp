// 문제 : 30804
//       https://www.acmicpc.net/problem/30804
// 풀이 결과 : [3]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//       참조 url : https://orthordox.tistory.com/144
// 시간 복잡도 : O(N)
// 알고리즘 : 슬라이딩 윈도우, Q 이용
// 풀이 방향 :
// 1. 순차적으로 입력을 받으며 Windows Size 값 증가
// 2. frute Type > 2 이상이면 앞에서 부터 윈도우 size 하나씩 감소, fruteType 감소 처리
// 3. 각각의 데이터 입력시 마다 Window Size를 비교하여 Max값을 답으로 출력

#include <iostream>
#include <queue>

using namespace std;

int frute[10]; // 1~9번 종류 과일 갯수

int main()
{
    freopen("input.txt", "rt", stdin);

    int N;
    int windowSize = 0;
    int typeCnt = 0;

    cin >> N;
    queue<int> Q;

    int result = 0;
    while (N--)
    {
        int num;
        cin >> num;
        Q.push(num);
        windowSize++;
        if (frute[num] == 0)
        {
            typeCnt++;
        }
        frute[num]++;
        while (typeCnt > 2)
        {
            num = Q.front();
            Q.pop();
            windowSize--;
            frute[num]--;
            if (frute[num] == 0)
            {
                typeCnt--;
            }
        }
        result = max(result, windowSize);
    }

    cout << result;
    return 0;
}

/*
//투포인터로 구현 시도
// 1. 데이터 입력하며 과인 종류 카운트
//     1-1. 해시에 과일 종류별 과일 개수 관리
// 2. 과일 종류가 <= 2, 입력 데이터 개수 출력
// 3. 과일 종류가 > 2 , 앞과 뒤 투포인터로 과일 종류를 가르키며 갯수 비교, 작은 수 선택
int main()
{
    freopen("input.txt", "rt", stdin);

    int N;

    cin >> N;

    int p1 = 0, p2 = N - 1, typeCnt = 0, fCnt = N;

    vector<int> V(N);

    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        V[i] = tmp;
        if (frute[tmp] == 0)
        {
            typeCnt++; // 과일종류
        }
        frute[tmp]++;
    }

    while (typeCnt > 2)
    {
        int type1 = V[p1];
        int type2 = V[p2];

        if (type1 == type2)  // 전,후 과일 종류가 같을때 처리하는 부분이 잘 구현되지 않음
        {
            int cnt=0;
            while (type1 == type2)
            {
                p1++;
                p2--;
                fCnt--;
                frute[type1]--;

                type1 = V[p1];
                type2 = V[p2];
                cnt++;
            }
        }

        if (frute[type1] <= frute[type2])
        {
            p1++;
            frute[type1]--;
        }
        else if (frute[type1] > frute[type2])
        {
            p2--;
            frute[type2]--;
        }

        if (frute[type1] == 0 || frute[type2] == 0)
        {
            typeCnt--;
        }
        fCnt--;
    }

    cout << fCnt;

    return 0;
}
*/