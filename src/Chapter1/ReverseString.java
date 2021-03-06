/**
 * This class reverses a C-style string, i.e., a string is represented by an array of characters and a delimiter at the 
 * end such as "abcd\0"
 * 
 * @author carolinabento
 *
 */
public class ReverseString {

	//Empty constructor
	public ReverseString(){}

	/**
	 * Reverses a string
	 * 
	 * @param string the string to reverse
	 * @return the reversed string
	 */
	public char[] reverse(char[] string){

		for(int i = 0, j = string.length - 2; i < string.length - 1 &&  j > i; i ++,j--){
			char temp = string[i];
			string[i] = string[j];
			string[j] = temp;
		}

		return string;
	}
}
