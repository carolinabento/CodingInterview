import static org.junit.Assert.*;

import org.junit.Test;

public class TestReplaceWhiteSpace {

	@Test
	public void testReplaceWS(){
		ReplaceWhiteSpace rws = new ReplaceWhiteSpace();
		
		char[] myString = {};
		char[] answer = rws.replaceWS(myString);
		
		assertTrue(myString == answer);
	}
	
	
	@Test
	public void testReplaceWSI(){
		ReplaceWhiteSpace rws = new ReplaceWhiteSpace();
		
		char[] myString = {'a','b',' ','d','\0'};
		char[] answer = {'a','b','%','2','0','d','\0'};
		
		char[] replacedString = rws.replaceWS(myString);

		for(int i = 0; i < myString.length; i++){
			assertTrue(answer[i] == replacedString[i]);
		}
	}
	
	@Test
	public void testReplaceWSII(){
		ReplaceWhiteSpace rws = new ReplaceWhiteSpace();
		
		char[] myString = {'a','b',' ','d','\0'};
		char[] answer = {'a','b','%','2','0','\0'};
		
		char[] replacedString = rws.replaceWS(myString);
		
		assertTrue(replacedString != answer);
	}
}
