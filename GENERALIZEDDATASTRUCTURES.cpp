#include<iostream>

using namespace std;

template<class h>
struct node
{
    h slldata;
    struct node *next;
};

template<class h>
class SLL
{
private:
     struct node <h>* head;
    int isize;
public:
    SLL()
    {
        head=NULL;
        isize=0;
    }
    ~SLL()
    {
        struct node <h>* temp=NULL;
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
        cout<<"inside destructor"<<endl;
    }
    void insertfirst(h);
    void displayll();
    void insertlast(h);
    void insertatpos(int,h);
    int countll();
    h  deletefirst();
    h deletelast();
    h deleteatpos(int);
};
template<class h>
void SLL<h>::insertfirst(h ino)
{
    struct node <h>* newn=NULL;

    newn=new struct node <h>;

    newn->next=NULL;
    newn->slldata=ino;

    if(head==NULL)
    {
        head=newn;
    }

    else
    {
        newn->next=head;
        head=newn;
    }
    isize++;
}
template<class h>
void SLL<h>::displayll()
{
    struct node <h>* temp=NULL;

    temp=head;

    cout<<"the linked list is\n";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->slldata<<"|->";
        temp=temp->next;
    }
}
template<class h>
void SLL<h>::insertlast(h ino)
{
    struct node <h>* newn=NULL;

    newn=new struct node<h>;

    newn->next=NULL;
    newn->slldata=ino;

    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        struct node <h>* temp=NULL;

        temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newn;
    }
    isize++;
}
template<class h>
void SLL<h>::insertatpos(int ipos,h ino)
{
    if((ipos<=0)||(ipos>isize+1))
    {
        return;
    }

    if(ipos==1)
    {
        insertfirst(ino);
    }
    else if(ipos==(isize+1))
    {
        insertlast(ino);
    }
    else
    {
        struct node <h>* newn=NULL;
        struct node<h>* temp=head;

        newn=new struct node<h>;

        newn->next=NULL;
        newn->slldata=ino;

        for(int i=0;i<ipos-2;i++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next=newn;

        isize++;
    }

}
template<class h>
int SLL<h>::countll()
{
    return isize;
}
template<class h>
h SLL<h>::deletefirst()
{
    h ret;
    struct node <h>* temp=head;
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        head=temp->next;
        ret=temp->slldata;
        delete(temp);
    }
    isize--;
    return ret;
}
template<class h>
h SLL<h>::deletelast()
{
    h ret;
    struct node <h>* temp=head;
    if(head==NULL)
    {
        return -1;
    }
    else if(isize==1)
    {
        ret=temp->slldata;
        delete(temp);
        head=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        ret=temp->next->slldata;
        delete(temp->next);
        temp->next=NULL;
    }
    isize--;
    return ret;
}
template<class h>
h SLL<h>::deleteatpos(int ipos)
{
    h ret;
    if((ipos<=0)||(ipos>isize))
    {
        return -1;
    }

    if(ipos==1)
    {
        ret=deletefirst();
    }
    else if(ipos==isize)
    {
        ret=deletelast();
    }
    else
    {
        struct node <h>* temp1=NULL;
        struct node <h>* temp2=NULL;
        temp1=head;

        for(int i=1;i<ipos-1;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp1->next->next;
        ret=temp2->slldata;
        delete(temp2);
        isize--;
        return ret;
    }
}

///SINGLY CIRCULAR LINKED LIST

template<class a>
struct scllnode
{
    a sclldata;
    struct scllnode *scllnext;
};

template<class a>
class SCLL
{
private:
    struct scllnode <a>* head;
    struct scllnode <a>* tail;
    int isize;
public:
    SCLL()
    {
        head=NULL;
        tail=NULL;
        isize=0;
    }

    ~SCLL()
    {
        struct scllnode <a>* temp=NULL;
        while(isize!=0)
        {
            temp=head;
            head=head->scllnext;
            delete temp;
            isize--;
        }
        cout<<"inside destructor"<<endl;
    }
    void insertfirst(a);
    void display();
    int countscll();
    void insertlast(a);
    void insertatpos(int,a);
    a deletefirst();
    a deletelast();
    a deleteatpos(int);
};

template<class a>
void SCLL<a>::insertfirst(a ino)
{
    struct scllnode <a>* newn=NULL;

    newn=new struct scllnode <a>;

    newn->scllnext=NULL;
    newn->sclldata=ino;

    if((head==NULL)&&(tail==NULL))
    {
        head=newn;
        tail=newn;
    }
    else
    {
        newn->scllnext=head;
        head=newn;
    }
    tail->scllnext=head;

    isize++;
}

template<class a>
void SCLL<a>::display()
{
    struct scllnode <a>* temp=NULL;

    temp=head;

    cout<<"the linked list is\n";
    do
    {
        cout<<"|"<<temp->sclldata<<"|->";
        temp=temp->scllnext;
    }while(temp!=head);

}

template<class a>
int SCLL<a>::countscll()
{
    return isize;
}

template<class a>
void SCLL<a>::insertlast(a ino)
{
    struct scllnode <a>* newn=NULL;

    newn=new struct scllnode <a>;

    newn->scllnext=NULL;
    newn->sclldata=ino;

    if((head==NULL)&&(tail==NULL))
    {
        head=newn;
        tail=newn;
    }
    else
    {
        tail->scllnext=newn;
        tail=newn;
        tail->scllnext=head;

    }
    isize++;
}

template<class a>
void SCLL<a>::insertatpos(int ipos,a ino)
{
    if((head==NULL)||(tail==NULL)||(ipos<=0)||(ipos>(isize+1)))
    {
        return;
    }
    else if(ipos==1)
    {
        insertfirst(ino);
    }
    else if(ipos==(isize+1))
    {
        insertlast(ino);
    }
    else
    {
        struct scllnode <a>* newn=NULL;
        struct scllnode <a>* temp=head;

        newn=new struct scllnode <a>;

        newn->scllnext=NULL;
        newn->sclldata=ino;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->scllnext;
        }
        newn->scllnext=temp->scllnext;
        temp->scllnext=newn;
        isize++;
    }
}

template<class a>
a SCLL<a>::deletefirst()
{
    a ret;
    struct scllnode <a>* temp=head;
    if((head==NULL)&&(tail==NULL))
    {
        return -1;
    }

    if(head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        head=temp->scllnext;
        tail->scllnext=head;
        ret=temp->sclldata;
        delete(temp);
    }
    isize--;
    ///return tail->scllnext->data;///we will get value of first node as we have lost address of first node
    return ret;
}

template<class a>
a SCLL<a>::deletelast()
{
    a ret;
    struct scllnode <a>* temp=NULL;
    struct scllnode <a>* temp2=NULL;
    if((head==NULL)&&(tail==NULL))
    {
        return (int)-1;
    }

    if(head==tail)
    {
        temp2=tail;
        ret=temp->sclldata;
        delete temp2;
        head=NULL;
        tail=NULL;
    }
    else
    {
        temp=head;

        while(temp->scllnext->scllnext!=head)
        {
            temp=temp->scllnext;
        }
        temp2=temp->scllnext;
        temp->scllnext=head;
        tail=temp;
        ret=temp2->sclldata;
        delete(temp2);
    }
    isize--;
    return ret;
}

template<class a>
a SCLL<a>::deleteatpos(int ipos)
{
    a ret;
    struct scllnode <a>* temp=NULL;
    struct scllnode <a>*temp2=NULL;
    if((ipos<=0)||(ipos>isize))
    {
        return (int)-1;
    }

    if(ipos==1)
    {
        ret=deletefirst();
    }
    else if(ipos==isize)
    {
        ret=deletelast();
    }
    else
    {
        temp=head;
        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->scllnext;
        }
        temp2=temp->scllnext;
        temp->scllnext=temp->scllnext->scllnext;
        ret=temp->scllnext
        ->sclldata;
        delete(temp2);
        isize--;
    }
    return ret;
}

///DOUBLY LINEAR LINKED LIST

template<class n>
struct dllnode
{
    n dlldata;
    struct dllnode *dllnext;
    struct dllnode *dllprev;
};

template<class n>
class dll
{
private:
    struct dllnode <n>* head;
    struct dllnode <n>* tail;
    int isize;

public:
    dll()
    {
        head=NULL;
        tail=NULL;
        isize=0;
    }
    ~dll()
    {
        struct dllnode <n>* temp=NULL;
        while(head!=NULL)
        {
            temp=head;
            head=head->dllnext;
            delete temp;
        }
        cout<<"inside destructor"<<endl;
    }
    void insertfirst(n);
    void displayf();
    void displayr();
    int countn();
    void insertlast(n);
    void insertatpos(int,n);
    n deletefirst();
    n deletelast();
    n deleteatpos(int);
};
template<class n>
void dll<n>::insertfirst(n ino)
{
    struct dllnode <n>* newn=NULL;

    newn=new struct dllnode<n>;

    newn->dllnext=NULL;
    newn->dllprev=NULL;
    newn->dlldata=ino;

    if((head==NULL)&&(tail==NULL))
    {
        head=newn;
        tail=newn;
    }
    else
    {
        newn->dllnext=head;
        head->dllprev=newn;
        head=newn;
    }
    isize++;
}

template<class n>
void dll<n>::displayf()
{
    struct dllnode <n>* temp=NULL;
    temp=head;
    cout<<"the linked list in forward direction is\n";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->dlldata<<"|->";
        temp=temp->dllnext;
    }
}

template<class n>
void dll<n>::displayr()
{
    struct dllnode <n>* temp=NULL;
    temp=tail;
    cout<<"the linked list in backward direction is\n";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->dlldata<<"|<-";
        temp=temp->dllprev;
    }
}

template<class n>
int dll<n>::countn()
{
    return isize;
}

template<class n>
void dll<n>::insertlast(n ino)
{
        struct dllnode <n>* newn=NULL;

        newn=new struct dllnode<n>;

        newn->dllnext=NULL;
        newn->dllprev=NULL;
        newn->dlldata=ino;

    if((head==NULL)&&(tail==NULL))
    {
        tail=newn;
        head=newn;
    }
    else
    {
        tail->dllnext=newn;
        newn->dllprev=tail;
        tail=newn;
    }
    isize++;
}

template<class n>
void dll<n>::insertatpos(int ipos,n ino)
{
    struct dllnode <n>* newn=NULL;

    newn=new struct dllnode<n>;

    newn->dllnext=NULL;
    newn->dllprev=NULL;
    newn->dlldata=ino;

    if((ipos>(isize+1))||(ipos<=0))
    {
        return;
    }

    if(ipos==1)
    {
        insertfirst(ino);
    }
    else if(ipos==(isize+1))
    {
        insertlast(ino);
    }
    else
    {
        struct dllnode <n>* temp=NULL;
        temp=head;
        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->dllnext;
        }
        newn->dllnext=temp->dllnext;
        newn->dllnext->dllprev=newn;
        temp->dllnext=newn;
        newn->dllprev=temp;
        isize++;
    }

}

template<class n>
n dll<n>::deletefirst()
{
    n ret;
    if((head==NULL)&&(tail==NULL))
    {
        return (int)-1;
    }
    else if(head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        head=head->dllnext;
        ret=head->dllprev->dlldata;
        delete head->dllprev;
        head->dllprev=NULL;
    }
    isize--;
    return ret;
}

template<class n>
n dll<n>::deletelast()
{
    n ret;
    if((head==NULL)&&(tail==NULL))
    {
        return (int)-1;
    }
    else if(head==tail)
    {
        ret=tail->dlldata;
        delete tail;
        head=NULL;
        tail=NULL;
    }
    else
    {
        tail=tail->dllprev;
        ret=tail->dllprev->dlldata;
        delete tail->dllnext;
        tail->dllnext=NULL;
    }
    isize--;
    return ret;
}

template<class n>
n dll<n>::deleteatpos(int ipos)
{
    n ret;
    if((ipos<=0)||(ipos>isize))
    {
        return(int)-1;
    }

    if(ipos==1)
    {
        ret=deletefirst();
    }
    else if(ipos==isize)
    {
        ret=deletelast();
    }
    else
    {
        struct dllnode <n>* temp=head;

        for(int i=1;i<ipos;i++)
        {
            temp=temp->dllnext;
        }
        temp->dllprev->dllnext=temp->dllnext;
        temp->dllnext->dllprev=temp->dllprev;
        ret=temp->dlldata;
        delete temp;
        isize--;
    }
    return ret;
}

///DOUBLY CIRCULAR LINKED LIST

template<class c>
struct dcllnode
{
    c dclldata;
    struct dcllnode *dcllnext;
    struct dcllnode *dcllprev;
};

template<class c>
class dcll
{
private:
    struct dcllnode<c>* head;
    struct dcllnode<c>* tail;
    int isize;
public:
    dcll()
    {
        head=NULL;
        tail=NULL;
        isize=0;
    }
    ~dcll()
    {
        struct dcllnode<c>* temp=NULL;
        while(isize!=0)
        {
            temp=head;
            head=head->dcllnext;
            delete temp;
            isize--;
        }
        cout<<"inside destructor"<<endl;
    }
    void insertfirst(c);
    void displayf();
    void displayr();
    int countn();
    void insertlast(c);
    void insertatpos(int,c);
    c deleteatpos(int);
    c deletefirst();
    c deletelast();
};

template<class c>
void dcll<c>::insertfirst(c ino)
{
    struct dcllnode<c>* newn=NULL;

    newn=new struct dcllnode<c>;

    newn->dcllnext=NULL;
    newn->dcllprev=NULL;
    newn->dclldata=ino;

    if((head==NULL)&&(tail==NULL))
    {
        head=newn;
        tail=newn;
    }
    else
    {
        newn->dcllnext=head;
        head->dcllprev=newn;
        head=newn;
    }
    tail->dcllnext=head;
    head->dcllprev=tail;
    isize++;
}

template<class c>
void dcll<c>::displayf()
{
    struct dcllnode<c>* temp=head;
    cout<<"the linked list in forward direction is\n";
    do
    {
        cout<<"|"<<temp->dclldata<<"|->";
        temp=temp->dcllnext;
    }while(temp!=head);
}
template<class c>
void dcll<c>::displayr()
{
    struct dcllnode<c>* temp=tail;
    cout<<"the linked list in backward direction is\n";
    do
    {
        cout<<"|"<<temp->dclldata<<"|<-";
        temp=temp->dcllprev;
    }while(temp!=tail);
}
template<class c>
int dcll<c>::countn()
{
    return isize;
}
template<class c>
void dcll<c>::insertlast(c ino)
{
    struct dcllnode<c>* newn=NULL;

    newn=new struct dcllnode<c>;

    newn->dcllnext=NULL;
    newn->dcllprev=NULL;
    newn->dclldata=ino;

    if((head==NULL)&&(tail==NULL))
    {
        tail=newn;
        head=newn;
    }
    else
    {
        tail->dcllnext=newn;
        newn->dcllprev=tail;
        tail=newn;
    }
    tail->dcllnext=head;
    head->dcllprev=tail;
    isize++;
}
template<class c>
void dcll<c>::insertatpos(int ipos,c ino)
{
    if((ipos<=0)||(ipos>=(isize+2)))
    {
        return;
    }
    else if(ipos==1)
    {
        insertfirst(ino);
    }
    else if(ipos==(isize+1))
    {
        insertlast(ino);
    }
    else
    {
        struct dcllnode<c>* newn=NULL;
        struct dcllnode<c>* temp=head;

        newn=new struct dcllnode<c>;

        newn->dcllnext=NULL;
        newn->dcllprev=NULL;
        newn->dclldata=ino;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->dcllnext;
        }
        newn->dcllnext=temp->dcllnext;
        temp->dcllnext->dcllprev=newn;
        temp->dcllnext=newn;
        newn->dcllprev=temp;
        isize++;
    }
}
template<class c>
c dcll<c>::deleteatpos(int ipos)
{
    c iret=0;
    if((ipos<=0)||(ipos>=(isize+1)))
    {
        return (int)-1;
    }

    if(ipos==1)
    {
        iret=deletefirst();
    }
    else if(ipos==isize)
    {
        iret=deletelast();
    }
    else
    {
        struct dcllnode<c>* temp=head;

        for(int i=1;i<ipos;i++)
        {
            temp=temp->dcllnext;
        }
        temp->dcllprev->dcllnext=temp->dcllnext;
        temp->dcllnext->dcllprev=temp->dcllprev;
        iret=temp->dclldata;
        delete temp;
        isize--;
        return iret;
    }
}
template<class c>
c dcll<c>::deletefirst()
{
    c iret=0;
    if((head==NULL)&&(tail==NULL))
    {
        return -1;
    }
    else
    {
        head=head->dcllnext;
        iret=tail->dcllnext->dclldata;
        delete tail->dcllnext;
    }
    tail->dcllnext=head;
    head->dcllprev=tail;
    isize--;
    return iret;
}
template<class c>
c dcll<c>::deletelast()
{
    c iret=0;
    if((head==NULL)&&(tail==NULL))
    {
        return -1;
    }
    else
    {
        tail=tail->dcllprev;
        iret=tail->dcllnext->dclldata;
        delete tail->dcllnext;
    }
    tail->dcllnext=head;
    head->dcllprev=tail;
    isize--;
    return iret;
}
///stack using linked list
template<class m>
struct stllnode
{
    m stlldata;
    struct stllnode *next;
};

///stack using linked list

template<class m>
class STLL
{
private:
     struct stllnode <m>* head;
public:
    STLL()
    {
        head=NULL;
    }
    ~STLL()
    {
        struct stllnode <m>* temp=NULL;
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
        cout<<"inside destructor"<<endl;
    }
    void insertfirst(m);
    void displayll();
    m  deletefirst();
};
template<class m>
void STLL<m>::insertfirst(m ino)
{
    struct stllnode <m>* newn=NULL;

    newn=new struct stllnode <m>;

    newn->next=NULL;
    newn->stlldata=ino;

    if(head==NULL)
    {
        head=newn;
    }

    else
    {
        newn->next=head;
        head=newn;
    }
}
template<class m>
void STLL<m>::displayll()
{
    struct stllnode <m>* temp=NULL;

    temp=head;

    cout<<"the stack is\n";
    while(temp!=NULL)
    {
        cout<<temp->stlldata<<" ";
        temp=temp->next;
    }
}
template<class m>
m STLL<m>::deletefirst()
{
    m ret;
    struct stllnode <m>* temp=head;
    if(head==NULL)
    {
        return (int)-1;
    }
    else
    {
        head=temp->next;
        ret=temp->stlldata;
        delete(temp);
    }
    return ret;
}

///stack using array

template<class y>
class arrstack
{
private:
    y *arr;
    int arrsize;
    int top;
public:
    arrstack(int no)
    {
        this->arrsize=no;
        this->arr=new y[arrsize];
        this->top=-1;
    }
    ~arrstack()
    {
        delete []arr;
    }
    void push(y);
    y pop();
    void display();
};
template<class y>
void arrstack<y>::push(y ino)
{
    if(top==(arrsize-1))
    {
        return;
    }
    top++;
    arr[top]=ino;
}

template<class y>
void arrstack<y>::display()
{
    cout<<"the stack is\n";
    for(int i=(arrsize-1);i>-1;i--)
    {
        cout<<arr[i]<<" ";
    }
}

template<class y>
y arrstack<y>::pop()
{
    y i;
    if(top==-1)
    {
        return -2;
    }
    i=arr[top];
    top--;
    return i;
}

///queue using array


template<class o>
class arrqueue
{
    o *arrq;
    int qfront;
    int qrear;
    int qsize;
public:
    arrqueue(int no)
    {
        this->qsize=no;
        this->qfront=-1;
        this->qrear=-1;
        this->arrq=new o[qsize];
    }
    ~arrqueue()
    {
        delete []arrq;
    }
    void enqueue(o);
    o dequeue();
    void display();
};

template<class o>
void arrqueue<o>::enqueue(o no)
{
    if((qfront==0)&&(qrear==(qsize-1))||(qrear==(qfront-1))%(qsize-1))
    {
        cout<<"queue is full";
        return;
    }
    else if(qfront==-1)
    {
        qfront=0;
        qrear=0;
        arrq[qrear]=no;
    }
    else if((qrear==(qsize-1))&&(qfront!=0))
    {
        qrear=0;
        arrq[qrear]=no;
    }
    else
    {
        qrear++;
        arrq[qrear]=no;
    }
}
template<class o>
o arrqueue<o>::dequeue()
{
    o temp;
    if(qfront==-1)
    {
        cout<<"queue is empty";
        return -1;
    }
    temp=arrq[qfront];

    if(qfront==qrear)
    {
        qfront=-1;
        qrear=-1;
    }
    else if(qfront==(qsize-1))
    {
        qfront=0;
    }
    else
    {
        qfront++;
    }
    return temp;
}
template<class o>
void arrqueue<o>::display()
{
    int i=0;

    cout<<"the queue is\n";

    for(i=qfront;i!=qrear;i=(i+1)%qsize)
    {
        cout<<arrq[i];
    }
    cout<<arrq[i];
}

int main()
{
    int x;
    cout<<"what to perform \n1.doubly linear linked list.\n2.doubly circular linked list.\n3.singly linear linked list.\n4.singly circular linked list\n5.stack using linked list\n6.stack using array\n7.queue using array\n"<<endl;
    cin>>x;

    switch(x)
    {
        case 1:
        {
            int value=0;
            int y=0;
            cout<<"which datatype to perform:\n1.char\n2.int\n3.float\n4.double";
            cin>>y;
            switch(y)
            {
                case 1:
                {
                    dll<char> dllobj;
                    char dlldata=0;
                    int iret=0;
                    cout<<"how many DLLNODEs to enter?"<<endl;
                    cin>>value;
                    cout<<"enter values"<<endl;
                    for(int i=1;i<=value;i++)
                    {
                        cin>>dlldata;
                        dllobj.insertfirst(dlldata);
                    }
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the element to be inserted at last"<<endl;
                    cin>>dlldata;
                    dllobj.insertlast(dlldata);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the position and dlldata to be inserted"<<endl;
                    cin>>value>>dlldata;
                    dllobj.insertatpos(value,dlldata);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"after deleting first node"<<endl;
                    cout<<dllobj.deletefirst();
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"after deleting last node"<<endl;
                    cout<<dllobj.deletelast();
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the position to be deleted:"<<endl;
                    cin>>value;
                    cout<<dllobj.deleteatpos(value);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                }
                break;

                case 2:
                {
                    dll<int> dllobj;
                    int dlldata=0;
                    int iret=0;
                    cout<<"how many DLLNODEs to enter?"<<endl;
                    cin>>value;
                    cout<<"enter values"<<endl;
                    for(int i=1;i<=value;i++)
                    {
                        cin>>dlldata;
                        dllobj.insertfirst(dlldata);
                    }
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the element to be inserted at last"<<endl;
                    cin>>dlldata;
                    dllobj.insertlast(dlldata);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the position and dlldata to be inserted"<<endl;
                    cin>>value>>dlldata;
                    dllobj.insertatpos(value,dlldata);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"after deleting first node"<<endl;
                    cout<<dllobj.deletefirst();
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"after deleting last node"<<endl;
                    cout<<dllobj.deletelast();
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the position to be deleted:"<<endl;
                    cin>>value;
                    cout<<dllobj.deleteatpos(value);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;
                }
                break;

                case 3:
                {
                    dll<float> dllobj;
                    float dlldata=0;
                    int iret=0;
                    cout<<"how many DLLNODEs to enter?"<<endl;
                    cin>>value;
                    cout<<"enter values"<<endl;
                    for(int i=1;i<=value;i++)
                    {
                        cin>>dlldata;
                        dllobj.insertfirst(dlldata);
                    }
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the element to be inserted at last"<<endl;
                    cin>>dlldata;
                    dllobj.insertlast(dlldata);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the position and dlldata to be inserted"<<endl;
                    cin>>value>>dlldata;
                    dllobj.insertatpos(value,dlldata);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"after deleting first node"<<endl;
                    cout<<dllobj.deletefirst();
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"after deleting last node"<<endl;
                    cout<<dllobj.deletelast();
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the position to be deleted:"<<endl;
                    cin>>value;
                    cout<<dllobj.deleteatpos(value);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;
                }
                break;

                case 4:
                {
                    dll<double> dllobj;
                    double dlldata=0;
                    int iret=0;
                    cout<<"how many DLLNODEs to enter?"<<endl;
                    cin>>value;
                    cout<<"enter values"<<endl;
                    for(int i=1;i<=value;i++)
                    {
                        cin>>dlldata;
                        dllobj.insertfirst(dlldata);
                    }
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the element to be inserted at last"<<endl;
                    cin>>dlldata;
                    dllobj.insertlast(dlldata);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the position and dlldata to be inserted"<<endl;
                    cin>>value>>dlldata;
                    dllobj.insertatpos(value,dlldata);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"after deleting first node"<<endl;
                    cout<<dllobj.deletefirst();
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"after deleting last node"<<endl;
                    cout<<dllobj.deletelast();
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;

                    cout<<"enter the position to be deleted:"<<endl;
                    cin>>value;
                    cout<<dllobj.deleteatpos(value);
                    dllobj.displayf();
                    cout<<endl;
                    dllobj.displayr();
                    cout<<endl;
                    iret=dllobj.countn();
                    cout<<"count of node is:"<<iret<<endl;
                }
                break;
            }
        }
        break;

        case 2:
        {
            int value=0;
            int x=0;
            cout<<"which datatype to use:\n1.char\n2.int\n3.float\n4.double\n";
            cin>>x;
            switch(x)
            {
                case 1:
                {///char
                    dcll<char> dcllobj;
                    char data='\0';
                    cout<<"how many nodes?"<<endl;
                    cin>>value;
                    cout<<"enter values"<<endl;
                    for(int i=1;i<=value;i++)
                    {
                        cin>>data;
                        dcllobj.insertfirst(data);
                    }
                    dcllobj.displayf();
                    cout<<endl;
                    dcllobj.displayr();
                    cout<<endl;
                    int iret=0;
                    iret=dcllobj.countn();
                    cout<<"count of nodes is:"<<iret;
                    cout<<endl;

                    cout<<"enter the element to insert last:"<<endl;
                    cin>>data;
                    dcllobj.insertlast(data);
                    dcllobj.displayf();
                    cout<<endl;
                    dcllobj.displayr();
                    cout<<endl;
                    iret=dcllobj.countn();
                    cout<<"count of nodes is:"<<iret;
                    cout<<endl;

                    cout<<"enter position and data to be inserted"<<endl;
                    cin>>value>>data;
                    dcllobj.insertatpos(value,data);
                    dcllobj.displayf();
                    cout<<endl;
                    dcllobj.displayr();
                    cout<<endl;
                    iret=dcllobj.countn();
                    cout<<"count of nodes is:"<<iret;
                    cout<<endl;

                    cout<<"after deleting first node"<<endl;
                    cout<<"deleted data of first node is:"<<dcllobj.deletefirst();
                    cout<<endl;
                    dcllobj.displayf();
                    cout<<endl;
                    dcllobj.displayr();
                    cout<<endl;
                    iret=dcllobj.countn();
                    cout<<"count of nodes is:"<<iret;
                    cout<<endl;

                    cout<<"after deleting last node"<<endl;
                    cout<<"deleted data of last node is:"<<dcllobj.deletelast();
                    cout<<endl;
                    dcllobj.displayf();
                    cout<<endl;
                    dcllobj.displayr();
                    cout<<endl;
                    iret=dcllobj.countn();
                    cout<<"count of nodes is:"<<iret;
                    cout<<endl;

                    cout<<"enter the position to delete"<<endl;
                    cin>>value;
                    iret=dcllobj.deleteatpos(value);
                    cout<<"deleted data of node is"<<iret;
                    cout<<endl;
                    dcllobj.displayf();
                    cout<<endl;
                    dcllobj.displayr();
                    cout<<endl;
                    iret=dcllobj.countn();
                    cout<<"count of nodes is:"<<iret;
                    cout<<endl;
                }
                break;

            case 2:
            {///int
                dcll<int> idcllobj;
                int data=0;
                cout<<"how many nodes?"<<endl;
                cin>>value;
                cout<<"enter values"<<endl;
                for(int i=1;i<=value;i++)
                {
                    cin>>data;
                    idcllobj.insertfirst(data);
                }
                idcllobj.displayf();
                cout<<endl;
                idcllobj.displayr();
                cout<<endl;
                int iret=0;
                iret=idcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"enter the element to insert last:"<<endl;
                cin>>data;
                idcllobj.insertlast(data);
                idcllobj.displayf();
                cout<<endl;
                idcllobj.displayr();
                cout<<endl;
                iret=idcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"enter position and data to be inserted"<<endl;
                cin>>value>>data;
                idcllobj.insertatpos(value,data);
                idcllobj.displayf();
                cout<<endl;
                idcllobj.displayr();
                cout<<endl;
                iret=idcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"after deleting first node"<<endl;
                cout<<"deleted data of first node is:"<<idcllobj.deletefirst();
                cout<<endl;
                idcllobj.displayf();
                cout<<endl;
                idcllobj.displayr();
                cout<<endl;
                iret=idcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"after deleting last node"<<endl;
                cout<<"deleted data of last node is:"<<idcllobj.deletelast();
                cout<<endl;
                idcllobj.displayf();
                cout<<endl;
                idcllobj.displayr();
                cout<<endl;
                iret=idcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"enter the position to delete"<<endl;
                cin>>value;
                iret=idcllobj.deleteatpos(value);
                cout<<"deleted data of node is"<<iret;
                cout<<endl;
                idcllobj.displayf();
                cout<<endl;
                idcllobj.displayr();
                cout<<endl;
                iret=idcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;
            }
            break;

        case 3:
        {   ///float
            dcll<float> dcllobj;
            float data=0.0;
            cout<<"how many nodes?"<<endl;
            cin>>value;
            cout<<"enter values"<<endl;
            for(int i=1;i<=value;i++)
            {
                cin>>data;
                dcllobj.insertfirst(data);
            }
            dcllobj.displayf();
            cout<<endl;
            dcllobj.displayr();
            cout<<endl;
            int iret=0;
            iret=dcllobj.countn();
            cout<<"count of nodes is:"<<iret;
            cout<<endl;

            cout<<"enter the element to insert last:"<<endl;
            cin>>data;
            dcllobj.insertlast(data);
            dcllobj.displayf();
            cout<<endl;
            dcllobj.displayr();
            cout<<endl;
            iret=dcllobj.countn();
            cout<<"count of nodes is:"<<iret;
            cout<<endl;

            cout<<"enter position and data to be inserted"<<endl;
            cin>>value>>data;
            dcllobj.insertatpos(value,data);
            dcllobj.displayf();
            cout<<endl;
            dcllobj.displayr();
            cout<<endl;
            iret=dcllobj.countn();
            cout<<"count of nodes is:"<<iret;
            cout<<endl;

            cout<<"after deleting first node"<<endl;
            cout<<"deleted data of first node is:"<<dcllobj.deletefirst();
            cout<<endl;
            dcllobj.displayf();
            cout<<endl;
            dcllobj.displayr();
            cout<<endl;
            iret=dcllobj.countn();
            cout<<"count of nodes is:"<<iret;
            cout<<endl;

            cout<<"after deleting last node"<<endl;
            cout<<"deleted data of last node is:"<<dcllobj.deletelast();
            cout<<endl;
            dcllobj.displayf();
            cout<<endl;
            dcllobj.displayr();
            cout<<endl;
            iret=dcllobj.countn();
            cout<<"count of nodes is:"<<iret;
            cout<<endl;

            cout<<"enter the position to delete"<<endl;
            cin>>value;
            iret=dcllobj.deleteatpos(value);
            cout<<"deleted data of node is"<<iret;
            cout<<endl;
            dcllobj.displayf();
            cout<<endl;
            dcllobj.displayr();
            cout<<endl;
            iret=dcllobj.countn();
            cout<<"count of nodes is:"<<iret;
            cout<<endl;
        }
        break;
        case 4:
        {///double
                dcll<double> dcllobj;
                double data=0.0;
                cout<<"how many nodes?"<<endl;
                cin>>value;
                cout<<"enter values"<<endl;
                for(int i=1;i<=value;i++)
                {
                    cin>>data;
                    dcllobj.insertfirst(data);
                }
                dcllobj.displayf();
                cout<<endl;
                dcllobj.displayr();
                cout<<endl;
                int iret=0;
                iret=dcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"enter the element to insert last:"<<endl;
                cin>>data;
                dcllobj.insertlast(data);
                dcllobj.displayf();
                cout<<endl;
                dcllobj.displayr();
                cout<<endl;
                iret=dcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"enter position and data to be inserted"<<endl;
                cin>>value>>data;
                dcllobj.insertatpos(value,data);
                dcllobj.displayf();
                cout<<endl;
                dcllobj.displayr();
                cout<<endl;
                iret=dcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"after deleting first node"<<endl;
                cout<<"deleted data of first node is:"<<dcllobj.deletefirst();
                cout<<endl;
                dcllobj.displayf();
                cout<<endl;
                dcllobj.displayr();
                cout<<endl;
                iret=dcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"after deleting last node"<<endl;
                cout<<"deleted data of last node is:"<<dcllobj.deletelast();
                cout<<endl;
                dcllobj.displayf();
                cout<<endl;
                dcllobj.displayr();
                cout<<endl;
                iret=dcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;

                cout<<"enter the position to delete"<<endl;
                cin>>value;
                iret=dcllobj.deleteatpos(value);
                cout<<"deleted data of node is"<<iret;
                cout<<endl;
                dcllobj.displayf();
                cout<<endl;
                dcllobj.displayr();
                cout<<endl;
                iret=dcllobj.countn();
                cout<<"count of nodes is:"<<iret;
                cout<<endl;
            }
            break;
        }
        break;
    }

    case 3:
    {
            int ivalue=0;
            int w=0;
            cout<<"which datatype to use:\n1.char\n2.int\n3.float\n4.double\n";
            cin>>w;
            switch(w)
            {
                case 1:
                {
                    SLL<char> sllobj;
                    char idata=0;
                    cout<<"how many nodes?"<<endl;
                    cin>>ivalue;
                    cout<<"enter value to be insert"<<endl;
                    for(int i=1;i<=ivalue;i++)
                    {
                        cin>>idata;
                        sllobj.insertfirst(idata);
                    }

                    sllobj.displayll();
                    cout<<endl;

                    int iret=sllobj.countll();
                    cout<<"\ncount of node is :"<<iret;
                    cout<<endl;
                    cout<<"enter data to be inserted at last"<<endl;
                    cin>>idata;
                    cout<<endl;

                    sllobj.insertlast(idata);

                    sllobj.displayll();
                    cout<<endl;

                    iret=sllobj.countll();
                    cout<<"\ncount of node is :"<<iret;
                    cout<<endl;

                    cout<<"enter the position & data"<<endl;
                    cin>>ivalue>>idata;
                    sllobj.insertatpos(ivalue,idata);

                    sllobj.displayll();
                    cout<<endl;

                    iret=sllobj.countll();
                    cout<<"\ncount of node is :"<<iret;
                    cout<<endl;

                    cout<<endl<<"after deleting first node"<<endl;
                    cout<<"data of deleted node is :"<<sllobj.deletefirst();
                    cout<<endl;
                    sllobj.displayll();

                    iret=sllobj.countll();
                    cout<<"\ncount of node is :"<<iret;
                    cout<<endl;

                    cout<<"after deleting last node"<<endl;
                    cout<<"data of deleted node is :"<<sllobj.deletelast();
                    cout<<endl;
                    sllobj.displayll();

                    iret=sllobj.countll();
                    cout<<"\ncount of node is :"<<iret;
                    cout<<endl;

                    cout<<"insert the position to delete node"<<endl;
                    cin>>ivalue;
                    cout<<"data of deleted node is:"<<sllobj.deleteatpos(ivalue);
                    cout<<endl;
                    sllobj.displayll();

                    iret=sllobj.countll();
                    cout<<"\ncount of node is :"<<iret;
                    cout<<endl;
                }
                break;

            case 2:
            {
                SLL<int> sllobj;
                int idata=0;
                cout<<"how many nodes?"<<endl;
                cin>>ivalue;
                cout<<"enter value to be insert"<<endl;
                for(int i=1;i<=ivalue;i++)
                {
                    cin>>idata;
                    sllobj.insertfirst(idata);
                }

                sllobj.displayll();
                cout<<endl;

                int iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"enter data to be inserted at last"<<endl;
                cin>>idata;
                cout<<endl;

                sllobj.insertlast(idata);

                sllobj.displayll();
                cout<<endl;

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"enter the position & data"<<endl;
                cin>>ivalue>>idata;
                sllobj.insertatpos(ivalue,idata);

                sllobj.displayll();
                cout<<endl;

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<endl<<"after deleting first node"<<endl;
                cout<<"data of deleted node is :"<<sllobj.deletefirst();
                cout<<endl;
                sllobj.displayll();

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"after deleting last node"<<endl;
                cout<<"data of deleted node is :"<<sllobj.deletelast();
                cout<<endl;
                sllobj.displayll();

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"insert the position to delete node"<<endl;
                cin>>ivalue;
                cout<<"data of deleted node is:"<<sllobj.deleteatpos(ivalue);
                cout<<endl;
                sllobj.displayll();

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;
            }
            break;

            case 3:
            {
                SLL<float> sllobj;
                float idata=0;
                cout<<"how many nodes?"<<endl;
                cin>>ivalue;
                cout<<"enter value to be insert"<<endl;
                for(int i=1;i<=ivalue;i++)
                {
                    cin>>idata;
                    sllobj.insertfirst(idata);
                }

                sllobj.displayll();
                cout<<endl;

                int iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"enter data to be inserted at last"<<endl;
                cin>>idata;
                cout<<endl;

                sllobj.insertlast(idata);

                sllobj.displayll();
                cout<<endl;

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"enter the position & data"<<endl;
                cin>>ivalue>>idata;
                sllobj.insertatpos(ivalue,idata);

                sllobj.displayll();
                cout<<endl;

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<endl<<"after deleting first node"<<endl;
                cout<<"data of deleted node is :"<<sllobj.deletefirst();
                cout<<endl;
                sllobj.displayll();

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"after deleting last node"<<endl;
                cout<<"data of deleted node is :"<<sllobj.deletelast();
                cout<<endl;
                sllobj.displayll();

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"insert the position to delete node"<<endl;
                cin>>ivalue;
                cout<<"data of deleted node is:"<<sllobj.deleteatpos(ivalue);
                cout<<endl;
                sllobj.displayll();

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;
            }
            break;

            case 4:
            {
                SLL<double> sllobj;
                double idata=0;
                cout<<"how many nodes?"<<endl;
                cin>>ivalue;
                cout<<"enter value to be insert"<<endl;
                for(int i=1;i<=ivalue;i++)
                {
                    cin>>idata;
                    sllobj.insertfirst(idata);
                }

                sllobj.displayll();
                cout<<endl;

                int iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"enter data to be inserted at last"<<endl;
                cin>>idata;
                cout<<endl;

                sllobj.insertlast(idata);

                sllobj.displayll();
                cout<<endl;

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"enter the position & data"<<endl;
                cin>>ivalue>>idata;
                sllobj.insertatpos(ivalue,idata);

                sllobj.displayll();
                cout<<endl;

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<endl<<"after deleting first node"<<endl;
                cout<<"data of deleted node is :"<<sllobj.deletefirst();
                cout<<endl;
                sllobj.displayll();

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"after deleting last node"<<endl;
                cout<<"data of deleted node is :"<<sllobj.deletelast();
                cout<<endl;
                sllobj.displayll();

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;

                cout<<"insert the position to delete node"<<endl;
                cin>>ivalue;
                cout<<"data of deleted node is:"<<sllobj.deleteatpos(ivalue);
                cout<<endl;
                sllobj.displayll();

                iret=sllobj.countll();
                cout<<"\ncount of node is :"<<iret;
                cout<<endl;
            }
            break;
        }
        break;
    }

    case 4:
    {
        int value=0;
        int z=0;
        cout<<"which datatype to use:\n1.char\n2.int\n3.float\n4.double\n";
        cin>>z;
        switch(z)
        {
            case 1:
            {
                SCLL<char> scllobj;
                char ch;
                cout<<"how many node to enter?"<<endl;
                cin>>value;
                cout<<"enter values"<<endl;
                for(int i=1;i<=value;i++)
                {
                    cin>>ch;
                    scllobj.insertfirst(ch);
                }

                scllobj.display();
                int iret=0;
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"enter element to be inserted at end"<<endl;
                cin>>ch;
                scllobj.insertlast(ch);
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                int pos=0;
                cout<<"enter the position and data"<<endl;
                cin>>pos>>ch;
                scllobj.insertatpos(pos,ch);
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"after deleting first node"<<endl;
                cout<<"deleted data of node is"<<scllobj.deletefirst()<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"after deleting last node"<<endl;
                cout<<"deleted data of node is:"<<scllobj.deletelast()<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"enter position to delete node:"<<endl;
                cin>>pos;
                cout<<"deleted data of node is:"<<scllobj.deleteatpos(pos)<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;
            }
            break;

        case 2:
        {
                SCLL<int> scllobj;
                int ch;
                cout<<"how many node to enter?"<<endl;
                cin>>value;
                cout<<"enter values"<<endl;
                for(int i=1;i<=value;i++)
                {
                    cin>>ch;
                    scllobj.insertfirst(ch);
                }

                scllobj.display();
                int iret=0;
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"enter element to be inserted at end"<<endl;
                cin>>ch;
                scllobj.insertlast(ch);
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                int pos=0;
                cout<<"enter the position and data"<<endl;
                cin>>pos>>ch;
                scllobj.insertatpos(pos,ch);
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"after deleting first node"<<endl;
                cout<<"deleted data of node is"<<scllobj.deletefirst()<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"after deleting last node"<<endl;
                cout<<"deleted data of node is:"<<scllobj.deletelast()<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"enter position to delete node:"<<endl;
                cin>>pos;
                cout<<"deleted data of node is:"<<scllobj.deleteatpos(pos)<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;
            }
            break;

        case 3:
        {
                SCLL<float> scllobj;
                float ch;
                cout<<"how many node to enter?"<<endl;
                cin>>value;
                cout<<"enter values"<<endl;
                for(int i=1;i<=value;i++)
                {
                    cin>>ch;
                    scllobj.insertfirst(ch);
                }

                scllobj.display();
                int iret=0;
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"enter element to be inserted at end"<<endl;
                cin>>ch;
                scllobj.insertlast(ch);
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                int pos=0;
                cout<<"enter the position and data"<<endl;
                cin>>pos>>ch;
                scllobj.insertatpos(pos,ch);
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"after deleting first node"<<endl;
                cout<<"deleted data of node is"<<scllobj.deletefirst()<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"after deleting last node"<<endl;
                cout<<"deleted data of node is:"<<scllobj.deletelast()<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"enter position to delete node:"<<endl;
                cin>>pos;
                cout<<"deleted data of node is:"<<scllobj.deleteatpos(pos)<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;
            }
            break;

            case 4:
            {
                SCLL<double> scllobj;
                double ch;
                cout<<"how many node to enter?"<<endl;
                cin>>value;
                cout<<"enter values"<<endl;
                for(int i=1;i<=value;i++)
                {
                    cin>>ch;
                    scllobj.insertfirst(ch);
                }

                scllobj.display();
                int iret=0;
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"enter element to be inserted at end"<<endl;
                cin>>ch;
                scllobj.insertlast(ch);
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                int pos=0;
                cout<<"enter the position and data"<<endl;
                cin>>pos>>ch;
                scllobj.insertatpos(pos,ch);
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"after deleting first node"<<endl;
                cout<<"deleted data of node is"<<scllobj.deletefirst()<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"after deleting last node"<<endl;
                cout<<"deleted data of node is:"<<scllobj.deletelast()<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;

                cout<<"enter position to delete node:"<<endl;
                cin>>pos;
                cout<<"deleted data of node is:"<<scllobj.deleteatpos(pos)<<endl;
                scllobj.display();
                iret=scllobj.countscll();
                cout<<endl<<"count of node is:"<<iret<<endl;
            }
            break;
        }
        break;
    }

    case 5:
    {
        int ivalue=0;
        int e=0;
        cout<<"which datatype to use\n1.char\n2.int\n3.float\n4.double\n";
        cin>>e;
        switch(e)
        {
            case 1:
            {
                STLL<char> sllobj;

                char idata='\0';
                cout<<"how many nodes?"<<endl;
                cin>>ivalue;
                cout<<"enter value to be insert"<<endl;
                for(int i=1;i<=ivalue;i++)
                {
                    cin>>idata;
                    sllobj.insertfirst(idata);
                }

                sllobj.displayll();
                cout<<endl;

                cout<<"how many nodes to delete?"<<endl;
                cin>>ivalue;
                for(int i=1;i<=ivalue;i++)
                {
                    cout<<"data of deleted node is :"<<sllobj.deletefirst();
                    cout<<"\n";
                }

                cout<<endl;
                sllobj.displayll();
                cout<<endl;
            }
            break;

            case 2:
            {
                STLL<int> sllobj;

                int idata=0;
                cout<<"how many nodes?"<<endl;
                cin>>ivalue;
                cout<<"enter value to be insert"<<endl;
                for(int i=1;i<=ivalue;i++)
                {
                    cin>>idata;
                    sllobj.insertfirst(idata);
                }

                sllobj.displayll();
                cout<<endl;

                cout<<"how many nodes to delete?"<<endl;
                cin>>ivalue;
                for(int i=1;i<=ivalue;i++)
                {
                    cout<<"data of deleted node is :"<<sllobj.deletefirst();
                    cout<<"\n";
                }

                cout<<endl;
                sllobj.displayll();
                cout<<endl;

            }
            break;

            case 3:
            {
                STLL<float> sllobj;

                float idata=0.0;
                cout<<"how many nodes?"<<endl;
                cin>>ivalue;
                cout<<"enter value to be insert"<<endl;
                for(int i=1;i<=ivalue;i++)
                {
                    cin>>idata;
                    sllobj.insertfirst(idata);
                }

                sllobj.displayll();
                cout<<endl;

                cout<<"how many nodes to delete?"<<endl;
                cin>>ivalue;
                for(int i=1;i<=ivalue;i++)
                {
                    cout<<"data of deleted node is :"<<sllobj.deletefirst();
                    cout<<"\n";
                }

                cout<<endl;
                sllobj.displayll();
                cout<<endl;

            }
            break;

            case 4:
                {
                    STLL<double> sllobj;

                    double idata=0.0;
                    cout<<"how many nodes?"<<endl;
                    cin>>ivalue;
                    cout<<"enter value to be insert"<<endl;
                    for(int i=1;i<=ivalue;i++)
                    {
                        cin>>idata;
                        sllobj.insertfirst(idata);
                    }

                    sllobj.displayll();
                    cout<<endl;

                    cout<<"how many nodes to delete?"<<endl;
                    cin>>ivalue;
                    cout<<"enter value to be insert"<<endl;
                    for(int i=1;i<=ivalue;i++)
                    {
                        cout<<"data of deleted node is :"<<sllobj.deletefirst();
                        cout<<"\n";
                    }

                    cout<<endl;
                    sllobj.displayll();
                    cout<<endl;
                }
                break;
        }
        break;
    }

    case 6:
    {
        int q=0,t=0;
        cout<<"which datatype to use:\n1.char\n2.int\n3.float\n4.double\n";
        cin>>t;
        switch(t)
        {
            case 1:
            {
                char e=0;
                cout<<"how many elememts in stack?\n";
                cin>>q;
                arrstack<char> saobj(q);
                cout<<"enter values\n";
                for(int i=0;i<q;i++)
                {
                    cin>>e;
                    saobj.push(e);
                }
                saobj.display();
                cout<<endl;

                cout<<"how many nodes to delete\n";
                cin>>q;
                for(int i=0;i<q;i++)
                {
                    cout<<"data is:"<<saobj.pop()<<"\n";
                }
                cout<<"how many elememts in stack?\n";
                cin>>q;
                cout<<"enter values\n";
                for(int i=0;i<q;i++)
                {
                    cin>>e;
                    saobj.push(e);
                }

                saobj.display();
                cout<<endl;

            }
            break;

            case 2:
            {
                int e=0;
                cout<<"how many elememts in stack?\n";
                cin>>q;
                arrstack<int> saobj(q);
                cout<<"enter values\n";
                for(int i=0;i<q;i++)
                {
                    cin>>e;
                    saobj.push(e);
                }
                saobj.display();
                cout<<endl;

                cout<<"how many nodes to delete\n";
                cin>>q;
                for(int i=0;i<q;i++)
                {
                    cout<<"data is:"<<saobj.pop()<<"\n";
                }
                cout<<"how many elememts in stack?\n";
                cin>>q;
                cout<<"enter values\n";
                for(int i=0;i<q;i++)
                {
                    cin>>e;
                    saobj.push(e);
                }

                saobj.display();
                cout<<endl;

            }
            break;
            case 3:
            {
                float e=0;
                cout<<"how many elememts in stack?\n";
                cin>>q;
                arrstack<float> saobj(q);
                cout<<"enter values\n";
                for(int i=0;i<q;i++)
                {
                    cin>>e;
                    saobj.push(e);
                }
                saobj.display();
                cout<<endl;

                cout<<"how many nodes to delete\n";
                cin>>q;
                for(int i=0;i<q;i++)
                {
                    cout<<"data is:"<<saobj.pop()<<"\n";
                }
                cout<<"how many elememts in stack?\n";
                cin>>q;
                cout<<"enter values\n";
                for(int i=0;i<q;i++)
                {
                    cin>>e;
                    saobj.push(e);
                }

                saobj.display();
                cout<<endl;

            }
            break;
            case 4:
            {
                double e=0;
                cout<<"how many elememts in stack?\n";
                cin>>q;
                arrstack<double> saobj(q);
                cout<<"enter values\n";
                for(int i=0;i<q;i++)
                {
                    cin>>e;
                    saobj.push(e);
                }
                saobj.display();
                cout<<endl;

                cout<<"how many nodes to delete\n";
                cin>>q;
                for(int i=0;i<q;i++)
                {
                    cout<<"data is:"<<saobj.pop()<<"\n";
                }
                cout<<"how many elements in stack?\n";
                cin>>q;
                cout<<"enter values\n";
                for(int i=0;i<q;i++)
                {
                    cin>>e;
                    saobj.push(e);
                }

                saobj.display();
                cout<<endl;
            }
            break;
        }

    }
    break;
        case 7:
                {
                    {
    int qsize;
    cout<<"size of arrray is?\n";
    cin>>qsize;
    int t;
    cout<<"which datatype to use:\n1.char\n2.int\n3.float\n4.double\n";
    cin>>t;
    switch(t)
    {
        case 1:
        {
            arrqueue<char> quobj(qsize);
            char ch='\0';
            int value=0;

            cout<<"enter "<<qsize<<" elements\n";
            for(int i=1;i<=qsize;i++)
            {
                cin>>ch;
                quobj.enqueue(ch);
            }
            quobj.display();
            cout<<"\nhow many entries to delete?\n";
            cin>>value;
            for(int i=1;i<=value;i++)
            {
                cout<<quobj.dequeue()<<"\n";
            }
            quobj.display();
        }
        break;
        case 2:
        {
            arrqueue<int> quobj(qsize);
            int ch=0;
            int value=0;

            cout<<"enter "<<qsize<<" elements\n";
            for(int i=1;i<=qsize;i++)
            {
                cin>>ch;
                quobj.enqueue(ch);
            }
            quobj.display();
            cout<<"\nhow many entries to delete?\n";
            cin>>value;
            for(int i=1;i<=value;i++)
            {
                cout<<quobj.dequeue()<<"\n";
            }
            quobj.display();
        }
        break;
        case 3:
        {
            arrqueue<float> quobj(qsize);
            float ch=0;
            int value=0;

            cout<<"enter "<<qsize<<" elements\n";
            for(int i=1;i<=qsize;i++)
            {
                cin>>ch;
                quobj.enqueue(ch);
            }
            quobj.display();
            cout<<"\nhow many entries to delete?\n";
            cin>>value;
            for(int i=1;i<=value;i++)
            {
                cout<<quobj.dequeue()<<"\n";
            }
            quobj.display();
        }
        break;
        case 4:
        {
            arrqueue<double> quobj(qsize);
            double ch=0;
            int value=0;

            cout<<"enter "<<qsize<<" elements\n";
            for(int i=1;i<=qsize;i++)
            {
                cin>>ch;
                quobj.enqueue(ch);
            }
            quobj.display();
            cout<<"\nhow many entries to delete?\n";
            cin>>value;
            for(int i=1;i<=value;i++)
            {
                cout<<quobj.dequeue()<<"\n";
            }
            quobj.display();
        }
        break;
    }

                }
    return 0;
    }
}}
