package Chapter1;

import org.junit.Test;
import static org.junit.Assert.assertEquals;




public class TestAnagramDetection {

	@Test
	public void IsEmptyTest(){
		AnagramDetection ad = new AnagramDetection();
		
		char[] word1 ={'\0'};
		char[] word2 = {'\0'};
		int length1 = word1.length;
		int length2 = word2.length;
		
		assertEquals(ad.isAnagram(word1, length1, word2, length2),true);
	}
	
	@Test(expected = NullPointerException.class)
	public void IsNullTest(){
		AnagramDetection ad = new AnagramDetection();
		
		char[] word1 = null;
		char[] word2 = {'\0'};
		int length1 = word1.length;
		int length2 = word2.length;		
		
		ad.isAnagram(word1, length1, word2, length2);
	}
	
	@Test
	public void differentLengthTest(){
		AnagramDetection ad = new AnagramDetection();
		
		char[] word1 ={'a','\0'};
		char[] word2 = {'\0'};
		int length1 = word1.length;
		int length2 = word2.length;
		
		assertEquals(ad.isAnagram(word1, length1, word2, length2),false);
	}
	
	@Test
	public void sameWordTest(){
		AnagramDetection ad = new AnagramDetection();
		
		char[] word1 ={'a','\0'};
		char[] word2 = {'a','\0'};
		int length1 = word1.length;
		int length2 = word2.length;
		
		assertEquals(ad.isAnagram(word1, length1, word2, length2),true);
	}
	
	@Test
	public void noAnagramTest(){
		AnagramDetection ad = new AnagramDetection();
		
		char[] word1 ={'a','b','\0'};
		char[] word2 = {'a','c','\0'};
		int length1 = word1.length;
		int length2 = word2.length;
		
		assertEquals(ad.isAnagram(word1, length1, word2, length2),false);
	}
	
	@Test
	public void isAnagramTest(){
		AnagramDetection ad = new AnagramDetection();
		
		char[] word1 ={'a','b','c','\0'};
		char[] word2 = {'b','c','a','\0'};
		int length1 = word1.length;
		int length2 = word2.length;
		
		assertEquals(ad.isAnagram(word1, length1, word2, length2),true);
	}
	
}
