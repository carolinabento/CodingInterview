package Chapter1;
/**
 * Implementation of a single Linked List with the common API methods:
 * 	- create empty single LinkedList
 * 	- create single LinkedList with an initial element
 * 	- isEmpty
 * 	- append
 * 	- remove
 * 	- peek
 * 
 * @author Carolina
 *
 * @param <Type> - any template
 */
public class LinkedList<Type> {

	private Node head;
	private Node tail;
	
	/**
	 * Empty constructor for LinkedList
	 */
	public LinkedList(){
		this.head = null;
		this.tail = null;
	}
	
	/**
	 * Create LinkedList with an initial element
	 */
	public LinkedList(Type value){
		Node node = new Node(value);
		this.head = node;
		this.tail = node;
	}
	
	/**
	 * Checks if the LinkedList is empty 
	 * @return boolean
	 */
	public boolean isEmpty(){
		return (this.head == null && this.tail == null);
	}
	
	/**
	 * Appends an element to the end of the list
	 * @param value - value to append
	 */
	public void append(Type value){
		Node node = new Node(value);
		if(isEmpty()){
			this.head = node;
			this.tail = this.head;
		}else{
			this.tail.next = node;
			this.tail = node;
		}
	}
	
	/**
	 * Remove first element of the LinkedList 
	 * @return
	 */
	public Type dequeue(){
		Node head = this.head;
		this.head = head.next;
		head.next = null;
		
		return head.value;
	}
	
	/**
	 * Check the value of head of the LinkedList
	 * @return the value of the tail Node
	 */
	public Type peek(){
		return this.head.value;
	}
	
	
	/**
	 * Implementation of Node class
	 * @author Carolina
	 *
	 */
	public class Node{
		private Type value;
		private Node next;	
		
		public Node(){
		}
		
		public Node(Type value){
			this.value = value;
			this.next = null;
		}
		
	}
}
