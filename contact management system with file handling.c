#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct contact
{
long ph;
char name[20],add[20],email[30];
} list;
char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;
int main()
{
main:
printf("\n\t Welcome to Contact Management System \n");
printf("\n\t\tMAIN MENU\n\t\t\t[1] Add a new Contact\n\t\t\t[2] List all Contacts\n\t\t\t[3] Search for contact\n\t\t\t[4] Edit a Contact\n\t\t\t[5] Delete a Contact\n\t\t\t[0] Exit\n\t\t");
printf("Enter the choice: \n");
scanf("%d",&ch);
switch(ch)
{
case 0:
printf("\n\n\t\tAre you sure you want to exit? \n");
break;
case 1:
fp=fopen("contact.dll","a");
for (;;)
{
fflush(stdin);
printf("To exit enter blank space in the name input\nName (Use identical): \n");
scanf("%[^\n]",&list.name);
if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
break;
fflush(stdin);
printf("Phone: ");
scanf("%ld",&list.ph);
fflush(stdin);
printf("address: ");
scanf("%[^\n]",&list.add);
fflush(stdin);
printf("email address: ");
gets(list.email);
printf("\n");
fwrite(&list,sizeof(list),1,fp);
}
fclose(fp);
break;
case 2:
printf("\n\t\tLIST OF CONTACTS\n\t\tName\n\t\tPhone No\n\t\tAddress\n\t\tE-mail ad.\n");
for(i=97; i<=122; i=i+1)
{
 fp=fopen("contact.dll","r");
fflush(stdin);
found=0;
 while(fread(&list,sizeof(list),1,fp)==1)
{
if(list.name[0]==i || list.name[0]==i-32)
{
printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.add,list.email);
found++;
}
}
if(found!=0)
{
printf("[%c]-(%d)\n\n",i-32,found);
getch();
}
fclose(fp);
}
break;
case 3:
do
{
found=0;
printf("\n\n\t CONTACT SEARCH\n\t \n\t Name of contact to search: \n");
fflush(stdin);
scanf("%[^\n]",&query);
l=strlen(query);
fp=fopen("contact.dll","r");
printf("\n\n Search result for '%s' \n\n",query);
while(fread(&list,sizeof(list),1,fp)==1)
{
for(i=0; i<=l; i++)
name[i]=list.name[i];
name[l]='\0';
if(stricmp(name,query)==0)
{
printf("\n Name\t: %s\n Phone\t: %ld\n Address\t: %s\n Email\t: %s\n",list.name,list.ph,list.add,list.email);
found++;
if (found%4==0)
{
printf("\n Press any key to continue \n");
getch();
}
}
}
if(found==0)
printf("\n No match found! \n");
else
printf("\n %d match(s) found! \n",found);
fclose(fp);
printf("\n Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
scanf("%d",&ch);
}
while(ch==1);
break;
case 4:
fp=fopen("contact.dll","r");
ft=fopen("temp.dat","w");
fflush(stdin);
printf(" \nEdit contact\n\n\n\t Enter the name of contact to edit: \n");
scanf("%[^\n]",name);
while(fread(&list,sizeof(list),1,fp)==1)
{
if(stricmp(name,list.name)!=0)
fwrite(&list,sizeof(list),1,ft);
}
fflush(stdin);
printf("\n\n..::Editing '%s'\n\n",name);
printf("Name(Use identical):");
scanf("%[^\n]",&list.name);
fflush(stdin);
printf("Phone:");
scanf("%ld",&list.ph);
fflush(stdin);
printf("address:");
scanf("%[^\n]",&list.add);
fflush(stdin);
printf("email address:");
gets(list.email);
printf("\n");
fwrite(&list,sizeof(list),1,ft);
fclose(fp);
fclose(ft);
remove("contact.dll");
rename("temp.dat","contact.dll");
break;
case 5:
fflush(stdin);
printf("\n\n\t DELETE A CONTACT\n\t\n\t Enter the name of contact to delete: \n");
scanf("%[^\n]",&name);
fp=fopen("contact.dll","r");
ft=fopen("temp.dat","w");
while(fread(&list,sizeof(list),1,fp)!=0)
if (stricmp(name,list.name)!=0)
fwrite(&list,sizeof(list),1,ft);
fclose(fp);
fclose(ft);
remove("contact.dll");
rename("temp.dat","contact.dll");
break;
default:
printf("Invalid choice\n");
break;
}
printf("\n\n\n Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
scanf("%d",&ch);
switch (ch)
{
case 1:
goto main;
case 0:
break;
default:
printf("Invalid choice");
break;
}
return 0;
}
