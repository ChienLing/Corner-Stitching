#ifndef _CUTTB_H_
#define _CUTTB_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "classTile.h"
tile* cutTB(tile* target, std::pair<long long,long long> point)
{
    tile* findPtr(NULL);
	
    if (target->RT.Y == point.Y)
    {
        findPtr = target;
        //target = NULL;
        return findPtr;
    }
    else if ( target->LB.Y == point.Y)
        return NULL;
    
    tile* cut_target = new tile;
	if (target->tr)
		findPtr = target->tr;	
    while (findPtr && findPtr->LB.Y >= point.Y)
        findPtr = findPtr->lb;
    
    cut_target->assignTile(target->LB.X, target->LB.Y, target->RT.X, point.Y, target, findPtr, target->lb, target->bl);
    cut_target->assignTile(target->solid);
	tile* ptr=target->tr;
	while (ptr && ptr->LB.Y >= target->LB.Y)
    {
        if (ptr->LB.Y<point.Y)
            ptr->bl = cut_target;
        ptr = ptr->lb;
    }

    ptr=target->lb;
    while ( ptr && ptr->rt == target)
    {
        ptr->rt = cut_target;
        ptr = ptr->tr;
    }

    ptr=target->bl;
    while ( ptr && ptr->RT.Y<=point.Y)
    {
        ptr->tr = cut_target;
        ptr = ptr->rt;//go up
    }
	
    /*findPtr = target->bl;
    while (findPtr && findPtr->RT.Y <= point.Y)
        findPtr = findPtr->rt;*/
    
    target->assignTile(target->LB.X, point.Y, target->RT.X, target->RT.Y, target->rt, target->tr, cut_target, ptr);
    return cut_target;
} 
#endif