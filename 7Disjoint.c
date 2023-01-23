#include<stdio.h>
#include<stdlib.h>
typedef struct
{
int value;
struct rep*repptr;
struct node*next;
}node;
typedef struct{
node*head;
node*tail;
}rep;
typedef struct{
int key;
node *obj_node_ptr;
struct nodaddr *next;
}nodaddr;
nodaddr *ndr=0;
void makeset(int a)
{
nodaddr *t=(nodaddr *)malloc(sizeof(nodaddr));
rep *newset=(rep*)malloc(sizeof(node));
node *n=(node *)malloc(sizeof(node));
n->value=a;
n->repptr=newset;
n->next=ndr;
ndr=t;
}
rep *find(int x)
{
nodaddr *t=ndr;
while(t->key!=x && t!=0)
t=t->next;
return t->obj_node_ptr->repptr;
}
void unionset(int key1,int key2)
{
rep*set1,*set2;
node*t1;
set1=find(key1);
set2=find(key2);
if(set1==set2)
print("\n %d and %d belongs to same set\n",key1,key2);
else
{
t1=set2->head;
while(t1!=0)
{
t1->repptr=set1;
t1=t1->next;
}
set1->tail=set2->tail;
set1->tail->next=set2->head;
free(set2);
}}
void display(int a)
{
rep *r;
node *t;
r=find(a);
t=r->head;
printf("set number containing %d:",a);
while(t!=0)
{
printf("%d",t->value);
t=t->next;
}
}
main()
{
int opt,data,data1,data2;
makeset(10);
makeset(20);
makeset(30);
makeset(40);
makeset(50);
do
{
printf("1.makeset");
printf("2.findset");
printf("3.unionset");
printf("4.dispaly set");
printf("5.exit");
printf("enter your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("enter data:");
scanf("%d",&data);
makeset(data);
break;
case 2:
printf("enter the data:");
scanf("%d",&data);
printf("reference of set containing %d is %x",data,findset(data));
break;
case 3:
printf("enter data:");
scanf("%d",&data);
printf("enter data2:");
scanf("%d",&data2);
unionset(data1,data2);
break;
case 4:
printf("enter the data:");
scanf("%d",&data);
display(data);
break;
case 5:exit(0);
}
}
while(1);
}
