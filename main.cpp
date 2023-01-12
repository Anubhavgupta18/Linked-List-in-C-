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
        node *t;
        t=start;
        while(start)
        {
            start=t->next;
            delete t;
            t=start;
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
