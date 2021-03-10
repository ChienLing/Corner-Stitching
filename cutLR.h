#ifndef _CUTLR_H_
#define _CUTLR_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "classTile.h"
tile* cutLR(tile* target, std::pair<long long,long long> point)
{
    tile* findPtr(NULL);
	
    if (target->LB.X == point.X )
        return NULL;
    
    else if (target->RT.X == point.X)
    {
        findPtr = target;
        return findPtr;
    }

    tile *cut_target = new tile;
    if (target->rt)//findPtr != NULL && 
        findPtr = target->rt;
    while (findPtr && findPtr->LB.X >= point.X)
        findPtr = findPtr->bl;
	
    cut_target->assignTile(target->LB.X, target->LB.Y, point.X, target->RT.Y, findPtr, target, target->lb, target->bl);
    cut_target->assignTile(target->solid);
    tile* ptr=target->rt;
    while ( ptr !=NULL && ptr->LB.X >= target->LB.X)
    {
        if (ptr->LB.X<point.X)
            ptr->lb = cut_target;
        ptr = ptr->bl;
    }

    ptr=target->lb;
    while ( ptr !=NULL && ptr->RT.X<=point.X)
    {
        ptr->rt = cut_target;
        ptr = ptr->tr;
    }

    ptr=target->bl;
 
    while ( ptr!= NULL && ptr->RT.Y<=target->RT.Y)// 
    {
        ptr->tr = cut_target;
        ptr = ptr->rt;//go up
    }

    findPtr = target->lb;
    while (findPtr && findPtr->RT.X <= point.X)
        findPtr = findPtr->tr;
    
    target->assignTile(point.X, target->LB.Y, target->RT.X, target->RT.Y, target->rt, target->tr, findPtr, cut_target);

    return cut_target;//return left tile
} 
#endif