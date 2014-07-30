/**
 * This class replaces the white-spaces in a string with '%20'
 * @author carolinabento
 *
 */
public class ReplaceWhiteSpace {

	//Empty constructor
	public ReplaceWhiteSpace(){}


	public char[] replaceWS(char[] string){
		int leng = string.length;

		if(leng > 0){
			int wsCount = 0;

			int[] replaceMap = new int[leng];

			for(int i = 0; i < leng; i++){
				if(string[i] == ' '){
					wsCount++;
					replaceMap[i] = 1;
				}
			}

			char[] result = new char[leng + (wsCount*3)];

			for(int j = 0, k = 0; j < replaceMap.length; j++, k++){
				if(replaceMap[j] == 0){
					//copy the character
					result[k] = string[j];
				}else{
					result[k] = '%';
					result[++k] = '2';
					result[++k] = '0';
				}
			}
			return result;
		}else{
			return string;
		}
	}
}
