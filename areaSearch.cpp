#ifndef _AREASEARCH_H_
#define _AERASEARCH_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "PointFind.h"
#include "classTile.h"
bool areaSearch(tile *startTile, std::pair<int, int> LB, std::pair<int,int> RT)
{
    std::cout<<"area : ("<<LB.X<<","<<LB.Y<<")"<<",("<<RT.X<<","<<RT.Y<<")"<<endl;
    tile *tilePtr;
    std::pair<int,int> LT;
    LT.X = LB.X;
    LT.Y = RT.Y;
    tilePtr = PointFind(startTile,LT);
    cout<<"start tile: ";tilePtr->displayTile();
    int count(0);
    do{
        cout<<"count: "<<count<<" ";tilePtr->displayTile();
        //std::cout<<tilePtr->solid<<" "<<tilePtr->RT.X<<"\n";
        if ((tilePtr->solid || tilePtr->RT.X < RT.X) && (tilePtr->RT.Y != LB.Y && tilePtr->LB.Y != RT.Y))
            return true;
        count++;
        tilePtr = tilePtr->lb;

        while (tilePtr->RT.X <= LT.X)
            tilePtr = tilePtr->tr;
    }while ( (tilePtr->RT.Y <= RT.Y && tilePtr->RT.Y > LB.Y) || (tilePtr->LB.Y < RT.Y && tilePtr->LB.Y >= LB.Y) );

    return false;
}
#endif