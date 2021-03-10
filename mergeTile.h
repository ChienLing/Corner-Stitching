#ifndef _MERGETILE_H_
#define _MERGETILE_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "classTile.h"
void mergeTile(tile* tile1, tile* tile2)
{
    extern int n;
    //if (n >= 4556)
        //std::cout<<"mergeTile debuger\n";
    //if (n != -1)
       //cout<<"debuger\n";
    if (tile1->LB.X == tile2->LB.X && tile1->RT.X == tile2->RT.X && tile1->solid == tile2->solid ) //merge bottom top tile
    {
        if (tile1->RT.Y > tile2->RT.Y)
            tile1->assignTile(tile2->LB.X, tile2->LB.Y, tile1->RT.X,tile1->RT.Y, tile1->rt, tile1->tr, tile2->lb, tile2->bl);
        else
            tile1->assignTile(tile1->LB.X, tile1->LB.Y, tile2->RT.X,tile2->RT.Y, tile2->rt, tile2->tr, tile1->lb, tile1->bl);
        
    }
    else if(tile1->LB.Y == tile2->LB.Y && tile1->RT.Y == tile2->RT.Y && tile1->solid == tile2->solid )
    {
        if (tile1->RT.X > tile2->RT.X)
            tile1->assignTile(tile2->LB.X, tile2->LB.Y, tile1->RT.X, tile1->RT.Y, tile1->rt, tile1->tr, tile2->lb, tile2->bl);
        else
            tile1->assignTile(tile1->LB.X, tile1->LB.Y, tile2->RT.X, tile2->RT.Y, tile2->rt, tile2->tr, tile1->lb, tile1->bl);
    }
    else
    {
        //std::cout<<"merge failed\n";
        return;
    }
    tile* ptr = tile2->rt;
    while(ptr && ptr->lb == tile2)
    {
        ptr->lb = tile1;
        ptr = ptr->bl;
    }
    ptr = tile2->tr;
    while(ptr && ptr->bl == tile2)
    {
        ptr->bl = tile1;
        ptr = ptr->lb;
    }
    ptr = tile2->lb;
    while(ptr && ptr->rt == tile2)
    {
        ptr->rt = tile1;
        ptr = ptr->tr;
    }
    ptr = tile2->bl;
    while(ptr && ptr->tr == tile2)
    {
        ptr->tr = tile1;
        ptr = ptr->rt;
    }
    delete tile2;
    tile2 = NULL;
    return;
}
#endif