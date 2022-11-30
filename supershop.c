#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>



void title();
void printChar(char ch,int n);
void title();
void addproduct();
void printproduct();
void preparebill();
int search(int n);
void search_product();


void gotoxy(int x,int y)
{
    COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

struct product
{
    char product_name[1001];
    int product_code;
    float product_price;
    int product_ammount;
} no[100000];
int count=0;
int ammount;
int customer_count=0;

int main()
{
    int option;
    system("color 9f");
    gotoxy(42,8);
    printf("To Continue Please Press ENTER)");
    gotoxy(42,10);
    printf("____________________________________");
    gotoxy(42,11);
    printf("|\tPress Enter :                |");
    gotoxy(42,12);
    printf("|__________________________________|");
    gotoxy(65,11);
    getchar();

    system("cls");
    gotoxy(10,3);
    printf("<<<< Loading Please Wait >>>>");
    for(int i=0; i<5; i++)
    {
        printf("\t(*_*)");
        Sleep(500);
    }
    printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *       Welcome      *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
    getch();
    title();
    printf("\n\n\t\t\t\t  Mayer Dua Super Shop\n\t\t\t");
    printChar('=',38);
    printf("\n\n\n\t\t\t       press any key to Enter");
    getch();
    while(1)
    {
        title();
        printf("\n\t");
        printChar('*',64);

        printf("\n\n\t\t\t\t1. Add Product to Inventory");
        printf("\n\n\t\t\t\t2. Prepare A Bill");
        printf("\n\n\t\t\t\t3. Show All Products");
        printf("\n\n\t\t\t\t4. Search Products");
        printf("\n\n\t\t\t\t5. Logout\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            addproduct();
            break;
        case 2:
            preparebill();
            break;
        case 3:
            printproduct();
            break;
        case 4:
            search_product();
            break;
        case 5:
            return 0;
            break;
        default:
            printf("\n\t\tNo Action Detected");
            printf("\n\t\tPress Any Key\n\n\n");
            getch();
            system("pause");
        }
    }


    return 0;
}



void title()
{
    system("cls");
    system("COLOR 03");
    printf("\n\n\t");
    printChar('=',25);
    printf(" SUPER SHOP MANAGEMENT SYSTEM ");
    printChar('=',25);
    printf("\n");
}
void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}
void addproduct()
{
    title();
    system("cls");
    system("COLOR 9");
    gotoxy(12,4);
    printf("How many Product You want to add: ");
    gotoxy(50,4);
    scanf("%d",&ammount);
    ammount+=count;
    system("cls");
    for(int i=count; i<ammount; i++)
    {
        gotoxy(12,4);
        printf("Enter Product Name: ");
        gotoxy(50,4);
        scanf(" %[^\n]s",&no[i].product_name);
        gotoxy(12,5);
        printf("Enter Product Code: ");
        gotoxy(50,5);;
        scanf("%d",&no[i].product_code);
        gotoxy(12,6);
        printf("Enter Product Price: ");
        gotoxy(50,6);
        scanf("%f",&no[i].product_price);
        gotoxy(12,7);
        printf("Enter Product Ammount: ");
        gotoxy(50,7);
        scanf("%d",&no[i].product_ammount);
        count++;
        system("cls");

    }
}
void printproduct()
{
    system("cls");
    title();
    printf("\n\n\t\t\t\t  Mayer Dua Super Shop\n\t\t\t");
    printChar('=',38);
    system("COLOR 9");
    if(ammount==0)
    {
        printf("\n\t\t Currently There Is No Product In Our Inventory");
        getch();
    }
    else if(ammount!=0)
    {
        for(int i=0; i<ammount; i++)
        {
            printf("Product Name: %s\n",no[i].product_name);
            printf("Product Code: %d\n",no[i].product_code);
            printf("Product Price: %0.2f\n",no[i].product_price);
            printf("Product Ammount: %d\n",no[i].product_ammount);
        }
        printf("\n\t\t\tPress Any Key\n\n\n");
        getch();
    }
}

void preparebill()
{
    system("cls");
    title();
    system("COLOR 9");
    if(ammount==0)
    {
        printf("\n\t\t Currently There Is No Product In Our Inventory");
        getch();
    }
    else if(ammount!=0)
    {
        int code;
        printf("Enter Product Code: ");
        scanf("%d",&code);
        int l=search(code);
        int amm;
        printf("Enter The Ammount ");
        scanf("%d",&amm);
        if(amm>no[l].product_ammount)
        {
            printf("You Dont Have That Much Product ");
            getch();
        }
        else if(amm<no[l].product_ammount)
        {
            customer_count++;
            no[l].product_ammount=no[l].product_ammount-amm;
            double price=amm*no[l].product_price;
            system("cls");
            title();
            printf("\n\n\t\t\t\t  Mayer Dua Super Shop\n\t\t\t");
            printChar('=',38);
            printf("\n\t\t\t\tCustomer No: %d\n",customer_count);
            printf("\t\t\t\tProduct Name: %s",no[l].product_name);
            printf("\n\t\t\t\tProduct Code: %d\n",no[l].product_code);
            printf("\t\t\t\tPer Unit Price: %f\n",no[l].product_price);
            printf("\t\t\t\tTotal Unit Purchased: %d\n",amm);
            printf("\t\t\t\tTotal Bill :%0.2lf\n\t\t\t",price);
            printChar('=',38);
            getch();
        }
    }
}

void search_product()
{
    system("cls");
    system("COLOR 9");
    int code;
    printf("\tEnter The Product Code You Want To Search: ");
    scanf("%d",&code);
    int flag=0;
    for(int i=0; i<ammount; i++)
    {
        if(no[i].product_code==code)
        {
            system("cls");
            flag=1;
            title();
            printf("\n\n\t\t\t\t  Mayer Dua Super Shop\n\t\t\t");
            printChar('=',38);
            printf("\n\t\t\t\tProduct Name: %s",no[i].product_name);
            printf("\n\t\t\t\tProduct Code: %d\n",no[i].product_code);
            printf("\t\t\t\tPer Unit Price: %f\n",no[i].product_price);
            printf("\t\t\t\tTotal Unit Available: %d\n\t\t\t",no[i].product_ammount);
            printChar('=',38);
            getch();
        }
    }
    if(flag==0)
    {
        system("cls");
        title();
        printf("\n\n\t\t\t\t  Mayer Dua Super Shop\n\t\t\t");
        printChar('=',38);
        printf("\n\n\n\t\t\t\tThere Is No Such Product\n");
        printf("\n\n\t\t\t\tPress Enter To Continue\n");
        getch();
    }

}

int search(int n)
{
    for(int i=0; i<ammount; i++)
    {
        if(n==no[i].product_code)
            return i;
    }

}
