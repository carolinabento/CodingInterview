package Chapter1;

import static org.junit.Assert.*;

import org.junit.Test;

public class TestStringRemoveDuplicates {

	@Test
	public void SameString() {
		char[] c = "abcde\0".toCharArray();
		StringRemoveDuplicates s = new StringRemoveDuplicates(c);
		s.RemoveDuplicates();
		assertTrue(StringRemoveDuplicates.CompareTo(s.GetArray(), c) == 0 );
	}
	
	@Test
	public void StringOnlyWithDuplicates() {
		char[] c = "abcdeaaabbbccc\0".toCharArray();
		char[] duplicate = "abcde\0".toCharArray();
		StringRemoveDuplicates s = new StringRemoveDuplicates(c);
		s.RemoveDuplicates();
		assertTrue(StringRemoveDuplicates.CompareTo(s.GetArray(), c) == 0 );
	}
	
	@Test
	public void StringWithDuplicatesInterleaved() {
		char[] c = "abcdeaaabbxcccyaaaz\0".toCharArray();
		char[] duplicate = "abcdexyz\0".toCharArray();
		StringRemoveDuplicates s = new StringRemoveDuplicates(c);
		s.RemoveDuplicates();
		assertTrue(StringRemoveDuplicates.CompareTo(s.GetArray(), c) == 0 );
	}

}
