package Chapter2;

import org.junit.Test;

public class TestMySet {

	
	@Test
	public void testEmptyList() {
		MySet myList = new MySet();
		LinkedList<Integer> list = new LinkedList<Integer>();
		myList.populateMySet(list);
	}
	
	@Test
	public void testPopulate() {
		MySet mySet = new MySet();
		LinkedList<Integer> list = new LinkedList<Integer>(new Integer(5));
		list.peek();
		mySet.populateMySet(list);
	}
	
}
