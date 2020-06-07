//
//  main.cpp
//  Parallel_Line_Segments
//
//  Created by Yash Arora on 07/06/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

int getCuttingYLineSegments(vector<std::pair<int,int>> &lines )
{
    int Ylines;
    
    int len = lines.size();
    set<pair<int,int>> range;
    //sort(lines.begin(),lines.end());
    vector<int> distance;
  
    for(int i=0;i<len;i++)
    {
        if(range.count(lines[i])==0)
        {
            bool isSubSet=false;
            for (auto x = range.begin(); x != range.end(); )
            {
                int linea=lines[i].first;
                int lineb =lines[i].second;
                int xa = x->first;
                int xb = x->second;
                if(( linea >= xa && linea <= xb) || (lineb <= xb && lineb >= xa ))
                {
                    isSubSet = true;
                    range.erase(x);
                    range.insert(make_pair(max(linea,xa),min(lineb,xb)));
                    break;
                }
                ++x;
            }
            if(!isSubSet)
                range.insert(lines[i]);
        }
    }
    
    return range.size();
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //vector<std::pair<int,int>> Xlines { {2, 12}, {4 ,10}, {3, 7}, {5, 13} , {0,1}};
    vector<std::pair<int,int>> Xlines { {4,9},{5,9},{8,13},{24,29},{100,200}, {4,5},{7,8}};
    int Ylines = getCuttingYLineSegments(Xlines);
    
    cout<<Ylines<<endl;

    return 0;
}
