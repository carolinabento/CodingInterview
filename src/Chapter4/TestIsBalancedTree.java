package Chapter4;

import static org.junit.Assert.*;
import org.junit.*;

public class TestIsBalancedTree {

	
	@Test(expected = NullPointerException.class)
	public void testNull(){
		TreeNode root = new TreeNode(1);
		
		assertTrue(root.left == null && root.right == null);
		
		IsBalancedTree ibs = new IsBalancedTree(root.left);
		ibs.isBalanced();
	}
	
	
	@Test
	public void testBalanced(){
		TreeNode root = new TreeNode(2);
		
		TreeNode node1 = new TreeNode(1);
		TreeNode node2 = new TreeNode(3);
		
		root.left = node1;
		root.right = node2;
		
		IsBalancedTree ibs = new IsBalancedTree(root);
		assertTrue(ibs.isBalanced());
	}
	
	@Test
	public void testBalancedI(){
		TreeNode root = new TreeNode(2);
		
		TreeNode node1 = new TreeNode(1);
		
		root.left = node1;
		
		IsBalancedTree ibs = new IsBalancedTree(root);
		assertTrue(ibs.isBalanced());
	}
	
	@Test
	public void testBalancedII(){
		TreeNode root = new TreeNode(8);
		
		TreeNode node5 = new TreeNode(5);
		TreeNode node10 = new TreeNode(10);
		TreeNode node4 = new TreeNode(4);
		TreeNode node6 = new TreeNode(6);
		TreeNode node9 = new TreeNode(9);
		TreeNode node11 = new TreeNode(11);
		TreeNode node3 = new TreeNode(3);
		TreeNode node12 = new TreeNode(12);
		
		root.left = node5;
		root.right = node10;
		
		root.left.left = node4;
		root.left.right = node6;
		
		root.right.left = node9;
		root.right.right = node11;
		
		root.left.left.left = node3;
		root.right.right.right = node12;
		
		IsBalancedTree ibs = new IsBalancedTree(root);
		assertFalse(ibs.isBalanced());
	}

	@Test
	public void testUnBalanced(){
		TreeNode root = new TreeNode(2);
		
		TreeNode node1 = new TreeNode(1);
		TreeNode node0 = new TreeNode(0);
		
		
		root.left = node1;
		root.left.left = node0;
		
		IsBalancedTree ibs = new IsBalancedTree(root);
		assertFalse(ibs.isBalanced());
	}
	
	@Test
	public void testUnBalancedI(){
		TreeNode root = new TreeNode(7);
		
		TreeNode node3 = new TreeNode(3);
		TreeNode node4 = new TreeNode(4);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		TreeNode node8 = new TreeNode(8);
		
		
		root.left = node5;
		root.right = node8;
		
		root.left.left = node4;
		root.left.right = node6;
		
		root.left.left.left = node3;
		
		IsBalancedTree ibs = new IsBalancedTree(root);
		assertFalse(ibs.isBalanced());
	}

}
