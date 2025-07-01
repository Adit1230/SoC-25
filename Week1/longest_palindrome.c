char* longestPalindrome(char* s)
{
    int low, high, length = 1, best_low = 0;


    for (float center = 1; s[(int)(center + 0.5)] != '\0'; center += 0.5)
    {
        low = center - 0.4;
        high = center + 0.4;

        while(low >= 0 && s[high] != '\0' && s[low] == s[high])
        {
            --low;
            ++high;
        }

        if (high - low - 1 > length)
        {
            length = high - low - 1;
            best_low = low + 1;
        }
        printf("%f %d %d\n", center, low, length);
    }

    char* ans = malloc((length + 1) * sizeof(char));
    for (low = 0; low < length; ++low)
    {
        ans[low] = s[best_low + low];
    }
    ans[length] = '\0';

    return ans;
    
}