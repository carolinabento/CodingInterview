package Chapter4;

public class ArrayToTree {

	public ArrayToTree(){}


	public TreeNode recursiveFunction(TreeNode node, int[] array, int pos, int length, int height){
		if(pos < length && height > 0){
			node = new TreeNode(array[pos]);
			node.left = recursiveFunction(node.left,array,(pos*2)+1,length, height--);
			node.right = recursiveFunction(node.right,array,(pos*2)+2,length,height--);
		}
		return node;
	}

	public TreeNode arrayToTree(int[] array){
		if(array == null){
			throw new NullPointerException();
		}else{
			TreeNode root = new TreeNode(array[0]);
			int length = array.length;

			if(length > 1){
				TreeNode current = root;
				int height = (int) Math.ceil(length/2.0);
				root.left = recursiveFunction(current.left,array,1,length, height);
				root.right = recursiveFunction(current.right,array,2,length,height);
			}
			return root;
		}
	}
}
