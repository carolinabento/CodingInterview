package Chapter2;

public class DeleteNodeLinkedList<T> {
	private Node<T> myNode;
	
	public DeleteNodeLinkedList(Node<T> node){
		this.myNode = node;
	}
	
	public void deleteNode(){
		
		if(this.myNode == null || this.myNode.isEmpty()){
			throw new NullPointerException();
		}else{
			
			if(this.myNode.next != null){
				this.myNode.value = (T) this.myNode.next.value;
				this.myNode.next = this.myNode.next.next;				
			}	
		}
	}
}
