#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    system("cls");
    char choices[3][10];
    strcpy(choices[0], "Rock");
    strcpy(choices[1], "Paper");
    strcpy(choices[2], "Scissors");
    int exit = 0;
    int machine_choices[5];
    char winner[20];
    char uname[20];
    printf("\nPress 0 To Play Game\tPress 1 to Exit: ");
    scanf("%d", &exit);

    while (!exit)
    {
        system("cls");
        printf("\nEnter your name: ");
        fflush(stdin);
        scanf("%s", uname);
        int user_wins = 0, mach_wins = 0, ties = 0;

        for (int i = 0; i < 5; i++)
        {
            printf("\n\n----------Round %d----------\n\n", i + 1);
            printf("\n\n1.Rock\n2.Paper\n3.Scissors  ");
            int userchoice;
            scanf("%d", &userchoice);
            if (userchoice != 1 && userchoice != 2 && userchoice != 3)
            {
                printf("\nInvalid Option Entered!");
                i--;
                continue;
            }
            int machine_choice;
            machine_choice = rand() % 3 + 1;
            machine_choices[i] = machine_choice;
            if (userchoice == machine_choice)
            {
                printf("\nRound %d Is tied!", i + 1);
                printf("\nBoth chose %s. ", choices[machine_choice - 1]);
                ties++;
            }
            if (machine_choice > userchoice)
            {
                if (userchoice == 1 && machine_choice == 3)
                {
                    printf("\nRound %d is won by %s!\n%s chose %s\tMachine chose %s. ", i + 1, uname, uname, choices[userchoice - 1], choices[machine_choice - 1]);
                    user_wins++;
                }
                if (userchoice == 2 && machine_choice == 3)
                {
                    printf("\nRound %d is won by Machine!\n%s chose %s\tMachine chose %s.", i + 1, uname, choices[userchoice - 1], choices[machine_choice - 1]);
                    mach_wins++;
                }
                if (userchoice == 1 && machine_choice == 2)
                {
                    printf("\nRound %d is won by Machine!\n%s chose %s\tMachine chose %s. ", i + 1, uname, choices[userchoice - 1], choices[machine_choice - 1]);
                    mach_wins++;
                }
            }
            if (machine_choice < userchoice)
            {
                if (userchoice == 3 && machine_choice == 1)
                {
                    printf("\nRound %d is won by Machine!\n%s chose %s\tMachine Chose %s. ", i + 1, uname, choices[userchoice - 1], choices[machine_choice - 1]);
                    mach_wins++;
                }
                if (userchoice == 3 && machine_choice == 2)
                {
                    printf("\nRound %d is won by %s!\n%s chose %s\tMachine chose %s. ", i + 1, uname, uname, choices[userchoice - 1], choices[machine_choice - 1]);
                    user_wins++;
                }
                if (userchoice == 2 && machine_choice == 1)
                {
                    printf("\nRound %d is won by %s!\n%s chose %s\tMachine chose %s. ", i + 1, uname, uname, choices[userchoice - 1], choices[machine_choice - 1]);
                    user_wins++;
                }
            }
        }
        if (user_wins > mach_wins)
        {
            strcpy(winner, uname);
        }
        else if (user_wins < mach_wins)
        {
            strcpy(winner, "Machine");
        }
        else if (user_wins == mach_wins)
        {
            strcpy(winner, "Tied");
        }
        printf("\n\n===========MATCH STATS===========\n\n%s Wins: %d\tMachine Wins: %d\tTies: %d", uname, user_wins, mach_wins, ties);
        printf("\n\nThe Winner is %s!\n\n", winner);

        // //Displaying MAchine choices
        // printf("\n\nMachine Choices: \n");
        // for (int i = 0; i < 5; i++)
        // {
        //     printf("%d\t", machine_choices[i]);
        // }
        printf("\nPress 0 to play again!: ");
        scanf("%d", &exit);
    }
    printf("\nGame Exited!");
}