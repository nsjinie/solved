// 문제 : 12757
//       https://www.acmicpc.net/problem/12757
// 시간 복잡도 : O(nlogn)
// 알고리즘 : map
// 풀이 방향 :
//          map.low_bound()와 map.upper_bound() 차이를 이해한다
//         왼쪽 값 검색을 위해 -key 값으로 Map을 하나 더 만든다

#include <iostream>
#include <map>
using namespace std;

map<int, int> Map;
map<int, int> nMap;

pair<int, int> findKey(int key)
{
    pair<int, int> ret;

    auto itr = Map.lower_bound(key);
    if (itr != Map.end())
    {
        ret.second = itr->first;
    }
    else
    {
        ret.second = -1;
    }

    auto nitr = nMap.lower_bound(-key);
    if (nitr != nMap.end())
    {
        ret.first = -(nitr->first);
    }
    else
    {
        ret.first = -1;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);
    int N, M, K;
    cin >> N >> M >> K;

    int a, b, c;
    int lkey, rkey;
    int diff_lkey, diff_rkey;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        Map[a] = b;
        nMap[-a] = b;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a;

        if (a == 1)
        {
            cin >> b >> c;
            Map[b] = c;
            nMap[-b] = c;
        }
        else if (a == 2)
        {
            cin >> b >> c;

            auto ret = findKey(b);
            lkey = ret.first;
            rkey = ret.second;
            diff_lkey = b - lkey;
            diff_rkey = rkey - b;

            if (lkey != -1 && rkey != -1)
            {
                if (lkey == rkey)
                {
                    Map[rkey] = c;
                    nMap[-rkey] = c;
                }
                else if ((diff_lkey > diff_rkey) && (diff_rkey <= K))
                {
                    Map[rkey] = c;
                    Map[-rkey] = c;
                }
                else if ((diff_lkey < diff_rkey) && (diff_lkey <= K))
                {
                    Map[lkey] = c;
                    Map[-lkey] = c;
                }
            }
            else if ((lkey >= 0 && rkey == -1) && (diff_lkey <= K))
            {
                Map[lkey] = c;
                Map[-lkey] = c;
            }
            else if ((lkey == -1 && rkey >= 0) && (diff_rkey <= K))
            {
                Map[rkey] = c;
                Map[-rkey] = c;
            }
        }
        else if (a == 3)
        {
            cin >> b;

            auto ret = findKey(b);
            lkey = ret.first;
            rkey = ret.second;

            diff_lkey = b - lkey;
            diff_rkey = rkey - b;

            if (lkey != -1 && rkey != -1)
            {
                if (lkey == rkey)
                {
                    cout << Map[rkey] << '\n';
                }
                else if ((diff_lkey > diff_rkey) && (diff_rkey <= K))
                {
                    cout << Map[rkey] << '\n';
                }
                else if ((diff_lkey < diff_rkey) && (diff_lkey <= K))
                {
                    cout << Map[lkey] << '\n';
                }
                else if ((diff_lkey == diff_rkey) && (diff_lkey <= K))
                {
                    cout << "?" << '\n';
                }
                else
                    cout << "-1" << '\n';
            }
            else if ((lkey >= 0 && rkey == -1) && (diff_lkey <= K))
            {
                cout << Map[lkey] << '\n';
            }
            else if ((lkey == -1 && rkey >= 0) && (diff_rkey <= K))
            {
                cout << Map[rkey] << '\n';
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
    }

    return 0;
}