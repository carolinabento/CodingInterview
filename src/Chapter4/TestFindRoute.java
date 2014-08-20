package Chapter4;

import static org.junit.Assert.*;

import org.junit.*;

public class TestFindRoute {

	@Test(expected = NullPointerException.class)
	public void testNull(){
		TreeNode root = new TreeNode(1);
		
		assertTrue(root.left == null && root.right == null);
		
		FindRoutes fr = new FindRoutes(root);
		
		fr.haveRoute(root.left, root.right);
	}
	
	@Test
	public void findRoutes(){
		TreeNode root = new TreeNode(1);
		
		TreeNode node0 = new TreeNode(0);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		
		
		root.left = node0;
		root.right = node2;
		root.right.right = node3;
		root.right.right.right = node6;
		root.right.right.right.left = node5;
		
		
		FindRoutes fr = new FindRoutes(root);
		
		//route 2->6
		assertTrue(fr.haveRoute(root.right, root.right.right.right));
	}
	
	@Test
	public void findRoutesI(){
		TreeNode root = new TreeNode(1);
		
		TreeNode node0 = new TreeNode(0);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		
		
		root.left = node0;
		root.right = node2;
		root.right.right = node3;
		root.right.right.right = node6;
		root.right.right.right.left = node5;
		
		
		FindRoutes fr = new FindRoutes(root);
		
		//route 0->6
		assertFalse(fr.haveRoute(root.left, root.right.right.right));
	}
	
	@Test
	public void findRoutesII(){
		TreeNode root = new TreeNode(1);
		
		TreeNode node0 = new TreeNode(0);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		
		
		root.left = node0;
		root.right = node2;
		root.right.right = node3;
		root.right.right.right = node6;
		root.right.right.right.left = node5;
		
		
		FindRoutes fr = new FindRoutes(root);
		
		//route 1->2
		assertTrue(fr.haveRoute(root, root.right));
	}
	
	
	@Test
	public void findRoutesIII(){
		TreeNode root = new TreeNode(1);
		
		TreeNode node0 = new TreeNode(0);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		
		
		root.left = node0;
		root.right = node2;
		root.right.right = node3;
		root.right.right.right = node6;
		root.right.right.right.left = node5;
		
		
		FindRoutes fr = new FindRoutes(root);
		
		//route 1->3
		assertTrue(fr.haveRoute(root, root.right.right));
	}
	
	@Test
	public void findRoutesIV(){
		TreeNode root = new TreeNode(1);
		
		TreeNode node0 = new TreeNode(0);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		
		root.left = node0;
		root.right = node2;
		root.right.right = node3;
		root.right.right.right = node6;
		root.right.right.right.left = node5;
		
		
		FindRoutes fr = new FindRoutes(root);
		
		//route 3->1
		assertFalse(fr.haveRoute(root.right.right,root));
	}
}
