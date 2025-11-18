#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// PROGRAM 1: PATTERN PRINTING 
void Square(int n)
{
    printf("\n--- Square ---\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void I(int n)
{
    printf("\n--- Letter I ---\n");
    if (n < 3)
    {
        printf("Size too small for clear 'I' pattern. Using size 5 for demonstration.\n");
        n = 5;
    }
    if (n % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == (n / 2) || i == n - 1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                if (i == 0 || j == (n / 2) - 1 || i == n - 1)
                {
                    printf("**");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

void T(int n)
{
    printf("\n--- Letter T ---\n");
    if (n < 3)
    {
        printf("Size too small for clear 'T' pattern. Using size 5 for demonstration.\n");
        n = 5;
    }
    if (n % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == n / 2)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                if (i == 0 || j == (n / 2) - 1)
                {
                    printf("**");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

void Lower_Left_Tri(int n)
{
    printf("\n--- Lower Left Triangle ---\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void Lower_Right_Tri(int n)
{
    printf("\n--- Lower Right Triangle ---\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1) - i; j++)
        {
            printf("  ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void Upper_Right_Tri(int n)
{
    printf("\n--- Upper Right Triangle ---\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("  ");
        }
        for (int k = 0; k < n - i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void Upper_Left_Tri(int n)
{
    printf("\n--- Upper Left Triangle ---\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void answer_patterns(int num, int n)
{
    switch (num)
    {
    case 1:
        Square(n);
        break;
    case 2:
        I(n);
        break;
    case 3:
        T(n);
        break;
    case 4:
        Lower_Left_Tri(n);
        break;
    case 5:
        Lower_Right_Tri(n);
        break;
    case 6:
        Upper_Right_Tri(n);
        break;
    case 7:
        Upper_Left_Tri(n);
        break;
    default:
        printf("Invalid choice. Please choose a number from 1 to 7.\n");
        break;
    }
}

void run_patterns()
{
    int num, n, c;
    int input_valid = 0;
    do
    {
        printf("\nChoose a pattern to print:\n");
        printf("1. Square\n");
        printf("2. Letter 'I'\n");
        printf("3. Letter 'T'\n");
        printf("4. Lower Left Triangle\n");
        printf("5. Lower Right Triangle\n");
        printf("6. Upper Right Triangle\n");
        printf("7. Upper Left Triangle\n");
        printf("Enter choice (1-7) and the size 'N' (e.g., 4 5): ");

        if (scanf("%d %d", &num, &n) != 2)
        {
            printf("Invalid input. Please enter two integers.\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        else if (num < 1 || num > 7)
        {
            printf("Invalid choice. Please choose a number from 1 to 7.\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        else if (n <= 0)
        {
            printf("Size N must be a positive integer.\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        else
        {
            input_valid = 1;
            answer_patterns(num, n);
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    } while (input_valid == 0);
}

// PROGRAM 2: ENCRYPTION
void encrypt_string(char *c)
{
    char *ptr = c;
    while (*ptr != '\0')
    {
        *ptr = *ptr + 1;
        ptr++;
    }
}
void run_encryption()
{
    char c[1000];
    while (getchar() != '\n')
        ;
    printf("Enter the text to encrypt:\n");
    if (fgets(c, sizeof(c), stdin) == NULL)
    {
        printf("Error reading input.\n");
        return;
    }
    encrypt_string(c);
    printf("\nEncrypted Text:\n");
    fputs(c, stdout);
    printf("\n");
}

// PROGRAM 3: NUMBER GUESSING GAME
void run_guessing_game()
{
    srand(time(0));

    int number, guess, nguesses = 1;
    number = rand() % 100 + 1;

    do
    {
        int c;
        printf("Guess the number between 1 to 100: ");
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        if (scanf("%d", &guess) != 1)
        {
            printf("Invalid input. Please enter an integer.\n");
            guess = -1;
            continue;
        }

        if (guess > number)
        {
            printf("Lower number please\n");
        }
        else if (guess < number)
        {
            printf("Higher number please\n");
        }
        else
        {
            printf("You WON! and you guessed it in %d attempts\n", nguesses);
        }
        nguesses++;
    } while (guess != number);
}

// PROGRAM 4: SNAKE, WATER, GUN GAME

int snakeWaterGun(char you, char comp)
{
    if (you == comp)
    {
        return 0;
    }

    if ((you == 'g' && comp == 's') || // Gun beats Snake
        (you == 's' && comp == 'w') || // Snake beats Water
        (you == 'w' && comp == 'g'))   // Water beats Gun
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void run_swg_game()
{
    int score_you = 0, score_comp = 0;

    srand(time(0));

    for (int i = 0; i < 3; i++)
    {
        char you, comp;
        int number = rand() % 100 + 1;

        if (number <= 33)
            comp = 's';
        else if (number <= 66)
            comp = 'w';
        else
            comp = 'g';

        printf("\nRound %d:\n", i + 1);
        printf("Enter 's' for Snake, 'w' for Water, or 'g' for Gun: ");

        if (scanf(" %c", &you) != 1)
        {
            printf("Invalid input.\n");
            return;
        }

        if (you >= 'A' && you <= 'Z')
            you = you + 32;

        if (you != 's' && you != 'w' && you != 'g')
        {
            printf("Invalid. Please enter 's', 'w', or 'g'.\n");
            return run_swg_game();
        }

        int result = snakeWaterGun(you, comp);

        if (result == 1)
            score_you++;
        else if (result == -1)
            score_comp++;

        printf("You chose: %c and computer chose: %c\n", you, comp);
    }

    printf("\n--- Result ---\n");
    if (score_you == score_comp)
        printf("Game DRAW!\n");
    else if (score_you > score_comp)
        printf("You WIN!\n");
    else
        printf("You LOSE!\n");
}

int main()
{
    int choice;
    srand(time(0));

    do
    {
        printf("\n=======================================================\n");
        printf("              MASTER C PROGRAM MENU (4-in-1)\n");
        printf("=======================================================\n");
        printf("1. Pattern Printing Program\n");
        printf("2. Encryption Program\n");
        printf("3. Number GUESSING Game\n");
        printf("4. Snake, Water, Gun Game\n");
        printf("0. Exit Program\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            run_patterns();
            break;
        case 2:
            run_encryption();
            break;
        case 3:
            run_guessing_game();
            break;
        case 4:
            run_swg_game();
            break;
        case 0:
            printf("\nExiting the Program. Goodbye!\n");
            break;
        default:
            printf("\nInvalid choice. Please select a number from the menu.\n");
            break;
        }

    } while (choice != 0);

    return 0;
}