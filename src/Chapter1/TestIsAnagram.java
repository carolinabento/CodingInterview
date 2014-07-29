import org.junit.Test;

public class TestIsAnagram {

	@Test
	public void testIsAnagram(){
		IsAnagram ia = new IsAnagram();
		
		char[] str1 = {'a','\0'};
		char[] str2 = {'a','b','\0'};
		
		assert(ia.isAnagram(str1,str2) == false);
	}
	
	
	@Test
	public void testIsAnagramI(){
		IsAnagram ia = new IsAnagram();
		
		char[] str1 = {'a','\0'};
		char[] str2 = {'a','\0'};
		
		assert(ia.isAnagram(str1,str2) == false);
	}
	
	
	@Test
	public void testIsAnagramII(){
		IsAnagram ia = new IsAnagram();
		
		char[] str1 = {'d','o','c','t','o','r','w','h','o','\0'};
		char[] str2 = {'t','o','r','c','h','w','o','o','d','\0'};
		
		assert(ia.isAnagram(str1,str2) == true);
	}
}
