package Chapter2;

import static org.junit.Assert.*;
import org.junit.Test;

public class TestLinkedListRemoveDuplicates {

	@Test(expected=NullPointerException.class)
	public void emptyTest(){
		LinkedList<Integer> list = new LinkedList<Integer>();
		LinkedListRemoveDuplicates rd = new LinkedListRemoveDuplicates(list);
		rd.remove();
	}
	
	@Test
	public void removeIntegerTest(){
		LinkedList<Integer> dupList = new LinkedList<Integer>();
		dupList.append(1);
		dupList.append(2);
		dupList.append(3);
		dupList.append(4);
		dupList.append(4);
		dupList.append(5);
		dupList.append(6);
		
		LinkedListRemoveDuplicates rd = new LinkedListRemoveDuplicates(dupList);
		LinkedList<Integer> nonDupList = rd.remove();
		assertEquals(new Integer(1),nonDupList.dequeue());
		assertEquals(new Integer(2),nonDupList.dequeue());
		assertEquals(new Integer(3),nonDupList.dequeue());
		assertEquals(new Integer(4),nonDupList.dequeue());
		assertEquals(new Integer(5),nonDupList.dequeue());
		assertEquals(new Integer(6),nonDupList.dequeue());
	}
	
	@Test
	public void removestringTest(){
		LinkedList<String> dupList = new LinkedList<String>();
		dupList.append("1");
		dupList.append("2");
		dupList.append("3");
		dupList.append("4");
		dupList.append("4");
		dupList.append("5");
		dupList.append("6");
		
		LinkedListRemoveDuplicates rd = new LinkedListRemoveDuplicates(dupList);
		LinkedList<String> nonDupList = rd.remove();
		assertEquals("1",nonDupList.dequeue());
		assertEquals("2",nonDupList.dequeue());
		assertEquals("3",nonDupList.dequeue());
		assertEquals("4",nonDupList.dequeue());
		assertEquals("5",nonDupList.dequeue());
		assertEquals("6",nonDupList.dequeue());
	}

	
}
