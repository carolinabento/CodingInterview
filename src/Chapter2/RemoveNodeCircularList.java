package Chapter2;

import sun.security.util.Length;


public class RemoveNodeCircularList<T> {
	private Object[] checkedElements;	
	private int size;

	public RemoveNodeCircularList(LinkedList<T> list, int length){
		this.checkedElements = new Object[length];		
		this.size = length;
	}

	public boolean alreadyChecked(Node<T> node){
		int i = 0;
		boolean res = false;

		while(i < this.size){
			if((Node<T>) checkedElements[i] == node){
				res = true;
				break;
			}else{
				i++;
			}
		}
		return res;
	}


	public Node<T> removeCircularNode(LinkedList<T> list){
		int index = 0;
		Node<T> result = new Node<T>();		
		boolean found = false;
		
		if(list.isEmpty()){
			throw new NullPointerException();
		}

		if(list.size() > 1){
			Node<T> currentNode = list.getHead();
			while(index < list.size()){
				if(!alreadyChecked(currentNode)){
					checkedElements[index] = currentNode;
					index++;
					currentNode = currentNode.next;	
				}else{
					result = (Node<T>) checkedElements[index];
					found = true;
					break;
				}
				
			}
			
			if(!found && alreadyChecked(currentNode)){
				result = (Node<T>) checkedElements[index-1];
			}
		}
		
		return result;
	}
	
}
