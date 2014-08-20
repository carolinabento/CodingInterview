package Chapter4;

public class IsBalancedTree {

	public TreeNode root;
	
	public IsBalancedTree(TreeNode root){
		this.root = root;
	}
	
	public int recursiveBalanced(TreeNode node, int dist){
		if(node == null || (node.left == null && node.right == null)){
			return dist;
		}else{
			if(node.left != null && node.right == null){
				dist += 1 + recursiveBalanced(node.left, dist+1);
				return dist;
			}else{
				if(node.left == null && node.right !=null){
					dist += 1 + recursiveBalanced(node.right, dist+1);
				}else{
					dist += Math.abs(2 + recursiveBalanced(node.left, dist+1) - recursiveBalanced(node.right, dist++));
				}
			}
		}
		return dist;
	}
	
	
	public boolean isBalanced(){
		if(this.root == null){
			throw new NullPointerException();
		}else{
			return Math.abs(recursiveBalanced(this.root.left,0) - recursiveBalanced(this.root.right,0)) <= 1;
		}
	}
}
