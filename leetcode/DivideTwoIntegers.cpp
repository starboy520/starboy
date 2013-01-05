class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
    	if(dividend < 0)
			sign *= -1;
		if(divisor < 0)
			sign *= -1;
		long long big = abs((long long)dividend);

		long long small = abs((long long)divisor);
		long long temp = small;
		long long midres = 1;
		while(temp < big)
		{
			temp <<= 1;
			midres <<= 1;
		}

		int ret = 0;
		while(temp >= small)
		{
			while(big >= temp)
			{
				big -= temp;
				ret += midres;
			}
			temp >>= 1;
			midres >>= 1;
		}
		return ret*sign;
    }
};
