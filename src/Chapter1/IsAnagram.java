/**
 * This class identifies 
 * @author carolinabento
 *
 */
public class IsAnagram {

	//Empty constructor
	public IsAnagram(){}

	/**
	 * Verifies if two different, non-empty strings are anagrams
	 * 
	 * @param str1 first string
	 * @param str2 second string
	 * @return true if strings are anagrams, otherwise returns false
	 */
	public boolean isAnagram(char[] str1, char[] str2){
		int len1 = str1.length;
		int len2 = str2.length;

		if(len1 != len2 || str1 == str2){
			return false;
		}else{
			int result = 0;

			for(int i = 0; i < len1 - 1; i++){
				for(int j = 0; j < len1 - 1; j++){
					if(str1[i] == str2[j] && str2[j] != ' '){
						result++;
						str2[j] = ' ';
						break;
					}
				}
			}
			return result == len1;
		}
	}
}