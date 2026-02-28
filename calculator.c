#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
#endif


void fullscreen(void)
{
    #ifdef _WIN32
        keybd_event(VK_MENU, 0x38, 0, 0);
        keybd_event(VK_RETURN, 0x1c, 0, 0);
        keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
    #endif
}


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
        if (strcmp(input, "quit") == 0 || (strcmp(input, "QUIT") == 0) || (strcmp(input, "q") == 0) || (strcmp(input, "Q") == 0) || (strcmp(input, "exit") == 0) || (strcmp(input, "EXIT") == 0) || (strcmp(input, "e") == 0) || (strcmp(input, "E") == 0))
        {
            status = false;
        } 
        else if (strcmp(input, "help") == 0 || (strcmp(input, "HELP") == 0) || (strcmp(input, "h") == 0) || (strcmp(input, "H") == 0))
        {
            // Description of what the program does
            printf("\n\n[DESCRIPTION]");
            printf("\n\n\tThis is a simple calculator that I am building to teach myself C. It currently supports simple calculations,");
            printf("\n\tthough I plan on implementing solutions to add more advanced computation capability.");
            
            // Instructions on how to use the calculator
            printf("\n\n\n\n[USAGE]");
            printf("\n\n\tPass your input as: <operand><operator><operand>");
            printf("\n\tFor example: 2+2\n\n");
            printf("\tThe following operators are available:\n\n");
            printf("\t\t[+]\t Addition\n");
            printf("\t\t[-]\t Subtraction\n");
            printf("\t\t[*]\t Multiplication\n");
            printf("\t\t[/]\t Division");

            // Instructions on how to use the calculator
            printf("\n\n\n\n[COMMANDS]");
            printf("\n\n\tThe following commands are available:\n\n");
            printf("\t\t['help', 'h'] ----------------------- Will list information on how to use the program.\n");
            printf("\n\n\t\t['clear', 'cls' 'c'] ---------------- Will clear the console.\n");
            printf("\n\n\t\t['quit', 'q' 'exit', 'e'] ----------- Will exit the program.\n\n\n");

        } 
        else if (strcmp(input, "clear") == 0 || (strcmp(input, "CLEAR") == 0) || (strcmp(input, "cls") == 0) || (strcmp(input, "CLS") == 0) || (strcmp(input, "c") == 0) || (strcmp(input, "C") == 0))
        {
            clear_screen();
            printf("(type 'help' for help)\n");
        } 
        else
        {
            // Parse input
            int matched = sscanf(input, "%lf %c %lf", &left, &op, &right);

            if (matched == 3)
            {
                double result;
                bool valid_result = true;

                switch (op)
                {
                    case '+':
                        result = left + right;
                        valid_result = true;
                        break;

                    case '-':
                        result = left - right;
                        valid_result = true;
                        break;

                    case '*':
                        result = left * right;
                        valid_result = true;
                        break;

                    case '/':
                        if (right == 0)
                        {
                            valid_result = false;
                            break;
                        } 
                        else
                        {
                            result = left / right;
                            valid_result = true;
                            break;
                        }
                        break;

                    default:
                        valid_result = false;
                        printf("[Unsupported operator]");
                        break;
                }

                if (valid_result == true)
                {   // Checks if result is an integer or double
                    if (result == (int)result)
                    {
                        printf("\n\tResult: %d\n\n", (int)result);
                    } else 
                    {
                        printf("\n\tResult: %g\n\n", result);
                    }
                } else
                {
                    printf("\n\t[Undefined behavior]\n");
                }

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
    fullscreen();

    printf("(type 'help' for help)\n");
    calculate();

    printf("\n");
    return 0;
}