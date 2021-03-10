#ifndef _CREATION_H_
#define _CREATION_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "classTile.h"
#include "PointFind.h"
#include "areaSearch.h"
#include "mergeTile.h"
#include "corner.h"
#include "cutTB.h"
#include "cutLR.h"
using std::cout;
// struct corner
// {
//     std::pair<int,int> RT;
//     std::pair<int,int> LB;
// };
bool creation (tile* &startTile, std::pair<long long,long long> newTile_LB, std::pair<long long,long long> newTile_RT)
{
    extern long long IdealArea;
    extern int CreationNum;
    extern int n; 
    extern int i; 
    // tile *startTile = *StartTile;
    bool tag = areaSearch(startTile, newTile_LB, newTile_RT);
    if (tag)
        return false;
    CreationNum++;
    corner Corner;
    Corner.RT = newTile_RT;
    Corner.LB = newTile_LB;
    IdealArea += 1LL*(newTile_RT.X-newTile_LB.X)*(newTile_RT.Y-newTile_LB.Y);
    tile *Found_topTile = PointFind(startTile,newTile_RT);         //std::cout<<"Found_topTile: ";Found_topTile->displayTile();/////////
    tile *cut_Found_topTile(NULL) ;
    cut_Found_topTile = cutTB(Found_topTile, newTile_RT);

    tile *Found_bottomTile = PointFind(startTile,newTile_LB); 
    tile *cut_Found_bottomTile(NULL);   

    if (Found_bottomTile->RT.X == newTile_LB.X)
    {
        Found_bottomTile = Found_bottomTile->tr;
        while (Found_bottomTile->LB.Y > newTile_LB.Y)
            Found_bottomTile = Found_bottomTile->lb;
    }
    
    if (Found_bottomTile->RT.Y == newTile_LB.Y)
    {
        Found_bottomTile = Found_bottomTile->rt;
        while (Found_bottomTile->LB.X >= newTile_RT.X)
            Found_bottomTile = Found_bottomTile->bl;
    }
    cut_Found_bottomTile = cutTB(Found_bottomTile, newTile_LB);

//////////////////////////////////cut left edge//////////////////////////////////////////

    tile *Tile(NULL), *findPtr(NULL);
    if (cut_Found_topTile != NULL)
        findPtr = cut_Found_topTile;
    else///////////////////////////////////////
        findPtr = Found_topTile;///////////////

    while(findPtr && findPtr->LB.Y >= newTile_LB.Y)
    {
        Tile = NULL;
        if (findPtr->LB.X < newTile_LB.X)
            Tile = cutLR(findPtr, newTile_LB);//return left tile 
        if (Tile && Tile->rt && Tile->LB.X == Tile->rt->LB.X && Tile->RT.X == Tile->rt->RT.X && !Tile->rt->solid)//&& Tile->rt->RT.Y <= newTile_RT.Y
        {
            tile* temTile = Tile->rt;
            mergeTile( Tile->rt, Tile);//////////////////////////////
            Tile = temTile;
        }
        findPtr = findPtr->lb;
        while (findPtr && findPtr->RT.X <= newTile_LB.X)
            findPtr = findPtr->tr;
    }
    if (Tile && Tile->lb && !Tile->solid && !Tile->lb->solid&& Tile->LB.X == Tile->lb->LB.X && Tile->RT.X == Tile->lb->RT.X )//&& Tile->rt->RT.Y <= newTile_RT.Y
        mergeTile(Tile, Tile->lb);

//////////////////////////////////cut right edge//////////////////////////////////////////
    Tile = Found_bottomTile;///////////////////
    while(Tile && Tile->RT.Y <= newTile_RT.Y)
    {
        findPtr = NULL;
        if (Tile->RT.X > newTile_RT.X)
        {
            findPtr = cutLR(Tile, newTile_RT);
            findPtr->solid = true;
            if (findPtr->lb && findPtr->lb->LB.Y >= newTile_LB.Y)///////////////////////////////
                mergeTile(findPtr, findPtr->lb);
            if (Tile->lb && Tile->LB.X == Tile->lb->LB.X && Tile->RT.X == Tile->lb->RT.X && !Tile->lb->solid)
                mergeTile(Tile, Tile->lb);
            if (Tile->rt && Tile->LB.X == Tile->rt->LB.X && Tile->RT.X == Tile->rt->RT.X && !Tile->rt->solid)//does it need?
            {
                tile* temTile = Tile->rt;/////////////
                mergeTile(Tile->rt, Tile);
                Tile = temTile;////////////
            }
            Tile = findPtr->rt;
            while (Tile && Tile->LB.X >= newTile_RT.X)//does it need?
                Tile = Tile->bl;
        }
        else//Tile->RT.X == newTile_RT.X
        {
            Tile->solid = true;
            if (Tile->lb && Tile->lb->LB.Y >= newTile_LB.Y)//avoid to merge with other solid(old solid)
                mergeTile(Tile, Tile->lb);
            Tile = Tile->rt;
            while (Tile && Tile->LB.X >= newTile_RT.X)//does it need?
                Tile = Tile->bl;
        }
    }
    Tile = PointFind(startTile, newTile_RT);
    startTile = Tile;
    Tile = Tile->tr;
    if (Tile && Tile->rt && !Tile->solid && !Tile->rt->solid && Tile->rt->RT.X == Tile->RT.X && Tile->rt->LB.X == Tile->LB.X)
    {
        tile* temTile = Tile->rt;
        mergeTile(Tile->rt,Tile);
        Tile = temTile;
    }

    return true;
}
#endif