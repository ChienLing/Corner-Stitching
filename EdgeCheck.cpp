#include<bits/stdc++.h>
/*class tile
{

};*/
using namespace std;

int main(int argc, char* argv[])//char* argv[] : input file name char* argv[0] = mainfile name
{
    if(argc < 2) return 0;
    string fileName;
    fileName = argv[1]; 
    ifstream input(fileName,ios_base::in);
    for (int i=0; i<8; i++)
    {
        input.ignore(1024,'\n');
    }
    string S;
    pair<int,int> LB,LT,RB,RT;
    int count(0);
    /**/while (input>>LB.first>>LB.second>>LT.first>>LT.second>>RT.first>>RT.second>>RB.first>>RB.second)
    {
        //input>>LB.first>>LB.second>>LT.first>>LT.second>>RT.first>>RT.second>>RB.first>>RB.second;
        cout<<LB.first<<LB.second<<LT.first<<LT.second<<RT.first<<RT.second<<RB.first<<RB.second<<endl;
        if (LB.first != LT.first)
        {
            cout<<"Num "<<count<<" left edge error\n";
            break;
        }
        else if (LB.second != RB.second)
        {
            cout<<"Num "<<count<<" bottom edge error\n";
            break;
        }
        else if (LT.second != RT.second)
        {
            cout<<"Num "<<count<<" top edge error";
            break;
        }
        else if (RT.first != RB.first)
        {
            cout<<"Num "<<count<<" right edge error";
            break;
        }
        count++;
    }
    input.close();
    return 0;
}
