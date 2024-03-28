#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
long long a, b;
char d;
vector<bool> vec;
 
void isPrime()
{
    vec[1] = false;
 
    for (long long i = 2; i <= b; i++)
    {
        if (!vec[i]) continue;
        for (long long j = 2 * i; j <= b; j += i)
        {
            vec[j] = false;
        }
    }
}
 
int main()
{
    cin >> a >> b >> d;
    vec.resize(b + 10, true);
    isPrime();
 
    int cnt = 0;
 
    for (int i = a; i <= b; i++)
    {
        if (vec[i] == true)
        {
            string temp = to_string(i);
            for (int j = 0; j < temp.length(); j++)
            {
                if (temp[j] == d)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
 
    cout << cnt;
 
    return 0;
}
