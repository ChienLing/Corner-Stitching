#ifndef _RPROVEDURE_H_
#define _RPROCEDURE_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "classTile.h"
void Rprocedure(tile* startTile, vector<tile*> & List, std::pair<int, int> areaLB, std::pair<int, int> areaRT, bool bottom)
{
    std::cout<<"R procesure List push back: ";startTile->displayTile();
    List.push_back(startTile);
    if (startTile->RT.X < areaRT.X && bottom == 0)
    {
        vector<tile*> Neighbor = NeighborFind(startTile);
        for (int i=0; i<Neighbor.size(); i++)
        {
            //if (Neighbor[i]->LB.Y >= startTile->LB.Y)
            if (Neighbor[i]->bl == startTile)
                Rprocedure(Neighbor[i], List, areaLB, areaRT, bottom);
        }
    }
    else if (startTile->RT.X < areaRT.X && bottom == 1)
    {
        std::cout<<"bottom\n";
        vector<tile*> Neighbor = NeighborFind(startTile);
        for (int i=0; i<Neighbor.size(); i++)
        {
            cout<<"Neighbor high : "<<Neighbor[i]->RT.Y<<" area bottom: "<<areaLB.Y<<endl;
            //if (Neighbor[i]->LB.Y >= startTile->LB.Y)
            if (Neighbor[i]->bl == startTile)
                Rprocedure(Neighbor[i], List, areaLB, areaRT, bottom);
            else if (Neighbor[i]->RT.Y > areaLB.Y)
            {
                cout<<"Add bottom\n";
                Rprocedure(Neighbor[i], List, areaLB, areaRT, bottom);
            }
        }
    }
    return;
}
#endif