import org.junit.*;
import static org.junit.Assert.*;

public class TestRemoveDuplicates {

	@Test
	public void removeDuplicates(){
		char[] myString = {'a','b','c','d','\0'};
		char[] answer = {'a','b','c','d','\0'};
		
		RemoveDuplicates rd = new RemoveDuplicates();
		
		assert(rd.removeDuplicates(myString) == answer);
	}
	
	@Test
	public void removeDuplicatesI(){
		char[] myString = {'a','b','c','d','a','\0'};
		char[] answer = {'a','b','c','d','\0'};
		
		RemoveDuplicates rd = new RemoveDuplicates();
		
		assert(rd.removeDuplicates(myString) == answer);
	}
	
	@Test
	public void removeDuplicatesII(){
		char[] myString = {'a','b','a','c','d','\0'};
		char[] answer = {'a','b','c','d','\0'};
		
		RemoveDuplicates rd = new RemoveDuplicates();
		
		assert(rd.removeDuplicates(myString) == answer);
	}
}
