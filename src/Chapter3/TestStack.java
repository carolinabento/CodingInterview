package Chapter3;

import static org.junit.Assert.*;
import org.junit.*;

public class TestStack {

	@Test
	public void testEmpty(){
		Stack myStack = new Stack();

		assertTrue(myStack.isEmpty());
		assertTrue(myStack.size() == 0);
	}

	@Test(expected = NullPointerException.class)
	public void invalidPop(){
		Stack myStack = new Stack();

		assertTrue(myStack.isEmpty());
		
		myStack.pop();
	}

	@Test
	public void testStackInit(){
		Stack myStack = new Stack(1);
		
		assertFalse(myStack.isEmpty());
		assertTrue(myStack.top.value == 1);
		assertTrue(myStack.size() == 1);
	}
	
	@Test
	public void testPush(){
		Stack myStack = new Stack(1);
		
		assertFalse(myStack.isEmpty());
		assertTrue(myStack.top.value == 1);
		myStack.push(2);
		assertTrue(myStack.top.value == 2);
		assertTrue(myStack.size() == 2);
	}
	
	@Test
	public void testMin(){
		Stack myStack = new Stack(1);
		
		assertFalse(myStack.isEmpty());
		assertTrue(myStack.top.value == 1);
		myStack.push(2);
		assertTrue(myStack.top.value == 2);
		
		assertTrue(myStack.min() == 1);
	}
	
	@Test
	public void testPop(){
		Stack myStack = new Stack(1);
		
		assertFalse(myStack.isEmpty());
		assertTrue(myStack.top.value == 1);
		myStack.push(2);
		assertTrue(myStack.top.value == 2);
		myStack.push(3);
		assertTrue(myStack.top.value == 3);
		myStack.push(0);
		assertTrue(myStack.top.value == 0);
		
		assertTrue(myStack.min() == 0);
		assertTrue(myStack.size() == 4);
		
		myStack.pop();
		assertTrue(myStack.top.value == 3);
		assertTrue(myStack.min() == 1);
		assertTrue(myStack.size() == 3);
		
		myStack.pop();
		assertTrue(myStack.top.value == 2);
		assertTrue(myStack.min() == 1);
		assertTrue(myStack.size() == 2);
		
		myStack.pop();
		assertTrue(myStack.top.value == 1);
		assertTrue(myStack.min() == 1);
		assertTrue(myStack.size() == 1);
		
		myStack.pop();
		assertTrue(myStack.isEmpty());
	}
	
	@Test
	public void testPopI(){
		Stack myStack = new Stack(1);
		
		assertFalse(myStack.isEmpty());
		assertTrue(myStack.top.value == 1);
		myStack.push(2);
		assertTrue(myStack.top.value == 2);
		myStack.push(3);
		assertTrue(myStack.top.value == 3);
		myStack.push(0);
		assertTrue(myStack.top.value == 0);
		
		assertTrue(myStack.min() == 0);
		
		myStack.pop();
		assertTrue(myStack.top.value == 3);
		assertTrue(myStack.min() == 1);
		
		myStack.pop();
		assertTrue(myStack.top.value == 2);
		assertTrue(myStack.min() == 1);
		
		myStack.pop();
		assertTrue(myStack.top.value == 1);
		assertTrue(myStack.min() == 1);
		
		myStack.push(0);
		assertTrue(myStack.top.value == 0);
		assertTrue(myStack.min() == 0);
		
		myStack.pop();
		myStack.pop();
		assertTrue(myStack.size() == 0);
		assertTrue(myStack.isEmpty());
	}
	
	@Test(expected = NullPointerException.class)
	public void testPopII(){
		Stack myStack = new Stack(1);
		
		assertFalse(myStack.isEmpty());
		assertTrue(myStack.top.value == 1);
		myStack.push(2);
		assertTrue(myStack.top.value == 2);
		myStack.push(3);
		assertTrue(myStack.top.value == 3);
		myStack.push(0);
		assertTrue(myStack.top.value == 0);
		
		assertTrue(myStack.min() == 0);
		
		myStack.pop();
		assertTrue(myStack.top.value == 3);
		assertTrue(myStack.min() == 1);
		
		myStack.pop();
		assertTrue(myStack.top.value == 2);
		assertTrue(myStack.min() == 1);
		
		myStack.pop();
		assertTrue(myStack.top.value == 1);
		assertTrue(myStack.min() == 1);
		
		myStack.push(0);
		assertTrue(myStack.top.value == 0);
		assertTrue(myStack.min() == 0);
		
		myStack.pop();
		myStack.pop();
		assertTrue(myStack.isEmpty());
		myStack.pop();
	}
}
