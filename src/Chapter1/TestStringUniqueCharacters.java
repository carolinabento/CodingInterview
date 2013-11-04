package Chapter1;

import static org.junit.Assert.*;

import org.junit.Test;

public class TestStringUniqueCharacters {

	@Test
	public void duplicateCharacters(){
		String s = "abcdefga";
		assertFalse(new StringUniqueCharacters(s).isOnlyUniqueCharacters());
	}
	
	@Test
	public void uniqueCharacters(){
		String s = "abcdefg";
		assertTrue(new StringUniqueCharacters(s).isOnlyUniqueCharacters());
	}
	
	@Test
	public void emptyString(){
		String s = "";
		assertTrue(new StringUniqueCharacters(s).isOnlyUniqueCharacters());
	}

}
