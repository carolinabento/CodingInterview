package Chapter1;

import static org.junit.Assert.*;

import org.junit.Ignore;
import org.junit.Test;

public class TestReverseString {

	@Test
	public void reverseString() {
		char[] regular =  {'a','b', 'c', 'd', '\n'};
		char[] reverse = {'d', 'c', 'b', 'a', '\n'}; 

		assertTrue(ReverseString.CompareTo(new ReverseString(regular).Reverse(), reverse) == 0);
	}
	
	@Test
	public void differentString() {
		char[] regular =  {'a','b', 'c', 'd', '\n'};
		char[] reverse = {'a', 'b', 'c', 'd', '\n'}; 

		assertFalse(ReverseString.CompareTo(new ReverseString(regular).Reverse(), reverse) == 0);
	}
	
	@Ignore
	public void emptyString() {
		fail("Not yet implemented");
	}
	
	@Ignore
	public void hugeString() {
		fail("Not yet implemented");
	}

}
