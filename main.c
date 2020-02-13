#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void createtickets();
void search_ticket();
void display_all_ticket();
void delete_all();
void displayseat();
int seat();
void cancel();

struct bus
{
        char name[20];
        char gender[5];
        char source[20];
        char destination[20];
        int price;
        int mob_no;
        struct bus *next;
	int seat;
}s;
typedef struct bus node;
node *first=NULL,*last=NULL;




int main()
{
        int n;
        while(1)
        {
                printf("\n=============================WELLCOME TO PRUTHVI BUS BOOKINGS================================\n");
                printf("\n\t\t\t1.BOOK A TICKET\n");
				printf("\t\t\t2.CANCEL A TICKET\n");
                printf("\t\t\t3.SEARCH\n");
                printf("\t\t\t4.DISPLAY ALL TICKETS\n");
                printf("\t\t\t5.DELETE ALL TICKETS\n");
				printf("\t\t\t6.CHECK SEAT AVAILABILITY\n");
                printf("\t\t\t7.EXIT\n");
                printf("\t\t\tENTER YOUR CHOICE:");
                scanf("%d",&n);
                if(n>=7)
                break;         
                switch(n)
                {
                    	case 1: createtickets();     
                                continue;
			case 2: cancel();
				continue;
                        case 3: search_ticket();
                                continue;
                        case 4: display_all_ticket();
                                continue;
                        case 5: delete_all();
                                continue;
			case 6: displayseat();
				continue;
                        default: printf("invalid choice\n");
                                 break;
                }
        }
        printf("\t\t\t\n ======================THANK YOU FOR USING PRUTHVI BOOKINGS=====================================\n");
}
void createtickets()
{	
	int a;
        FILE *fp=fopen("ticketss.txt","a++");
        node *new=(node*)malloc(sizeof(node)); 
        printf("\n\t\t\tenter mob no:");
        scanf("%d",&s.mob_no);
        printf("\n\t\t\tenter the name of passenger:");
        scanf("%s",s.name);
        printf("\n\t\t\tenter the gender of passenger:");
        scanf("%s",s.gender);
        printf("\n\t\t\tenter the source:");
        scanf("%s",s.source);
        printf("\n\t\t\tenter the destination:");
        scanf("%s",s.destination);
        printf("\n\t\t\tenter the price:");
        scanf("%d",&s.price);
	printf("\n\t\t\tselect seat number:");
	displayseat();
	a=seat();
	
	
	printf("\n\t\t\tSeat no %d selected\n",a);
if(first==NULL)
        {
                strcpy(new->name,s.name);
                new->mob_no=s.mob_no;
                strcpy(new->gender,s.gender);
                strcpy(new->source,s.source);
                strcpy(new->destination,s.destination);
                new->price=s.price;
		new->seat=a;
                first=last=new;
        }
        else
        {
                strcpy(new->name,s.name);
                new->mob_no=s.mob_no;
                strcpy(new->gender,s.gender);
                strcpy(new->source,s.source);
                strcpy(new->destination,s.destination);
		new->seat=a;
                new->price=s.price;
                new->next=NULL;
                last->next=new;
                last=new;
        }
        fprintf(fp,"\n\t\t\tpassengername:%s\n\t\t\tmob_no:%d\n\t\t\tgender:%s\n\t\t\tsource:%s\n\t\t\tdestination:%s\n\t\t\tprice:%d\n\t\t\tseat_no:%d\n",s.name,s.mob_no,s.gender,s.source,s.destination,s.price,a);
        fclose(fp);
        printf("\t\t\tRecord of passenger %s added successfully\n\n",s.name);
}       

void search_ticket()
{
        int seat;
        printf("\t\t\tENTER A SEAT NUMBER TO SEARCH:");
        scanf("%d",&seat);
        node *temp=first,*temp1;
	if(first==NULL)
        {
                printf("\n\t\t\tNO RECORD FOUND\n");
        }
	else if(temp->next==NULL&&temp->seat!=seat)

        {       
        printf("\n\t\t\tNO RECORD FOUND\n");
        }
	

        else
        {
	while(temp->seat!=seat)
        {
                temp1=temp;
                temp=temp->next;
        }
		if(temp->seat==seat)
	{
                printf("\n\t\t\tpassenger name:%s\n",temp->name);
                printf("\t\t\tmob_no:%d\n",temp->mob_no);
                printf("\t\t\tgender:%s\n",temp->gender);
                printf("\t\t\tsource:%s\n",temp->source);
                printf("\t\t\tdestination:%s\n",temp->destination);
                printf("\t\t\tprice:%d\n",temp->price);
		printf("\t\t\tseat_no:%d\n\n",temp->seat);
        }
		else
		printf("\n\t\t\tNO RECORD FOUND\n");
	}
}


void display_all_ticket()
{
        node *temp=first;
        if(temp==NULL)
        {
                printf("\n\t\t\tNO RECORDS FOUND\n");
        }
while(temp!=NULL)
        {
                printf("\n\t\t\tpassenger name:%s\n",temp->name);
                printf("\t\t\tmob_no:%d\n",temp->mob_no);
                printf("\t\t\tgender:%s\n",temp->gender);
                printf("\t\t\tsource:%s\n",temp->source);
                printf("\t\t\tdestination:%s\n",temp->destination);
                printf("\t\t\tprice:%d\n",temp->price);
		printf("\t\t\tseat_no:%d\n\n",temp->seat);
                temp=temp->next;
        }
}
void delete_all()
{
        node *temp=first;
        if(temp==NULL)
        {
                printf("\t\t\tNO RECORDS\n");
        }

        while(temp!=NULL)
        {
        first=first->next;
        free(temp);
        temp=temp->next;
        }
        printf("\t\t\tALL RECORDS DELETED\n");
}
int seat()
{
int num,flag=0;
label:
flag=0;
printf("\t\t\tEnter seat number:");
scanf("%d",&num);
printf("\n\n");
node *temp=first,*temp1;
if(first!=NULL)
{
        while(temp!=NULL)
        {
		if(temp->seat==num)
		flag=1;
                temp1=temp;
                temp=temp->next;
        }
 }      
if(flag!=0)
{
printf("\t\t\t\nSeat occupied select another seat\n");
goto label;
}
if(flag==0)
return num;
}

void displayseat()
{
char seat[32];
node *temp=first,*temp1;
if(first!=NULL)
{
        while(temp!=NULL)
        {	
		
		seat[temp->seat]='*';
                temp1=temp;
                temp=temp->next;
        }
}
int i,j,k=1;
printf("\n");
for(i=1;i<=4;i++)
{
for(j=i;j<8+i;j++,k++)
{
if(seat[k]!='*')
{
if(k>=1&&k<=9)
printf("%d .EMPTY   ",k);
else
printf("%d.EMPTY   ",k);
}
else
{
if(k>=1&&k<=9)
printf("%d .OCCUPIED   ",k);
else
printf("%d.OCCUPIED   ",k);
}
}
printf("\n");

}

printf("\n\n");

}
void cancel()
{
	int seat;
        printf("\t\t\tENTER A SEAT NUMBER TO CANCEL TICKET:");
        scanf("%d",&seat);
        node *temp=first,*temp1;
        if(first==NULL)
        {
                printf("\n\t\t\tNO RECORD FOUND\n");
        }
	else if(temp->next==NULL)
	{
	free(first);
	first=last=NULL;	
	}
	
        else
        {
        while(temp->seat!=seat)
        {
                temp1=temp;
                temp=temp->next;
        }
		temp1->next=temp->next;
		temp->next=NULL;
		free(temp);
	printf("\n\t\t\tSEAT NO %d HAS BEEN CANCELLED\n",seat);
	}
		


}





