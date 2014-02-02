package Chapter3;

import static org.junit.Assert.assertTrue;
import org.junit.Test;

public class TestExtendedStack {

	
	@Test
	public void emptyStackTest(){
		ExtendedStack es = new ExtendedStack();
		
		assertTrue(es.isEmpty()== true);
	}
	
	@Test
	public void pushTest(){
		ExtendedStack es = new ExtendedStack();
		es.push(new Integer(1));
		assertTrue(es.isEmpty() == false);		
	}
	
	@Test
	public void popTest(){
		ExtendedStack es = new ExtendedStack();
		es.push(new Integer(1));
		es.push(new Integer(2));
		es.push(new Integer(3));
		es.push(new Integer(4));
		assertTrue(es.isEmpty() == false);
		int res = es.pop();
		assertTrue(res == new Integer(4));
		res = es.pop();
		assertTrue(res == new Integer(3));
		res = es.pop();
		assertTrue(res == new Integer(2));
		res = es.pop();
		assertTrue(res == new Integer(1));
		assertTrue(es.isEmpty() == true);
	}
	
	@Test(expected = UnsupportedOperationException.class)
	public void popTestI(){
		ExtendedStack es = new ExtendedStack();
		es.push(new Integer(1));
		int res = es.pop();
		assertTrue(res == new Integer(1));
		res = es.pop();
	}
	
	@Test
	public void minTest(){
		ExtendedStack es = new ExtendedStack();
		es.push(new Integer(5));
		es.push(new Integer(6));
		es.push(new Integer(3));
		es.push(new Integer(7));
		es.push(new Integer(2));
		es.push(new Integer(4));
		es.push(new Integer(0));
		
		assertTrue(es.isEmpty() == false);
		assertTrue(es.getMin() == new Integer(0));
		int res = es.pop();
		assertTrue(res == new Integer(0));
		assertTrue(es.getMin() == new Integer(2));
	}
	
	@Test
	public void minTestI(){
		ExtendedStack es = new ExtendedStack();
		es.push(new Integer(3));
		es.push(new Integer(2));
		assertTrue(es.isEmpty() == false);
		assertTrue(es.getMin() == new Integer(2));
		int res = es.pop();
		assertTrue(res == new Integer(2));
		assertTrue(es.getMin() == new Integer(3));
	}
	
	@Test
	public void minTestII(){
		ExtendedStack es = new ExtendedStack();
		es.push(new Integer(4));
		assertTrue(es.isEmpty() == false);
		assertTrue(es.getMin() == new Integer(4));
		int res = es.pop();
		assertTrue(res == new Integer(4));
		assertTrue(es.getMin() == new Integer(4));
	}
}
