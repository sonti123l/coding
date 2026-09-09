int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    int *number_product = malloc(numsSize * sizeof(int));

    if (number_product == NULL)
    {
        return NULL;
    }

    int product = 1;

    for (int i = 0; i < numsSize; i++)
    {
        number_product[i] = product;
        product = product * nums[i];
    }

    product = 1;

    for (int i = numsSize - 1; i >= 0; i--)
    {
        number_product[i] = number_product[i] * product;
        product = product * nums[i];
    }

    return number_product;
}