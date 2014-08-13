package Chapter2;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Ignore;
import org.junit.Test;

public class TestFindNodeCircularList {

	@Test(expected = NullPointerException.class)
	public void emptyTest(){
		LinkedList<Integer> myList = new LinkedList<Integer>();
		FindNodeCircularList<Integer> remCircN = new FindNodeCircularList<Integer>(myList);
		remCircN.removeCircularNode(myList);
	}

	@Test
	public void noRemoveTest(){
		LinkedList<Integer> myList = new LinkedList<Integer>(new Integer(1));
		Node<Integer> node = new Node<Integer>();
		myList.append(new Integer (2));		

		FindNodeCircularList<Integer> remCircN = new FindNodeCircularList<Integer>(myList);
		assertTrue(node.value == remCircN.removeCircularNode(myList).value);
	}
	
	@Test
	public void removeEndTest(){
		LinkedList<Integer> myList = new LinkedList<Integer>(new Integer(1));

		myList.append(new Integer (2));
		myList.getHead().next.next = myList.getHead();
		
		FindNodeCircularList<Integer> remCircN = new FindNodeCircularList<Integer>(myList);
		assertTrue(remCircN.removeCircularNode(myList).value == 1);
	}
	
	@Test
	public void removeTestI(){
		LinkedList<Integer> myList = new LinkedList<Integer>(new Integer(1));

		myList.append(new Integer (2));
		myList.append(new Integer (3));
		myList.append(new Integer (4));
		myList.append(new Integer (5));
		myList.getHead().next.next.next.next.next = myList.getHead().next.next;
		
		
		FindNodeCircularList<Integer> remCircN = new FindNodeCircularList<Integer>(myList);
		
		assertTrue(remCircN.removeCircularNode(myList).value == 3);
	}
	
}
