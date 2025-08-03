#include <stdio.h>
#include <math.h>

void menu_print();
void menu_print()
{
    printf("----------------------------------------------\n");
    printf("welcome to the simple calculator made by manav\n ");
    printf("choose one of the following options:\n");
    printf("1. add\n");
    printf("2. subtract\n");
    printf("3. multiply\n");
    printf("4. divide\n");
    printf("5. modulus\n");
    printf("6. power\n");
    printf("7. exit\n");
    printf("----------------------------------------------\n");
}

int main()
{
    int choice;
    double first, second, result;
    while (1)
    {
        menu_print();
        printf("Now, enter your choice:");
        if (scanf("%d", &choice) != 1) /*Fails to store a number in choice
Leaves the invalid input (x) in the input buffer
Keeps repeating the same loop with invalid input still there, causing an infinite loop.*/
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ;     // flush the input buffer
            continue; // if we not do this then sometime it will run like infinite loop
        }

        if (choice == 7)
        {
            printf("\nTHANK YOU FOR USING MY CALCULATOR. GOODBYE!!!");
            break;
        }
        if (choice < 1 || choice > 7)
        {
            printf("\n INVALID CHOICE PLS TRY AGAIN!!!\n");
            continue;
        }

        printf("\nenter your first number:");
        scanf("%lf", &first);
        printf("\nenter your second number:");
        scanf("%lf", &second);

        switch (choice)
        {
        case 1:
            result = first + second;
            break;
        case 2:
            result = first - second;
            break;
        case 3:
            result = first * second;
            break;
        case 4:
            if (second == 0)
            {
                printf("\nerror:divison by zero\n");
                continue;
            }
            result = first / second;
            break;
        case 5:
            if (second == 0)
            {
                printf("\nerror:divison by zero\n");
                continue;
            }
            result = (int)first % (int)second;
            break;
        case 6:
            result = pow(first, second);
            break;
        default:
            printf("u have entered invalid choice");
            break;
        }

        printf("\nResult of the operation is: %.2f\n ", result);
    }
    system("pause"); // this keep open exe file

    return 0;
}