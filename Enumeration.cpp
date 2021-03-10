#ifndef _ENUMERATION_H_
#define _ENUMERATION_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "Rprocedure.h"
#include "classTile.h"
vector<tile*> Enumeration(tile *startTile, std::pair<int,int> LB, std::pair<int,int> RT )
{
    vector<tile*> enuList;
    tile* CurrentTile = PointFind(startTile, {LB.X,RT.Y});
    bool bottom(false);
    std::cout<<"Enumeration startTile: ";CurrentTile->displayTile();
    queue<tile*> temQue;
    do{
        if (CurrentTile->LB.Y != RT.Y && CurrentTile->RT.Y != LB.Y)
            temQue.push(CurrentTile);
        if (CurrentTile->lb)
            CurrentTile = CurrentTile->lb;
        else
            break;

        while (CurrentTile->RT.X <= LB.X)
        {
            if (CurrentTile->tr)
            {
                CurrentTile = CurrentTile->tr;
            }
            else
                break;
        }    
    }while ( (CurrentTile->RT.Y <= RT.Y && CurrentTile->RT.Y > LB.Y) || (CurrentTile->LB.Y < RT.Y && CurrentTile->LB.Y >= LB.Y) );

    while (!temQue.empty())
    {
        std::cout<<"Enumeration Queue size: "<<temQue.size()<<"\n";
        tile *startTile = temQue.front();
        //std::cout<<"Enumeration leftest tile: ";startTile->displayTile();
        temQue.pop();
        if (temQue.empty())
            bottom = true;
        //std::cout<<"Enumeration List push back: ";startTile->displayTile();
        //enuList.push_back(startTile);
        Rprocedure(startTile, enuList, LB, RT, bottom);
    }
    return enuList;
}
#endif