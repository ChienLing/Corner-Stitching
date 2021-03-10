#ifndef _CORNER_H_
#define _CORNER_H_
struct corner
{
    std::pair<long long,long long> RT;
    std::pair<long long,long long> LB;
    bool operator < (const corner& tem) const
    {
        return RT.Y < tem.RT.Y || RT.X < tem.RT.X;
    }
    bool operator > (const corner& tem) const
    {
        return RT.Y > tem.RT.Y || RT.X > tem.RT.X;
    }
};
#endif