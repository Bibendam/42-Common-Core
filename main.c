#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int op_count = 0;

typedef struct s_stack
{
    int *data;
    int top;
    int size;
} t_stack;

t_stack *init_stack(int size)
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    stack->data = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

void swap(t_stack *stack, char stack_name)
{
    if (stack->top < 1)
        return;
    int temp = stack->data[stack->top];
    stack->data[stack->top] = stack->data[stack->top - 1];
    stack->data[stack->top - 1] = temp;
    printf("s%c\n", stack_name);
    op_count++;
}

void push_pop(t_stack *src, t_stack *dst, char src_name)
{
    if (src->top == -1)
        return;
    dst->data[++dst->top] = src->data[src->top--];
    printf("p%c\n", src_name);
    op_count++;
}

void rotate(t_stack *stack, char stack_name)
{
    if (stack->top < 1)
        return;
    int temp = stack->data[0];
    for (int i = 0; i < stack->top; i++)
    {
        stack->data[i] = stack->data[i + 1];
    }
    stack->data[stack->top] = temp;
    printf("r%c\n", stack_name);
    op_count++;
}

void reverse_rotate(t_stack *stack, char stack_name)
{
    if (stack->top < 1)
        return;
    int temp = stack->data[stack->top];
    for (int i = stack->top; i > 0; i--)
    {
        stack->data[i] = stack->data[i - 1];
    }
    stack->data[0] = temp;
    printf("rr%c\n", stack_name);
    op_count++;
}

void ss(t_stack *a, t_stack *b)
{
    swap(a, 'a');
    swap(b, 'b');
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a, 'a');
    rotate(b, 'b');
}

void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a, 'a');
    reverse_rotate(b, 'b');
}

void radixsort(t_stack *a, t_stack *b, int max)
{
    t_stack *buckets[10];
    for (int i = 0; i < 10; i++)
    {
        buckets[i] = init_stack(a->top + 1);
    }

    int maxDigits = 0;
    while (max != 0) {
        max /= 10;
        maxDigits++;
    }

    for (int exp = 0; exp < maxDigits; exp++)
    {
        while (a->top != -1)
        {
            int bucket_index = abs((a->data[a->top] / (int)pow(10, exp)) % 10);
            push_pop(a, buckets[bucket_index], 'a');
        }
        for (int i = 0; i < 10; i++)
        {
            while (buckets[i]->top != -1)
            {
                push_pop(buckets[i], a, 'a'); // push back to 'a' instead of 'b'
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        free(buckets[i]->data);
        free(buckets[i]);
    }
}

void insertionsort(t_stack *a, t_stack *b)
{
    while (a->top != -1)
    {
        int min_index = 0;
        for (int i = 0; i <= a->top; i++)
        {
            if (a->data[i] < a->data[min_index])
                min_index = i;
        }
        for (int i = 0; i < min_index; i++)
            rotate(a, 'a');
        push_pop(a, b, 'a');
        for (int i = 0; i < min_index; i++)
            reverse_rotate(a, 'a');
    }
    while (b->top != -1)
        push_pop(b, a, 'b');
}

int find_max(t_stack *a)
{
    int max = a->data[0];
    for (int i = 1; i <= a->top; i++)
    {
        if (a->data[i] > max)
        {
            max = a->data[i];
        }
    }
    return max;
}

void print_stack(t_stack *stack)
{
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void push_swap(int *nums, int size)
{
    t_stack *a = init_stack(size);
    t_stack *b = init_stack(size);
    for (int i = 0; i < size; i++)
    {
        a->data[i] = nums[i];
        a->top++;
    }

    printf("Initial stack: ");
    print_stack(a);

    if (size <= 10)
    {
        insertionsort(a, b);
    }
    else
    {
        int max = find_max(a);
        radixsort(a, b, max);
        insertionsort(a, b);
    }

    printf("Sorted stack: ");
    print_stack(a);

    free(a->data);
    free(a);
    free(b->data);
    free(b);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    int size = argc - 1;
    int *nums = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        nums[i] = atoi(argv[i + 1]);
    }

    push_swap(nums, size);

    printf("Total operations: %d\n", op_count);

    free(nums);

    return 0;
}