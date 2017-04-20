//Program to Implement Graph using Linked List Implementation

/*
 * Created by Devashish Katoriya on 17-02-2017
 */

#include <iostream>
#include <string.h>

using namespace std;

#define LIMIT 20

//Class definitions
class Node													//Node Class
{
public :
    char name[LIMIT];
    float time,fuel;
    Node *next;
};

class Graph													//Graph Class
{
    Node *head[LIMIT];
    int n;
public :
    Graph()
    {
        n = 0;
        for(int i=0;i<LIMIT;i++)
            head[i] = NULL;
    }
    void create();
    void insert();
    void display();
    void display_city_wise();
    void check_path();
};

void Graph::create()								//create()
{
    int i;
    cout<<"\nEnter number of Cities : ";
    cin>>n;
    cout<<"\n";
    for(i=0;i<n;i++)
    {
        head[i] = new Node;
        cout<<"Enter next city : ";
        cin>>head[i]->name;
        head[i]->time = 0;
        head[i]->fuel = 0;
        head[i]->next = NULL;
    }
}
void Graph::insert()
{
    char name1[LIMIT],name2[LIMIT];
    int i,j,found1=0,found2=0;
    cout<<"\nEnter Starting City : ";
    cin>>name1;
    for(i=0;i<n;i++)
    {
        if(strcmp(name1,head[i]->name)==0)
        {
            found1 = 1;
            break;
        }
    }
    if(found1==0)
    {
        cout<<"\nCity does not exist!";
        return;
    }
    cout<<"Enter Destination City : ";
    cin>>name2;
    if(strcmp(name1,name2)==0)
    {
        cout<<"\nStarting and Destination city cannot be same.";
        return;
    }
    for(j=0;j<n;j++)
    {
        if(strcmp(name2,head[j]->name)==0)
        {
            found2 = 1;
            break;
        }
    }
    if(found2==0)
    {
        cout<<"\nDestination City does not exist!";
        return;
    }
    Node *temp;
    temp = new Node;
    strcpy(temp->name,name2);
    cout<<"Enter Time of Flight : ";
    cin>>temp->time;
    cout<<"Enter Fuel Consumed : ";
    cin>>temp->fuel;
    temp->next = head[i]->next;
    head[i]->next = temp;
    cout<<"\nRoute Successfully added!";
}
void Graph::display()								//Display data
{
    Node *temp;
    int i,count;
    if(n == 0)
    {
        cout<<"\nEmpty database!";
        return;
    }
    count = 0;
    cout<<"\n----------------------------";
    cout<<"\n    Here are the Details";
    cout<<"\n----------------------------";
    cout<<"\nFrom\tTo\tTime\tFuel";
    cout<<"\n----------------------------";
    for(i=0;i<n;i++)
    {
        temp = head[i]->next;
        while(temp!=NULL)
        {
            cout<<"\n"<<head[i]->name<<"\t"<<temp->name<<"\t"<<temp->time<<"\t"<<temp->fuel;
            temp = temp->next;
            count++;
        }
    }
    cout<<"\n----------------------------";
    cout<<"\nTotal Flights : "<<count;
}

void Graph::display_city_wise()								//City-wise
{
    Node *temp;
    char city[LIMIT];
    int i,count;
    if(n == 0)
    {
        cout<<"\nEmpty database!";
        return;
    }
    cout<<"\nEnter City name : ";
    cin>>city;
    for(i=0;i<n;i++)
    {
        if(strcmp(head[i]->name,city)==0)
            break;
    }
    if(i==n)
    {
        cout<<"\nInvalid City!";
        return;
    }
    count = 0;
    cout<<"\n----------------------------";
    cout<<"\n    Here are the Details";
    cout<<"\n----------------------------";
    cout<<"\nFrom\tTo\tTime\tFuel";
    cout<<"\n----------------------------";
    temp = head[i]->next;
    while(temp!=NULL)
    {
        cout<<"\n"<<head[i]->name<<"\t"<<temp->name<<"\t"<<temp->time<<"\t"<<temp->fuel;
        temp = temp->next;
        count++;
    }
    cout<<"\n----------------------------";
    cout<<"\nTotal Flights : "<<count;
}

void Graph::check_path()
{
    Node *temp;
    char city[LIMIT],city2[LIMIT];
    int i,j,flag;
    if(n == 0)
    {
        cout<<"\nEmpty database!";
        return;
    }
    cout<<"\nEnter First city  : ";
    cin>>city;
    cout<<"Enter Second city : ";
    cin>>city2;
    
    for(i=0;i<n;i++)
    {
        if(strcmp(head[i]->name,city)==0)
            break;
    }
    if(i==n)
    {
        cout<<"\nInvalid City!";
        return;
    }
    for(j=0;j<n;j++)
    {
        if(strcmp(head[j]->name,city2)==0)
            break;
    }
    if(j==n)
    {
        cout<<"\nInvalid City!";
        return;
    }
    flag = 0;
    temp = head[i];
    while(temp!=NULL)
    {
        if(strcmp(temp->name,city2)==0)
        {
            cout<<"\nYes, there are Flights between "<<city<<" and "<<city2;
            cout<<"\nTotal Time of Flight   : "<<temp->time;
            cout<<"\nTotal Fuel Consumption : "<<temp->fuel;
            flag = 1;
        }
        temp = temp->next;
    }
    if(flag == 0)
    {
        cout<<"\nSorry, there are no Flights between "<<city<<" and "<<city2;
    }
}

//main()
int main()
{
    Graph obj;
    int ch;
    
    cout<<"\nProgram to Implement Graph using Adjacency List.";
    
    do
    {
        ch = 0;
        cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n 1 to Create.";
        cout<<"\n 2 to Insert.";
        cout<<"\n 3 to Display Data.";
        cout<<"\n 4 to Display City-wise.";
        cout<<"\n 5 to Check for path.";
        cout<<"\n 0 to Exit.";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~\n";
        switch(ch)
        {
            case 1 : obj.create();
                break;
            case 2 : obj.insert();
                break;
            case 3 : obj.display();
                break;
            case 4 : obj.display_city_wise();
                break;
            case 5 : obj.check_path();
                break;
            case 0 : break;
            default : cout<<"\nInvalid Option!";
        }
    }while(ch!=0);
    cout<<"\nThank you for using this program :)\n\n";
    return 0;
}