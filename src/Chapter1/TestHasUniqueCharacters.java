import static org.junit.Assert.*;

import org.junit.Test;

public class TestHasUniqueCharacters {

	@Test
	public void testNonUniqueString(){
		HasUniqueCharacters huc = new HasUniqueCharacters();
		
		char[] myString = {'a','b','c','a','\0'};
		
		assertFalse(huc.hasUniqueChars(myString));
		
	}
	
	@Test
	public void testNonUniqueStringI(){
		char[] myString = {'b','a','c','d','e','a','f','g','\0'};
		
		HasUniqueCharacters huc = new HasUniqueCharacters();
		
		assertFalse(huc.hasUniqueChars(myString));
	}
	
	@Test
	public void testUniqueString(){
		char[] myString = {'b','a','c','\0'};
		
		HasUniqueCharacters huc = new HasUniqueCharacters();
		
		assertTrue(huc.hasUniqueChars(myString));
	}
	
	@Test
	public void testEmpty(){
		char[] myString = {'\0'};
		
		HasUniqueCharacters huc = new HasUniqueCharacters();
		
		assertTrue(huc.hasUniqueChars(myString));
	}
}
