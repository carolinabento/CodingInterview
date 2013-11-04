package Chapter1;

import java.util.Stack;

public class ReverseString {
	public static final int MAX_SIZE = 1000;
	private char[] s;
	
	public ReverseString (char[] s) {
		this.s = s;
	}
	
	public char[] Reverse() {
		Stack<Character> stack = new Stack<Character>();
		int i = 0;
		while(s[i] != '\n' && i < MAX_SIZE) {
			stack.add(s[i++]);
		}
		char[] str = new char[i+1];
		i = 0;
		while(!stack.isEmpty()) {
			str[i++] = stack.pop();
		}
		stack.add('\n');
		
		return str;
	}
	
	public static int CompareTo(char[] c1, char[] c2) {
		if(c1 == c2) {
			return 0;
		}
		if (c1 == null) {
			if (c2 == null) {
				return 0;
			} else {
				return -1;
			}
		}
		if (c2 == null) {
			return 1;
		}
		int i = 0;
		while (c1[i] != '\n' && c2[i] != '\n') {
			if (c1[i] < c2[i]) {
				return -1;
			}
			if (c1[i] > c2[i]) {
				return 1;
			}
		}
		if (c1[i] == '\n' && c2[i] != '\n') {
			return -1;
		}
		if (c1[i] != '\n' && c2[i] == '\n') {
			return 1;
		}
		return 0;
	}

}
