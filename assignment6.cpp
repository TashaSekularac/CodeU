//
//  assignment6.cpp
//  crc
//
//  Created by Tamara Sekularac on 7/21/17.
//  Copyright © 2017 Tamara Sekularac. All rights reserved.
//

#include <list>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <vector>

#define maxN 10000

using namespace std;

//time complexity O(N)
void parking(int N, int startPos[], int endPos[])
{
    int nextOne=1, posTo, posFrom, carNum;
    int curP[maxN], endP[maxN];
    for(int i=0; i<N;i++)
    {
        curP[startPos[i]]=i;
        endP[endPos[i]]=i;
    }
    while(curP[0]!=endP[0])
    {
        posTo=curP[0];
        carNum=endPos[posTo];
        posFrom=curP[carNum];
        curP[0]=posFrom;
        curP[carNum]=posTo;
        cout<<"move from "<<posFrom<<" to "<<posTo<<endl;
    }
    while(nextOne<N)
    {
        if(curP[nextOne]!=endP[nextOne])
        {
            posTo=curP[0];
            carNum=nextOne;
            posFrom=curP[nextOne];
            curP[0]=posFrom;
            curP[carNum]=posTo;
            cout<<"move from "<<posFrom<<" to "<<posTo<<endl;
            while(curP[0]!=endP[0])
            {
                posTo=curP[0];
                carNum=endPos[posTo];
                posFrom=curP[carNum];
                curP[0]=posFrom;
                curP[carNum]=posTo;
                cout<<"move from "<<posFrom<<" to "<<posTo<<endl;
            }
        }
        nextOne++;
    }
}

int main()
{
    int startPos[5]={4,3,1,2,0};
    int endPos[5]={0,1,2,3,4};
    parking(5,startPos,endPos);
    return 0;
    
}
