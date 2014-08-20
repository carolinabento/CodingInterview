package Chapter4;

public class FindRoutes {

	TreeNode root;
	
	public FindRoutes(TreeNode root){
		this.root = root;
	}
	
	public boolean recursiveRoute(TreeNode node, TreeNode node1, TreeNode node2, boolean found1, boolean found2){
		if(node == null || (node.left == null && node.right == null) && !(found1 || found2)){
			return false;
		}else{
			if(found1 && node == node2){
				return true;
			}else{
				if(node == node1 && !found2){
					return recursiveRoute(node.left,node1,node2,true,found2) || recursiveRoute(node.right,node1,node2,true,found2);
				}else{
					return recursiveRoute(node.left,node1,node2,found1,found2) || recursiveRoute(node.right,node1,node2,found1,found2);
				}
			}
		}
	}
	
	public boolean haveRoute(TreeNode node1, TreeNode node2){
		boolean found1 = false;
		boolean found2 = false;
		
		if(node1 == null && node2 == null){
			throw new NullPointerException();
		}else{
			if((node1 == null && node2 != null) || (node1 != null && node2 == null)){
				return false;
			}else{
				if(node1.left == node2 || node1.right == node2 || node2.left == node1 || node2.right == node1){
					return true;
				}else{
					
					if(node1 == this.root) found1 = true;
					if(node2 == this.root) found2 = true;
					
					return recursiveRoute(this.root.left,node1,node2,found1,found2) || recursiveRoute(this.root.right,node1,node2,found1,found2); 
				}
			}
		}
	}
	
}
