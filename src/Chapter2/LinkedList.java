package Chapter2;
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
 * @param <T> - any template
 */
public class LinkedList<T> {

	private Node<T> head;
	private Node<T> tail;
	private int size;

	/**
	 * Empty constructor for LinkedList
	 */
	public LinkedList(){
		this.head = null;
		this.tail = null;
		this.size = 0;
	}

	/**
	 * Create LinkedList with an initial element
	 */
	public LinkedList(T value){
		Node<T> node = new Node(value);
		this.head = node;
		this.tail = node;
		this.size = 1;
	}

	/**
	 * Checks if the LinkedList is empty 
	 * @return boolean
	 */
	public boolean isEmpty(){
		return (this.head == null && this.tail == null);
	}

	public int size(){
		return this.size;
	}

	/**
	 * Appends an element to the end of the list
	 * @param value - value to append
	 */
	public void append(T value){
		Node<T> node = new Node<T>(value);
		if(isEmpty()){
			this.head = node;
			this.tail = this.head;
			this.size++;
		}else{
			this.tail.next = node;
			this.tail = node;
			this.size++;
		}
	}

	/**
	 * Remove first element of the LinkedList 
	 * @return
	 */
	public T dequeue(){
		if(isEmpty()){
			throw new NullPointerException();
		}else{
			Node<T> head = this.head;
			this.head = head.next;
			head.next = null;
			
			if(size == 1){
				this.tail = null;
			}
			
			this.size--;

			return head.value;
		}
	}

	/**
	 * Check the value of head of the LinkedList
	 * @return the value of the head Node
	 */
	public T peek(){
		return this.head.value;
	}

	public Node<T> getHead(){
		return this.head;
	}
	
	public void prettyPrint(){
		Node<T> head = this.getHead();

		while(head.next != null){
			System.out.print(head.value + " -> ");
			head = head.next;
		}
		System.out.println(" //");
	}
}
