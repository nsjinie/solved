// 문제 : 1541 잃어버린 괄호
//        https://www.acmicpc.net/problem/1541
// 시간 복잡도 : O(N)
// 알고리즘 : 스트링 처리
// 풀이 방향 : -기호가 확인되면 뒤에 따라오는 숫자를 모두 뺀다

#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    string str;
    cin >> str;

    int res = 0;
    bool checkMinus = false;
    string num;

    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || i == str.size())
        {
            if (checkMinus == true)
            {
                res -= stoi(num);
            }
            else
            {
                res += stoi(num);
            }
            num = "";
            if (str[i] == '-')
            {
                checkMinus = true;
            }
        }
        else
        {
            num += str[i];
        }
    }

    cout << res;

    return 0;
}
