package Chapter2;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Ignore;
import org.junit.Test;

public class TestRemoveNodeCircularList {

	@Test(expected = NullPointerException.class)
	public void emptyTest(){
		LinkedList<Integer> myList = new LinkedList<Integer>();
		RemoveNodeCircularList<Integer> remCircN = new RemoveNodeCircularList<Integer>(myList,myList.size());
		remCircN.removeCircularNode(myList);
	}

	@Test
	public void noRemoveTest(){
		LinkedList<Integer> myList = new LinkedList<Integer>(new Integer(1));
		Node<Integer> node = new Node<Integer>();
		myList.append(new Integer (2));		

		RemoveNodeCircularList<Integer> remCircN = new RemoveNodeCircularList<Integer>(myList,myList.size());
		assertTrue(node.value == remCircN.removeCircularNode(myList).value);
	}

	@Test
	public void removeEndTest(){
		LinkedList<Integer> myList = new LinkedList<Integer>(new Integer(1));

		myList.append(new Integer (2));
		myList.getHead().next.next = myList.getHead();
		
		RemoveNodeCircularList<Integer> remCircN = new RemoveNodeCircularList<Integer>(myList,myList.size());
		assertTrue(remCircN.removeCircularNode(myList).value == 2);
	}
	
}
