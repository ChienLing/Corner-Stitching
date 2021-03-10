#ifndef _POINTFIND_H_
#define _POINTFIND_H_
#define X first
#define Y second
#include <bits/stdc++.h>
tile* PointFind(tile* startTile, std::pair<long long, long long> point)
{
    extern int n;
    tile *tilePtr = startTile;
    while (tilePtr && !(tilePtr->RT.Y >= point.Y && tilePtr->LB.Y < point.Y && tilePtr->RT.X >= point.X && tilePtr->LB.X < point.X))
    {
        while (tilePtr &&  !(tilePtr->RT.Y >= point.Y && tilePtr->LB.Y < point.Y) )
        {
            if (tilePtr->RT.Y < point.Y && tilePtr->rt)
                tilePtr = tilePtr->rt;
            else if (tilePtr->RT.Y >= point.Y && tilePtr->lb)
                tilePtr = tilePtr->lb;
            else
                break;
            
        }
        while (tilePtr &&  !(tilePtr->RT.X >= point.X && tilePtr->LB.X < point.X) )
        {
            if (tilePtr->RT.X < point.X && tilePtr->tr)
                tilePtr = tilePtr->tr;
            else if (tilePtr->RT.X >= point.X && tilePtr->bl)
                tilePtr = tilePtr->bl;
            else
                break;
            
        }
        if (tilePtr->RT.X >= point.X && tilePtr->LB.X <= point.X && tilePtr->RT.Y >= point.Y && tilePtr->LB.Y <= point.Y)
        {
            if(tilePtr->LB.X == point.X && !tilePtr->bl)
                break;
            if (tilePtr->LB.Y == point.Y && !tilePtr->lb)
                break;
        }
    }
    return tilePtr;
}
#endif