//#ifndef _TILE_H_
//#define _TILE_H_
//#define F first
//#define S second
#include "classTile.h"
#include <bits/stdc++.h>
using namespace std;
/*class tile
{
    //private:
    public:
        bool solid;
        std::pair<int,int> RT,LB;
        tile *rt, *tr, *lb, *bl;
        tile();
        void assignTile(bool solidType);
        void assignTile(int LBx, int LBy, int RTx, int RTy);
        void assignTile(tile *rt_ptr, tile *tr_ptr, tile *lb_ptr, tile *bl_ptr );
        void assignTile(int LBx, int LBy, int RTx, int RTy,  tile *rt_ptr, tile *tr_ptr, tile *lb_ptr , tile *bl_ptr);
        void displayTile();
        void displayNearTile();
};*/

tile::tile(): solid(0), rt(NULL), tr(NULL), bl(NULL), lb(NULL)
{
    LB.first  = 0;
    LB.second = 0;
    RT.first  = 0;
    RT.second = 0;
}

void tile::assignTile(bool solidType)
{
    solid = solidType;
}

void tile::assignTile(int LBx, int LBy, int RTx, int RTy)
{
    RT.first  = RTx;
    RT.second = RTy;
    LB.first  = LBx;
    LB.second = LBy;
}

void tile::assignTile(tile *rt_ptr, tile *tr_ptr, tile *lb_ptr, tile *bl_ptr)
{
    rt = rt_ptr;
    tr = tr_ptr;
    bl = bl_ptr;
    lb = lb_ptr;
}

void tile::assignTile(int LBx, int LBy, int RTx, int RTy, tile *rt_ptr, tile *tr_ptr, tile *lb_ptr, tile *bl_ptr)
{
    RT.first  = RTx;
    RT.second = RTy;
    LB.first  = LBx;
    LB.second = LBy;
    rt = rt_ptr;
    tr = tr_ptr;
    bl = bl_ptr;
    lb = lb_ptr;
}

void tile::displayTile()
{
    std::cout<<"("<<LB.first<<","<<LB.second<<") , ("<<RT.first<<","<<RT.second<<")\n";
}

void tile::displayNearTile()
{
    if (rt)
        rt->displayTile();
    if (tr)
        tr->displayTile();
    if (lb)
        lb->displayTile();
    if (bl)
        bl->displayTile();
}