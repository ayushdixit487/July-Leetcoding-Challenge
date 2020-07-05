class Solution {
public:
    int hammingDistance(int x, int y) {
       int dist = 0;
    for (unsigned val = x ^ y; val > 0; val = val >> 1)
    {
        if (val & 1)
            dist++;
    }

    return dist;
    }
};
