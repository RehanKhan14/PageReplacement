#pragma once
#include <iostream>
using namespace std;

#include "../linkedList.hpp"

class LRU{
public:
    LRU();
    bool executeLRU(vector<int>, int);
    void setFrames(int);
    int getHits();
    int getFaults();
private:
    int frames,hits,faults;
    // int hits;
    // int

};
LRU::LRU(){
    this->frames=3;//default
    hits=0;
    faults=0;
}
void LRU::setFrames(int frames){
    this->frames=frames;
}
int LRU::getHits(){
    return hits;
}
int LRU::getFaults(){
    return faults;
}

bool LRU::executeLRU(vector<int>proc, int frames){
    linkedList exec(frames);
    cout<<"\nLeast Recently Used Page Replacement Algorithm\n";
    cout<<"Data printed from least recently used to most recently used\n";
    
    for(int i=0;i<proc.size();i++){
        int currProc=proc[i];
        if(exec.search(currProc)){
            // exec.deleteSpecific(currProc);
            exec.foundLRU(currProc);
            // exec.deleteSpecific(currProc);
            // exec.append(currProc);
            hits++;
            cout<<"Hit:\t";
            // cout<<i<<"Proc: "<<currProc<<" Hits: "<<hits<<endl;
        }
        else{
            exec.append(currProc);
            faults++;
            cout<<"Fault:\t";
            // cout<<i<<"Proc: "<<currProc<<" Fault: "<<faults<<endl;
        }
        exec.print();
    }
}