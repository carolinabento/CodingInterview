package Chapter2;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Ignore;
import org.junit.Test;

public class TestSumTwoNumbersLinkedList {

	@Test(expected=NullPointerException.class)
	public void emptyDoubleTest(){
		LinkedList<Integer> firstList = new LinkedList<Integer>();
		LinkedList<Integer> secondList = new LinkedList<Integer>();
		
		SumTwoNumbersLinkedList sum = new SumTwoNumbersLinkedList(firstList,0,secondList,0);		
		sum.sumNumbersReverseOrder();
	}
	
	@Test
	public void emptyFirstTest(){
		LinkedList<Integer> firstList = new LinkedList<Integer>();
		LinkedList<Integer> secondList = new LinkedList<Integer>(3);
		
		SumTwoNumbersLinkedList sum = new SumTwoNumbersLinkedList(firstList,1, secondList,0);		
		LinkedList<Integer> res = sum.sumNumbersReverseOrder();
				
		assertTrue(res.getHead().value == 3);
		assertTrue(secondList.getHead().value == res.getHead().value);
	}
	
	@Test
	public void emptySecondTest(){
		LinkedList<Integer> firstList = new LinkedList<Integer>(3);
		LinkedList<Integer> secondList = new LinkedList<Integer>();
		
		SumTwoNumbersLinkedList sum = new SumTwoNumbersLinkedList(firstList,0, secondList,1);		
		LinkedList<Integer> res = sum.sumNumbersReverseOrder();
		
		assertTrue(res.getHead().value == 3);
		assertTrue(firstList.getHead().value == res.getHead().value);
	}
	
	@Test
	public void sumTestReverse(){
		LinkedList<Integer> firstList = new LinkedList<Integer>(new Integer(1));
		LinkedList<Integer> secondList = new LinkedList<Integer>(new Integer(1));
		
		SumTwoNumbersLinkedList sum = new SumTwoNumbersLinkedList(firstList,1, secondList,1);
		LinkedList<Integer> res = sum.sumNumbersReverseOrder();
		
		res.prettyPrint();
		assertTrue(res.getHead().value == 2);
		
	}
	
	@Test
	public void sumTestIReverse(){
		LinkedList<Integer> firstList = new LinkedList<Integer>(new Integer(7));
		firstList.append(1);
		firstList.append(6);

		LinkedList<Integer> secondList = new LinkedList<Integer>(new Integer(5));
		secondList.append(9);
		secondList.append(2);
		
		SumTwoNumbersLinkedList sum = new SumTwoNumbersLinkedList(firstList,3, secondList,3);
		LinkedList<Integer> res = sum.sumNumbersReverseOrder();
		
		res.prettyPrint();
		
		assertTrue(res.getHead().value == 2);
		assertTrue(res.getHead().getNext().value == 1);
		assertTrue(res.getHead().getNext().getNext().value == 9);		
	}
	
	
	
	@Test
	public void sumTestIIReverse(){
		LinkedList<Integer> firstList = new LinkedList<Integer>(new Integer(9));
		firstList.append(9);
		firstList.append(9);

		LinkedList<Integer> secondList = new LinkedList<Integer>(new Integer(1));
		secondList.append(0);
		secondList.append(0);

		SumTwoNumbersLinkedList sum = new SumTwoNumbersLinkedList(firstList,3, secondList,3);
		LinkedList<Integer> res = sum.sumNumbersReverseOrder();
		
		res.prettyPrint();
		
		assertTrue(res.getHead().value == 0);
		assertTrue(res.getHead().getNext().value == 0);
		assertTrue(res.getHead().getNext().getNext().value == 0);
		assertTrue(res.getHead().getNext().getNext().getNext().value == 1);
	}

}
