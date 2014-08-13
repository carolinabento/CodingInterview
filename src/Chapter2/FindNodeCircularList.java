package Chapter2;

public class FindNodeCircularList<T> {
	private Object[] checkedElements;	
	private int size;

	public FindNodeCircularList(LinkedList<T> list){
		this.size = list.size();
		this.checkedElements = new Object[this.size];		
	}

	public int alreadyChecked(Node<T> node){
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
		if(res){
			return i;
		}else{
			return -1;
		}
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
			while(index < this.size){
				if(alreadyChecked(currentNode) == -1){
					checkedElements[index] = currentNode;
					index++;
					currentNode = currentNode.next;	
				}else{
					result = (Node<T>) checkedElements[index];
					found = true;
					break;
				}
				
			}
			
			int checkedValue = alreadyChecked(currentNode);
			if(!found && checkedValue != -1){
				result = (Node<T>) checkedElements[checkedValue];
			}
		}
		
		return result;
	}
	
}
