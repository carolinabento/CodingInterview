package Chapter1;

import static org.junit.Assert.*;

import org.junit.Test;

public class TestStringUniqueCharactersHash {

	@Test
	public void duplicateCharacters(){
		String s = "abcdefga";
		assertFalse(new StringUniqueCharactersHash(s).isOnlyUniqueCharacters());
	}
	
	@Test
	public void uniqueCharacters(){
		String s = "abcdefg";
		assertTrue(new StringUniqueCharactersHash(s).isOnlyUniqueCharacters());
	}
	
	@Test
	public void emptyString(){
		String s = "";
		assertTrue(new StringUniqueCharactersHash(s).isOnlyUniqueCharacters());
	}

}
