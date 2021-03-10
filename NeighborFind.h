#ifndef _NEIGHBORFIND_H_
#define _NEIGHBORFIND_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "classTile.h"
//using namespace std;
vector<tile*> NeighborFind(tile* startTile)
{
    extern int n;
    tile *tracePtr;
    vector<tile*> Neighborhood;
    if (!startTile)
        return Neighborhood;
    else if (startTile->tr)
        tracePtr = startTile->tr;
    else
        return Neighborhood;
    
    std::pair<long long,long long> Tile_rt, Tile_lb;
    Tile_rt = startTile->RT;
    Tile_lb = startTile->LB;
    while (tracePtr && tracePtr->LB.Y > Tile_lb.Y)
    {
        Neighborhood.push_back(tracePtr);
        if (tracePtr->lb)
            tracePtr = tracePtr->lb;
        else
            break;
    }
    Neighborhood.push_back(tracePtr);
    return Neighborhood;
}
#endif