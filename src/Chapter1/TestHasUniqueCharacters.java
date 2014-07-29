import org.junit.Test;

public class TestHasUniqueCharacters {

	@Test
	public void testNonUniqueString(){
		char[] myString = {'a','b','c','a','\0'};
		
		HasUniqueCharacters huc = new HasUniqueCharacters();
		
		assert(huc.hasUniqueChars(myString) == false);
	}
	
	@Test
	public void testNonUniqueStringI(){
		char[] myString = {'b','a','c','d','e','a','f','g','\0'};
		
		HasUniqueCharacters huc = new HasUniqueCharacters();
		
		assert(huc.hasUniqueChars(myString) == false);
	}
	
	@Test
	public void testUniqueString(){
		char[] myString = {'b','a','c','\0'};
		
		HasUniqueCharacters huc = new HasUniqueCharacters();
		
		assert(huc.hasUniqueChars(myString) == true);
	}
	
	@Test
	public void testEmpty(){
		char[] myString = {'\0'};
		
		HasUniqueCharacters huc = new HasUniqueCharacters();
		
		assert(huc.hasUniqueChars(myString) == true);
	}
}
