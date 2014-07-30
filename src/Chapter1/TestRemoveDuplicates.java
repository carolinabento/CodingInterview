import static org.junit.Assert.*;

import org.junit.*;

public class TestRemoveDuplicates {

	@Test
	public void removeDuplicates(){
		char[] myString = {'a','b','c','d','\0'};
		char[] answer = {'a','b','c','d','\0'};
		
		RemoveDuplicates rd = new RemoveDuplicates();
		char[] removedDuplicates = rd.removeDuplicates(myString);
		
		for(int i = 0; i < myString.length; i++){
			assertTrue(answer[i] == removedDuplicates[i]);
		}
	}
	
	@Test
	public void removeDuplicatesI(){
		char[] myString = {'a','b','c','d','a','\0'};
		char[] answer = {'a','b','c','d','\0'};
		
		RemoveDuplicates rd = new RemoveDuplicates();
		
		char[] removedDuplicates = rd.removeDuplicates(myString);
		
		for(int i = 0; i < answer.length; i++){	
			assertTrue(answer[i] == removedDuplicates[i]);
		}
	}
	
	@Test
	public void removeDuplicatesII(){
		char[] myString = {'a','b','a','c','d','\0'};
		char[] answer = {'a','b','c','d','\0'};
		
		RemoveDuplicates rd = new RemoveDuplicates();
		
		char[] removedDuplicates = rd.removeDuplicates(myString);
		
		for(int i = 0; i < answer.length; i++){	
			assertTrue(answer[i] == removedDuplicates[i]);
		}
	}
	
	@Test
	public void removeDuplicatesIII(){
		char[] myString = {'a','b','a','c','b','\0'};
		char[] answer = {'a','b','c','\0'};
		
		RemoveDuplicates rd = new RemoveDuplicates();
		char[] removedDuplicates = rd.removeDuplicates(myString);
		
		
		for(int i = 0; i < answer.length; i++){
			assertTrue(answer[i] == removedDuplicates[i]);
		}
	}
}
