package Chapter2;

import org.junit.Test;

public class TestDeleteNodeLinkedList {


	@Test(expected = NullPointerException.class)
	public void emptyTest(){
		Node<Integer> node = new Node<Integer>();
		DeleteNodeLinkedList<Integer> dn = new DeleteNodeLinkedList<Integer>(node);
		dn.deleteNode();
	}

	@Test
	public void deleteTailTest(){

		LinkedList<Integer> myList = new LinkedList<Integer>(new Integer(1));
		myList.append(new Integer(2));
		myList.append(new Integer(3));				

		Node<Integer> node = myList.getHead().next.next;

		DeleteNodeLinkedList<Integer> dn = new DeleteNodeLinkedList<Integer>(node);
		dn.deleteNode();		
	}

	@Test
	public void deleteMiddleTest(){
		LinkedList<Integer> myList = new LinkedList<Integer>(new Integer(1));

		myList.append(new Integer(2));
		myList.append(new Integer(3));
		myList.append(new Integer(4));
		myList.append(new Integer(5));
		myList.append(new Integer(6));
		myList.append(new Integer(7));
		myList.append(new Integer(8));
		myList.append(new Integer(9));
		myList.append(new Integer(10));

		myList.prettyPrint();

		Node<Integer> node = myList.getHead().next.next;
		
		DeleteNodeLinkedList<Integer> dn = new DeleteNodeLinkedList<Integer>(node);
		dn.deleteNode();

		myList.prettyPrint();
	}
}
