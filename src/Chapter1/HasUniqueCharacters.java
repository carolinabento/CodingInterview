
/**
 * This class verifies if a string contains only unique characters
 * 
 * */
public class HasUniqueCharacters {
	
	//class empty constructor
	public HasUniqueCharacters(){}
	
	/**
	 * Verifies if a string contains only unique characters
	 * @param string the string to analyze
	 * @return true if the string only has unique characters, otherwise returns false
	 */
	public boolean hasUniqueChars(char[] string){
		boolean result = true;
		
		for(int i = 0; i < string.length - 1; i ++){
			for(int j = 1; j < string.length - 1; j++){
				if(string[i] == string[j] && i != j){
					return result = false;
				}else{
					result = true;
					continue;
				}
			}
		}
		return result;
	}
}
