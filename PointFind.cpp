#ifndef _POINTFIND_H_
#define _POINTFIND_H_
#define X first
#define Y second
#include <bits/stdc++.h>
tile* PointFind(tile* startTile, std::pair<int, int> point)
{
    tile *tilePtr = startTile;
    tilePtr->displayTile();
    while (!(tilePtr->RT.Y >= point.Y && tilePtr->LB.Y <= point.Y && tilePtr->RT.X >= point.X && tilePtr->LB.X <= point.X))
    {
        while ( !(tilePtr->RT.Y >= point.Y && tilePtr->LB.Y <= point.Y) )
        {
            if (tilePtr->RT.Y < point.Y)
                tilePtr = tilePtr->rt;
            else
                tilePtr = tilePtr->lb;
        }
        while ( !(tilePtr->RT.X >= point.X && tilePtr->LB.X <= point.X) )
        {
            if (tilePtr->RT.X < point.X)
                tilePtr = tilePtr->tr;
            else
                tilePtr = tilePtr->bl;
        }
        tilePtr->displayTile();
    }
    return tilePtr;
}
#endif