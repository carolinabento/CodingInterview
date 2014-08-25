package Chapter4;

import static org.junit.Assert.*;

import org.junit.*;


public class TestArrayToTree {

	@Test(expected = NullPointerException.class)
	public void testNull(){
		int[] array = null;
		
		ArrayToTree att = new ArrayToTree();
		
		att.arrayToTree(array);
	}
	
	@Test
	public void testArrayToTree(){
		int[] array = {1,2,3,4,5};
		
		ArrayToTree att = new ArrayToTree();
		
		TreeNode root = att.arrayToTree(array);
		
		TreeNode result = new TreeNode(1);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node4 = new TreeNode(4);
		TreeNode node5 = new TreeNode(5);
		
		result.left = node2;
		result.right = node3;
		
		result.left.left = node4;
		result.left.right = node5;
		
		
		assertTrue(root.value == result.value);
		assertTrue(root.left.value == result.left.value);
		assertTrue(root.right.value == result.right.value);
	
		assertTrue(root.left.left.value == result.left.left.value);
		assertTrue(root.left.right.value == result.left.right.value);	
	}
	
	@Test
	public void testArrayToTreeI(){
		int[] array = {1,2,3,4,5,6,7,8};
		
		ArrayToTree att = new ArrayToTree();
		
		TreeNode root = att.arrayToTree(array);
		
		TreeNode result = new TreeNode(1);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node4 = new TreeNode(4);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		TreeNode node7 = new TreeNode(7);
		TreeNode node8 = new TreeNode(8);
		
		result.left = node2;
		result.right = node3;
		
		result.left.left = node4;
		result.left.right = node5;
		
		result.left.left.left = node8;
		
		result.right.left = node6;
		result.right.right = node7;
		
		
		assertTrue(root.value == result.value);
		assertTrue(root.left.value == result.left.value);
		assertTrue(root.right.value == result.right.value);
	
		assertTrue(root.left.left.value == result.left.left.value);
		assertTrue(root.left.right.value == result.left.right.value);	
		
		assertTrue(root.right.left.value == result.right.left.value);
		assertTrue(root.right.right.value == result.right.right.value);
		
		assertTrue(root.left.left.left.value == result.left.left.left.value);
	}
	
	@Test
	public void testArrayToTreeII(){
		int[] array = {1,2,3,4,5,6,7,8,9,10};
		
		ArrayToTree att = new ArrayToTree();
		
		TreeNode root = att.arrayToTree(array);
		
		TreeNode result = new TreeNode(1);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node4 = new TreeNode(4);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		TreeNode node7 = new TreeNode(7);
		TreeNode node8 = new TreeNode(8);
		TreeNode node9 = new TreeNode(9);
		TreeNode node10 = new TreeNode(10);
		
		result.left = node2;
		result.right = node3;
		
		result.left.left = node4;
		result.left.right = node5;
		
		result.left.left.left = node8;
		result.left.left.right = node9;
		
		result.left.right.left = node10;
		
		result.right.left = node6;
		result.right.right = node7;
		
		
		assertTrue(root.value == result.value);
		assertTrue(root.left.value == result.left.value);
		assertTrue(root.right.value == result.right.value);
	
		assertTrue(root.left.left.value == result.left.left.value);
		assertTrue(root.left.right.value == result.left.right.value);	
		
		assertTrue(root.right.left.value == result.right.left.value);
		assertTrue(root.right.right.value == result.right.right.value);
		
		assertTrue(root.left.left.left.value == result.left.left.left.value);
		assertTrue(root.left.left.right.value == result.left.left.right.value);
		
		assertTrue(root.left.right.left.value == result.left.right.left.value);
	}
}
