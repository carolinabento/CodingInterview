/*1.3- Reverse a C-style string
 */
package Chapter1;

import java.util.Stack;

public class ReverseString {
	public static final int MAX_SIZE = 100;
	public static final char END_OF_STRING = '\0';
	private char[] s; //this could be final
	private char[] reversed;
	private int size;
	
	public ReverseString (char[] s) {
		this.s = s;
		Stack<Character> stack = new Stack<Character>();
		int i = 0;
		while(s[i] != END_OF_STRING && i < MAX_SIZE) {
			stack.add(s[i++]);
		}
		size = i + 1;
		reversed = new char[size];
		i = 0;
		while(!stack.isEmpty()) {
			reversed[i++] = stack.pop();
		}
		reversed[i] = END_OF_STRING;
	}
	
	public char[] Reverse() {
		return this.reversed;
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
		while (c1[i] != END_OF_STRING && c2[i] != END_OF_STRING) {
			if (c1[i] < c2[i]) {
				return -1;
			}
			if (c1[i] > c2[i]) {
				return 1;
			}
			i++;
		}
		if (c1[i] == END_OF_STRING && c2[i] != END_OF_STRING) {
			return -1;
		}
		if (c1[i] != END_OF_STRING && c2[i] == END_OF_STRING) {
			return 1;
		}
		return 0;
	}
	
	public String PrintString() {
		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < size; i++) {
			builder.append(s[i]);
		}
		return builder.toString();
	}
	
	public String PrintReverse() {
		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < size; i++) {
			builder.append(reversed[i]);
		}
		return builder.toString();
	}
	

}
