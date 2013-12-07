//1.1 improvement
package Chapter1;

public class StringUniqueCharsNoHash {
	public static final int MAX_SIZE = 100;
	public static final char END_OF_STRING = '\0';
	
	private char[] s;
	private int length;
	private boolean isUnique;
	
	public StringUniqueCharsNoHash(char[] s) {
		this.length = getStringSize(s);
		this.s = copyString(s, length);
		this.isUnique = !hasDuplicates();
	}
	
	private int getStringSize(char[] s) {
		int i = 0;
		while(s[i] != END_OF_STRING && i < MAX_SIZE) {
			i++;
		}
		return i+1;
	}
	
	private char[] copyString(char[]s, int size) {
		char[] str = new char[size];
		for (int i = 0; i < size; i++) {
			str[i] = s[i];
		}
		return str;
	}
	
	public char[] GetArray() {
		return s;
	}
	
	public boolean isUnique() {
		return isUnique;
	}
	
	//invariant : left of i there are only non-duplicates
	private boolean hasDuplicates() {
		int i = 0, j = 0, k = 1;
		while (k < length) {
			for (j = i; j >= -1; j--) {
				if(j >= 0) {
					if (s[k] == s[j]) { //is duplicate
						return true;
					}
				} else {
					i++; k++;
				}
			}
		}
		return false;
	}
	
	
}
