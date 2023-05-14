#pragma once
#include <iostream>
#include <vector>

#include "../linkedList.hpp"
using namespace std;

class FIFO{
public:
    FIFO();
    bool executeFIFO(vector<int>, int);
    void setFrames(int);
    int getHits();
    int getFaults();
    bool find(int [],int);
    void print(int []);
private:
    int frames,hits,faults;
    
    // int hits;
    // int

};
FIFO::FIFO(){
    this->frames=3;//default
    hits=0;
    faults=0;
}
void FIFO::setFrames(int frames){
    this->frames=frames;
}
int FIFO::getHits(){
    return hits;
}
int FIFO::getFaults(){
    return faults;
}

bool FIFO::executeFIFO(vector<int> proc, int frames){
    if(frames<=0){
        cout<<"Error: Invalid Number Of Frames\n";
        return false;
    }
    cout<<"\nFirst In First Out Page Replacement Algorithm\n";
    this->frames=frames;
    int oldest=0;
    int arr[frames];
    for(int i=0;i<frames;i++){
        arr[i]=-1;
    }
    int k=0;
    for(int i=0;i<proc.size();i++){
        int currProc=proc[i];
        if(find(arr,currProc)){
            hits++;
            cout<<"Hit:\t";
        }
        else{
            arr[k]=currProc;
            k=(k+1)%3;
            faults++;
            cout<<"Fault:\t";
        }
        print(arr);
    }
    // linkedList exec(frames);

    // for(int i=0;i<proc.size();i++){
    //     int currProc=proc[i];
    //     //searching
    //     if(exec.search(currProc)){
    //         hits++;
    //         cout<<"Proc: "<<currProc<<"HIT: "<<hits<<endl;
    //     }
    //     else{
    //         //it will automatically delete if frame limit reached
    //         exec.append(currProc);
    //         faults++;
    //         cout<<"Proc: "<<currProc<<"Fault: "<<faults<<endl;
    //     }
    // }
    // return true; 
}

bool FIFO::find(int arr[],int val){
    for(int i=0;i<frames;i++){
        if(arr[i]==val){
            return true;
        }
    }
    return false;
}

void FIFO::print(int arr[]){
    cout<<"{";
    for(int i=0;i<frames;i++){
        if(arr[i]!=-1){
            cout<<" "<<arr[i];
        }
    }
    cout<<" }\n";
}
