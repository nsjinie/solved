// 문제 : 28702
//       https://www.acmicpc.net/problem/28702
// 시간 복잡도 :
// 알고리즘 : 문자열 다루기, 구현문제
// 풀이 방향 : string을 int로 바꾸는 함수 사용

#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    string arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];

    int tmp;
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] != "FizzBuzz" && arr[i] != "Fizz" && arr[i] != "Buzz")
        {
            tmp = stoi(arr[i]) + 3 - i;
            break;
        }
    }

    if (tmp % 15 == 0)
        cout << "FizzBuzz";
    else if (tmp % 5 == 0)
        cout << "Buzz";
    else if (tmp % 3 == 0)
        cout << "Fizz";
    else
        cout << tmp;

    return 0;
} // namespace std;
