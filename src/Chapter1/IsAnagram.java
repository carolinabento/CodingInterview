//1.3 - find if a string is a permutation of another
package Chapter1;

public class IsAnagram {
	private boolean isAnagram;
	
	public IsAnagram(char[] str1, int len1, char[] str2, int len2) {
		this.isAnagram = innerIsAnagram(str1, len1, str2, len2);
	}
	
	private boolean innerIsAnagram(char[] str1, int len1, char[] str2, int len2) {
		//invariant: everything to the left of str2[j] is the same as str1
		if(len1 != len2) {
			return false;
		}
		int i = 0, j = 0;
		while(i < len1) {
			while(j < len2) {
				if(str1[i] == str2[j]) {
					swap(str2, i, j);
					j = ++i;
				} else {
					if(j == len2 -1) {
						return false;
					} else {
						j++;						
					}
				}
			}
		}
		return true;
	}
	
	private void swap(char[] str, int i, int j) {
		char aux = str[i];
		str[i] = str[j];
		str[j] = aux;
	}
	
	public static void main(String[] args){
		bothEmpty();
		differentLengths();
		sameWord();
		anagram();
		noAnagram();
	}
	
	private static void bothEmpty() {
		char[] str1 = "\0".toCharArray();
		char[] str2 = "\0".toCharArray();
		IsAnagram isAnagram = new IsAnagram(str1, str1.length, str2, str2.length);
		assert(isAnagram.isAnagram == true);
	}
	
	private static void differentLengths() {
		char[] str1 = "\0".toCharArray();
		char[] str2 = "ups\0".toCharArray();
		IsAnagram isAnagram = new IsAnagram(str1, str1.length, str2, str2.length);
		assert(isAnagram.isAnagram == false);
	}
	
	private static void sameWord() {
		char[] str1 = "ops\0".toCharArray();
		char[] str2 = "ops\0".toCharArray();
		IsAnagram isAnagram = new IsAnagram(str1, str1.length, str2, str2.length);
		assert(isAnagram.isAnagram == true);
	}
	
	private static void anagram() {
		char[] str1 = "orchestra\0".toCharArray();
		char[] str2 = "carthorse\0".toCharArray();
		IsAnagram isAnagram = new IsAnagram(str1, str1.length, str2, str2.length);
		assert(isAnagram.isAnagram == true);
	}
	
	private static void noAnagram() {
		char[] str1 = "abcdefg\0".toCharArray();
		char[] str2 = "abcdxyz\0".toCharArray();
		IsAnagram isAnagram = new IsAnagram(str1, str1.length, str2, str2.length);
		assert(isAnagram.isAnagram == false);
	}
}
