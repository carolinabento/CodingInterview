package Chapter2;

import static org.junit.Assert.*;

import org.junit.*;

public class TestDeleteNodeLinkedList {


	@Test(expected = NullPointerException.class)
	public void emptyTest(){
		Node<Integer> node = new Node<Integer>();
		LinkedList<Integer> myList = new LinkedList<Integer>();
		DeleteNodeLinkedList<Integer> dn = new DeleteNodeLinkedList<Integer>(myList,node);
		dn.deleteNode();
	}

	@Test
	public void deleteTailTest(){

		Node<Integer> node1 = new Node<Integer>(new Integer(1));
		Node<Integer> node2 = new Node<Integer>(new Integer(2));
		Node<Integer> node3 = new Node<Integer>(new Integer(3));
		LinkedList<Integer> myList = new LinkedList<Integer>(node1);
		myList.append(node2.value);
		myList.append(node3.value);				
		
		Node<Integer> node = myList.getHead().next.next;

		DeleteNodeLinkedList<Integer> dn = new DeleteNodeLinkedList<Integer>(myList,node);
		dn.deleteNode();	

		assertTrue(myList.getHead().value == node1.value);
		assertTrue(myList.getHead().next.value == node2.value);
		assertTrue(myList.getTail().value == node3.value);
	}

	@Test
	public void deleteMiddleTest(){
		Node<Integer> node1 = new Node<Integer>(new Integer(1));
		Node<Integer> node2 = new Node<Integer>(new Integer(2));
		Node<Integer> node3 = new Node<Integer>(new Integer(3));
		Node<Integer> node4 = new Node<Integer>(new Integer(4));
		Node<Integer> node5 = new Node<Integer>(new Integer(5));
		Node<Integer> node6 = new Node<Integer>(new Integer(6));
		Node<Integer> node7 = new Node<Integer>(new Integer(7));
		Node<Integer> node8 = new Node<Integer>(new Integer(8));
		Node<Integer> node9 = new Node<Integer>(new Integer(9));
		Node<Integer> node10 = new Node<Integer>(new Integer(10));
		
		LinkedList<Integer> myList = new LinkedList<Integer>(node1);

		myList.append(node2.value);
		myList.append(node3.value);
		myList.append(node4.value);
		myList.append(node5.value);
		myList.append(node6.value);
		myList.append(node7.value);
		myList.append(node8.value);
		myList.append(node9.value);
		myList.append(node10.value);
		
		Node<Integer> node = myList.getHead().next.next;
		
		DeleteNodeLinkedList<Integer> dn = new DeleteNodeLinkedList<Integer>(myList,node);
		dn.deleteNode();

		
		assertTrue(myList.getHead().value == node1.value);
		assertTrue(myList.getHead().next.value == node2.value);
		assertTrue(myList.getHead().next.next.value == node4.value);
		assertTrue(myList.getHead().next.next.next.value == node5.value);
		assertTrue(myList.getHead().next.next.next.next.value == node6.value);
		assertTrue(myList.getHead().next.next.next.next.next.value == node7.value);
		assertTrue(myList.getHead().next.next.next.next.next.next.value == node8.value);
		assertTrue(myList.getHead().next.next.next.next.next.next.next.value == node9.value);
		assertTrue(myList.getTail().value == node10.value);
	}
}
