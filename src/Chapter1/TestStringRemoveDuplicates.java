package Chapter1;

import static org.junit.Assert.*;

import org.junit.Ignore;
import org.junit.Test;


public class TestStringRemoveDuplicates {

	@Test
	public void SameString() {
		char[] original = "abcde\0".toCharArray();
		StringRemoveDuplicates s = new StringRemoveDuplicates(original);
		assertTrue(StringRemoveDuplicates.CompareTo(s.GetArray(), original) == 0 );
	}
	
	@Test
	public void StringOnlyWithDuplicates() {
		char[] original = "abcdeaaabbbccc\0".toCharArray();
		char[] withoutDuplicates = "abcde\0".toCharArray();
		StringRemoveDuplicates s = new StringRemoveDuplicates(original);
		assertTrue(StringRemoveDuplicates.CompareTo(s.GetArray(), withoutDuplicates) == 0 );
	}
	
	@Test
	public void StringWithDuplicatesInterleaved() {
		char[] original = "abcdeaaabbxcccyaaaz\0".toCharArray();
		char[] withoutDuplicates = "abcdexyz\0".toCharArray();
		StringRemoveDuplicates s = new StringRemoveDuplicates(original);
		assertTrue(StringRemoveDuplicates.CompareTo(s.GetArray(), withoutDuplicates) == 0 );
	}

}
