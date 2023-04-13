#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct std
{
    int roll_no,age;
    char name[33];
    char gender, section,ph_no[15],pincode[10];
    struct std *next;
}node;

node *create();
void display(node *);
void totcount(node *);
void search_name(node *,char ndata[32]);
void search_rollno(node *,int);
void search_phno(node *, char pdata[15]);
node *addatbeg(node *);
node *addatend(node *);
node *addatpos(node *,int);
node *delete(node *,int);


 
void main(){
    node *start;
    char ndata[33],pdata[15];
    int rdata,ch,item,pos;
    start=NULL;
    do
    {
        printf("ENTER YOUR CHOICE\n");
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Count the no. of students\n");
        printf("4.Add at the beginning\n");
        printf("5.Add at the end\n");
        printf("6.Add at position\n");
        printf("7.Search by name\n");
        printf("8.Search by roll number\n");
        printf("9.Search by phone number\n");
        printf("10.Delete\n");
        printf("11.Quit\n\n");
         
        printf("Enter your choice : ");
        scanf("%d",&ch);
         
        switch(ch)
        {
         case 1:
            start=create();
            break;
         case 2:
            display(start);
            break;
         case 3:
            totcount(start);
            break;
         case 4:
            start=addatbeg(start);
            break;
         case 5:
            start=addatend(start);
            break;
         case 6:
            printf("Enter the position at which to insert : ");
            scanf("%d",&pos);
            start=addatpos(start,pos);
            break;
         case 7:
            printf("Enter the name to be searched : ");
            scanf("%s",ndata);
            search_name(start,ndata);
            break;
         case 8:
            printf("Enter the roll number to be searched : ");
            scanf("%d",&rdata);
            search_rollno(start,rdata);
            break;
         case 9:
            printf("Enter the phone number to be searched : ");
            scanf("%s",pdata);
            search_phno(start,pdata);
            break;
         case 10:
            printf("Enter the roll no to be deleted : ");
            scanf("%d",&rdata);
            start=delete(start, rdata);   
            break;
         case 11:
             exit(0);
         default:
             printf("Wrong choice\n");
        }
    }while(ch!=11);
}

node *create()
{
    int roll_no,flag = 1,age;
    char Name[33],gender,ph_no[15],pincode[10];
    char section;
    char ans='y';
    node *tempr,*new,*start;
    node *getnode();
    tempr=NULL;
    do
    {
        printf("Enter the roll number : \n");
        scanf("%d",&roll_no);
        printf("Enter name of student : \n");
        scanf("%s",Name);
        printf("Enter the gender : \n");
        scanf("%s",&gender);
        printf("Enter the section A or B : \n");
        scanf("%s",&section);
        printf("Enter the age : \n");
        scanf("%d",&age);
        if(age<14){
            printf("minimum age should be 14\n");
            printf("Enter the age : \n");
            scanf("%d",&age);
        }
        printf("Enter phone no. of parent : \n");
        scanf("%s",ph_no);
        if(strlen(ph_no)!=10)
            printf("enter valid 10 digit phone number\n");
        printf("Enter 6 digit pincode : \n");
        scanf("%s",pincode);
        if(strlen(pincode)!=6)
            printf("enter valid pincode\n");
        new=getnode();
        if(new==NULL)
        printf("\nMemory is not allocated : \n");
        new->roll_no=roll_no;
        strcpy(new->name,Name);
        new->section=section;
        new->gender=gender;
        new->age=age;
        strcpy(new->ph_no,ph_no);
        strcpy(new->pincode,pincode);
        if(flag==1)
        {
            start=new;
            tempr=start;
            flag=0;
        }
        else
        {
            tempr->next=new;
            tempr=new;
        }
    printf("\nDo you want to enter more elements(y/n) : \n");
    //ans=getch();
    scanf("%s",&ans);
    } while (ans=='y');
    printf("\nThe list is created\n");
    return start;
}
node *getnode()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    return temp;
}

void display(node *start)
{
    node *p;
    p=start;
    if(p==NULL)
    {
        printf("Record is empty\n");
        return;
    }
    printf("List is :\n");
    while(p!=NULL)
    {
        printf("%d|%s|%c|%c|%d|%s|%s \n",p->roll_no,p->name,p->section,p->gender,p->age,p->ph_no,p->pincode);
        p=p->next;
    }
    printf("\n\n");
}

void totcount(node *start)
{
    node *p;
    int count=0;
    p=start;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    printf("Number of elements are %d\n",count);
}

void search_name(node *start,char ndata[33])
{
    node *p;
    p=start;
    int pos=1;
    /*char ndata[32];
    printf("Enter the name to be searched : ");
    scanf("%s",ndata);*/
    while(p!=NULL)
    {
        if(strcmp(p->name,ndata)==0)
        printf("Item %s found at position %d\n",ndata,pos);
        p=p->next;
        pos++;
    }
    printf("Item %s not found in list\n",ndata);
}

void search_rollno(node *start,int rdata)
{
    node *p;
    p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(p->roll_no==rdata)
        printf("Item %d found at position %d\n",rdata,pos);
        p=p->next;
        pos++;
    }
    printf("Item %d not found in list\n",rdata);
}

void search_phno(node *start,char pdata[15])
{
    node *p;
    p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(strcmp(p->ph_no,pdata)==0)
        printf("Item %s found at position %d\n",pdata,pos);
        p=p->next;
        pos++;
    }
    printf("Item %s not found in list\n",pdata);
}

node *addatbeg(node *start)
{
    node *tmp,*new;
    new=getnode();

    printf("Enter the roll number : ");
    scanf("%d",&new->roll_no);
    printf("Enter name of student : ");
    scanf("%s",new->name);
    printf("Enter the section A or B: ");
    scanf("%s",&new->section);
    printf("Enter the gender : ");
    scanf("%s",&new->gender);
    printf("Enter the age : ");
    scanf("%d",&new->age);
    if(new->age<14)
        printf("minimum age is 14");
    printf("Enter phone no. of parent : ");
    scanf("%s",new->ph_no);
    if(strlen(new->ph_no)!=10)
        printf("enter valid 10 digit phone number");
    printf("Enter 6 digit pincode : ");
    scanf("%s",new->pincode);
    if(strlen(new->pincode)!=6)
        printf("enter valid pincode");
    if(start==NULL)
    start=new;
    else
    {
        tmp=start;
        new->next=tmp;
        start=new;
    }
    return start;
}

node *addatend(node *start)
{
    node *p,*tmp;
    p=getnode();
    printf("Enter the roll number : ");
    scanf("%d",&p->roll_no);
    printf("Enter name of student : ");
    scanf("%s",p->name);
    printf("Enter the section A or B: ");
    scanf("%s",&p->section);
    printf("Enter the gender : ");
    scanf("%s",&p->gender);
    printf("Enter the age : ");
    scanf("%d",&p->age);
    if(p->age<14)
        printf("minimum age is 14");
    printf("Enter phone no. of parent : ");
    scanf("%s",p->ph_no);
    if(strlen(p->ph_no)!=10)
        printf("enter valid 10 digit phone number");
    printf("Enter 6 digit pincode : ");
    scanf("%s",p->pincode);
    if(strlen(p->pincode)!=6)
        printf("enter valid pincode");
    
    if(start==NULL){
    start=p;
    return start;}
    else{
    tmp=start;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    tmp->next=p;
    p->next=NULL;
    return start;}
}

node *addatpos(node *start,int pos)
{
    node *tmp,*p;
    int i;
    tmp=getnode();
    
    printf("Enter the roll number : ");
    scanf("%d",&tmp->roll_no);
    printf("Enter name of student : ");
    scanf("%s",tmp->name);
    printf("Enter the section A or B: ");
    scanf("%s",&tmp->section);
    printf("Enter the gender : ");
    scanf("%s",&tmp->gender);
    printf("Enter the age : ");
    scanf("%d",&tmp->age);
    if(tmp->age<14)
        printf("minimum age is 14");
    printf("Enter phone no. of parent : ");
    scanf("%s",tmp->ph_no);
    if(strlen(tmp->ph_no)!=10)
        printf("enter valid 10 digit phone number");
    printf("Enter 6 digit pincode : ");
    scanf("%s",tmp->pincode);
    if(strlen(tmp->pincode)!=6)
        printf("enter valid pincode");
    if(pos==1)
    {
        tmp->next=start;
        start=tmp;
        return start;
    }
    p=start;
    for(i=1; i<pos-1 && p!=NULL; i++)
        p=p->next;
    if(p==NULL)
        printf("There are less than %d elements\n",pos);
    else
    {
        tmp->next=p->next;
        p->next=tmp;
    }   
    return start;
}

node *delete(node *start,int rdata)
{
    node *tmp,*p;
    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }
    //Deletion of first node
    if(start->roll_no==rdata)
    {
        tmp=start;
        start=start->next; 
        printf("deleted node is %s \n",tmp->name);
        //free(tmp);
        return start;
    }
    //Deletion in between or at the end
    p=start;
    while(p->next!=NULL)
    {
        if(p->next->roll_no==rdata)  
        {
            tmp=p->next;
            p->next=tmp->next;
            //free(tmp);
            
            printf("deleted node is %s \n",tmp->name);
            return start;
        }
        p=p->next;
        
        
    }
    
    printf("Element %d not found\n",rdata);
    
    return start;
}
