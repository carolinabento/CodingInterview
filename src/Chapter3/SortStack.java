package Chapter3;

public class SortStack {

	public Stack stack;

	public SortStack(Stack s){
		this.stack = s;
	}


	/**
	 * insert a stack node in between two other stack nodes, i.e., insert node in between aux and aux.prev
	 * @param aux the node on top of the one we want to insert
	 * @param node the node we want to insert
	 * @return true, because a node was inserted in order
	 */
	public boolean insertInMidle(StackNode<Integer> aux, StackNode<Integer> node){
		StackNode temp = aux.prev;
		temp.next = node;
		node.prev = temp;
		node.next = aux;
		aux.prev = node;
		return true;
	}
	
	
	/**
	 * Sort the stack in ascending order
	 * @return the sorted stack
	 */
	public Stack sortStackAsc(){
		Stack auxStack = new Stack();

		while(!this.stack.isEmpty()){
		
			if(auxStack.isEmpty()){
				auxStack.push(this.stack.pop());
			}else{
				StackNode<Integer> node = new StackNode(this.stack.pop());
				StackNode<Integer> auxTop = auxStack.top;
				boolean pushed = false;

				if(node.value < auxTop.value){
					auxStack.push(node.value);
					pushed = true;
				}else{
					if(node.value >= auxTop.value){
						while(auxTop.prev != null){
							if(auxTop.prev.value < node.value){
								auxTop = auxTop.prev;
							}else{
								pushed = insertInMidle(auxTop, node);
								break;
							}
						}
					}
				}
				
				if(!pushed){
					if(node.value < auxTop.value){
						pushed = insertInMidle(auxTop, node);
					}else{
						auxTop.prev = node;
						node.next = auxTop;
						node.prev = null;
						pushed = true;
					}
				}
			}
		}

		return auxStack;
	}
}
