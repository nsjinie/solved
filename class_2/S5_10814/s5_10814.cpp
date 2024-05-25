// 문제 : 10814 나이순 정렬
//       https://www.acmicpc.net/problem/10814
// 시간 복잡도 : O(nlogn)   -> sort 함수 시간 복잡도
// 알고리즘 : 정렬
// 풀이 방향 :  구조체 정렬 구현

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Person
{
    int age;
    int num;
    string name;
    Person(int _age, int _num, string _name)
    {
        age = _age;
        num = _num;
        name = _name;
    }

    bool operator<(const Person &b) const
    {
        if (age == b.age)
            return num < b.num;
        return age < b.age;
    }
};

main()
{
    freopen("input.txt", "rt", stdin);

    vector<Person> arr;

    int n;
    cin >> n;

    int age;
    string name;
    for (int i = 0; i < n; i++)
    {
        cin >> age >> name;
        arr.push_back(Person(age, i, name));
    }

    sort(arr.begin(), arr.end());

    for (auto p : arr)
        cout << p.age << " " << p.name << '\n';

    return 0;
}