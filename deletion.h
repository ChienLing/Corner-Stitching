#ifndef _DELETION_H_
#define _DELETION_H_
#define X first
#define Y second
#include <bits/stdc++.h>
#include "PointFind.h"
#include "mergeTile.h"
#include "NeighborFind.h"
#include "cutTB.h"
bool deletion(tile* &startTile, std::pair<long long,long long> LB, std::pair<long long,long long> RT)
{
    extern int n;
    extern long long newNum;
    extern tile* Tile0;
    //tile startTile = *StartTile;
    tile* delTile = PointFind(startTile,RT);
    if (!delTile)           return false;
    if (!delTile->solid)    return false;
    if (delTile->RT != RT || delTile->LB != LB)     return false;
    if (delTile->rt)
        startTile = delTile->rt;
    else if (delTile->tr)
        startTile = delTile->tr;
    else
        startTile = delTile;
    
    delTile->assignTile(false);

    vector<tile*> rightTile;
    tile *tilePtr(NULL);

////////////merge right side

    tile* cutTileL1(NULL), *cutTileL2(NULL);
    tile* cutTileR1(NULL), *cutTileR2(NULL);
    tile* rightSideTile(NULL);
    rightSideTile = delTile->tr;
    ///////////////check right side Tile have same top bound with delTile
    if (rightSideTile && !rightSideTile->solid)
    {
        if (delTile->RT.Y < rightSideTile->RT.Y)
        tile* temTile = cutTB(rightSideTile, delTile->RT);
    }
    else if (rightSideTile && rightSideTile->solid)//equal to else if (rightSideTile)
    {
        if (rightSideTile->LB.Y > delTile->LB.Y)
        {
            while (rightSideTile->lb->solid && rightSideTile->LB.Y >= delTile->LB.Y)//while (rightSideTile->lb->solid && rightSideTile->LB.Y > delTile->LB.Y)
                rightSideTile = rightSideTile->lb;

            if (rightSideTile->LB.Y > delTile->LB.Y)
                 delTile = cutTB(delTile, rightSideTile->LB);
            else //rightSideTile->LB.Y <= delTile->LB.Y
                delTile = NULL;
        }
        else //rightSideTile->LB.Y <= delTile->LB.Y
            delTile = NULL;
    }
    rightTile = NeighborFind(delTile);

    for (int idx=0; idx<rightTile.size(); idx++)
    {
        cutTileL1 = NULL;   cutTileL2 = NULL;  cutTileR1 = NULL;   cutTileR2 = NULL;  rightSideTile = NULL;
        rightSideTile = rightTile[idx];
        if (rightSideTile->LB.Y > delTile->LB.Y)
        {
            tile* temTile(NULL);
            temTile = cutTB(delTile, rightSideTile->LB);
            newNum++;
            if (delTile && !rightSideTile->solid && delTile->RT.Y == rightSideTile->RT.Y && delTile->LB.Y == rightSideTile->LB.Y)
                mergeTile(rightSideTile, delTile);;
            delTile = temTile;
        }
        else if ((rightSideTile->LB.Y < delTile->LB.Y))
        {
            if (!rightSideTile->solid)
            {
                tile* temTile(NULL);
                temTile = cutTB(rightSideTile, delTile->LB);
                newNum++;
                if (delTile )//&& !rightSideTile->solid && delTile->RT.Y == rightSideTile->RT.Y && delTile->LB.Y == rightSideTile->LB.Y
                    mergeTile(rightSideTile,delTile);
                delTile = rightSideTile;//now delTile means the bottom of delete area. So it dont need to point bpttom Tile
                //temTile = delTile->rt;
            }    
        }
        else// (rightSideTile->LB.Y == delTile->LB.Y)
        {
            if (!rightSideTile->solid)
                mergeTile(rightSideTile,delTile),delTile = rightSideTile;//now delTile means the bottom of delete area. So it dont need to point bpttpm Tile
        }
    }

///////////merge left side
    tile* leftTile(NULL);
    tile* bottomTile = PointFind(startTile,LB);
    if (bottomTile->RT.X == LB.X)
    {
        bottomTile = bottomTile->tr;
        while (bottomTile->LB.Y > LB.Y)
            bottomTile = bottomTile->lb;
    }
    
    if (bottomTile->RT.Y == LB.Y)
    {
        bottomTile = bottomTile->rt;
        while (bottomTile->LB.X >= RT.X)
            bottomTile = bottomTile->bl;
    }
    delTile = bottomTile;

    while (delTile && delTile->RT.Y <= RT.Y)
    {
        tile* cutTileR1(NULL);      tile* cutTileR2(NULL);
        tile* cutTileL1(NULL);      tile* cutTileL2(NULL);
        leftTile = delTile->bl;
        
        if (leftTile && leftTile->solid)
        {
            if (leftTile->RT.Y >= delTile->RT.Y && leftTile->LB.Y <= delTile->LB.Y)
            {
                delTile = delTile->rt;
                while (delTile && delTile->LB.X >=RT.X)////////////////////////
                    delTile = delTile->bl;
            }
            else if (delTile->RT.Y > leftTile->RT.Y)
                cutTileR1 = cutTB(delTile, leftTile->RT),newNum++;
        }
        else if (leftTile)//leftTile = space Tile
        {
            if (leftTile->LB.Y < delTile->LB.Y)
            {
                if (leftTile->RT.Y < delTile->RT.Y)
                {
                    cutTileL1 = cutTB(leftTile, delTile->LB),newNum++;
                    cutTileR1 = cutTB(delTile, leftTile->RT),newNum++;
                    mergeTile(cutTileR1, leftTile);
                    leftTile = NULL;
                    //dont change delTile!!
                }
                else if (leftTile->RT.Y == delTile->RT.Y)
                {
                    cutTileL1 = cutTB(leftTile,delTile->LB),newNum++;
                    mergeTile(delTile, leftTile);
                    leftTile = NULL;
                    delTile = delTile->rt;
                    while(delTile && delTile->LB.X >= RT.X)
                        delTile = delTile->bl;
                }
                else//leftTile->RT.Y > delTile->RT.Y
                {
                    cutTileL1 = cutTB(leftTile, delTile->RT),newNum++;
                    cutTileL2 = cutTB(cutTileL1, delTile->LB),newNum++;
                    mergeTile(delTile, cutTileL1);
                    cutTileL1 = NULL;
                    delTile = delTile->rt;
                    while(delTile && delTile->LB.X >= RT.X)
                        delTile = delTile->bl;
                }
            }
            else//leftTile->LB.Y == delTile->LB.Y
            {
                if (leftTile->LB.Y > delTile->LB.Y)
                    cout<<"deletion 172 error\n";
                if (leftTile->RT.Y < delTile->RT.Y)
                {
                    cutTileR1 = cutTB(delTile,leftTile->RT),newNum++;
                    mergeTile(cutTileR1, leftTile);
                    leftTile = NULL;
                    //dont change delTile!!
                }
                else if (leftTile->RT.Y == delTile->RT.Y)
                {
                    mergeTile(delTile, leftTile);
                    leftTile = NULL;
                    delTile = delTile->rt;
                    while (delTile && delTile->LB.X >= RT.X)
                        delTile = delTile->bl;
                }
                else//leftTile->RT.Y > delTile->RT.Y
                {
                    cutTileL1 = cutTB(leftTile, delTile->RT),newNum++;
                    mergeTile(delTile, cutTileL1);
                    cutTileL1 = NULL;
                    delTile = delTile->rt;
                    while (delTile && delTile->LB.X >= RT.X)
                        delTile = delTile->bl;
                }
            }
        }
        else
        {
            delTile = delTile->rt;
            while (delTile && delTile->LB.X >=RT.X)
                delTile = delTile->bl;
        }
    }
    bottomTile = PointFind(startTile,LB);
    if (bottomTile->RT.X == LB.X)
    {
        bottomTile = bottomTile->tr;
        while (bottomTile->LB.Y > LB.Y)
            bottomTile = bottomTile->lb;
    }
    
    if (bottomTile->RT.Y == LB.Y)
    {
        bottomTile = bottomTile->rt;
        while (bottomTile->LB.X >= RT.X)
            bottomTile = bottomTile->bl;
    }
    if (bottomTile && bottomTile->lb && !bottomTile->lb->solid && bottomTile->LB.X == bottomTile->lb->LB.X && bottomTile->RT.X == bottomTile->lb->RT.X)
        mergeTile(bottomTile, bottomTile->lb);
    tile* topTile = PointFind(startTile,RT);
    //
    if (topTile && topTile->rt && !topTile->rt->solid && topTile->LB.X == topTile->rt->LB.X && topTile->RT.X == topTile->rt->RT.X)
    {
        // startTile = topTile->rt;
        mergeTile(topTile->rt, topTile);
    }
    // else
        // startTile = topTile;
    return true;
}
#endif