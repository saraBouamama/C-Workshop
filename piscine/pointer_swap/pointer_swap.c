void pointer_swap(int **a, int **b)
{
    int *temporary = *a;
    *a = *b;
    *b = temporary;
}
