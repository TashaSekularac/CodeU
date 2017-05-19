#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

bool permutation ( string a, string b)
{
    if(a.length()!=b.length())
        return false;
    int number[26];
    for(int i=0; i<26; i++)
        number[i]=0;
    for(int i=0; i<a.length(); i++)
        if(a[i]<='Z' && a[i]>='A')
            number[a[i]-'A']++;
        else
            if(a[i]<='z' && a[i]>='a')
                number[a[i]-'a']++;
            else
                return false;
    for(int i=0; i<b.length(); i++)
    {
        if(b[i]<='Z' && b[i]>='A')
        {
            number[b[i]-'A']--;
            if(number[b[i]-'A']<0)
                return false;
        }
        else
            if(b[i]<='z' && b[i]>='a')
            {
                number[b[i]-'a']--;
                if(number[b[i]-'a']<0)
                    return false;
            }
            else
                return false;
    }
    return true;
}
int main()
{
    string a,b;
    cin>>a>>b;
    if(permutation(a, b))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
    
}
