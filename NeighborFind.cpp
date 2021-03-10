#ifndef _NEIGHBORFIND_H_
#define _NEIGHBORFIND_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "classTile.h"
//using namespace std;
vector<tile*> NeighborFind(tile* startTile)
{
    
    tile *tracePtr;
    vector<tile*> Neighborhood;
    if (startTile->tr)
        tracePtr = startTile->tr;
    else
        return Neighborhood;
    
    std::pair<long long,long long> Tile_rt, Tile_lb;
    Tile_rt = startTile->RT;
    Tile_lb = startTile->LB;
    //Neighborhood.push_back(tracePtr);
    while(tracePtr->LB.Y > Tile_lb.Y)
    {
        //std::cout<<"tracePtr->LB.Y: "<<tracePtr->LB.Y<<" Tile_lb.Y: "<<Tile_lb.Y<<std::endl;
        std::cout<<"neighborFind: ";tracePtr->displayTile();
        Neighborhood.push_back(tracePtr);
        if (tracePtr->lb)
            tracePtr = tracePtr->lb;
        else
            break;
        //std::cout<<"tracePtr->LB.Y: "<<tracePtr->LB.Y<<" Tile_lb.Y: "<<Tile_lb.Y<<std::endl;
    }
    std::cout<<"neighborFind: ";tracePtr->displayTile();
    Neighborhood.push_back(tracePtr);
    return Neighborhood;
}
#endif