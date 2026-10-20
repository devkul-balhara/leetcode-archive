public int SortableIntegers(int[] nums) {
    int n = nums.Length, res = 0;

    for(int i = 1; i * i <= n; i++)
    {
        if(n % i != 0) continue;

        int div1 = i, div2 = n / i, prevMax = 0;
        bool sorted = true;

        for(int j = 0; j < div1 && sorted; j++)
        {
            int currMin = nums[j * div2], currMax = nums[j * div2];
            int negDiff = nums[j * div2] - nums[j * div2 + div2 - 1] < 0 ? 1 : 0;
            if(currMin < prevMax) sorted = false;

            for(int k = j * div2 + 1; k < (j + 1) * div2 && sorted; k++)
            {
                currMin = Math.Min(currMin, nums[k]);
                currMax = Math.Max(currMax, nums[k]);
                int diff = nums[k] - nums[k - 1];
                if(diff < 0) negDiff++;
                if(negDiff > 1) sorted = false;
                if(currMin < prevMax) sorted = false;
            }
            prevMax = currMax;
        }
        if(sorted) res += div2;

        if(div1 == div2) continue;

        sorted = true;
        prevMax = 0;

        for(int j = 0; j < div2 && sorted; j++)
        {
            int currMin = nums[j * div1], currMax = nums[j * div1];
            int negDiff = nums[j * div1] - nums[j * div1 + div1 - 1] < 0 ? 1 : 0;
            if(currMin < prevMax) sorted = false;

            for(int k = j * div1 + 1; k < (j + 1) * div1 && sorted; k++)
            {
                currMin = Math.Min(currMin, nums[k]);
                currMax = Math.Max(currMax, nums[k]);
                int diff = nums[k] - nums[k - 1];
                if(diff < 0) negDiff++;
                if(negDiff > 1) sorted = false;
                if(currMin < prevMax) sorted = false;
            }
            prevMax = currMax;
        }
        if(sorted) res += div1;
    }

    return res;
}