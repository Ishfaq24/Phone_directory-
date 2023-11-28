#include<stdio.h>

int main()
{
char n[50];
int a;
int p;
int d;
char add[50];

char na[50];
int ag;
int ph;
int da;
char addr[50];

printf("WELCOME TO PHONE BOOK\n");
printf("MENU\n");

printf("Press 1 to add the contact\n");

int x;
printf("enter x \n");
scanf("%d",&x); 

if(x==1)
{

int y;
printf("enter the number of contacts to be added :");
scanf("%d",&y);
if (y==1)
{
    printf("-------------\n");
    printf("Name :");
    scanf("%s",&n);
    printf(" age :");
    scanf("%d",&a);
    printf("phone number :");
    scanf("%d",&p);
    printf("date of birth :");
    scanf("%d",&d);
    printf("address :");
    scanf("%s",&add);
    printf("--------------\n");
}
    else if(y==2)
    {
    printf("-------------\n");
    printf("Name :");
    scanf("%s",&n);
    printf(" age :");
    scanf("%d",&a);
    printf("phone number :");
    scanf("%d",&p);
    printf("date of birth :");
    scanf("%d",&d);
    printf("address :");
    scanf("%s",&add);
    printf("--------------\n");

    printf("--------------\n");
    printf("name :");
    scanf("%s",&na);
    printf("age :");
    scanf("%d",&ag);
    printf("Phone number :");
    scanf("%d",&ph);
    printf("Date of birth :");
    scanf("%d",&da);
    printf("Address :");
    scanf("%s",&add);
    printf("---------------\n");
}
printf("press 2 to see the entered contact\n");
printf("press 3 to exit the phone book\n");

int z ;
printf("Enter z \n");
scanf("%d",&z);

if (z==2)
{
int num;
 printf("Enter the no  of contacts to be viewed :");
 scanf("%d",&num);

if (num==1)
{
    printf("-------------\n");
    printf("Name :");
    printf("%s",n);
    printf("Age :");
    printf("%d",a);
    printf("phone number");
    printf("%d",p);
    printf("Date of birth");
    printf("%d",d);
    printf("Address :");
    printf("%s",add);
    printf("-----------\n");
}
else if(y==2)
{
printf("-------------\n");
printf("Name :");
printf("%s",n);
printf(" age :");
printf("%d",a);
printf("phone number :");
printf("%d",p);
printf("date of birth :");
printf("%d",d);
printf("address :");
printf("%s",add);
printf("-------------\n");

printf("--------------\n");
printf("name :");
printf("%s",na);
printf("age :");
printf("%d",ag);
printf("Phone number :");
printf("%d",ph);
printf("Date of birth :");
printf("%d",da);
printf("Address :");
printf("%s",add);
printf("---------------\n");
}

}
else if(y==3)
{
    printf("Are you sure you want  to close the phone book \n");
    printf("print 1 for yess \n ");
    printf("print 2 for close \n ");

    int ans;
    printf("enter ans :");
    scanf("%d", &ans);

    if(ans==1)
    {
    printf("The phone book is closed ");
    printf("have a good day;)");
    }
  else if(ans==2)
  {
printf("Thee is not closed\n");
printf("You can continue\n");

  }
}
}
else
{
    printf("Invalid:(" );

}
return 0;
}