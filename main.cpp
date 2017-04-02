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
    void display();
    void display_city_wise();
    void check_path();
};

void Graph::create()								//create()
{
    Node *temp;
    char choice;
    int i,j;
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
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                cout<<"\nIs there any path between "<<head[i]->name<<" and "<<head[j]->name<<" ? ";
                cin>>choice;
                if(choice=='y' || choice=='Y')
                {
                    temp = new Node;
                    strcpy(temp->name,head[j]->name);
                    cout<<"Enter the time taken \t\t: ";
                    cin>>temp->time;
                    cout<<"Enter the fuel consumption \t: ";
                    cin>>temp->fuel;
                    temp->next = head[i]->next;
                    head[i]->next = temp;
                }
            }
        }
    }
}

void Graph::display()								//Display data
{
    Node *temp;
    int i,j,count;
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
    int i,j,count;
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
        cout<<"\n 1 to Read Data.";
        cout<<"\n 2 to Display Data.";
        cout<<"\n 3 to Display City-wise.";
        cout<<"\n 4 to Check for path.";
        cout<<"\n 0 to Exit.";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~\n";
        switch(ch)
        {
            case 1 : obj.create();
                break;
            case 2 : obj.display();
                break;
            case 3 : obj.display_city_wise();
                break;
            case 4 : obj.check_path();
                break;
            case 0 : break;
            default : cout<<"\nInvalid Option!";
        }
        
        /*
        if(ch!=0)
        {
            cout<<"\n\n\n\n\n\n\nPress any key to continue...";
            cin.ignore();
            cin.get();
        }
        */
    }while(ch!=0);
    
    cout<<"\nThank you for using this program :)\n\n";
    return 0;
}

/* OUTPUT

Program to Implement Graph using Adjacency List.

~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Read Data.
 2 to Display Data.
 3 to Display City-wise.
 4 to Check for path.
 0 to Exit.
Enter your choice : 1
~~~~~~~~~~~~~~~~~~~~~~~~

Enter number of Cities : 3

Enter next city : Nashik
Enter next city : Mumbai
Enter next city : Pune

Is there any path between Nashik and Mumbai ? y
Enter the time taken 		: 123
Enter the fuel consumption 	: 45

Is there any path between Nashik and Pune ? y
Enter the time taken 		: 147
Enter the fuel consumption 	: 258

Is there any path between Mumbai and Nashik ? y
Enter the time taken 		: 258
Enter the fuel consumption 	: 369

Is there any path between Mumbai and Pune ? y
Enter the time taken 		: 456
Enter the fuel consumption 	: 789

Is there any path between Pune and Nashik ? y
Enter the time taken 		: 321
Enter the fuel consumption 	: 564

Is there any path between Pune and Mumbai ? n


~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Read Data.
 2 to Display Data.
 3 to Display City-wise.
 4 to Check for path.
 0 to Exit.
Enter your choice : 2
~~~~~~~~~~~~~~~~~~~~~~~~

----------------------------
    Here are the Details
----------------------------
From	To	Time	Fuel
----------------------------
Nashik	Pune	147	258
Nashik	Mumbai	123	45
Mumbai	Pune	456	789
Mumbai	Nashik	258	369
Pune	Nashik	321	564
----------------------------
Total Flights : 5

~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Read Data.
 2 to Display Data.
 3 to Display City-wise.
 4 to Check for path.
 0 to Exit.
Enter your choice : 3
~~~~~~~~~~~~~~~~~~~~~~~~

Enter City name : Nashik

----------------------------
    Here are the Details
----------------------------
From	To	Time	Fuel
----------------------------
Nashik	Pune	147	258
Nashik	Mumbai	123	45
----------------------------
Total Flights : 2

~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Read Data.
 2 to Display Data.
 3 to Display City-wise.
 4 to Check for path.
 0 to Exit.
Enter your choice : 4
~~~~~~~~~~~~~~~~~~~~~~~~

Enter First city  : Pune
Enter Second city : Mumbai

Sorry, there are no Flights between Pune and Mumbai

~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Read Data.
 2 to Display Data.
 3 to Display City-wise.
 4 to Check for path.
 0 to Exit.
Enter your choice : 4
~~~~~~~~~~~~~~~~~~~~~~~~

Enter First city  : Pune
Enter Second city : Nashik

Yes, there are Flights between Pune and Nashik
Total Time of Flight   : 321
Total Fuel Consumption : 564

~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Read Data.
 2 to Display Data.
 3 to Display City-wise.
 4 to Check for path.
 0 to Exit.
Enter your choice : 0
~~~~~~~~~~~~~~~~~~~~~~~~

Thank you for using this program :)

*/
