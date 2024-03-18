int minBitFlips(int start, int goal)
{
    int cnt = 0;
    int ans = start ^ goal;
    while (ans != 0)
    {
        ans = ans & ans - 1;
        cnt = cnt + 1;
    }
    return cnt;
}