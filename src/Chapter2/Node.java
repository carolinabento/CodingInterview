package Chapter2;

/**
 * Implementation of Node class
 * @author Carolina
 *
 */
public class Node<T>{
	public T value;
	public Node next;	

	public Node(){}

	public Node(T value){
		this.value = value;
		this.next = null;
	}

	public T getValue(){
		return this.value;
	}
	
	public Node<T> getNext(){
		return this.next;
	}
	
	public boolean isEmpty(){
		return this.getValue() == null && this.getNext() == null;
	}
}
