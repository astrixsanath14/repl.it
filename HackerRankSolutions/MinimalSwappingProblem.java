import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static int countSwaps(String s1, String s2, int size)
    {
        int i = 0, j = 0;
        int result = 0;
    
        // Iterate over the first string and convert
        // every element equal to the second string
        while (i < size) {
            j = i;
    
            // Find index element of first string which
            // is equal to the ith element of second string
            while (s1.charAt(j) != s2.charAt(i)) {
                j += 1;
            }
    
            // Swap adjacent elements in first string so
            // that element at ith position becomes equal
            while (i < j) {
    
                // Swap elements using temporary variable
                char temp = s1.charAt(j);
                s1 = s1.substring(0, j) + s1.charAt(j - 1) + s1.substring(j + 1);
                s1 = s1.substring(0, j - 1) + temp + s1.substring(j - 1 + 1);
                j -= 1;
                result += 1;
            }
            i += 1;
        }
        return result;
    }
    
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        System.out.print(countSwaps(s1, s2, s1.length()));
    }
}

/*
123
321
123 132 312 321

12345
54321
12345 12354 12534 15234 51234
*/