/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize)
{
    int* ans = malloc((n+1) * sizeof(int));
    *returnSize = n+1;

    int max_bit = 1;
    ans[0] = 0;

    for (int i = 1; i < n+1; i++)
    {
        if (i == max_bit << 1)
        {
            max_bit = i;
        }

        ans[i] = ans[i - max_bit] + 1;
    }

    return ans;
}