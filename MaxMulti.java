// Give a O(n) algorithm to compute the max product of a successive sub array


public class MaxMulti {
	public static double Max_Num(double[] a) {
		double max_positive = 1;
		double min_negative = 1;
		double max = 1;
		
		for (int i = 0; i < a.length; i++) {
			if (a[i] > 0) {
				max_positive = max_positive *a[i];
				min_negative = Math.min(min_negative*a[i], 1);
			}else if(a[i] == 0) {
				max_positive = 1; 
				min_negative = 1;
			}else {
				double temp = max_positive;
				max_positive = Math.max(min_negative*a[i], 1);
				min_negative = temp*a[i];
			}
			max = Math.max(max, max_positive);
		}
		return max;
	}
	
	public static void main(String[] args) {
		double[] a = {1.5, 3, -2, 2.5, 10.2, 0, 12, -3};
		System.out.println(Max_Num(a));
	}
}
