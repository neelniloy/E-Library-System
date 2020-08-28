#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char USER[50];
char pass[50];
char mail[50];
char phone[50];

struct book
{
    char name[50];
    char author[50];
    char publish[50];
    struct book *next;

}*head = NULL;

struct List
{
    char b_name[50];
    char writer[50];
    char pbl[50];
    struct List *next;

}*Start = NULL;

void data()
{
    struct book *new_book, *current;

    new_book = (struct book*)malloc(sizeof(struct book));
    new_book->next = NULL;

    strcpy(new_book->name, "Introduction to Algorithms");
    strcpy(new_book->author, "Thomas H. Cormen");           // 1st book
    strcpy(new_book->publish, "MIT Press");

    head = new_book;
    current = new_book;


    struct book *new_book2 = (struct book*)malloc(sizeof(struct book));
    new_book2->next = NULL;

    strcpy(new_book2->name, "Data Structures and Algorithms Made Easy");
    strcpy(new_book2->author, "Narasimha Karumanchi");      // 2nd book
    strcpy(new_book2->publish, "CareerMonk");

    current->next = new_book2;
    current = new_book2;



    struct book *new_book3 = (struct book*)malloc(sizeof(struct book));
    new_book3->next = NULL;

    strcpy(new_book3->name, "Atomic Habits");
    strcpy(new_book3->author, "James Clear");      // 3rd book
    strcpy(new_book3->publish, "Penguin Publishing Group");


    current->next = new_book3;
    current = new_book3;



    struct book *new_book4 = (struct book*)malloc(sizeof(struct book));
    new_book4->next = NULL;

    strcpy(new_book4->name, "Python Crash Course");
    strcpy(new_book4->author, "Eric Matthes");      // 4th book
    strcpy(new_book4->publish, "No starch press");

    current->next = new_book4;
    current = new_book4;



    struct book *new_book5 = (struct book*)malloc(sizeof(struct book));
    new_book5->next = NULL;

    strcpy(new_book5->name, "Operating System Concepts");
    strcpy(new_book5->author, "Avi Silberschatz");      // 5th book
    strcpy(new_book5->publish, "CareerMonk");

    current->next = new_book5;
    current = new_book5;

}

void search()
{

    system("cls");

    int n;
    struct book *current;
    char b[50], a[50], p[50];

    printf("\n\nSearch by\n\n");
    printf("1. Book\n2. Author\n3. Publisher\n");

    scanf("%d", &n);

    if(n == 1)
    {

        printf("\nEnter book name: ");
        scanf(" %[^\n]", b);

        current = head;

        while(current != NULL)
        {

            if(strcmp(current->name, b) == 0)
            {

                printf("\n");
                printf("Book     : %s\n", current->name);
                printf("Author   : %s\n", current->author);
                printf("Publisher: %s\n", current->publish);

                printf("\n");

                printf("\nWanna add this to reading list(y/n): ");
                char c;
                scanf(" %c", &c);

                if(c == 'y' || c == 'Y')
                {

                    readingList(current);
                }

                return;
            }

            current = current->next;
        }

        printf("\nSorry ! We have not found this book\nWould you like to request to add this book?(y/n) ");
        char ch;
        scanf(" %c", &ch);

        if(ch == 'y' || ch == 'Y')
        {

            requestBook();
        }
        else
        {

            return;
        }
    }
    else if(n == 2)
    {

        printf("\nEnter author name: ");
        scanf(" %[^\n]", a);

        current = head;

        while(current != NULL)
        {

            if(strcmp(current->author, a) == 0)
            {

                printf("\n");
                printf("Book     : %s\n", current->name);
                printf("Author   : %s\n", current->author);
                printf("Publisher: %s\n", current->publish);

                printf("\n");

                printf("\nWanna add this to reading list(y/n): ");
                char c;
                scanf(" %c", &c);

                if(c == 'y' || c == 'Y')
                {

                    readingList(current);
                }
                return;
            }

            current = current->next;
        }

        printf("\nSorry ! We have not found this book\nWould you like to request to add this book?(y/n) ");
        char ch;
        scanf(" %c", &ch);

        if(ch == 'y' || ch == 'Y')
        {

            requestBook();
        }
        else
        {

            return;
        }
    }
    else if(n == 3)
    {

        printf("\nEnter publisher name: ");
        scanf(" %[^\n]", p);

        current = head;

        while(current != NULL)
        {

            if(strcmp(current->publish, p) == 0)
            {

                printf("\n");
                printf("Book     : %s\n", current->name);
                printf("Author   : %s\n", current->author);
                printf("Publisher: %s\n", current->publish);

                printf("\n");

                printf("\nWanna add this to reading list(y/n): ");
                char c;
                scanf(" %c", &c);

                if(c == 'y' || c == 'Y')
                {

                    readingList(current);
                }
                return;
            }

            current = current->next;
        }

        printf("\nSorry ! We have not found this book\nWould you like to request to add this book?(y/n) ");
        char ch;
        scanf(" %c", ch);

        if(ch == 'y' || ch == 'Y')
        {

            requestBook();
        }
        else
        {

            return;
        }
    }
}
struct List *sorting(struct List *a, struct List *b)
{
    if (a == NULL)
    {
        return b;
    }

    else if (b == NULL)
    {
        return a;
    }

    struct List *result = NULL;

    char ch[50], c[50], l, r;

    strcpy(ch, a->b_name);
    strcpy(c, b->b_name);

    l = ch[0];
    r = c[0];


    if (l <= r)
    {
        result = a;
        result->next = sorting(a->next, b);
    }
    else
    {
        result = b;
        result->next = sorting(a, b->next);
    }

    return result;
}

void partition(struct List *current, struct List **front, struct List **back)
{
    if (current == NULL || current->next == NULL)
    {
        *front = current;
        *back = NULL;
        return;
    }

    struct List *last = current;
    struct List *first = current->next;


    while (first != NULL)
    {
        first = first->next;
        if (first != NULL)
        {
            last = last->next;
            first = first->next;
        }
    }

    *front = current;
    *back = last->next;
    last->next = NULL;
}

void MergeSort(struct List **current)
{
    if (*current == NULL || (*current)->next == NULL)
    {
        return;
    }

    struct List *a;
    struct List *b;

    partition(*current, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *current = sorting(a, b);
}

void readingList(struct book *temp)
{
    struct List *new_list;

    new_list = (struct List*)malloc(sizeof(struct List));
    new_list->next = NULL;

    strcpy(new_list->b_name, temp->name);
    strcpy(new_list->writer, temp->author);
    strcpy(new_list->pbl, temp->publish);


    new_list->next = Start;
    Start = new_list;
}

void home()
{
    struct book *current, *temp;
    int i = 0, c = 0, n;
    char ch;

    current = head;
    temp = head;
    system("cls");

    printf("\n\t******* Home *******\n\n");


    while(current != NULL)
    {
        c++;
        printf("%d. \n", c);
        printf("Book     : %s\n\n", current->name);

        current = current->next;

    }

    printf("\nEnter a number for details(0 for main menu): ");
    scanf("%d", &n);

    system("cls");

    if(n == 0)
    {

        return;
    }

    c = 0;
    current = head;

    printf("\n\n***Details***\n\n");
    while(current != NULL)
    {

        c++;

        if(c == n)
        {

            printf("Book     : %s\n", current->name);
            printf("Author   : %s\n", current->author);
            printf("Publisher: %s\n\n", current->publish);

            break;
        }

        current = current->next;
    }


    printf("\nDo you want to add this in reading-list ?(y/n)\n\n");
    scanf(" %c", &ch);

    if(ch == 'y' || ch == 'Y')
    {

        readingList(current);

        MergeSort(&Start);

        printf("\n\nAdded to your reading list\n\n");;
    }

    system("pause");
}


void profile()
{
    system("cls");
    printf("\n\t<<<<-------- Profile -------->>>>\n\n");
    printf("Name : %s\n", USER);
    printf("Email: %s\n", mail);
    printf("Phone: %s\n\n", phone);
}

void showList()
{
    struct List *temp;
    int c = 0;

    temp = Start;

    printf("\n\tReading List:\n\n");

    while(temp != NULL)
    {

        printf("Book     : %s\n", temp->b_name);
        printf("Author   : %s\n", temp->writer);
        printf("Publisher: %s\n\n", temp->pbl);

        temp = temp->next;
    }

    printf("\n");

    system("pause");
}

void requestBook()
{
    struct book *current, *temp, *new_book;


    new_book = (struct book*)malloc(sizeof(struct book));
    new_book->next = NULL;

    printf("\nEnter book name: ");
    scanf(" %[^\n]", new_book->name);
    printf("Enter author name: ");
    scanf(" %[^\n]", new_book->author);
    printf("Enter publisher's name: ");
    scanf(" %[^\n]", new_book->publish);

    current = head;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_book;


    system("cls");
    printf("\n\n\t\tThanks for staying with us :-) \n\t\tWe will add this book ASAP\n\n\n");
    system("pause");
    system("cls");
}
void maintenance()
{

    int n, i,a;

    while(1)
    {


        printf("\t  **Main Menu**\n\tFor\t\t Press\n\n");
        printf("\tHome\t\t  0\n");
        printf("\tProfile\t\t  1\n");
        printf("\tSearch new book\t  2\n");
        printf("\tReading List\t  3\n");
        printf("\tRequest a book    4\n");
        printf("\tExit\t\t  5\n");

        scanf("%d", &n);

        if(n == 0)
        {

            home();
            system("cls");
        }
        else if(n == 1)
        {

            profile();
            printf("\n");

            system("pause");
            system("cls");
        }
        else if(n == 2)
        {
            search();
            system("pause");
            system("cls");

        }
        else if(n == 3)
        {

            showList();
            system("cls");
        }
        else if(n == 4)
        {
            requestBook();
        }
        else if(n==5)
        {

            break;
        }
    }
}

void isValid()  // Check a mail is valid or not
{
    int a, i, j = 0, b,c, d;
    char temp[11], temp1[12];

    a = strlen(mail) - 10;

    for(i=a, j = 0; mail[i]!= '\0'; j++, i++)
    {

        temp[j] = mail[i];
    }

    temp[j] = '\0';


    for(i=a-1, j = 0; mail[i]!= '\0'; j++, i++)
    {

        temp1[j] = mail[i];
    }

    temp1[j] = '\0';

    b = strcmp(temp, "@gmail.com");
    c = strcmp(temp1, "@diu.edu.bd");
    d = strcmp(temp, "@yahoo.com");

    if(b == 0 || c == 0 || d == 0)
    {

        return;
    }

    printf("\nPlease enter a valid mail : ");
    scanf(" %[^\n]", mail);

    isValid();
}

bool isNum()
{
    char no[4];
    int i, j, a, b, c, d, e;


    for(i=0; phone[i] != '\0'; i++)
    {

        if(phone[i] < 48 || phone[i] > 57)
        {

            return false;
        }
    }

    int len = strlen(phone) - 8;

    for(i=0, j = 0; i<len; i++, j++)
    {

        no[j] = phone[i];
    }

    no[j] = '\0';

    a = strcmp(no, "017");
    b = strcmp(no, "019");
    c = strcmp(no, "013");
    d = strcmp(no, "018");
    e = strcmp(no, "015");

    if(a == 0 || b == 0 || c == 0 || d == 0 || e == 0)
    {

        return true;
    }

    return false;
}

void validPhone()
{
    int length;

    length = strlen(phone);

    if(length == 11 && isNum())
    {

        return;
    }

    printf("\nPlease enter a valid no: ");
    scanf(" %[^\n]", phone);

    validPhone();
}
void signup()
{

    int length = 0, i;

    printf("\n\n----- SignUp --------\n\n");

    printf("\nUser Name: ");
    scanf(" %[^\n]", USER);

    printf("\nEmail: ");
    scanf(" %[^\n]", mail);

    isValid();

    printf("\nPhone number: ");
    scanf(" %[^\n]", phone);
    validPhone();

    while(length < 5)
    {
        printf("\nPassword(must contain 5 letters): ");
        scanf(" %[^\n]", pass);

        length = strlen(pass);
    }

    system("cls");

    printf("\n\n\t***************** SignUp Successful *****************\n\n");

    system("pause");
}
void login()
{
    int a, b, i, c, d;
    char name[50], p[50];

    system("cls");

    printf("\n--- Log-In -----\n\n");
    printf("\nUser Name: ");
    scanf("%s", name);
    printf("\nPassword: ");
    scanf("%s", p);

    a = strcmp(name,USER);
    b = strcmp(p, pass);

    if(a== 0 && b == 0)
    {
        system("cls");
        printf("\n\n*************** Welcome ***************\n\n\n");
        data();
        maintenance();
    }
    else
    {
        system("cls");
        printf("\n\nUsername/password error\n\n");
        system("pause");
        login();
    }

}
int main()
{
    printf("\n\n\t\t\t\t----------- Welcome To our E-Library System ----------- \n\n\t\t\t\t\t\t\tTeam: SemiColon\n\n");

    int a = 0, b, n;
    char ch;

    system("pause");

    system("cls");

    printf("\n--- Log-In -----\n\n");


    printf("New user ? (y or n)\n\n");
    ch = getchar();
    system("cls");

    if(ch == 'y' || ch == 'Y')
    {

        signup();
        login();
        a = 1;
    }
    else if(ch == 'n' || ch == 'N')
    {

        login();
    }

    printf("\n\n\t\t***** Thanks for staying with us *****\n\n");

    return 0;
}
