// 문제 : 10816 숫자 카드2
//       https://www.acmicpc.net/problem/10816
// 시간 복잡도 : O()
// 알고리즘 : 자료구조, 해시
// 풀이 방향 : 출력시 시간초과 주의, 코드 참조

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);

    int n, m, tmp;
    cin >> n;

    unordered_map<int, int> HM;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        HM[tmp]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        cout << HM[tmp] << " ";
    }

    return 0;
}