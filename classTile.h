#ifndef _CLASSTILE_H_
#define _CLASSTILE_H_
#define X first
#define Y second
#include <bits/stdc++.h>
using namespace std;
class tile
{
    //private:
    public:
        bool solid;
        bool enu;
        std::pair<long long,long long> RT,LB;
        tile *rt, *tr, *lb, *bl;
        tile();

        void assignTile(tile*);
        void assignTile(tile);
        void assignTile(bool solidType);
        void assignTile(long long LBx, long long LBy, long long RTx, long long RTy);
        void assignTile(tile *rt_ptr, tile *tr_ptr, tile *lb_ptr, tile *bl_ptr );
        void assignTile(long long LBx, long long LBy, long long RTx, long long RTy,  tile *rt_ptr, tile *tr_ptr, tile *lb_ptr , tile *bl_ptr);
        void displayTile();
        void displayNearTile();
};

tile::tile(): solid(0), enu(0), rt(NULL), tr(NULL), bl(NULL), lb(NULL)
{
    LB.first  = 0;
    LB.second = 0;
    RT.first  = 0;
    RT.second = 0;
}

void tile::assignTile(tile newTile)
{
    RT.X = newTile.RT.X;
    RT.Y = newTile.RT.Y;
    LB.X = newTile.LB.X;
    LB.Y = newTile.LB.Y;
    rt = newTile.rt;
    tr = newTile.tr;
    lb = newTile.lb;
    bl = newTile.bl;
}

void tile::assignTile(tile* newTile)
{
    RT.X = newTile->RT.X;
    RT.Y = newTile->RT.Y;
    LB.X = newTile->LB.X;
    LB.Y = newTile->LB.Y;
    rt = newTile->rt;
    tr = newTile->tr;
    lb = newTile->lb;
    bl = newTile->bl;
}

void tile::assignTile(bool solidType)
{
    solid = solidType;
}

void tile::assignTile(long long LBx, long long LBy, long long RTx, long long RTy)
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

void tile::assignTile(long long LBx, long long LBy, long long RTx, long long RTy, tile *rt_ptr, tile *tr_ptr, tile *lb_ptr, tile *bl_ptr)
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
        std::cout<<"rt tile: ",rt->displayTile();
    if (tr)
        std::cout<<"tr tile: ",tr->displayTile();
    if (lb)
        std::cout<<"lb tile: ",lb->displayTile();
    if (bl)
        std::cout<<"bl tile: ",bl->displayTile();
}
#endif