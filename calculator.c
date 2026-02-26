#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void clear_screen(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void calculate(void)
{
bool status = true;

    while (status == true)
    {
        char input[100];
        double left;
        double right;
        char op;
        
        // Prompt user
        printf("\nEnter an expression: ");
        scanf("%s", input);

        // User can type quit to exit
        if (strcmp(input, "quit") == 0)
        {
            status = false;
        } 
        else if (strcmp(input, "help") == 0)
        {
            // Description of what the program does
            printf("\n[DESCRIPTION]");
            printf("\n\tThis is a simple calculator. In it's current form, the program only handles integers,");
            printf("\n\tthough I will be adding logic in the future to handle both integers and floating point numbers.");
            
            // Instructions on how to use the calculator
            printf("\n\n[USAGE]");
            printf("\n\tPass your input as: <operand><operator><operand>");
            printf("\n\tFor example: 2+2\n\n");
            printf("The following operators are available:\n\n");
            printf("\t[+]\t Addition\n");
            printf("\t[-]\t Subtraction\n");
            printf("\t[*]\t Multiplication\n");
            printf("\t[/]\t Division\n\n");
        } 
        else if (strcmp(input, "clear") == 0)
        {
            clear_screen();
            printf("\n(type 'quit' to exit)\n");
            printf("(type 'help' for help)\n");
            printf("(type 'clear' to clear the screen)\n");
        } 
        else
        {
            // Parse input
            int matched = sscanf(input, "%lf %c %lf", &left, &op, &right);

            if (matched == 3)
            {
                int result;

                switch (op)
                {
                    case '+':
                        result = left + right;
                        break;

                    case '-':
                        result = left - right;
                        break;

                    case '*':
                        result = left * right;
                        break;

                    case '/':
                        if (right == 0)
                        {
                            printf("\n[Undefined] Division by zero\n");
                        } else
                        {
                            result = left / right;
                            break;
                        }
                }
                printf("\n\tResult: %d\n\n", result);
            } else 
            {
                printf("\n\t[Error] Invalid input or format: <num> <operator> <num>\n\n");
            }
        }
    }
}


// Main function
int main(void)
{
    printf("\n(type 'quit' to exit)\n");
    printf("(type 'help' for help)\n");
    printf("(type 'clear' to clear the screen)\n");
    calculate();

    printf("\n");
    return 0;
}