package Chapter2;

/**
 * Implementation of Node class
 * @author Carolina
 *
 */
public class Node<Type>{
	public Type value;
	public Node next;	

	public Node(){
	}

	public Node(Type value){
		this.value = value;
		this.next = null;
	}

	public Type getValue(){
		return this.value;
	}
	
	public Node<Type> getNext(){
		return this.next;
	}
}
