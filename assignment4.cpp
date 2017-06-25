//
//  assignment4.cpp
//  assignment4
//
//  Created by Tamara Sekularac on 6/25/17.
//  Copyright © 2017 Tamara Sekularac. All rights reserved.
//


int numberOfIslands(int n, int m, bool** map)
{
    int mapNum[n][m];
    int num=0;
    int islandConnection[n*m];
    if(map[0][0])
    {
        num++;
        mapNum[0][0]=num;
    }
        
    for(int i=1; i<m; i++)
        if(map[0][i])
        {
            if(map[0][i-1])
                mapNum[0][i]=mapNum[0][i-1];
            else
            {
                num++;
                mapNum[0][i]=num;
            }
        }
    for(int i=0; i<n; i++)
    {
        if(map[i][0])
        {
            if(map[i-1][0])
            mapNum[i][0]=mapNum[i-1][i];
            else
            {
                num++;
                mapNum[i][0]=num;
            }
        }
        for(int j=1; j<m; j++)
            if(map[i][j])
            {
                if(map[i-1][j])
                    if(map[i][j-1])
                    {
                        if(mapNum[i-1][j]>mapNum[i][j-1])
                        {
                            mapNum[i][j]=mapNum[i][j-1];
                            islandConnection[mapNum[i-1][j]]=mapNum[i][j-1];
                        }
                        else
                        {
                            mapNum[i][j]=mapNum[i-1][j];
                            islandConnection[mapNum[i][j-1]]=mapNum[i-1][j];
                        }
                    }
                    else
                        mapNum[i][j]=mapNum[i-1][j];
                else
                    if(map[i][j-1])
                        mapNum[i][j]=mapNum[i][j-1];
                    else
                    {
                        num++;
                        mapNum[i][j]=num;
                    }
                }
    }
    int rez=0;
    for(int i=1; i<=num; i++)
        if(i==islandConnection[i])
            rez++;
    return rez;
}

