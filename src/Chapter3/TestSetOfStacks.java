package Chapter3;

import static org.junit.Assert.*;

import org.junit.*;

public class TestSetOfStacks {

	@Test
	public void testEmpty(){
		SetOfStacks<Integer> sos = new SetOfStacks<Integer>(5);
		
		assertTrue(sos.stack.isEmpty());
	}
	
	@Test(expected = NullPointerException.class)
	public void testPopEmpty(){
		SetOfStacks<Integer> sos = new SetOfStacks<Integer>(5);
		
		assertTrue(sos.stack.isEmpty());
		sos.pop();
	}
	
	@Test
	public void testPush(){
		SetOfStacks<Integer> sos = new SetOfStacks<Integer>(3);
		
		sos.push(1);
		sos.push(2);
		sos.push(3);
		
		assertTrue(sos.stack.top.value == 3);
		
		sos.push(4);
		sos.push(5);
		sos.push(6);
		
		assertTrue(sos.stack.top.value == 6);
	}
	
	@Test
	public void testPop(){
		SetOfStacks<Integer> sos = new SetOfStacks<Integer>(3);
		
		sos.push(1);
		sos.push(2);
		sos.push(3);
		assertTrue(sos.stack.top.value == 3);
		
		sos.push(4);
		sos.push(5);
		sos.push(6);
		assertTrue(sos.stack.top.value == 6);
		
		sos.pop();
		sos.pop();
		sos.pop();
		assertTrue(sos.stack.top.value == 3);
		
		sos.pop();
		assertTrue(sos.stack.top.value == 2);
		
		sos.pop();
		assertTrue(sos.stack.top.value == 1);
		
		sos.pop();
		assertTrue(sos.stack.isEmpty());
	}
}
