#include <bits/stdc++.h>
#include "classTile.h"
#include "PointFind.h"
#include "NeighborFind.h"
#include "areaSearch.h"
#include "Enumeration.h"
#include "Creation.h"
#include "corner.h"
#include "deletion.h"
#include "mergeTile.h"
#define X first
#define Y second
// #define int ll
// typedef long long ll;
int n(-1);
int i;
int CreationNum(0);
long long newNum(0);
long long IdealArea(0);
long long Area(0);
long long IdealTotalArea(0);
long long TotalArea(0);
long long min(long long, long long, long long, long long);
long long max(long long, long long, long long, long long);
int32_t main(int32_t argc, char* argv[])
{
    time_t start,end;
    start = time(NULL);
    if (argc<2) {
        cout<<"input format: ./main.exe InputFileName \n";
        exit(1);
    }
    string inputFileName(argv[1]);  size_t found = inputFileName.find(".");    inputFileName.erase(found,4);
    string GDToutput=inputFileName+".gdt";
    string output=inputFileName+"_output.txt";
    fstream output1, input, output2;
    vector<corner> InputData;
    // input.open("chip.txt", ios::in);//RSA chip
    // output1.open("Case_chip.txt",ios::out|ios::trunc);
    // output2.open("Case_chip.gdt",ios::out|ios::trunc);
    input.open(argv[1], ios::in);//RSA chip
    output1.open(output,ios::out|ios::trunc);
    output2.open(GDToutput,ios::out|ios::trunc);
    if(!output1)     //test if file opened
    { cerr << "Can't open CornerStitchTest_output.txt!\n";
            exit(1);     //if unusual, close it 
    }
    if(!output2)     //test if file opened
    { cerr << "Can't open CornerStitchTest.gdt!\n";
            exit(1);     //if unusual, close it 
    }
    if (!input)
    {
        cerr << "Can't open RSA1.txt!\n";
        exit(1);
    }
    // output1<<"gds2{600\nm=2018-09-14 14:26:15 a=2018-09-14 14:26:15\nlib 'asap7sc7p5t_24_SL' 0.00025 2.5e-10\ncell{c=2018-09-14 14:26:15 m=2018-09-14 14:26:15 'AND2x2_ASAP7_75t_SL'\n";
    output2<<"gds2{600\nm=2018-09-14 14:26:15 a=2018-09-14 14:26:15\nlib 'asap7sc7p5t_24_SL' 0.00025 2.5e-10\ncell{c=2018-09-14 14:26:15 m=2018-09-14 14:26:15 'AND2x2_ASAP7_75t_SL'\n";

    std::pair<long long,long long> point1, point2, point3, point4;
    corner temCorner;
    tile* Tile0 = new tile;
    string S;
    long long Tile0MaxX(0), Tile0MaxY(0), Tile0MinX(1e7), Tile0MinY(1e7);
    while (getline(input,S))//input>>point1.X>>point1.Y>>point2.X>>point2.Y>>point3.X>>point3.Y>>point4.X>>point4.Y
    {
        if (S[0] == '#')
            continue;
        stringstream SS(S);
        long long minX, minY;
        long long maxX, maxY;
        SS>>point1.X>>point1.Y>>point2.X>>point2.Y>>point3.X>>point3.Y>>point4.X>>point4.Y;
        minX = min(point1.X, point2.X, point3.X, point4.X);
        maxX = max(point1.X, point2.X, point3.X, point4.X);
        minY = min(point1.Y, point2.Y, point3.Y, point4.Y);
        maxY = max(point1.Y, point2.Y, point3.Y, point4.Y);
        if (maxX > 2e8 || maxY >2e8)
            system("pause"),std::cout<<"error\n";
        if (Tile0MaxX < maxX)
            Tile0MaxX = maxX;
        if (Tile0MaxY < maxY)
            Tile0MaxY = maxY;
        if (Tile0MinX > minX)
            Tile0MinX = minX;
        if (Tile0MinY > minY)
            Tile0MinY = minY;
        temCorner.LB.X = minX;
        temCorner.LB.Y = minY;
        temCorner.RT.X = maxX;
        temCorner.RT.Y = maxY;
        InputData.push_back(temCorner);
    }
    end = time(NULL);
    cout<<"read file time: "<<difftime(end,start)<<endl;
    cout<<"input size: "<<InputData.size()<<endl;
    Tile0->assignTile(Tile0MinX,Tile0MinY,Tile0MaxX,Tile0MaxY,NULL, NULL, NULL, NULL);

    for (i=0; i<InputData.size(); i++)
        creation(Tile0,InputData[i].LB,InputData[i].RT);
    output1<<"Creation Number: "<<CreationNum<<endl;
    start = time(NULL);
    cout<<"Creation time: "<<difftime(start,end)<<endl;
    output1<<"Creation time: "<<difftime(start,end)<<endl;
    vector<tile*> allTile = Enumeration(Tile0,{Tile0MinX,Tile0MinY},{Tile0MaxX,Tile0MaxY});
    for (int i=0; i<allTile.size(); i++){
        TotalArea += ((unsigned long long)allTile[i]->RT.X-(unsigned long long)allTile[i]->LB.X)*((unsigned long long)allTile[i]->RT.Y-(unsigned long long)allTile[i]->LB.Y);
        if (allTile[i]->solid)
        {
            Area += ((unsigned long long)allTile[i]->RT.X-(unsigned long long)allTile[i]->LB.X)*((unsigned long long)allTile[i]->RT.Y-(unsigned long long)allTile[i]->LB.Y);
            output2<<"b{2 xy("<<allTile[i]->LB.X/100.0<<" "<<allTile[i]->RT.Y/100.0<<" "<<allTile[i]->LB.X/100.0<<" "<<allTile[i]->LB.Y/100.0<<" "<<allTile[i]->RT.X/100.0<<" "<<allTile[i]->LB.Y/100.0<<" "<<allTile[i]->RT.X/100.0<<" "<<allTile[i]->RT.Y/100.0<<")}\n";
        }
        else
            output2<<"b{1 xy("<<allTile[i]->LB.X/100.0<<" "<<allTile[i]->RT.Y/100.0<<" "<<allTile[i]->LB.X/100.0<<" "<<allTile[i]->LB.Y/100.0<<" "<<allTile[i]->RT.X/100.0<<" "<<allTile[i]->LB.Y/100.0<<" "<<allTile[i]->RT.X/100.0<<" "<<allTile[i]->RT.Y/100.0<<")}\n";
    }
    start = time(NULL);
    for (n=0; n<InputData.size(); n++)//1InputData.size()
        deletion(Tile0,InputData[n].LB,InputData[n].RT);
    end = time(NULL);
    cout<<"Deletion time: "<<difftime(end,start)<<endl;
    output1<<"Deletion time: "<<difftime(end,start)<<endl;
    cout<<"new Number: "<<newNum<<endl;
    vector<tile*> remainingTile = Enumeration(Tile0,{Tile0MinX,Tile0MinY},{Tile0MaxX,Tile0MaxY});
    
    //cout<<"all Tile Number: "<<allTile.size()<<"\n";
    cout<<"remaining Tile Number: "<<remainingTile.size()<<"\n";
    // for (int i=0; i<remainingTile.size(); i++){
    //     if (remainingTile[i]->solid)
    //         output2<<"b{2 xy("<<remainingTile[i]->LB.X/100.0<<" "<<remainingTile[i]->RT.Y/100.0<<" "<<remainingTile[i]->LB.X/100.0<<" "<<remainingTile[i]->LB.Y/100.0<<" "<<remainingTile[i]->RT.X/100.0<<" "<<remainingTile[i]->LB.Y/100.0<<" "<<remainingTile[i]->RT.X/100.0<<" "<<remainingTile[i]->RT.Y/100.0<<")}\n";
    //     else
    //         output2<<"b{1 xy("<<remainingTile[i]->LB.X/100.0<<" "<<remainingTile[i]->RT.Y/100.0<<" "<<remainingTile[i]->LB.X/100.0<<" "<<remainingTile[i]->LB.Y/100.0<<" "<<remainingTile[i]->RT.X/100.0<<" "<<remainingTile[i]->LB.Y/100.0<<" "<<remainingTile[i]->RT.X/100.0<<" "<<remainingTile[i]->RT.Y/100.0<<")}\n";
    // }
    output2<<"}\n}";        // output1<<"}\n}";
    IdealTotalArea = 1LL*(Tile0MaxY-Tile0MinY)*(Tile0MaxX-Tile0MinX);

    cout<<"LB: ("<<Tile0MinX<<","<<Tile0MinY<<") , RT: ("<<Tile0MaxX<<","<<Tile0MaxY<<")\n";
    cout<<"Ideal Area: "<<IdealArea<<"\nFinal Area: "<<Area<<endl;
    cout<<"Ideal Total Area: "<<IdealTotalArea<<"\nFinal Total Area: "<<TotalArea<<endl;
    output1<<"Ideal Area: "<<IdealArea<<"\nFinal Area: "<<Area<<endl;
    output1<<"Ideal Total Area: "<<IdealTotalArea<<"\nFinal Total Area: "<<TotalArea<<endl;
    output2.close();        output1.close();

    return 0;
}
long long min(long long n1, long long n2, long long n3, long long n4)
{
    long long t1, t2;
    t1 = std::min(n1, n2);
    t2 = std::min(n3, n4);
    return std::min(t1, t2);
}
long long max(long long n1, long long n2, long long n3, long long n4)
{
    long long t1, t2;
    t1 = std::max(n1, n2);
    t2 = std::max(n3, n4);
    return std::max(t1, t2);
}
