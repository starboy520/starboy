public class MinSum {
	
	
  // Give a set such as [0,1,3,8] (this set contains number 0-9, but may not
  // contain all
  // Specify a number k, please use the number in the set, consist a number 
  // which is the min number greater than k, and output it.
  // such as A[1, 0] k = 21, then you should output 100;
  public static int minGreateThanK(int[] intset, int k) {
    int[] num = new int[10];
    for (int i = 0; i < 10; i++) {
      num[i] = 0;
    }
    for (int i = 0; i < intset.length; i++) {
      num[intset[i]] = 1;
    }
    
    int factor = 1;
    while (k / factor != 0) {
      
      int current = (k/factor) % 10; // current bit
      int bigger = (k/factor)/10;
      
      // check if there is left num bigger than current bit 
      // If this exist, then the num can be computed easily.
      int tem = current+1; 
      while (tem < 10) {
        if (num[tem] == 1) {
          break;
        } else {
          tem++;
        }
      }
      if (tem < 10) {
        int a = 0;
        a += factor*bigger*10;
        a += factor*tem; 
        
        int temp = 0;
        while (num[temp] != 1) {
          temp++;
        }
        
        int n = factor/10;
        while (n !=0) {
          a += n*temp;
          n = n/10;
        }
        return a;
        
      } else {
        factor *= 10;
      }
      
    }
    
    if (k / factor == 0) {
      int temp = 1;
      while (num[temp] != 1) {
        temp++;
      }
      if (num[0] == 1) {
        return factor * temp;
      } else {
        int a = 0;
        while (factor != 0) {
          a += factor* temp;
          factor = factor / 10;
        }
        return a;
      }
    }
    
    return -1234;
  }
  
  /* Give a array, let left is odd and right is even*/
  public static void reshuffle(int[] a) {
    int begin = 0;
    int end = a.length-1;
    int temp;
    while (begin < end) {
      while (a[begin]%2 == 1) {
        begin++;
      }
      while (a[end]%2 == 0) {
        end--;
      }

      temp = a[begin];
      a[begin] = a[end];
      a[end] = temp;
      begin++;
      end--;
    }
  }
  
  /* given a set of letters and a length N, produce all possible output.(Not permutation). 
   * For example, give the letter (p,o) and length of 3, produce the following output(in any order you want, 
   * not just my example order) ppp ppo poo pop opp opo oop ooo
   * another example would be given (a,b) and length 2
   * answer: ab aa bb ba
   */
  public static void permu(int[] a, int[] output, int index) {
    if (index == output.length) {
      for (int i = 0; i < output.length; i++) {
        System.out.print(output[i]);
      }
      System.out.println();
    } else {
      for (int i = 0; i < a.length; i++) {
        output[index] = a[i];
        permu(a, output, index+1);
      }
    }
  }
  
  public static void main(String[] args) {
    //int[] a = {0,1};
    //System.out.println(minGreateThanK(a, 21));
    
    //int[] b = { 12, 4,2,12,3,455,3212};
    //reshuffle(b);
    //for (int i = 0; i < b.length; i++)
    //  System.out.println(b[i]);
    
    int[] a = {1,2};
    int[] output = new int[3];
    permu(a, output, 0);
  }
}