//1.4 Remove duplicates from string
package Chapter1;

public class StringRemoveDuplicates {
	public static final int MAX_SIZE = 100;
	public static final char END_OF_STRING = '\0';
	private char[] s;
	private int length;
	
	public StringRemoveDuplicates(char[] s) {
		this.s = s;
		int i = 0;
		while(s[i] != END_OF_STRING && i < MAX_SIZE) {
			i++;
		}
		this.length = i + 1;
	}
	
	public char[] GetArray() {
		return s;
	}
	
	//invariant : left of i there are only non-duplicates
	public void RemoveDuplicates() {
		int i = 0, j = 0, k = 1;
		while (k < length) {
			for (j = i; j >= -1; j--) {
				if(j >= 0) {
					if (s[k] == s[j]) { //is duplicate
						k++;
						break;
					}
				} else {
					if (k > i + 1) {
						swap(i, k);						
					}
					i++;
					k++;
				}
			}
		}
		s[i] = '\0';
	}
	
	private void swap(int i, int j) {
		char aux = s[i];
		s[i] = s[j];
		s[j] = aux;
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

}
