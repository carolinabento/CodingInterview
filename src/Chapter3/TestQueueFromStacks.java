package Chapter3;

import static org.junit.Assert.*;

import org.junit.*;

public class TestQueueFromStacks {

	@Test
	public void testEmpty(){
		QueueFromStacks qfs = new QueueFromStacks();

		assertTrue(qfs.isEmpty());
		assertTrue(qfs.s1.size() == 0 && qfs.s2.size() == 0);
	}
	
	@Test(expected = NullPointerException.class)
	public void testBadRemove(){
		QueueFromStacks qfs = new QueueFromStacks();

		assertTrue(qfs.isEmpty());
		assertTrue(qfs.s1.size() == 0 && qfs.s2.size() == 0);
		
		qfs.remove();
	}
	
	@Test
	public void testAppend(){
		QueueFromStacks qfs = new QueueFromStacks();

		qfs.append(1);
		qfs.append(2);
		
		assertTrue(qfs.peek() == 1);
	}
	
	@Test
	public void testRemove(){
		QueueFromStacks qfs = new QueueFromStacks();

		qfs.append(1);
		qfs.append(2);
		
		assertTrue(qfs.peek() == 1);
		
		qfs.append(3);
		assertTrue(qfs.remove() == 1);
		assertTrue(qfs.peek() == 2);
		
		assertTrue(qfs.remove() == 2);
		assertTrue(qfs.peek() == 3);
		
		assertTrue(qfs.remove() == 3);
		assertTrue(qfs.isEmpty());
	}
	
}
