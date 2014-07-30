import static org.junit.Assert.*;

import org.junit.*;

public class TestReverseString {

	@Test
	public void testReverse(){
		ReverseString rs = new ReverseString();
		
		char[] myString = {'a','\0'};
		char[] reversed = rs.reverse(myString);
		
		assertTrue(myString == reversed);
	}
	
	
	@Test
	public void testReverseI(){
		ReverseString rs = new ReverseString();
		
		char[] myString = {'a','b','c','d','\0'};
		char[] answer = {'d','c','b','a','\0'};
		
		char[] reversed = rs.reverse(myString);
		

		for(int i = 0; i < myString.length; i++){
			assertTrue(answer[i] == reversed[i]);
		}
	}
	
	@Test
	public void testReverseII(){
		ReverseString rs = new ReverseString();
		
		char[] myString = {'a','b','c','d','\0'};
		char[] answer = {'d','b','c','a','\0'};
		
		char[] reversed = rs.reverse(myString);
		
		boolean result = true;
		for(int i = 0; i < myString.length; i++){
			result = result && (answer[i] == reversed[i]);
		}
		
		assertFalse(result);
	}
}
