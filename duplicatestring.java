
import java.util.*;


class GFG {
    public static void main(String[] args)
    {
        String s = "peeks for peeks";
        String ans = "";
       
        for (int i = 0; i < s.length(); i++) {
            char temp = s.charAt(i);
           
            if (temp != ' ') {
              
                if (ans.indexOf(temp) <= -1) {
                    ans = ans + temp;
                }
            }
           
            else {
                ans = ans + ' ';
            }
        }
    
        ans = ans.trim();
        System.out.println("Output : " + ans);
    }
}
