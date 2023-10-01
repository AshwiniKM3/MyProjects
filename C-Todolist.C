#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
char data[100];
struct node *next;
};
struct node *s=NULL;
void create1(char a[100]);
void create();
void add();
void done();
void del();
void display();
void _display_done();
int main()
{
int ch;
clrscr();
while(1)
{
printf("\n**************************CREATE YOUR TO-DO LIST*******************\n");
printf("\t\t\tMENU\n-----------------------------------------------------");
printf("\n1.create\n2.add\n3.task done!\n4.delete a task\n5.My list\n6.exit");
printf("\n------------------------------------------------------------------");
printf("\n enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
int a;
printf("enter 1 for continue 0 for exit");
scanf("%d",&a);
while(a!=0)
{
create();
printf("1 for add 0 for exit");
scanf("%d",&a);
}
display();
break;
}
case 2:
add();
break;
case 3:
done();
break;
case 4:
del();
break;
case 5:
display();
break;
case 6:
exit(0);
break;
default:
printf("\ninvalid option\n");
break;
}
}
return 0;
}
void create()
{
struct node *p,*s1;
p=(struct node *)malloc(sizeof(struct node));
printf("\n enter task\n");
scanf("%s",&p->data);
p->next=NULL;
if(s==NULL)
s=p;
else
{
s1=s;
while(s1->next!=NULL)
{
s1=s1->next;
}
s1->next=p;
}
}
void display()
{
struct node *s1;
if(s==NULL)
{
textcolor(YELLOW);
cprintf("You do not have any task\n");
return;
}
else
{
s1=s;
textcolor(MAGENTA);
textbackground(BLACK);
cprintf("=============TO-DO=============\n");
printf("\n");
while(s1!=NULL)
{
cprintf("|");
cprintf("%s",s1->data);
printf("\t\t\t\t");
cprintf("|");
printf("\n");
s1=s1->next ;
}
cprintf("===============================\n");
}
}
void add()
{
int o;
struct node *p,*s1;
p=(struct node*)malloc(sizeof(struct node));
printf("\n1.add at beginning\n2.add at end\n3. add at nth position\nenter option:");
scanf("%d",&o);
switch(o)
{
case 1:
{
printf("\nenter the task:");
scanf("%s",&p->data);
p->next=NULL;
if(s==NULL)
s=p;
else
{
p->next=s;
s=p;
}
break;
}
case 2:
{
printf("\nenter the task:");
scanf("%s",&p->data);
p->next=NULL;
if(s==NULL)
{
s=p;
}
else
{
s1=s;
while(s1->next!=NULL)
{
s1=s1->next;
}
s1->next=p;
}
break;
}
case 3:
{
int i,pos;
printf("\nenter the position:");
scanf("%d",&pos);
printf("\nenter the task");
scanf("%s",&p->data);
p->next=NULL;
if(pos==0)
{
p->next=s;
s=p;
}
else
{
s1=s;
for(i=0;i<pos-2;i++)
s1=s1->next;
}
p->next=s1->next;
s1->next=p;
break;
}
default :
printf("invalid");
break;
}
}
void done()
{
struct node *s1;
if(s==NULL)
{
printf("\nempty");
exit(1);
}
else
{
s1=s;
s=s->next;
textcolor(GREEN);
printf("\n");
cprintf("you have finished %s !",s1->data);
printf("\n");
cprintf("and is out of list ");

free(s1);
}
}
void del()
{
int i,pos;
struct node *s1,*temp;
if(s==NULL)
{
printf("\nempty");
exit(0);
}
else
{
printf("\nenter the position");
scanf("%d",&pos);
if(pos==0)
{
s1=s;
s=s->next;
printf("%s is deleted",s1->data);
free(s1);
}
else
{
s1=s;
for(i=0;i<pos-1;i++&&s1->next!=NULL)
{
temp=s1;
s1=s1->next;
}
}
temp->next=s1->next;
printf("\n%s is deleted",s1->data);
free(s1);
}
}


