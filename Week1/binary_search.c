int search(int* nums, int numsSize, int target)
{
    int low = 0, mid;
    --numsSize;

    while (low <= numsSize)
    {
        mid = (low + numsSize) / 2;
        if (nums[mid] > target)
        {
            numsSize = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}