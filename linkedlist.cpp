#include "linkedlist.h"
#include<fstream>

template <class T>
LinkedList<T>::LinkedList()
{
	start = NULL;
	
	int i=1;
	ifstream in("Player_data.bin", ios_base::binary);
	if(in)
	{
		while(!in.eof())
		{
			T p1;
			in.read((char*) &p1, sizeof(p1));
			if(in.eof())
			{
				break;
			}
			storeData(p1, i);
			i++;
		}
		in.close();
	}
	
} 
template <class T>
void LinkedList<T> ::storeData(T p1, int pos)
{
	Node<T>* temp = new Node<T>(p1);
	
	if(pos==1 || start==NULL)
	{
		temp->setNext(start);
		start=temp;
	}
	else
	{
		Node<T>* p=start;
		int i=1;
		while(i<pos-1 && p->getNext() != NULL)
		{
			p=p->getNext();
			i++;
		}
		temp->setNext(p->getNext());
		p->setNext(temp);
	}
}

template <class T>
void LinkedList<T>::displayPlayer()
{
	if(start == NULL)
	{
		cout<<"\nNo Player Details in LinkList";
	}
	else
	{
		Node<T>* p=start;
		while(p != NULL)
		{
			p->getData().displayData();
			p=p->getNext();
		}
		
	}
}

template <class T>
void LinkedList<T>::searchByJerseyNumber(int jno)
{
	if(start == NULL)
	{
		cout<<"\nlinked list is Empty!!..";
		return;
	}
	else
	{
		Node<T>* p= start;
		while(p != NULL)
		{
			if(p->getData().getJerseyNumber()==jno)
			{
				p->getData().displayData();
				return;
			}
			p=p->getNext();
		}
		cout<<"\n"<<jno<<" is not in linklist..!!";
	}
}

template <class T>
void LinkedList<T>::searchByPlayerName(const char*nm)
{
	if(start == NULL)
	{
		cout<<"\nlinked list is Empty!!..";
		return;
	}
	else
	{
		Node<T>* p= start;
		while(p != NULL)
		{
			if(strcasecmp(nm, p->getData().getPlayerName())==0)
			{
				p->getData().displayData();
				return;
			}
			p=p->getNext();
		}
		cout<<"\n"<<nm<<" linked list is empty!!";
	}
}
template <class T>
void LinkedList<T> :: updateDetails(int jno)
{
 		if(start == NULL) 
		{
  			cout<<"\nlinked list is empty!!..";
			return;
		}
 		else 
		{
	 		Node<T>* p = start;
			 int flag=0;    
			while(p != NULL)
			{    
			if(jno == p->getData().getJerseyNumber())
			{ 
				int choice;
		     	cout<<"\nUpdate";    
			 	cout<<"\n1.Update Runs";
		    	cout<<"\n2.Update Wickets";     
				cout<<"\n3.Update Matches";   
				
		        cout<<"\nEnter Your Choice For Update: ";
		        cin>>choice;
		       	if(choice == 1)
		        {
		        	int runs;
		           	cout<<"\nEnter Runs to update: ";            
					cin>>runs;
		            T p1;
		            p1=p->getData();                
					p1.setRuns(runs);
		            p->setData(p1);
					p->getData().displayData(); 
					break;     
				
				}
		        else if(choice == 2)         
				{
		            int wickets;
		     		cout<<"\nEnter wickets to update: ";            
					cin>>wickets;
		            T p1;
		            p1=p->getData();                
					p1.setWickets(wickets);
		            p->setData(p1); 
		            p->getData().displayData();
					break;     
				}
				else if(choice == 3)         
				{
		            int matchesPlayed;
		     		cout<<"\nEnter Matches to update: ";            
					cin>>matchesPlayed;
		            T p1;
		            p1=p->getData();                
					p1.setMatchesPlayed(matchesPlayed);
		            p->setData(p1); 
		            p->getData().displayData();
					break;     
				}
		        else
				{
		        	cout<<"\nInvalid Choice..!!";
					break;      
				}    
		    } 
		      
		p = p->getNext(); 
		 
		}
		if(p==NULL){
			cout<<"Not Found";
		}
 	}
}

template <class T>
void LinkedList<T>::sortData()
{
	Node<T>* p =start;
	if(start == NULL)
	{
		cout<<"linked list is empty!";
	}
	else
	{
		int choice;
		cout<<"\nSorting";
		cout<<"\n1.Sort By Runs";
		cout<<"\n2.Sort By Wickets";
		cout<<"\nEnter a Choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					for(Node<T>* p=start; p!=NULL; p=p->getNext())
					{
						for(Node<T>* q=p->getNext(); q!=NULL; q=q->getNext())
						{
							if(p->getData().getRuns() < q->getData().getRuns())
							{
								T temp = p->getData();
								p->setData(q->getData());
								q->setData(temp);
							}
						}
					}
				}
				break;
				
			case 2:
				{
					for(Node<T>* p=start; p!=NULL; p=p->getNext())
					{
						for(Node<T>* q=p->getNext(); q!=NULL; q=q->getNext())
						{
							if(p->getData().getWickets() < q->getData().getWickets())
							{
								T temp = p->getData();
								p->setData(q->getData());
								q->setData(temp);
							}
						}
					}
				}
				break;
		}
	}
	displayPlayer();
}

template <class T>
void LinkedList<T>::deletePlayer(int jno)
{
	if(start == NULL)
	{
		cout<<"\nNo Player to delete!..";
		return;
	}
	
	if(start->getData().getJerseyNumber()==jno)
	{
		Node<T>* p =start;
		cout<<"\nPlayer is deleted Successfully!..";
		start = start->getNext();
		delete p;
		return;
	}
	
	Node<T>* p = start->getNext();
	Node<T>* q = start;
	while(p->getNext()!= NULL)
	{	
		if(p->getData().getJerseyNumber() == jno)
		{
			q->setNext(p->getNext());
			delete p;
			return;
		}
		q=p;
		p=p->getNext();
	}
	if(p->getData().getJerseyNumber() == jno){
		q->setNext(NULL);
		delete p;
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* p =start;
	ofstream out("Player_data.bin", ios_base::binary);
	while(p != NULL)
	{
		T p1 = p->getData();
		out.write((char*)&p1, sizeof(p1));
		p=p->getNext();
		cout<<endl;
	}
	out.close();
	p=start;
	while(start != NULL)
	{
		start = start->getNext();
		delete p;
		p = start;
		//cout<<"\nDestructor Called.....!";
	}
}


