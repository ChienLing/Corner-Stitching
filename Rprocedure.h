#ifndef _RPROVEDURE_H_
#define _RPROCEDURE_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "classTile.h"
void Rprocedure(tile* startTile, vector<tile*> & List, std::pair<long long, long long> areaLB, std::pair<long long, long long> areaRT, bool bottom){
    //if (startTile->enu == true)
        //cout<<"repeat enumerate\n";
    List.push_back(startTile);
    startTile->enu = true;
    if (startTile->LB.X < areaRT.X && !bottom){
        vector<tile*> Neighbor = NeighborFind(startTile);
        for (int i=0; i<Neighbor.size(); i++){
            if (Neighbor[i]->bl == startTile)
                Rprocedure(Neighbor[i], List, areaLB, areaRT, bottom);
        }
    }
    else if (startTile->LB.X < areaRT.X && bottom){
        vector<tile*> Neighbor = NeighborFind(startTile);
        for (int i=0; i<Neighbor.size(); i++){
            if (Neighbor[i]->bl == startTile)
            {
                if (Neighbor[i]->LB.Y == startTile->LB.Y)
                    Rprocedure(Neighbor[i], List, areaLB, areaRT, bottom);
                else
                    Rprocedure(Neighbor[i], List, areaLB, areaRT, !bottom);

            }
            else if (Neighbor[i]->RT.Y > areaLB.Y)
                Rprocedure(Neighbor[i], List, areaLB, areaRT, bottom);
        }
    }
    return;
}
#endif