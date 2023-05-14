#pragma once
#include <iostream>
#include<vector>
using namespace std;
class nodeCir
{
    public:
    int data;
    bool chance;
    nodeCir *next;
    //int c;
    nodeCir()
    {
        data=0;
        chance=false;
        next=NULL;

    }
    nodeCir(int data)
    {
        this->data=data;
        chance=false;
        next=NULL;
       // c=0;

    }

};
class circularList
{
    public:
   nodeCir *head;
   nodeCir *curr;
   int c;
  // nodeCir *tail;
    int len;
    int frames;
    circularList(int frames)
    {
    	head=NULL;
        curr=NULL;
		//tail=NULL;
        this->frames=frames;
        len=0;
        c=0;
    }
    void append(int a)
    {
        nodeCir* temp= new nodeCir(a);
		if(head==NULL)
        {
			head=temp;
			//tail=temp;
            curr=head;
            head->next=head;
            len++;
            //cout<<curr->data<<endl;
		}
		else if(len==frames)
        {
            update(a);
        }
		else
        {
				len++;
			nodeCir*temp1=head;
            while(temp1->next!=head)
            {
                temp1=temp1->next;
            }
            temp1->next=temp;
            temp->next=head;
            curr=temp;
		}
            //cout<<curr->data<<endl;
	}
	
    void update(int a)
    {
        if(c==0)
        {
        curr=curr->next;
            c=1;
        }
        int flag=0;
        nodeCir *temp=head;
        // while(temp->next!=head)
        do
        {
            if(temp->data==a)
            {
                temp->chance=true;
                flag=1;
                break;
            }
            temp=temp->next;
        }while(temp!=head);
        // else if(curr->chance==true)
        // {
        //     curr->chance=false;
        //     curr=curr->next;
        // }
        // else 
        // {
        //     curr->data=a;
        // }
        if(flag!=1)
        {
        while(curr->chance==true)
        {
            curr->chance=false;
            curr=curr->next;
        }
        curr->data=a;
        curr=curr->next;
        //curr->chance=false;
        }

        // cout<<curr->data<<endl;
        
    }
    bool search(int val){
        nodeCir* temp=head;
        if(head==NULL){
            return false;
        }
        do{
            // cout<<temp->data<<"|";
            if(temp->data==val){
                return true;
            }
            temp=temp->next;
        }while(temp!=head);
        return false;
    }
    void print(){
        nodeCir* temp=head;
        cout<<"{ ";
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while (temp!=head);
        cout<<"}";
        temp=head;
        cout<<" Chance: ";
        cout<<"{ ";
        do
        {
            cout<<temp->chance<<" ";
            temp=temp->next;
        } while (temp!=head);
        cout<<"}\n";
        
    }
};