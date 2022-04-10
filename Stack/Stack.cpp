#include <iostream>

using namespace std;

char stack[50];
int top = -1;

int postfix[50];
int top_post = -1;

void push(char element);
char pop();
void display();
bool check_palindrome();
void reverse_string();
bool check_braces();
string convert_to_postfix();
double evaluate_postfix();

int main()
{
    int exit = 1;
    do
    {
        cout << "Enter number to perform operation\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. Display Stack\n"
             << "4. Check palindrome\n"
             << "5. Reverse string\n"
             << "6. Check balanced braces in a expression\n"
             << "7. Convert expression infix to postfix\n"
             << "8. Evaluate postfix expression\n"
             << "0. Exit\n";
        cin >> exit;

        switch (exit)
        {
        case 0:
            cout << "Exit...\n";
            break;
        case 1:
            cout << "\n";
            char element;
            cout << "Enter element too add: ";
            cin >> element;
            push(element);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            char poped;
            poped = pop();
            cout << "Char poped is: " << poped << "\n";
            cout << "\n";
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "\n";
            if (check_palindrome())
            {
                cout << "String is palindrome\n";
            }
            else
            {
                cout << "Not a palindrome\n";
            }
            cout << "\n";
            break;
        case 5:
            cout << "\n";
            reverse_string();
            cout << "\n";
            cout << "\n";
            break;
        case 6:
            cout << "\n";
            if (check_braces())
            {
                cout << "Balanced Expression\n";
            }
            else
            {
                cout << "Not Balanced\n";
            }
            cout << "\n";
            break;
        case 7:
            cout << "\n";
            cout << convert_to_postfix();
            cout << "\n";
            cout << "\n";
            break;
        case 8:
            cout << "\n";
            cout << evaluate_postfix();
            cout << "\n";
            cout << "\n";
            break;
        default:
            cout << "Wrong input\n";
            break;
        }
    } while (exit != 0);
    
    return 0;
}

void push(char element)
{
    if (top < 20)
    {
        stack[++top] = element;
    }
    else
    {
        cout << "Stack is full\n";
    }
}

char pop()
{
    if (top > -1)
    {
        return stack[top--];
    }
    char a;
    cout << "Stack empty\n";
    return a;
}

char top_char()
{
    char c;
    if (top > -1)
    {
        return stack[top];
    }
    return c;
}

void push_int(int element)
{
    if (top_post < 20)
    {
        postfix[++top_post] = element;
    }
    else
    {
        cout << "Stack is full\n";
    }
}

char pop_int()
{
    if (top_post > -1)
    {
        return postfix[top_post--];
    }
    int a;
    cout << "Stack empty\n";
    return a;
}

int top_int()
{
    int c;
    if (top_post > -1)
    {
        return postfix[top_post];
    }
    return c;
}

void display()
{
    cout << "\n";
    if (top > -1)
    {
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << "\n";
        }
    }
    else
    {
        cout << "Stack is empty\n";
    }
    cout << "\n";
}

void reverse_string()
{
    string str;
    cout << "Enter string to reverse: ";
    cin >> str;
    top = -1;
    cout << "\n";
    for (int i = 0; i < str.length(); i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < str.length(); i++)
    {
        cout << pop();
    }
}

bool check_palindrome()
{
    string str;
    cout << "Enter string to check palindrome: ";
    cin >> str;
    top = -1;
    cout << "\n";
    for (int i = 0; i < str.length(); i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (!(pop() == str[i]))
        {
            return false;
        }
    }
    return true;
}

bool check_braces()
{
    string exp;
    cout << "Enter expression with braces: ";
    cin >> exp;
    top = -1;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
            continue;
        }
        else if (exp[i] == '{')
        {
            if (top_char() == '(')
            {
                return false;
            }
            push(exp[i]);
            continue;
        }
        else if (exp[i] == '[')
        {
            if (top_char() == '(' || top_char() == '{')
            {
                return false;
            }
            push(exp[i]);
            continue;
        }
        else if (exp[i] == ')')
        {
            if (top_char() == '(')
            {
                pop();
            }
            continue;
        }
        else if (exp[i] == '}')
        {
            if (top_char() == '{')
            {
                pop();
            }
            continue;
        }
        else if (exp[i] == ']')
        {
            if (top_char() == '[')
            {
                pop();
            }
            continue;
        }
    }
    if (top == -1)
    {
        return true;
    }
    return false;
}

string convert_to_postfix()
{
    string exp, out_exp = "";
    cout << "Enter expression: ";
    cin >> exp;
    top = -1;
    cout << "\n";
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '(' && exp[i] != '{' && exp[i] != '[' && exp[i] != ')' && exp[i] != '}' && exp[i] != ']')
        {
            out_exp += exp[i];
        }
        else if (exp[i] == '+' || exp[i] == '-')
        {
            if (top_char() != '+' && top_char() != '-' && top_char() != '*' && top_char() != '/')
            {
                push(exp[i]);
            }
            else
            {
                while (top != -1 && top_char() != '(' && top_char() != '{' && top_char() != '[')
                {
                    out_exp += pop();
                }
                push(exp[i]);
            }
        }
        else if (exp[i] == '*' || exp[i] == '/')
        {
            if (top_char() != '*' && top_char() != '/')
            {
                push(exp[i]);
            }
            else
            {
                while (top != -1 && top_char() != '+' && top_char() != '-' && top_char() != '(' && top_char() != '{' && top_char() != '[')
                {
                    out_exp += pop();
                }
                push(exp[i]);
            }
        }
        else if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            do
            {
                if (top_char() != '(')
                {
                    out_exp += pop();
                }
                else
                {
                    pop();
                }
            } while (top != -1 && top_char() != '(');
        }
        else if (exp[i] == '}')
        {
            do
            {
                if (top_char() != '(' && top_char() != '{')
                {
                    out_exp += pop();
                }
                else
                {
                    pop();
                }
            } while (top != -1 && top_char() != '}');
        }
        else if (exp[i] == ']')
        {
            do
            {
                if (top_char() != '(' && top_char() != '{' && top_char() != '[')
                {
                    out_exp += pop();
                }
                else
                {
                    pop();
                }

            } while (top != -1 && top_char() != '[');
        }
    }
    while (top != -1)
    {
        if (top_char() != '(' && top_char() != '{' && top_char() != '[')
        {
            out_exp += pop();
        }
        else
        {
            pop();
        }
    }
    return out_exp;
}

double evaluate_postfix()
{
    string exp, out_exp = "";
    cout << "Enter expression: ";
    cin >> exp;
    top_post = -1;
    int a, b;
    cout << "\n";
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/')
        {
            push_int(exp[i] - 48);
        }
        else if (exp[i] == '+')
        {
            a = pop_int();
            b = pop_int();
            push_int(b + a);
        }
        else if (exp[i] == '-')
        {
            a = pop_int();
            b = pop_int();
            push_int(b - a);
        }
        else if (exp[i] == '*')
        {
            a = pop_int();
            b = pop_int();
            push_int(b * a);
        }
        else if (exp[i] == '/')
        {
            a = pop_int();
            b = pop_int();
            push_int(b / a);
        }
    }
    return top_int();
}