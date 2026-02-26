#include <stdio.h>
#include <stdbool.h>
#include <string.h>


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


        if (strcmp(input, "quit") == 0)
        {
            status = false;
        } else if (strcmp(input, "help") == 0)
        {
            printf("\n\tPass your input as: <operand><operator><operand>");
            printf("\n\tFor example: 2+2\n\n");
        } else
        {
            // Parse input
            int matched = sscanf(input, "%lf %c %lf", &left, &op, &right);

            if (matched == 3)
            {
                // The code below does not work. Need to use a switch on op to determine which case to use based on the value of op
                int result = ("%d %c %d", (int)left, op, (int)right);
                printf("\nResult: %d\n", result);
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
    calculate();

    return 0;

}