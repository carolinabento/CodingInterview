import static org.junit.Assert.*;

import org.junit.Test;

public class TestIsAnagram {

	@Test
	public void testIsAnagram(){
		IsAnagram ia = new IsAnagram();
		
		char[] str1 = {'a','\0'};
		char[] str2 = {'a','b','\0'};
		
		assertFalse(ia.isAnagram(str1,str2));
	}
	
	
	@Test
	public void testIsAnagramI(){
		IsAnagram ia = new IsAnagram();
		
		char[] str1 = {'a','\0'};
		char[] str2 = {'a','\0'};
		
		assertTrue(ia.isAnagram(str1,str2));
	}
	
	
	@Test
	public void testIsAnagramII(){
		IsAnagram ia = new IsAnagram();
		
		char[] str1 = {'d','o','c','t','o','r','w','h','o','\0'};
		char[] str2 = {'t','o','r','c','h','w','o','o','d','\0'};
		
		assertTrue(ia.isAnagram(str1,str2));
	}
	
	@Test
	public void testIsAnagramIII(){
		IsAnagram ia = new IsAnagram();
		
		char[] str1 = {'d','o','c','t','o','r','w','h','o','\0'};
		char[] str2 = {'t','o','r','c','h','w','o','o','i','\0'};
		
		assertFalse(ia.isAnagram(str1,str2));
	}
	
	@Test
	public void testIsAnagramIV(){
		IsAnagram ia = new IsAnagram();
		
		char[] str1 = {'d','o','c','t','o','r','w','h','o','\0'};
		char[] str2 = {'t','o','r','c','h','w','o','o','\0'};
		
		assertFalse(ia.isAnagram(str1,str2));
	}
}
