#include <bits/stdc++.h>
using namespace std;
#define M 26
bool isPalin(string str, int *freq)
{
    memset(freq, 0, M * sizeof(int));
    int l = str.length();
    for (int i = 0; i < l; i++)
        freq[str[i] - 'a']++;
    int odd = 0;
    for (int i = 0; i < M; i++)
        if (freq[i] % 2 == 1)
            odd++;
    if ((l % 2 == 1 && odd == 1) || (l % 2 == 0 && odd == 0))
        return true;
    else
        return false;
}
string reverse(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return rev;
}
void printAllPossiblePalindromes(string str)
{
    int freq[M];
    if (!isPalin(str, freq))
        return;
    int l = str.length();
    string half = "";
    char oddC;
    for (int i = 0; i < M; i++)
    {
        if (freq[i] % 2 == 1)
            oddC = i + 'a';
        half += string(freq[i] / 2, i + 'a');
    }
    string palin;
    do
    {
        palin = half;
        if (l % 2 == 1)
            palin += oddC;
        palin += reverse(half);
        cout << palin << endl;
    } while (next_permutation(half.begin(), half.end()));
}
int main()
{
    string str = "aabbcadad";
    printAllPossiblePalindromes(str);
    return 0;
}
