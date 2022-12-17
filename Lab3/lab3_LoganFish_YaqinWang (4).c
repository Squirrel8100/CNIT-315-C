/******************************************************************************
Logan Fish
CNIT 315 Lab Section 002 Wednesday 3:30 - 5:20
Lab 3 Function Program
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "Lab3lib.h"

int main()
{
    int counter = 0;
    do
    {
        int n = 0;
        int i = 0;
        int UserInput = 0;
        char m = 'y';
        
        printf("\n--------------------------------------------------\n"
        "Enter in the number 1 to select Factorials \n" 
        "Enter in the number 2 to select the Fibonacci Series \n" 
        "Enter in the number 3 to select the Towers of Hanoi \n" 
        "Enter in the number 4 to select String Reversal \n"
        "Enter in the number 5 to select Binary Conversion \n"
        "Enter in the number 6 to END! THE! PROGRAM! \n"
        "--------------------------------------------------\n"
        "Please Enter in Your Choice!"
        "\nThe curret program count is: %d \n" "\nEnter Number here: ", counter);
        
        scanf("%d", &UserInput);
        if(m == 'y' || m == 'Y')
        
        switch(UserInput)
        {
            //Recursive Call upon Function 1 Factorials
            //Usage of n should be changed

        case 1: //Case 1 of the switch statement  
            printf("\nPlease Enter a Positive Integer to calculate its Factorial: ");
            scanf("%d", &n);
            
            if(n < 0)
            {
                printf("\nPlease only use positive numbers ");
                return 2;
            }
            else
            {
                i = factorial(n);
                printf("Factorial of %d! = %d \n", n, i);
            }
            counter++;
        break;
        
        //Recursive Call upon Function 2 The Fibonacci Sequence
        case 2: //case 2 of the switch statement 
            printf("\nPlease Enter a Positive Integer to create the Fibonacci ");
            scanf("%d", &n);
        
            if(n < 0)
            {
                printf("Please only use positive numbers ");
                return 2;
            }
            else
            {
                //I dont know about doing it this way...?
                printf("\nThe Fibonacci is: ");
                printf("%d", FibonacciFun(n));
            }
            counter++;
        break;
        
        //Recursive call upong the Towers of Hanoi
        case 3: //case 3 of the switch statement 
            printf("\nPlease enter the number of discs on the pegs, This must be greater than 0 ");
            scanf("%d", &n);
            
            if(n <= 0 )
            {
                printf("\nYou need to enter a value that is greater than 0 ");
                return 2;
            }
            else
            {
                printf("The tower of Hanoi uses the moves \n ");
                runHanoi(n, 'A', 'C', 'B');   
            }
            counter++;
        break;
        
        case 4: //case 4 of the string switcher
            printf("please enter a string to be reversed. Do Not Enter any Spaces! \n"); //recursive function for string reversal
            scanf("%s", &m);
            printf("The Typed String is: %s\n", &m);
            ReverseString(&m, 0, strlen(&m)-1);
            counter++;
        break;
        
        case 5: //This is where i will put the ASCII Conversion?
            printf("please enter a string to be converted to Binary. Do Not Enter any Spaces! \n"); //recursive function for string reversal
            scanf("%s", &m);
            printf("The Typed String is: %s\n", &m);
            BinaryConverter(&m);
            counter++;
        break;
        
        //end the Program
        case 6: //case that ends the Program
        printf("You have chosen to end the program." 
        "\nThe number of functions ran was: %d", counter);
            return 0;
        break;
        }
    } 
    while(counter != 0);
}
