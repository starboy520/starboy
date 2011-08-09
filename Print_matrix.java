public class Print_matrix {
  public static void print_matrix(int[][] a , int m, int n) {
    int x = 0;
    int y = 0;
    
    int end_x = m-1;
    int end_y = n-1;
    
    while (x <= end_x && y <= end_y) {
      int lint_x = x;
      int lint_y = y;
      
      while (lint_x <= end_x) {
        System.out.print(a[lint_x][lint_y]);
        lint_x++;
      }
      lint_x--;
      lint_y++;
      
      while (lint_y <= end_y ) {
        System.out.print(a[lint_x][lint_y]);
        lint_y++;
      }
      lint_y--;
      lint_x--;
      
      while (lint_x >= x) {
        System.out.print(a[lint_x][lint_y]);
        lint_x--;
      }
      lint_x++;
      lint_y--;
      
      while (lint_y > y) {
        System.out.print(a[lint_x][lint_y]);
        lint_y--;
      }
      
      x++;
      y++;
      end_x--;
      end_y--;
      }
    }
  
  public static void main(String[] args) {
    int[][] a = {{1,2,3},{6,5,4}, {7,8,9}};
    
    print_matrix(a, 3, 3);
    
  }
}
