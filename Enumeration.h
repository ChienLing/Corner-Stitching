#ifndef _ENUMERATION_H_
#define _ENUMERATION_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "Rprocedure.h"
#include "classTile.h"
vector<tile*> Enumeration(tile *startTile, std::pair<long long,long long> LB, std::pair<long long,long long> RT )
{
    vector<tile*> enuList;
    extern long long area;
    tile* CurrentTile = PointFind(startTile, {LB.X,RT.Y});
    bool bottom(false);
    queue<tile*> temQue;
    do{
        if (CurrentTile->LB.Y != RT.Y && CurrentTile->RT.Y != LB.Y)
            temQue.push(CurrentTile);
        if (CurrentTile->lb)
            CurrentTile = CurrentTile->lb;
        else
            break;

        while (CurrentTile->RT.X <= LB.X){
            if (CurrentTile->tr)
                CurrentTile = CurrentTile->tr;
            else
                break;
        }    
    }while ( (CurrentTile->RT.Y <= RT.Y && CurrentTile->RT.Y > LB.Y) || (CurrentTile->LB.Y < RT.Y && CurrentTile->LB.Y >= LB.Y) );

    while (!temQue.empty()){
        tile *startTile = temQue.front();
        temQue.pop();
        if (temQue.empty())
            bottom = true;
        Rprocedure(startTile, enuList, LB, RT, bottom);
    }
    return enuList;
}
#endif