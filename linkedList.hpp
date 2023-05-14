#pragma once
#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(){
			data=0;
			next=NULL;
		}
		node(int a){
			data=a;
			next=NULL;
		}
};
class linkedList{
	public:
		node* head;
		node* tail;
        int len;
        int frames;
		linkedList(int frames){
			head=NULL;
			tail=NULL;
            this->frames=frames;
            len=0;
		}
		void append(int a){
			node* temp= new node(a);
			if(head==NULL){
				head=temp;
				tail=temp;
                len++;
			}
			else{
                if(len==frames){
                    deleteHead();
                }
				else{
				len++;
				}
				tail->next=temp;
				tail=temp;

			}
		}
		
		void deleteHead(){
			node* temp= new node;
			temp=head;
			head=head->next;
			delete temp;
		}
        bool search(int val){
            node* temp=head;
            while(temp!=NULL){
                if(temp->data==val){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }
		bool deleteSpecific(int val){
			node* temp=head;
			node* del;
			len--;
			if(temp->data==val){
				deleteHead();
				return true;
			}
				// cout<<temp->data<<"|";
			while(temp->next->data!=val && temp!=NULL){
				temp=temp->next;
			}
			if(temp->next==tail){
				len++;
				return false;
			}
			if(temp->next->data==val && temp->next!=NULL){	
				del=temp->next;
				temp->next=del->next;
				delete del; 
				return true;
			}
			return false;
		}
		void foundLRU(int val){
			if(deleteSpecific(val)){
				append(val);
			}
		}
		void search_v(vector<int> p,int index,int val){		//check for the page which is the least used in the future.
			if(len<frames){
				append(val);
			}
			else{
			int m[frames];
			int j=0;
			node* temp=head;
			while(temp!=NULL){
				int max=0;
				for(int i=index;i<p.size();i++){
					if(temp->data!=p[i]){
						max++;
					}
					else{
						break;
					}
				}
				m[j]=max;
				j++;
				temp=temp->next;
			}
			int ans=m[0];
			int idx=0;
			for(int i=0;i<frames;i++){
				if(ans<m[i]){
					ans=m[i];
					idx=i;
				}
			}
			opt_replace(idx,val);
		}
	}
		void opt_replace(int idx,int val){	//This function will replace the least used pag with the new page.
			int j=idx;
			node* temp=head;
			if(idx==0){
				temp->data=val;
			}
			else{
				for(int i=0;i<j;i++){
					temp=temp->next;
				}
				temp->data=val;
			}
		}
		void print(){
			node* temp=head;
			cout<<"{ ";
			do{
				cout<<temp->data<<" ";
				temp=temp->next;
			}while(temp!=NULL);
			cout<<"}\n";
		}
		
};
