double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int count = 0;
    int *l1 = nums1;
    int *b1 = nums1 + nums1Size - 1;
    int *l2 = nums2;
    int *b2 = nums2 + nums2Size - 1;

    int *l1_to_cmp, *b1_to_cmp, *l2_to_cmp, *b2_to_cmp;


    while (nums2Size + nums1Size - count > 2)
    {
        if (l1 <= b1)
        {
            l1_to_cmp = l1;
            b1_to_cmp = b1;
        }
        else
        {
            l1_to_cmp = b1_to_cmp = NULL;
        }
        if (l2 <= b2)
        {
            l2_to_cmp = l2;
            b2_to_cmp = b2;
        }
        else
        {
            l2_to_cmp = b2_to_cmp = NULL;
        }
        if (l1_to_cmp && l2_to_cmp)
        {
            *l1_to_cmp < *l2_to_cmp ? ++l1 : ++l2;
            ++count;
        }
        if (b1_to_cmp && b2_to_cmp)
        {
            *b1_to_cmp > *b2_to_cmp ? --b1 : --b2;
            ++count;
        }
        if (!l1_to_cmp)
        {
            --b2;
            ++l2;
            count += 2;
            continue;
        }
        if (!l2_to_cmp)
        {
            --b1;
            ++l1;
            count += 2;
            continue;
        }
    }
    
    if (nums1Size + nums2Size - count == 2)
    {
        if (l1 == b1)
        {
            return ((double)*l1 + *l2) / 2;
        }
        else if (l1 < b1)
        {
            return ((double)*l1 + *b1) / 2;
        }
        else
        {
            return ((double)*l2 + *b2) / 2;
        }
    }
    else
    {
        if (l1 == b1)
        {
            return *b1;
        }
        else
        {
            return *b2;
        }
    }
}

