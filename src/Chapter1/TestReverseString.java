import org.junit.*;

public class TestReverseString {

	@Test
	public void testReverse(){
		ReverseString rs = new ReverseString();
		
		char[] myString = {'a','\0'};
		char[] reversed = rs.reverse(myString);
		
		assert(myString == reversed);
	}
	
	
	@Test
	public void testReverseI(){
		ReverseString rs = new ReverseString();
		
		char[] myString = {'a','b','c','d','\0'};
		char[] answer = {'d','c','b','a','\0'};
		
		char[] reversed = rs.reverse(myString);
		
		assert(reversed == answer);
	}
}
