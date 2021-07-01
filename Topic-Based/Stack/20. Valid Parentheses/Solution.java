
class Solution {
    public boolean isValid(String s) {
        if (s.equals(""))
            return true;
        Stack<Character> stack = new Stack<Character>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(' || ch == '[' || ch == '{')
                stack.push(ch);
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (stack.isEmpty()) {
                    return false;
                } else {
                    char open = stack.pop();

                    switch (ch) {
                        case ')':
                            if (open != '(')
                                return false;
                            break;
                        case ']':
                            if (open != '[')
                                return false;
                            break;
                        case '}':
                            if (open != '{')
                                return false;
                            break;
                        default:
                            return false;
                    }
                }
            }
        }
        return stack.isEmpty();
    }
}
