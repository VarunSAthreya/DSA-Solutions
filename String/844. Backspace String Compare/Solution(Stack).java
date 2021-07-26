
class Solution {
    public String transform(String str) {
        String result = "";
        Stack<Character> stack = new Stack<Character>();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == '#') {
                if (!stack.empty())
                    stack.pop();
            } else {
                stack.push(ch);
            }
        }
        while (!stack.empty()) {
            result += stack.pop();
        }
        return result;
    }

    public boolean backspaceCompare(String s, String t) {
        return transform(s).equals(transform(t));
    }
}
