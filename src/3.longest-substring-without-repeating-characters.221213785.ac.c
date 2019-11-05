int lengthOfLongestSubstring(char *s)
{
    int cache[128];
    for (int i = 0; i < 128; ++i)
    {
        cache[i] = -1;
    }
    int maxlen = 0;
    char *curp = s;
    char *startp = s;
    while (*curp)
    {
        if (cache[*curp] >= startp - s && cache[*curp] < curp - s)
        {
            if (curp - startp > maxlen)
            {
                maxlen = curp - startp;
            }
            startp = s + cache[*curp] + 1;
            // curp = startp;
            continue;
        }
        cache[*curp] = curp - s;
        ++curp;
    }
    if (curp - startp > maxlen)
    {
        maxlen = curp - startp;
    }
    return maxlen;
}
