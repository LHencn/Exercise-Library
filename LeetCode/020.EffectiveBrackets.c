typedef struct Stack {
    int *data;
    int size, top;
}Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int top(Stack *s) {
    return s->data[s->top];
}

void expand(Stack *s) {
    int *temp = s->data;
    s->size = 2 * s->size;
    s->data = (int *)malloc(sizeof(s->size));
    for (int i = 0; i < s->top + 1; i++) {
        s->data[i] = temp[i];
    }
}

void push(Stack *s, int val) {
    if (s->top == s->size - 1) 
        expand(s);
    s->top++;
    s->data[s->top] = val;
}

void pop(Stack *s) {
    s->top--;
}

bool isValid(char* s) {
    Stack *stack = init(100000);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(stack, s[i]);
        } else {
            if (stack->top < 0)
                return false;
            else if (top(stack) == '(' && s[i] == ')' || top(stack) == '[' && s[i] == ']' ||top(stack) == '{' && s[i] == '}')
                pop(stack);
            else 
                return false;
        }
    }
    if (stack->top < 0) {
        return true;
    } else
        return false;
}
