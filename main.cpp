#include<iostream>
#include<conio.h>
using namespace std;
class linked_list
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *start;
public:
    linked_list()
    {
        start=NULL;
    }
    ~linked_list()
    {
        node *t1,*t2;
        t1=start;
        while(t1)
        {
            t2=t1->next;
            delete t1;
            t1=t2;
        }
    }
    void insert_first(int data)
    {
            node *temp=new node;
            temp->item=data;
            temp->next=start;
            start=temp;
    }
    void insert_after(int element,int data)
    {
        node *temp1=start;
        for(; temp1!=NULL;)
        {
            if(temp1->item==element)
            {
                break;
            }
            temp1=temp1->next;
        }
        if(temp1==NULL)
        {
            cout<<"OPERATION FAILED: ELEMENT NOT FOUND!"<<endl;
            return;
        }
        node *temp2=new node;
        temp2->item=data;
        temp2->next=temp1->next;
        temp1->next=temp2;
    }
    void insert_last(int data)
    {
        if(start==NULL)
        {
            start=new node;
            start->item=data;
            start->next=NULL;
        }
        else
        {
            node *temp=start;
            for(; temp->next!=NULL;)
            {
                temp=temp->next;
            }
            temp->next=new node;
            temp->next->item=data;
            temp->next->next=NULL;
        }
    }
    void view_list_items()
    {
        if(start==NULL)
        {
            cout<<"OPERATION FAILED: LINKED LIST IS EMPTY!"<<endl;
            return;
        }
        for(node *temp=start; temp!=NULL;)
        {
            cout<<temp->item<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void delete_first()
    {
        if(start==NULL)
        {
            cout<<"OPERATION FAILED: LINKED LIST IS EMPTY!"<<endl;
        }
        else
        {
            node *temp=start->next;
            delete start;
            start=temp;
        }
    }
    void delete_last()
    {
        if(start==NULL)
        {
            cout<<"OPERATION FAILED: LINKED LIST IS EMPTY!"<<endl;
        }
        else
        {
            if(start->next==NULL)
            {
                delete start;
                start=NULL;
            }
            else
            {
                node *temp=start;
                for(; temp->next->next!=NULL;)
                {
                   temp=temp->next;
                }
                delete temp->next;
                temp->next=NULL;
            }
        }
    }
    void delete_element(int element)
    {
        if(start==NULL)
        {
            cout<<"OPERATION FAILED: LINKED LIST IS EMPTY!"<<endl;
        }
        else
        {
            node *temp1=start,*temp2=NULL;
            for(;temp1!=NULL;)
            {
                if(temp1->item==element)
                {
                    break;
                }
                temp2=temp1;
                temp1=temp1->next;
            }
            if(temp1==NULL)
            {
                cout<<"OPERATION FAILED: ELEMENT NOT FOUND!"<<endl;
                return;
            }
            else
            {
                if(temp2==NULL)
                start=temp1->next;
                else
                temp2->next=temp1->next;
                delete temp1;
            }
        }
    }
};
void viewListData(linked_list &l);
int menu();
int main()
{
    int data,element;
    linked_list l;
    while(true)
    {
       system("cls");
       viewListData(l);
       switch(menu())
       {
       case 1:
        cout<<"Enter data to insert at first:";
        cin>>data;
        l.insert_first(data);
        break;
       case 2:
        cout<<"Enter data to insert after a element:";
        cin>>data;
        cout<<"Enter element to after it:";
        cin>>element;
        l.insert_after(element,data);
        break;
       case 3:
        cout<<"Enter data to insert at last:";
        cin>>data;
        l.insert_last(data);
        break;
       case 4:
        l.delete_first();
        break;
       case 5:
        cout<<"Enter the element to delete:";
        cin>>element;
        l.delete_element(element);
        break;
       case 6:
        l.delete_last();
        break;
       case 7:
        exit(0);
       default:
        cout<<"INVALID CHOICE!!"<<endl;
       }
       getch();
    }
    return 0;
}

int menu()
{
    int choice;
    cout<<"1.Insert at first"<<endl;
    cout<<"2.Insert after the element"<<endl;
    cout<<"3.Insert at last"<<endl;
    cout<<"4.Delete first"<<endl;
    cout<<"5.Delete element"<<endl;
    cout<<"6.Delete last"<<endl;
    cout<<"7.Exit"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    return choice;
}
void viewListData(linked_list &l)
{
    l.view_list_items();
}
