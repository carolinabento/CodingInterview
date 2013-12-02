package Chapter1;
/**
 * Implementation of a double Linked List with the common API methods:
 * 	- create empty double LinkedList
 * 	- create double LinkedList with an initial element
 * 	- isEmpty
 * 	- append
 * 	- remove
 * 	- peek
 * 
 * TODO
 * - add(index,elem)
 * - contains
 * - get(index)
 * - indexOf(elem)
 * - set(index,elem)
 *
 * @author Carolina
 *
 * @param <T> - any template
 */
public class DoubleLinkedList<T> {

	private Node head;
	private Node tail;
	private int size;

	/**
	 * Empty constructor for LinkedList
	 */
	public DoubleLinkedList(){
		this.head = null;
		this.tail = null;
		this.size = 0;
	}

	/**
	 * Create LinkedList with an initial element
	 */
	public DoubleLinkedList(T value){
		Node node = new Node(value);
		this.head = node;
		this.tail = node;
		this.size = 0;
	}

	/**
	 * Checks if the LinkedList is empty 
	 * @return boolean
	 */
	public boolean isEmpty(){
		return (this.head == null && this.tail == null);
	}

	/**
	 * Checks the number of elements on the DoubleLinkedList
	 * @return total number of elements
	 */
	public int size(){
		return size;
	}

	/**
	 * Appends an element to the end of the list
	 * @param value - value to append
	 */
	public void append(T value){
		Node node = new Node(value);
		if(isEmpty()){
			this.head = node;
			this.tail = this.head;
		}else{
			node.prev = this.tail;
			node.next = null;

			this.tail.next = node;
			this.tail = node;
		}
		this.size++;
	}
	
	/**
	 * Removes all elements on the list
	 */
	public void clear(){
		if(!isEmpty()){	
			while(this.tail.prev != null){
				Node tail = this.tail;
				Node prev = this.tail.prev;

				this.tail = prev;
				this.tail.next = null;
				tail.prev = null;
			}

			//remove the remaining element
			this.head = null;
			this.tail = this.head;
		}else{
			throw new NullPointerException();
		}
	}

	/**
	 * Retrieve and remove first element of the LinkedList 
	 * @return
	 */
	public T removeHead(){
		if(!isEmpty()){
			Node head = this.head;
			this.head = head.next;
			head.next = null;
			this.size--;

			return head.value;
		}else{
			throw new NullPointerException();
		}
	}


	/**
	 * Remove last element of the LinkedList 
	 * @return
	 */
	public T removeTail(){
		if(!isEmpty()){
			Node tail = this.tail;

			this.tail = tail.prev;
			this.tail.next = null;

			tail.prev = null;

			this.size--;
			return this.tail.value;
		}else{
			throw new NullPointerException();
		}
	}	

	/**
	 * Check the value of head of the LinkedList
	 * @return the value of the head Node
	 */
	public T peek(){
		return this.head.value;
	}

	/**
	 * Check the value of head of the LinkedList
	 * @return the value of the tail Node
	 */
	public T peekTail(){
		return this.tail.value;
	}
	
	/**
	 * Implementation of Node class
	 * @author Carolina
	 *
	 */
	public class Node{
		private T value;
		private Node next;
		private Node prev;

		public Node(){
		}

		public Node(T value){
			this.value = value;
			this.next = null;
			this.prev = null;
		}
	}
}
