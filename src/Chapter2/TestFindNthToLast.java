package Chapter2;

import static org.junit.Assert.*;

import org.junit.*;

public class TestFindNthToLast {

	@Test(expected = NullPointerException.class)
	public void emptyTest(){
		LinkedList<Integer> list = new LinkedList<Integer>();
		FindNthToLast<Integer> fnthl = new FindNthToLast<Integer>();
		
		fnthl.find(list, 2);
	}
	
	@Test
	public void testNthToLast(){
		LinkedList<Integer> list = new LinkedList<Integer>();
		FindNthToLast<Integer> fnthl = new FindNthToLast<Integer>();
		
		Node<Integer> node1 = new Node<Integer>(new Integer(1));
		Node<Integer> node2 = new Node<Integer>(new Integer(2));
		Node<Integer> node3 = new Node<Integer>(new Integer(3));
		Node<Integer> node4 = new Node<Integer>(new Integer(4));
		Node<Integer> node5 = new Node<Integer>(new Integer(5));
		
		list.append(node1.value);
		list.append(node2.value);
		list.append(node3.value);
		list.append(node4.value);
		list.append(node5.value);
		
		assertTrue(list.getHead().value == node1.value);
		assertTrue(list.getHead().next.value == node2.value);
		assertTrue(list.getHead().next.next.value == node3.value);
		assertTrue(list.getHead().next.next.next.value == node4.value);
		assertTrue(list.getHead().next.next.next.next.value == node5.value);
		
		assertTrue(fnthl.find(list, 2).value == node3.value);
	}
	
	@Test
	public void testNthToLastI(){
		LinkedList<Integer> list = new LinkedList<Integer>();
		FindNthToLast<Integer> fnthl = new FindNthToLast<Integer>();
		
		Node<Integer> node1 = new Node<Integer>(new Integer(1));
		Node<Integer> node2 = new Node<Integer>(new Integer(2));
		Node<Integer> node3 = new Node<Integer>(new Integer(3));
		Node<Integer> node4 = new Node<Integer>(new Integer(4));
		Node<Integer> node5 = new Node<Integer>(new Integer(5));
		
		list.append(node1.value);
		list.append(node2.value);
		list.append(node3.value);
		list.append(node4.value);
		list.append(node5.value);
		
		assertTrue(list.getHead().value == node1.value);
		assertTrue(list.getHead().next.value == node2.value);
		assertTrue(list.getHead().next.next.value == node3.value);
		assertTrue(list.getHead().next.next.next.value == node4.value);
		assertTrue(list.getHead().next.next.next.next.value == node5.value);
		
		assertTrue(fnthl.find(list, 5).value == node1.value);
	}
	
	@Test
	public void testNthToLastII(){
		LinkedList<Integer> list = new LinkedList<Integer>();
		FindNthToLast<Integer> fnthl = new FindNthToLast<Integer>();
		
		Node<Integer> node1 = new Node<Integer>(new Integer(1));
		Node<Integer> node2 = new Node<Integer>(new Integer(2));
		Node<Integer> node3 = new Node<Integer>(new Integer(3));
		Node<Integer> node4 = new Node<Integer>(new Integer(4));
		Node<Integer> node5 = new Node<Integer>(new Integer(5));
		
		list.append(node1.value);
		list.append(node2.value);
		list.append(node3.value);
		list.append(node4.value);
		list.append(node5.value);
		
		assertTrue(list.getHead().value == node1.value);
		assertTrue(list.getHead().next.value == node2.value);
		assertTrue(list.getHead().next.next.value == node3.value);
		assertTrue(list.getHead().next.next.next.value == node4.value);
		assertTrue(list.getHead().next.next.next.next.value == node5.value);
		
		assertTrue(fnthl.find(list, 0).value == node5.value);
	}
}
