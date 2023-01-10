#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char surname[100];
    char number[100];
    char uslessButNeeded[50];
    char uslessButNeeded_2[50];
    char uslessButNeeded_3[50];
}book;

int countStr()
{
    FILE* bk;
    while((bk=fopen("E:/2 term/Progr/Lab6/Lab6File/PB.txt", "r"))==NULL)
    {
        perror("\nError. Could not open the file\t :( \n");
        return EXIT_FAILURE;
    }

    size_t counter = 0;
    int ch, pre = EOF;

    while ( ( ch = fgetc( bk ) ) != EOF )
    {
        pre = ch;

        if ( ch == '\n' )
        {
         counter++;
        }
    }

    if ( pre == EOF )
        puts( "File is empty!" );
    else if ( pre != '\n'  )
    {
        counter++;
    }
    fclose(bk);
    return (counter);
}


void fileReedOpen(book *book)
{
    FILE* bk;
    int j=0;
    while((bk=fopen("E:/2 term/Progr/Lab6/Lab6File/PB.txt", "r"))==NULL)
        printf("\nError. Could not open the file\t :( \n");
    while (!feof(bk))
    {
        fscanf(bk, "%s %s %s %s %s", book[j].uslessButNeeded, book[j].surname, book[j].uslessButNeeded_2, book[j].uslessButNeeded_3, book[j].number);
        j++;
    }
    fclose(bk);
}

char addcont(book *book, int i)
{
    int count;
    char choose;
    for (int j=i; ; j++)
    {
        count=j;
        printf("\nDo you want to add new contact [y/n]?\n");
        scanf("%c",&choose); getchar();
        switch (choose)
        {
        case 'y':
        {
            printf("\nEnter surname: ");
            gets(book[j].surname);
            printf("Enter number: ");
            gets(book[j].number);
            break;
        }
        case 'n':
        {
            break;
        }
        default:
            printf("\nSomething seems to have gone wrong. ERROR\n");
        }
        if (choose=='n')
            break;
    }

    printf("\n\n\t\tYour PhoneBook:\n");

    for (int j=0; j<count; j++)
    {
        if (((strcmp(book[j].surname,"0"))==0) && ((strcmp(book[j].number,"0"))==0))
        {
            count=count-1;
        }
        if (((strcmp(book[j].surname,"0"))!=0) && ((strcmp(book[j].number,"0"))!=0))
        {
            printf("|Surname:%s, Number:%s|\n",book[j].surname,book[j].number);
        }
    }
    printf("Your phone book currently contains: %d contacts \n\n\n",count);

    return (count);
}

void findsurname(book *book, int i)
{
    bool flag=false;
    int index;
    char surname[100];
    gets(surname);
    for (int j=0; j<i; j++)
    {
        if ((strcmp(surname,((book[j].surname))))==0)
        {
            flag=true;
            index=j;
            break;
        }
    }

    if (flag==true)
    {
        printf("\nPerson with surname: %s is in your PhoneBook\n\n",surname);
        printf("\tPerson's Info:\n");
        printf("Surname: %s Phone number: %s\n",book[index].surname,book[index].number);
    }
    else
        printf("\nPerson not found\n");
}

void findnumber(book *book, int i)
{
    int index;
    bool flag=false;
    char number[100];
    gets(number);
    for (int j=0; j<i; j++)
    {
        if ((strcmp(number,((book[j].number))))==0)
        {
            flag=true;
            index=j;
            break;
        }
    }
    if (flag==true)
    {
        printf("\nPerson with this number: %s is in your PhoneBook\n\n",number);
        printf("\tPerson's Info:\n");
        printf("Surname: %s Phone number: %s\n",book[index].surname,book[index].number);
    }
    else
        printf("\nPerson not found\n");
}

void delcont(book *book, int i)
{
    int index;
    bool flag=false;
    char surname[100], choose;
    gets(surname);
    for (int j=0; j<i; j++)
    {
        if ((strcmp(surname,((book[j].surname))))==0)
        {
            flag=true;
            index=j;
            break;
        }
    }
    if (flag==true)
    {
            printf("\nDo you really want to delete a contact %s? [y/n]\n",book[index].surname);
            scanf("%c",&choose); getchar();
            switch (choose)
            {
            case 'y':
                {
                    strcpy(book[index].surname, "0");
                    strcpy(book[index].number, "0");
                    printf("\nYou have successfully deleted the contact\n");
                    break;
                }
            case 'n':
            {
                printf("\nYou canceled the deletion of the contact %s\n",book[index].surname);
                break;
            }
            default:
                printf("\nSomething seems to have gone wrong. ERROR\n");
            }
    }
    else
        printf("\nPerson not found\n");
}

void surnameChange(book *book, int i)
{
    int index;
    bool flag=false;
    char surname[100], choose;
    gets(surname);
    for (int j=0; j<i; j++)
    {
        if ((strcmp(surname,((book[j].surname))))==0)
        {
            flag=true;
            index=j;
            break;
        }
    }
    if (flag==true)
    {
            printf("\nDo you really want to change the contact's last name %s? [y/n]\n",book[index].surname);
            scanf("%c",&choose); getchar();
            switch (choose)
            {
            case 'y':
            {
                printf("Enter a new last name for the contact %s \n",book[index].surname);
                gets(book[index].surname);
                printf("You have successfully changed the contact's last name to %s\n",book[index].surname);
                break;
            }
            case 'n':
            {
                printf("\nYou canceled the contact change %s\n",book[index].surname);
                break;
            }
            default:
                printf("\nSomething seems to have gone wrong. ERROR\n");
            }
    }
    else
        printf("Person not found\n");
}

void numberChange(book *book, int i)
{
    int index;
    bool flag=false;
    char surname[100], choose;
    gets(surname);
    for (int j=0; j<i; j++)
    {
        if ((strcmp(surname,((book[j].surname))))==0)
        {
            flag=true;
            index=j;
            break;
        }
    }
    if (flag==true)
    {
            printf("\nDo you really want to change the contact number %s? [y/n]\n",book[index].surname);
            scanf("%c",&choose); getchar();
            switch (choose)
            {
            case 'y':
            {
                printf("Enter a new number for the contact %s \n",book[index].surname);
                gets(book[index].number);
                printf("You have successfully changed the contact number to %s\n",book[index].number);
                break;
            }
            case 'n':
            {
                printf("\nYou canceled the contact change %s\n",book[index].surname);
                break;
            }
            default:
                printf("\nSomething seems to have gone wrong. ERROR\n");
            }
    }
    else
        printf("Person not found\n");
}

int main()
{

    book book[100];
    int count=countStr();
    fileReedOpen(book);

    int chooseCase;

    do
    {
    printf("\nWhat action do you want to do? \n[1] << Add new contact \n"
           "[2] << Find a contact by surname \n[3] << Find a contact by number \n[4] << Delete contact \n[5] << Change the last name of an existing contact "
           "\n[6] << Change the phone number of an existing contact\n[7] << Display a list of contacts\n[8] << Save file\n[9] << Finish the job\n>> ");
    scanf("%d",&chooseCase); getchar();
    switch (chooseCase)
    {
        case 1:
    {
            printf("\nAdd new contact\n");
            count=addcont(book, count);
            break;
    }
        case 2:
        {
            printf("\nEnter the surname of the contact you want to find\n");
            findsurname(book, count);
            break;
        }
        case 3:
        {
            printf("\nEnter the phone number of the contact you want to find\n");
            findnumber(book, count);
            break;
        }
        case 4:
        {
            printf("\nEnter the last name of the contact you want to delete\n");
            delcont(book,count);
            break;
        }
        case 5:
        {
            printf("\nEnter the last name of the contact you want to change\n");
            surnameChange(book,count);
            break;
        }
        case 6:
        {
            printf("\nEnter the last name of the contact whose number you want to change\n");
            numberChange(book,count);
            break;
        }
        case 7:
        {
            printf("\n\t\tYour contact list:\n");
            int change=0;
            for (int j=0; j<count; j++)
            {
                if (((strcmp(book[j].surname,"0"))==0) && ((strcmp(book[j].number,"0"))==0))
                {
                    change++;
                    continue;
                }
                if (((strcmp(book[j].surname,"0"))!=0) && ((strcmp(book[j].number,"0"))!=0))
                {
                    printf("|Surname:%s, Number:%s|\n",book[j].surname,book[j].number);
                }
            }
            printf("Your phone book currently contains: %d contacts\n",count-change);
            break;
        }
        case 8:
        {
            FILE* file;
            file=fopen("E:/2 term/Progr/Lab6/Lab6File/PB.txt", "w");
            for (int j=0; j<count; j++)
            {
                 if (((strcmp(book[j].surname,"0"))==0) && ((strcmp(book[j].number,"0"))==0))
                 {
                     continue;
                 }
                 if (((strcmp(book[j].surname,"0"))!=0) && ((strcmp(book[j].number,"0"))!=0))
                 {
                     if (j+1==count)
                     {
                          fprintf(file,"Surname: %s \t\t\t\t\t\t\t\t|\t Number: %s",book[j].surname,book[j].number);
                          break;
                     }
                    fprintf(file,"Surname: %s \t\t\t\t\t\t\t\t|\t Number: %s\n",book[j].surname,book[j].number);
                 }
            }
            puts ("The file is saved!");
            fclose(file);
            break;
        }
        case 9:
        {
            printf("\n\tThe work is completed\n");
            break;
        }
    }
    }while(chooseCase!=9);
    return 0;
}
