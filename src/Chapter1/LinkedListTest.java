package Chapter1;
import static org.junit.Assert.*;

import org.junit.Test;


public class LinkedListTest {

	@Test(expected = NullPointerException.class)
	public void testEmptyList() {
		LinkedList<String> myList = new LinkedList<String>();
		myList.peek();
	}

	@Test
	public void testAppend(){
		LinkedList<String>  myList = new LinkedList<String> ();

		myList.append("5");
		assertEquals(myList.peek(), "5");
	}


	@Test(expected = NullPointerException.class)
	public void testDequeueEmpty(){
		LinkedList<String> myList = new LinkedList<String> ();
		myList.dequeue();
	}

	@Test
	public void testDequeue(){
		LinkedList<Integer>  myList = new LinkedList<Integer> ();
		myList.append(5);

		assertEquals(myList.dequeue(),new Integer(5));
	}

	@Test
	public void testDoubleDequeue(){
		LinkedList<Integer> myList = new LinkedList<Integer>();
		myList.append(1);
		myList.append(2);

		assertEquals(myList.dequeue(),new Integer(1));
		assertEquals(myList.dequeue(),new Integer(2));
	}
}