import java.util.Stack;

class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> stack = new Stack<>();
        StringBuilder rep = new StringBuilder(s);
        for (int i = 0; i < rep.length(); i++) {
            if (rep.charAt(i) == '(')
                stack.push(i);
            else if (rep.charAt(i) == ')') {
                if (stack.isEmpty()) {

                    rep.deleteCharAt(i);
                    i--;
                } else {
                    stack.pop();
                }
            }
        }
        while (!stack.isEmpty())
            rep.deleteCharAt(stack.pop());

        return rep.toString();
    }
}
