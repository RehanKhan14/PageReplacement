#pragma once
#include "../circularList.hpp"
// using namespace std;

class SCD{
public:
    SCD();
    bool executeSCD(vector<int>, int);
    void setFrames(int);
    int getHits();
    int getFaults();
private:
    int frames,hits,faults;
    // int hits;
    // int

};
SCD::SCD(){
    this->frames=3;//default
    hits=0;
    faults=0;
}
void SCD::setFrames(int frames){
    this->frames=frames;
}
int SCD::getHits(){
    return hits;
}
int SCD::getFaults(){
    return faults;
}

bool SCD::executeSCD(vector<int>proc, int frames){
    this->frames=frames;
    circularList exec(frames);
    // circularList exec(frames);
    cout<<endl;
    cout<<"Second Chance Page Replacement Algorithm"<<endl;
    for(int i=0;i<proc.size();i++){
        int currProc=proc[i];
        if(exec.search(currProc)){
            // exec.deleteSpecific(currProc);
            //exec.foundLRU(currProc);
            // exec.deleteSpecific(currProc);
            exec.append(currProc);
           // exec.update(currProc);
            hits++;
            cout<<"Hits:\t";
        }
        else{
            // cout<<i;
            exec.append(currProc);
            //exec.search_v(proc,i,currProc);	//this will search for future pages and then order the circularList according to that.
           // exec.update(currProc);
            faults++;
            cout<<"Fault:\t";
        }
        exec.print();
    }
}


