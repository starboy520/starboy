
// http://www.topcoder.com/tc?module=Static&d1=tutorials&d2=stringSearching
public class Kmp {
	// Prefix and sufix.
	public static int[] next(char[] pattern) {
		int[] next = new int[pattern.length + 1];
		next[0] = 0;
		next[1] = 0;
		
		for (int i=2; i <= pattern.length; i++) {
			int j = next[i-1];
			while (true) {
				if (pattern[j] == pattern[i-1]) {
					next[i] = j + 1;
					break;
				}
				if (j == 0) {
					next[i] = 0;
					break;
				}
				j = next[j];
			}
		}
		return next;
	}
	
	public static void KnuthMorrisPratt(char[] text, char[] pattern) {
		int[] next2 = next(pattern);
		
		int i = 0;
		int j = 0; // The first character of the text;
		
		while (j != text.length) { // reach the end.			
			if (text[j] == pattern[i]) {
				i++;
				j++;
				if (i == pattern.length) {// mark as found;
					int m = j - i;
					System.out.println("found at index: " + m);
					i = next2[i]; // found next match.
				}
			} else if (i > 0) {
				i = next2[i];
			} else {
				j++;
			}
		}
		
	}
	
	public static void main(String[] args) {
		char[] pattern = { 'a', 'b', 'a', 'b', 'a', 'c'};
		char[] text = {'a','b', 'a', 'b', 'a', 'c', 'a', 'b', 'a', 'b', 'a', 'c'};
		KnuthMorrisPratt(text, pattern);
	}
	
}
