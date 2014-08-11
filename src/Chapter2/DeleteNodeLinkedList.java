package Chapter2;

public class DeleteNodeLinkedList<T> {
	private Node<T> node;
	private LinkedList<T> list;
	
	public DeleteNodeLinkedList(LinkedList<T> list, Node<T> node){
		this.node = node;
		this.list = list;
	}
	
	public void deleteNode(){
		
		if(this.node == null || this.node.isEmpty()){
			throw new NullPointerException();
		}else{
			if(this.node.next != null){
				Node<T> temp = this.node.next;
				this.node.value = (T) this.node.next.value;
				this.node.next = this.node.next.next;
				temp = null;
			}
		}
	}
}
