package Chapter3;

import static org.junit.Assert.*;

import org.junit.Ignore;
import org.junit.Test;

public class TestStack {

	@Test
	public void emptyStackTest(){
		Stack<Integer> s = new Stack<Integer>();
		
		assertTrue(s.isEmpty()== true);
	}
	
	@Test
	public void pushTest(){
		Stack<Integer> s = new Stack<Integer>();
		s.push(new Integer(3));	
		assertTrue(s.getSize() == 1);
	}
	
	@Test
	public void popTest(){
		Stack<Integer> s = new Stack<Integer>();
		s.push(new Integer(3));
		s.push(new Integer(4));
		assertTrue(s.isEmpty() == false);
		assertTrue(s.getSize() == 2);
		int res = s.pop();
		assertTrue(res == new Integer(4));
		res = s.pop();
		assertTrue(res == new Integer(3));
		assertTrue(s.isEmpty() == true);
	}
}
