package Chapter1;
import static org.junit.Assert.assertEquals;

import org.junit.Test;


public class DoubleLinkedListTest {

	@Test(expected = NullPointerException.class)
	public void testEmptyList() {
		DoubleLinkedList<String> myList = new DoubleLinkedList<String>();
		myList.peek();
	}
	
	@Test
	public void testSize() {
		DoubleLinkedList<String> myList = new DoubleLinkedList<String>();

		assertEquals(myList.size(), 0);
		
		myList.append("5");
		assertEquals(myList.size(), 1);
	}
	
	@Test
	public void testAppend(){
		DoubleLinkedList<String> myList = new DoubleLinkedList<String>();

		myList.append("5");
		assertEquals(myList.peek(), "5");
		assertEquals(myList.peekTail(), "5");
		
		myList.append("15");
		
		assertEquals(myList.peek(), "5");
		assertEquals(myList.peekTail(), "15");
	}
	
	@Test(expected = NullPointerException.class)
	public void testClear(){
		DoubleLinkedList<String> myList = new DoubleLinkedList<String>();
		
		myList.append("1");
		myList.append("2");
		myList.append("3");
		
		assertEquals(myList.peek(), "1");
		assertEquals(myList.peekTail(), "3");
		
		myList.clear();
		
		myList.peek();
		
	}

	@Test(expected = NullPointerException.class)
	public void testRemoveEmpty(){
		DoubleLinkedList<String> myList = new DoubleLinkedList<String>();
		myList.removeHead();
	}
	
	@Test
	public void testRemove(){
		DoubleLinkedList<String> myList = new DoubleLinkedList<String>();
		
		myList.append("1");
		myList.append("2");
		myList.append("3");
		
		assertEquals(myList.peek(), "1");
		assertEquals(myList.peekTail(), "3");
		
		myList.removeHead();
		
		assertEquals(myList.peek(), "2");
		assertEquals(myList.peekTail(), "3");
		
		myList.removeTail();
		
		assertEquals(myList.peek(), "2");
		assertEquals(myList.peekTail(), "2");
	}
}
