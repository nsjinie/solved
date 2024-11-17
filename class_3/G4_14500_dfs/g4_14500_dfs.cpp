// 문제 : 14500 테트로미노
//       https://www.acmicpc.net/problem/14500
// 풀이 결과 : [3]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//       https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14500-%ED%85%8C%ED%8A%B8%EB%A1%9C%EB%AF%B8%EB%85%B8
// 시간 복잡도 : O()
// 알고리즘 : dfs 변형 (백트래킹)
// 풀이 방향 :
//    1. 연속적으로 연결된 'ㅜ' 를 제외한 모든 테트로미노는 DFS로 탐색 구현
//    2. 연속적으로 연결되지 않은 'ㅜ' 테트로미노는 예외 탐색 로직 구현

#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
bool check[501][501];
int N, M;
int res = 0;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

// ㅏ,ㅜ,ㅓ,ㅗ 정의
int exdi[4][4] = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, -1, 0, 1}, {0, 0, 0, -1}};
int exdj[4][4] = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}, {0, 1, 2, 1}};

void dfs(int i, int j, int sum, int d)
{
    if (d == 4)
    {
        res = max(res, sum);
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int ii = i + di[k];
        int jj = j + dj[k];
        if (ii < 0 || ii >= N || jj < 0 || jj >= M)
            continue;

        if (check[ii][jj] == false)
        {
            check[ii][jj] = true;
            dfs(ii, jj, sum + arr[ii][jj], d + 1);
            check[ii][jj] = false;
        }
    }
}

// ㅗ, ㅓ, ㅜ, ㅏ 에 대해서 탐색
void exshape(int i, int j)
{
    for (int l = 0; l < 4; l++)
    {
        bool isOut = false;
        int sum = 0;
        for (int m = 0; m < 4; m++)
        {
            int ii = i + exdi[l][m];
            int jj = j + exdj[l][m];
            if (ii < 0 || ii >= N || jj < 0 || jj >= M)
            {
                isOut = true;
                break;
            }
            else
            {
                sum += arr[ii][jj];
            }
        }
        if (isOut == false)
        {
            res = max(res, sum);
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            check[i][j] = true;
            dfs(i, j, 0, 0);
            check[i][j] = false;
            exshape(i, j);
        }

    cout << res;

    return 0;
}