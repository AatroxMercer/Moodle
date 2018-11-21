#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#define LEN sizeof(struct datas)
using namespace std;
int delsign=0;

struct datas
{
    string id,clas,name;
    double score[3],ans;
    struct datas *next;
}
stu[4]={{"1001","11","zhang",{99.5,88.5,89.5},277.5},{"1002","22","li",{77.9,56.5,87.5},221.9},{"1003","11","wang",{92.5,99.0,60.5},252.0}};

struct datas *head=NULL,*last=NULL;

void precreate()
{
    head=&stu[0];
    stu[0].next=&stu[1];
    stu[1].next=&stu[2];
    stu[2].next=NULL;
}

struct datas *seek1 (string x)
{
    struct datas *p2=NULL,*p1=NULL;
    p2=head->next;
    if (head->id==x)
        return head;
    while (1)
    {
        if (p2==NULL) break;
        p1=p2;
        p2=p2->next;
        if (p1->id==x) { return p1;}
    }
    last=p1;
    return NULL;
}

struct datas *seek2 (string x)
{
    struct datas *p2=NULL;
    p2=head;
    delsign=0;
    if (head->id==x||head->name==x)
       {
           delsign=1;
           return head;

       }
    while (1)
    {
        if (p2->next==NULL) break;
        if ((p2->next)->id==x||(p2->next)->name==x) return p2;
        p2=p2->next;
    }
    return NULL;
}


void seek3 (string x)
{
    struct datas *p2=NULL;
    p2=head;
    int sign=0;
    while (p2!=NULL)
    {
        if (p2->id==x||p2->clas==x)
            {
                sign=1;
                cout<<(p2->id)<<','<<(p2->clas)<<','<<(p2->name)<<',';
                printf("%.1lf,%.1lf,%.1lf,%.1lf\n",p2->score[0],p2->score[1],p2->score[2],p2->ans);
            }
        p2=p2->next;
    }
    if (sign==0) cout<<"there is no eligible student"<<endl;
}


void del(struct datas *delpoint)
{
    if (delpoint==NULL) return;
    else if (delpoint==head&&delsign==1) head=head->next;
    else delpoint->next=(delpoint->next)->next;
}


void mysort()
{
    int number=1,times=0;
    struct datas *p1,*p2,*p3,*tmp1,*tmp2;
    if ((head->clas)>((head->next)->clas))
    {
   //    cout<<"&&&&&&";
        tmp2=head;
        tmp1=head->next;
        head->next=(head->next)->next;
        head=tmp1;
        head->next=tmp2;
    }
    else if ((head->clas)==((head->next)->clas))
    {
         if ((head->ans)<((head->next)->ans))
        {
            tmp2=head;
            tmp1=head->next;
            head->next=(head->next)->next;
            head=tmp1;
            head->next=tmp2;
        }
    }
    p1=head;
    p2=p1->next;
    p3=p2->next;
    while (p3!=0)
    {
        number+=1;
        if ((p2->clas)>(p3->clas))
        {
            p1->next=p3;
            tmp1=p3->next;
            p3->next=p2;
            p2->next=tmp1;
        }
        else if (p2->clas==p3->clas)
        {
            if ((p2->ans)<(p3->ans))
            {
                p1->next=p3;
                tmp1=p3->next;
                p3->next=p2;
                p2->next=tmp1;
            }
        }
        p1=p2;
        p2=p3;
        p3=p3->next;
    }
    for (int i=0;i<number-1;i++)
    {
        if ((head->clas)>((head->next)->clas))
        {
            tmp2=head;
            tmp1=head->next;
            head->next=(head->next)->next;
            head=tmp1;
            head->next=tmp2;
        }
        else if ((head->clas)==((head->next)->clas))
        {
            if ((head->ans)<((head->next)->ans))
            {
                tmp2=head;
                tmp1=head->next;
                head->next=(head->next)->next;
                head=tmp1;
                head->next=tmp2;
            }
        }
        p1=head;
        p2=p1->next;
        p3=p2->next;
        times=1;
        while (p3!=0)
        {
            times+=1;
            number+=1;
            if ((p2->clas)>(p3->clas))
            {
                p1->next=p3;
                tmp1=p3->next;
                p3->next=p2;
                p2->next=tmp1;
            }
            else if (p2->clas==p3->clas)
            {
                if ((p2->ans)<(p3->ans))
                {
                    p1->next=p3;
                    tmp1=p3->next;
                    p3->next=p2;
                    p2->next=tmp1;
                }
            }
            p1=p2;
            p2=p3;
            p3=p3->next;
            if (times==i) return;
        }

    }
}

int preprint()
{
    int option;
    printf("1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input your option\n");
    cin>>option;
    return option;
}


void outprint()
{
    struct datas *p2=NULL;
    p2=head;
    int sign=0;
    while (p2!=NULL)
    {
        cout<<(p2->id)<<','<<(p2->clas)<<','<<(p2->name)<<',';
        printf("%.1lf,%.1lf,%.1lf,%.1lf\n",p2->score[0],p2->score[1],p2->score[2],p2->ans);
        p2=p2->next;
    }
}


void action1()
{
    string x,tmp,iden,aaa;
    int temp;
    struct datas *p=NULL,*ps=NULL;
    do
    {
        cout<<"Id ";cin>>iden;
        ps=seek1(iden);

        if (ps==NULL)
        {

            p=( struct datas*) malloc(LEN);
            last->next=p;
            p->id=iden;
            cout<<"class ";cin>>aaa;p->clas=aaa;
            cout<<"name ";cin>>aaa;p->name=aaa;
            for (int i=0;i<3;i++)
            {
                printf("score%d ",i+1);
                cin>>temp;
                p->score[i]=temp;
                p->ans+=p->score[i];
            }
            p->next=NULL;
        }
        else
        {
            cout<<"class ";cin>>ps->clas;
            cout<<"name ";cin>>ps->name;
            ps->ans=0;
            for (int i=0;i<3;i++)
            {
                printf("score%d ",i+1);
                cin>>ps->score[i];
                ps->ans+=ps->score[i];
            }

        }
        cout<<"continue?\n";
        cin>>x;
    }
    while (x=="yes");
}


void action2()
{
    string x,in;
    do
    {
        cin>>in;
        del(seek2(in));
        outprint();
        cout<<"continue?\n";
        cin>>x;
    }
    while (x=="yes");
}


void action3()
{
    string x,in;
    int sign=0;
    do
    {
        cin>>in;
        seek3(in);
        cout<<"continue?\n";
        cin>>x;
        sign=0;
    }
    while (x=="yes");
}


void action4()
{
    mysort();
    outprint();
}

void action5()
{
    outprint();
}

void action6()
{
    exit(0);
}

void optiontake(int option)
{
    switch (option)
    {
        case 1:{action1();break;}
        case 2:{action2();break;}
        case 3:{action3();break;}
        case 4:{action4();break;}
        case 5:{action5();break;}
        case 6:{action6();break;}
    }
}


int main()
{
    precreate();
    while (1)
        optiontake(preprint());
    return 0;
}
