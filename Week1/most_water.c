int maxArea(int* height, int heightSize)
{
    int maxA = 0,low = 0;
    --heightSize;

    while (low < heightSize)
    {
        if (height[low] <= height[heightSize])
        {
            maxA = fmax( ((heightSize - low) * height[low]), maxA);
            ++low;
        }
        else
        {
            maxA = fmax( ((heightSize - low) * height[heightSize]), maxA);
            --heightSize;
        }
    }

    return maxA;
}