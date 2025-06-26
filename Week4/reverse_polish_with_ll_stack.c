struct Node
{
    int val;
    struct Node* next;
};

void push(struct Node** stack, int value)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->val = value;
    new_node->next = *stack;
    *stack = new_node;
    return;
}

int pop(struct Node** stack)
{
    int value = (*stack)->val;
    struct Node* node = *stack;
    *stack = (*stack)->next;
    free(node);
    return value;
}

int evalRPN(char** tokens, int tokensSize)
{
    struct Node* stack = 0;
    int x, curr = tokens[0][0];

    if (curr == '-')
    {
        curr = '0' - tokens[0][1];
        x = 1;
            
        while (tokens[0][++x] != '\0')
        {
            printf("%d ", curr);
            curr = 10 * curr - (tokens[0][x] - '0');
        }
    }
    else
    {
        curr = curr - '0';
        x = 0;
            
        while (tokens[0][++x] != '\0')
        {
            printf("%d ", curr);
            curr = 10 * curr + (tokens[0][x] - '0');
        }
    }

    push(&stack, curr);

    for (int i = 1; i < tokensSize; i++)
    {
        curr = tokens[i][0];
        printf("%c %d\n", curr, stack->val);

        if (curr >= '0' && curr <= '9' || tokens[i][1] != '\0')
        {
            if (curr == '-')
            {
                curr = '0' - tokens[i][1];
                x = 1;

                while (tokens[i][++x] != '\0')
                {
                    curr = 10 * curr - (tokens[i][x] - '0');
                }
            }
            else
            {
                curr = curr - '0';
                x = 0;

                while (tokens[i][++x] != '\0')
                {
                    curr = 10 * curr + (tokens[i][x] - '0');
                }
            }
            
            push(&stack, curr);
        }
        else
        {
            switch(curr)
            {
                case '+':
                    push(&stack, pop(&stack) + pop(&stack));
                    break;
                
                case '-':
                    x = pop(&stack);
                    push(&stack, pop(&stack) - x);
                    break;

                case '*':
                    push(&stack, pop(&stack) * pop(&stack));
                    break;

                case '/':
                    x = pop(&stack);
                    push(&stack, pop(&stack) / x);
                    break;
            }
        }
    }

    return pop(&stack);

}