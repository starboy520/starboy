/*问题描述：
在计算机中，由于处理器位宽限制，只能处理有限精度的十进制整数加减法，比如在32位宽处理器计算机中，参与运算的操作数和结果必须在-231~231-1之间。如果需要进行更大范围的十进制整数加法，需要使用特殊的方式实现，比如使用字符串保存操作数和结果，采取逐位运算的方式。如下：
9876543210 + 1234567890 = ?
让字符串 num1="9876543210"，字符串 num2="1234567890"，结果保存在字符串 result = "11111111100"。
-9876543210 + (-1234567890) = ?
让字符串 num1="-9876543210"，字符串 num2="-1234567890"，结果保存在字符串 result = "-11111111100"。
要求编程实现上述高精度的十进制加法。
要求实现函数：
void add (const char *num1, const char *num2, char *result)
【输入】num1：字符串形式操作数1，如果操作数为负，则num1[0]为符号位'-'
num2：字符串形式操作数2，如果操作数为负，则num2[0]为符号位'-'
【输出】result：保存加法计算结果字符串，如果结果为负，则result[0]为符号位。
注： I、 当输入为正数时，'+'不会出现在输入字符串中；当输入为负数时，'-'会出现在输入字符串中，且一定在输入字符串最左边位置；
II、输入字符串所有位均代表有效数字，即不存在由'0'开始的输入字符串，比如"0012", "-0012"不会出现；
III、要求输出字符串所有位均为有效数字，结果为正或0时'+'不出现在输出字符串，结果为负时输出字符串最左边位置为'-'。
示例 输入：num1 = "580"
num2 = "-50"
输出：result = "530"
输入：num1 = "580"
num2 = "-600"
输出：result = "-20"
*/

#include <cstdio>
#include <cstring>
void add(const char* num1, const char* num2, char* result) {
  int flag1 = 1;
  int flag2 = 1;
  
  // strip the flag.
  if (*num1 == '-') {
    num1++;
    flag1 = 0;
  }
  if (*num2 == '-') {
    flag2 = 0;
    num2++;
  }

  int length1 = strlen(num1);
  int length2 = strlen(num2);
  
  if ((flag1 == 1 && flag2 == 1) || (flag1 == 0 && flag2 == 0)) {
    char* add_result = result;
    
    int len1 = length1-1;
    int len2 = length2-1;

    int added = 0;
    while (len1 >=0 || len2 >=0) {
      int temp1 = 0;
      int temp2 = 0;
      
      if (len1 >= 0)
        temp1 = num1[len1] - '0';
      if (len2 >= 0)
        temp2 = num2[len2] - '0';

      *add_result++ = (temp1+temp2 + added)%10 +'0';
      added = (temp1+temp2 + added)/10;
      len1--;
      len2--;
    }

    if (added) 
      *add_result++ = added + '0';

    if (flag1 == '-')
      *add_result++ = '-';

    *add_result = '\0';
    // reverse will do reserse string.
    reverse(result);

  } else {
    // do substitution.
    // first I think we need to determine which one is bigger
    int bigger_one = 0; // two are the same
    int len1 = length1-1;
    int len2 = length2-1;
    
    if (len1 >len2) {
      bigger_one = 1;
    } else if (len2 > len1) {
      bigger_one = 2;
    } else {
      while (len1 >= 0 && len2 >= 0) {
        if (num1[len1] > num2[len2]) {
          bigger_one = 1;
          break;
        }
        if (num1[len1] < num2[len2]) {
          bigger_one = 2;
          break;
        }
        len2--;
        len1--;
      }
    }

    if (bigger_one == 0) {
      *result++ = '0';
      *result = '\0';
    } else {
      char* temp_result = result;
      const char* sub = num1;
      const char* subed = num2;
      if (bigger_one == 2) {
        sub = num2;
        subed = num1;
      }

      int borrowed = 0;
      int len_sub = strlen(sub)-1;
      int len_subed = strlen(subed)-1;

      while (len_sub >= 0 && len_subed >= 0) {
        int temp_sub = 0;
        int temp_subed = 0;
        if (len_sub >= 0) {
          temp_sub = sub[len_sub] - '0' - borrowed;
          borrowed = 0;
        }
        if (len_subed >= 0) {
          temp_subed = subed[len_subed] - '0';
        }

        if (temp_sub < temp_subed) {
          temp_sub += 10;
          borrowed = 1;
        }

        *temp_result = temp_sub - temp_subed + '0';

        len_subed--;
        len_sub--;
      }

      if ((flag1 == 0 && bigger_one == 1) || ((flag2 == 0 && bigger_one == 2)))
          *temp_result++ = '-';
      
      *temp_result = '\0';
      reverse(result);
    }
  }
}





    
