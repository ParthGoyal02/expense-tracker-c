
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 50
#define FILE_NAME "expenses.txt"

struct Expense
{
    char category[CATEGORY_LENGTH];
    float amount;
};

int main(void)
{
    struct Expense expenses[MAX_EXPENSES];
    int choice;
    int count = 0;
    int i, j;
    float total;
    FILE *fp;

    /* Load previously saved expenses */
    fp = fopen(FILE_NAME, "r");

    if (fp != NULL)
    {
        while (count < MAX_EXPENSES &&
               fscanf(fp, "%49[^\t]\t%f\n",
                      expenses[count].category,
                      &expenses[count].amount) == 2)
        {

            if (expenses[count].amount <= 0)
            {
                break;
            }

            count++;
        }

        fclose(fp);
    }

    printf("Loaded %d saved expense(s).\n", count);

    do
    {
        printf("\n===== EXPENSE TRACKER =====\n");
        printf("1. Add expense\n");
        printf("2. View all expenses\n");
        printf("3. Show total spending\n");
        printf("4. Show category-wise spending\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
        case 1:
            if (count >= MAX_EXPENSES)
            {
                printf("Expense limit reached!\n");
                break;
            }

            printf("Enter expense category: ");

            if (scanf(" %49[^\n]",
                      expenses[count].category) != 1)
            {
                printf("Invalid category!\n");
                return 1;
            }

            printf("Enter expense amount: ");

            if (scanf("%f", &expenses[count].amount) != 1 ||
                expenses[count].amount <= 0)
            {
                printf("Invalid amount!\n");
                return 1;
            }

            count++;

            /* Save all expenses */
            fp = fopen(FILE_NAME, "w");

            if (fp == NULL)
            {
                printf("Error saving expenses!\n");
                count--;
                break;
            }

            for (i = 0; i < count; i++)
            {
                fprintf(fp, "%s\t%.2f\n",
                        expenses[i].category,
                        expenses[i].amount);
            }

            fclose(fp);
            printf("Expense added and saved successfully!\n");
            break;

        case 2:
            if (count == 0)
            {
                printf("No expenses recorded yet.\n");
                break;
            }

            printf("\n--- All Expenses ---\n");

            for (i = 0; i < count; i++)
            {
                printf("%d. %s - Rs. %.2f\n",
                       i + 1,
                       expenses[i].category,
                       expenses[i].amount);
            }
            break;

        case 3:
            total = 0;

            for (i = 0; i < count; i++)
            {
                total += expenses[i].amount;
            }

            printf("Total spending: Rs. %.2f\n", total);
            break;

        case 4:
            if (count == 0)
            {
                printf("No expenses recorded yet.\n");
                break;
            }

            printf("\n--- Category-wise Spending ---\n");

            for (i = 0; i < count; i++)
            {
                int already_counted = 0;
                float category_total = 0;

                for (j = 0; j < i; j++)
                {
                    if (strcmp(expenses[i].category,
                               expenses[j].category) == 0)
                    {
                        already_counted = 1;
                        break;
                    }
                }

                if (already_counted)
                {
                    continue;
                }

                for (j = i; j < count; j++)
                {
                    if (strcmp(expenses[i].category,
                               expenses[j].category) == 0)
                    {
                        category_total += expenses[j].amount;
                    }
                }

                printf("%s: Rs. %.2f\n",
                       expenses[i].category,
                       category_total);
            }
            break;

        case 5:
            printf("Exiting Expense Tracker. Goodbye!\n");
            break;

        default:
            printf("Invalid menu choice!\n");
        }

    } while (choice != 5);

    return 0;
}
