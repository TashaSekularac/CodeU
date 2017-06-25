//
//  assignment3.cpp
//  assignment3
//
//  Created by Tamara Sekularac on 6/17/17.
//  Copyright © 2017 Tamara Sekularac. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

class Dictionary{
public:
    bool isWord(string s);
    bool isPrefix(string s);
};

void wordSearchHelper(int i, int j, int n, int m, char** grid, bool** used,  Dictionary* dict, string currStr, set<string>* wordSet)
{
    if(used[i][j]==false)
    {
        used[i][j]=true;
        currStr+=grid[i][j];
        if(dict->isPrefix(currStr))
        {
            if(dict->isWord(currStr))
                wordSet->insert(currStr);
            if(i>0)
            {
                if(j>0)
                    wordSearchHelper(i-1,j-1, n, m, grid,used, dict,currStr,wordSet);
                wordSearchHelper(i-1,j, n, m, grid,used, dict,currStr,wordSet);
                if(j<m-1)
                    wordSearchHelper(i-1,j+1, n, m, grid,used, dict,currStr,wordSet);
            }
            if(j>0)
                wordSearchHelper(i,j-1, n, m, grid,used, dict,currStr,wordSet);
            if(j<m-1)
                wordSearchHelper(i,j+1, n, m, grid,used, dict,currStr,wordSet);
            if(i<n-1)
            {
                if(j>0)
                    wordSearchHelper(i+1,j-1, n, m, grid,used, dict,currStr,wordSet);
                wordSearchHelper(i+1,j, n, m, grid,used, dict,currStr,wordSet);
                if(j<m-1)
                    wordSearchHelper(i+1,j+1, n, m, grid,used, dict,currStr,wordSet);
            }
        }
        used[i][j]=false;
    }
}

set<string>* wordSarch(int n, int m, char** grid, Dictionary* dict)
{
    bool used[n][m];
    fill(used[0], used[0] + n * m, 0);
    set<string>* wordSet=new set<string>();
    string currStr="";
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            wordSearchHelper(i,j, n, m, grid, (bool**)used, dict, currStr, wordSet);
    return wordSet;
}

