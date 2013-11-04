// 1.1 - Determine if a string has inly unique characters
package Chapter1;

import java.util.HashMap;


public class StringUniqueCharacters {

	private String s;
	
	public StringUniqueCharacters(String s) {
		this.s = s;
	}
	
	public boolean isOnlyUniqueCharacters() {
		HashMap<Character, Boolean> map = new HashMap<Character, Boolean>();
		for (int i = 0; i < s.length(); i++) {
			if(map.get(s.charAt(i)) != null) {
				return false;
			} else {
				map.put(s.charAt(i), true);
			}
			
		}
		return true;
	}
}
	


