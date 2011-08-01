public class Nap {
	public static int makeChange(int n, int demon) {
		int next_demon = 0;
		switch (demon) {
		case 25:
			next_demon = 10;
			break;
		case 10:
			next_demon = 5;
			break;
		case 5:
			next_demon = 1;
			break;
		case 1:
			return 1;
		default:
			break;
		}
		int ways = 0;
		for (int i = 0; i * demon <= n; i++) {
			ways += makeChange(n-i*demon, next_demon);
		}
		return ways;
	}
	
	public static void main(String[] args) {
		int n = makeChange(100, 25);
		System.out.println(n);
	}
}