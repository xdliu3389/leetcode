class Solution {
public:
    int lengthOfLIS(vector<int>& array) {
        int len = array.size();
        if(0 == len)
            return 0;

        int *lis = new int[len];

        for(int i=0; i<len; i++)
            lis[i] = 1;

        int max = 1;
        for(int i=1; i<len; i++) {
            //The lis before i is non-rule, we need to loop from 0 to i to get the max ;
            for(int j=0; j<i; j++) {
                if(array[j] < array[i] && (lis[j] + 1) > lis[i])
                    lis[i] = lis[j] + 1;

                max = max < lis[i] ? lis[i] : max;
            }
        }

        return max;
    }
};
