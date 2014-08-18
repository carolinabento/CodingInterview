package Chapter3;

import static org.junit.Assert.assertTrue;
import org.junit.Test;

public class TestSortStack {

	@Test
	public void testSort(){
		Stack s = new Stack(3);
		
		s.push(5);
		s.push(2);
		s.push(8);
		s.push(1);
		s.push(7);
		
		SortStack ss = new SortStack(s);
		
		Stack sortedStack = ss.sortStackAsc();
		
		assertTrue(sortedStack.top.value == 1);
		assertTrue(sortedStack.top.prev.value == 2);
		assertTrue(sortedStack.top.prev.prev.value == 3);
		assertTrue(sortedStack.top.prev.prev.prev.value == 5);
		assertTrue(sortedStack.top.prev.prev.prev.prev.value == 7);
		assertTrue(sortedStack.top.prev.prev.prev.prev.prev.value == 8);
	}
	
	
	@Test
	public void testSortI(){
		Stack s = new Stack(3);
		
		s.push(5);
		s.push(2);
		s.push(8);
		s.push(1);
		s.push(7);
		s.push(7);
		
		SortStack ss = new SortStack(s);
		
		Stack sortedStack = ss.sortStackAsc();
		
		assertTrue(sortedStack.top.value == 1);
		assertTrue(sortedStack.top.prev.value == 2);
		assertTrue(sortedStack.top.prev.prev.value == 3);
		assertTrue(sortedStack.top.prev.prev.prev.value == 5);
		assertTrue(sortedStack.top.prev.prev.prev.prev.value == 7);
		assertTrue(sortedStack.top.prev.prev.prev.prev.prev.value == 7);
		assertTrue(sortedStack.top.prev.prev.prev.prev.prev.prev.value == 8);
	}
	
	@Test
	public void testSortII(){
		Stack s = new Stack(7);
		
		s.push(6);
		s.push(5);
		s.push(4);
		s.push(3);
		s.push(2);
		s.push(1);
		
		SortStack ss = new SortStack(s);
		
		Stack sortedStack = ss.sortStackAsc();
		
		assertTrue(sortedStack.top.value == 1);
		assertTrue(sortedStack.top.prev.value == 2);
		assertTrue(sortedStack.top.prev.prev.value == 3);
		assertTrue(sortedStack.top.prev.prev.prev.value == 4);
		assertTrue(sortedStack.top.prev.prev.prev.prev.value == 5);
		assertTrue(sortedStack.top.prev.prev.prev.prev.prev.value == 6);
		assertTrue(sortedStack.top.prev.prev.prev.prev.prev.prev.value == 7);
	}
	
	@Test
	public void testSortIII(){
		Stack s = new Stack(1);
		
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(5);
		s.push(6);
		s.push(6);
		
		SortStack ss = new SortStack(s);
		
		Stack sortedStack = ss.sortStackAsc();
		
		assertTrue(sortedStack.top.value == 1);
		assertTrue(sortedStack.top.prev.value == 2);
		assertTrue(sortedStack.top.prev.prev.value == 3);
		assertTrue(sortedStack.top.prev.prev.prev.value == 4);
		assertTrue(sortedStack.top.prev.prev.prev.prev.value == 5);
		assertTrue(sortedStack.top.prev.prev.prev.prev.prev.value == 6);
		assertTrue(sortedStack.top.prev.prev.prev.prev.prev.prev.value == 6);
	}
}
