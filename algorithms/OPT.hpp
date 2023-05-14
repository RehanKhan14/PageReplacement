#pragma once
#include <iostream>
using namespace std;

#include "../linkedList.hpp"

class OPT{
public:
    OPT();
    bool executeOPT(vector<int>, int);
    void setFrames(int);
    int getHits();
    int getFaults();
private:
    int frames,hits,faults;
    // int hits;
    // int

};
OPT::OPT(){
    this->frames=3;//default
    hits=0;
    faults=0;
}
void OPT::setFrames(int frames){
    this->frames=frames;
}
int OPT::getHits(){
    return hits;
}
int OPT::getFaults(){
    return faults;
}

bool OPT::executeOPT(vector<int>proc, int frames){
    linkedList exec(frames);
    cout<<"\nOptimal Page Replacement Algorithm\n";
    for(int i=0;i<proc.size();i++){
        int currProc=proc[i];
        if(exec.search(currProc)){
            // exec.deleteSpecific(currProc);
            //exec.foundLRU(currProc);
            // exec.deleteSpecific(currProc);
            // exec.append(currProc);
            hits++;
            cout<<"Hit:\t";
            // cout<<i<<" Proc: "<<currProc<<" Hits: "<<hits<<endl;
        }
        else{
            //exec.append(currProc);
            exec.search_v(proc,i,currProc);	//this will search for future pages and then order the list according to that.
            faults++;
            cout<<"Fault:\t";
            // cout<<i<<" Proc: "<<currProc<<" Fault: "<<faults<<endl;
        }
        exec.print();
    }
}
