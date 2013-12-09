package Chapter1;

public class AnagramDetection {

	public boolean isEmpty(char[] word){
		return word == null || word[0] == '\0';
	}

	public boolean isAnagram(char[] word1, int length1, char[] word2, int length2){
		int i = 0;
		int j = 0;
		boolean result = false;

		if(length1 != length2){
			return false;
		}

		if(isEmpty(word1) && isEmpty(word2)){
			return true;
		}

		while(i < length1){
			if(word1[i] == word2[j] && word1[i] == '\0'){
				break;
			}
			
			if(word1[i] != word2[j]){
				result = false;
				i++;
			}else{
				result = true;
				
				if(i != j){
					char temp = word1[j];
					word1[j] = word2[i];
					word1[i] = temp;
					j++;
					i = j;
				}else{
					i++;
					j++;
				}
			}
		}
		return result;
	}

	//orchestra == carthorse
}
/*
word1   	\   word2    		\  result
-----------------------------------------
orchestra		[]					FALSE	- length1 != length2
[]				[]					TRUE	- isEmpty(word1) && isEmpty(word2)
orchestra 		orchestra			TRUE	- while(word1[i] == word2[i])
orchestra		carthorse			TRUE	- 

 */