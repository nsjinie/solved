// 문제 : 5525 IOIOI
//       https://www.acmicpc.net/problem/5525
// 풀이 결과 : [2]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//       참조 url : https://testcase.ac/problems/5525  (반례 찾아주는 사이트)
// 시간 복잡도 : O(N)
// 알고리즘 : 문자열 처리, 슬라이딩 윈도우
// 풀이 방향 :
//    1. 'I' 문자열이 나오면 'OI' 문자열이 매칭되는지 슬라이딩 윈도우 기법으로 탐색
//    2. 연속된 Pn 갯수를 구할 때 주의 필요 (IOIOIOI에서 P2를 찾으면 2개임)

#include <iostream>
#include <string>

using namespace std;
int main()
{
    freopen("input.txt", "rt", stdin);

    int N, M;
    string s;

    cin >> N >> M;
    cin >> s;

    int ans = 0;

    for (int i = 0; i < M - 2; i++)
    {
        if (s[i] == 'I')
        {
            int k = 0;
            while (s[i + 1] == 'O' && s[i + 2] == 'I')
            {
                k++;
                // cout << "K : " << k << '\n';
                i += 2;
                if (k == N)
                {
                    ans++;
                    k--;
                }
            }
        }
    }
    cout << ans;

    return 0;
}
