#include<iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


class Node
{
public:
    int data;

    Node* prev;
    Node* next;

};
//create the main head pointer pointing always towards the head node
Node* headpointer = NULL;

vector<string> nodeArray;
vector<string> nameArray{"  Address   " , "   Previous " , "    Data " , "   Next "};

void printName()
{
    cout<<"\nThe current List is below : "<<endl<<endl;
    for(int i=0;i<4;i++)
        cout<<nameArray[i]<<" ";
    cout<<endl;
}

void printVector()
{
    for(int i=0;i<nodeArray.size();i++)
    {
        cout<<nodeArray[i]<<"  ";

        if((i+1)%4==0) cout<<endl;
    }
    cout<<endl;
}

Node* getNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertAtHead(int data)
{
    Node* newNode = getNewNode(data);

    if(headpointer == NULL)
    {
        headpointer = newNode;
        return;
    }

    headpointer->prev = newNode;
    newNode->next = headpointer;
    headpointer = newNode;
}

void insertAtTail(int data)
{
    Node* newNode = getNewNode(data);

    if(headpointer == NULL)
    {
        headpointer = newNode;
        return;
    }

    Node* temp = headpointer;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
}

void insertAtMiddle(int data,int position)
{
    Node* newNode = getNewNode(data);
    if(headpointer == NULL)
    {
        headpointer = newNode;
        return;
    }

    Node* currentNode = headpointer;

    for(int i=1; i<position-1; i++)
    {
        currentNode=currentNode->next;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;

}

void insertVector()
{
    Node* temp = headpointer;

    while(temp != nullptr)
    {
        string s;
        ostringstream ossAddress , ossPrev , ossData , ossNext;
        ossAddress << temp;
        s = "  " + ossAddress.str() + "  ";
        nodeArray.push_back(s);

        ossPrev << temp->prev;
        s = "  " + ossPrev.str() + "  ";
        nodeArray.push_back(s);

        ossData << temp->data;
        s = "  " + ossData.str() + "  ";
        nodeArray.push_back(s);

        ossNext << temp->next;
        s = "  " + ossNext.str() + "  ";
        nodeArray.push_back(s);

        temp = temp->next;
    }
}

void print()
{
    Node* temp = headpointer;
    while(temp->next != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data;
}

int main()
{

    int n=1,data,nodeNumber,mid,node,t,c;
    bool mode=false;

    cout<<endl<<endl;
    cout<<"                      Welcome to Doubly Linked List World  "<<endl;
    cout<<"                      -----------------------------------  "<<endl;
    cout<<"                   Do you want to make a doubly linked list ? "<<endl<<endl;
    cout<<"                                Press 1 for YES "<<endl;
    cout<<"                                Press 2 for NO  "<<endl<<endl;
    cout<<"                      Give choice here : ";
    cin>>c;

    if(c==1)
        mode = true;
    else
    {
        cout<<endl;
        cout<<"      Thanks for your choice. There will be no doubly linked list."<<endl;
        return 0;
    }

    while(mode)
    {
        if(n==1)
        {
            cout<<endl;
            cout<<"Thanks for you choice . A doubly linked list has been created."<<endl<<endl;
            cout<<"How many nodes do you want to insert?"<<endl;
            cout<<"\nNode Number : ";
            cin>>nodeNumber;
            cout<<"\nEnter the Values : ";
            for(int i=1; i<=nodeNumber; i++)
            {
                cin>>node;
                insertAtTail(node);
            }
            nodeArray.clear();
            insertVector();
            printName();
            printVector();
            n++;
        }
        else
        {
            cout<<"\nIn which position you want to insert?"<<endl;
            cout<<"\nPress 1 for Head Position"<<endl;
            cout<<"\nPress 2 for Middle Position"<<endl;
            cout<<"\nPress 3 for Tail Position"<<endl;
            cout<<"\nPress any other key for exit."<<endl;
            cout<<"\nGive Choice here : ";
            cin>>t;
            if(t == 1)
            {
                cout<<"\nInsert the data : ";
                cin>>data;
                insertAtHead(data);
                nodeArray.clear();
                insertVector();
                printName();
                printVector();
            }
            else if(t == 2)
            {
                cout<<"\nIn which position?"<<endl;
                cout<<"Give choice here : ";
                cin>>mid;
                cout<<"Insert The data : ";
                cin>>data;
                insertAtMiddle(data,mid);
                nodeArray.clear();
                insertVector();
                printName();
                printVector();
            }
            else if(t == 3)
            {
                cout<<"Insert The data : ";
                cin>>data;
                insertAtTail(data);
                nodeArray.clear();
                insertVector();
                printName();
                printVector();
            }
            else
            {
                break;
            }
        }
    }

    cout<<"The current and final doubly list is : "<<endl;
    nodeArray.clear();
    insertVector();
    printName();
    printVector();
}
