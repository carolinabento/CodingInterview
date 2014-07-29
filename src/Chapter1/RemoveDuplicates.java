/**
 * This class removes the duplicates from a C-style string, i.e., a string is represented by an array of characters and a delimiter at the 
 * end such as "abcd\0"
 * 
 * @author carolinabento
 *
 */
public class RemoveDuplicates {

	//Empty constructor
	public RemoveDuplicates(){}
	
	/**
	 * Reduces the size of the array, skipping the element at position pos (indicating the position of the duplicate element)
	 * It copies each element in the original string, except the duplicate, i.e., the element in position pos.
	 * 
	 * @param string the string to shrink
	 * @param leng the new length of the string
	 * @param pos position of the duplicate element
	 * @return
	 */
	public char[] shrinkString(char[] string, int leng, int pos){
		char[] result = new char[leng];
		result[leng - 1] = '\0';
		
		int i = 0, j =0;
		
		while(i < leng - 1){
			if(i != pos){
				result[i] = string[j % (leng - 1)];
				i++;
			}
			j++;
		}
		
		return result;
	}
	
	/**
	 * Traverses the string and eliminates its duplicate elements
	 * 
	 * @param string the original string with duplicates
	 * @return the string only with unique characters
	 */
	public char[] removeDuplicates(char[] string){
		int leng = string.length;
		
		for(int i = 0; i < leng - 1; i ++){
			for(int j = leng - 2; j >= 0; j--){
				if(string[i] == string[j]){
					leng--;
					string = shrinkString(string, leng, j);
				}
			}
		}
		return string;
	}
}
