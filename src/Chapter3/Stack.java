package Chapter3;

public class Stack {

	private int min = Integer.MAX_VALUE; 
	StackNode<Integer> top;

	/**
	 * Initializes an empty stack
	 */
	public Stack(){
		this.top = null;
	}

	/**
	 * Initializes the stack with a given value
	 * @param value the value on top of the stack
	 */
	public Stack(int value){
		StackNode<Integer> node = new StackNode(value);
		this.min = value;
		this.top = node;
	}

	/**
	 * checks if the stack is empty
	 * @return true if the stack is empty, false otherwise
	 */
	public boolean isEmpty(){
		return this.top == null;
	}

	/**
	 * pushes a new value to the top of the stack
	 * @param value the value to push on to the top of the stack
	 */
	public void push(int value){
		StackNode<Integer> node = new StackNode(value);

		if(this.min > value) this.min = value;

		if(this.top == null){
			this.top = node;
		}else{
			this.top.next = node;
			node.prev = this.top;
			this.top = node;
		}
	}

	/**
	 * Removes the element on the top of the stack
	 * @return the element on the top of the stack
	 */
	public int pop(){

		if(isEmpty()){
			throw new NullPointerException();
		}else{

			StackNode<Integer> temp = this.top;

			if(this.top.prev != null){
				this.top.prev.next = null;
				this.top = this.top.prev;

				if(temp.value == min) updateMin();

				temp.prev = null;
			}else{
				this.top = null;
			}

			return temp.value;
		}
	}

	
	/**
	 * checks which is the minimum value in the stack
	 * @return
	 */
	public int min(){
		return this.min;
	}


	/**
	 * updates the minimum value in the stack
	 */
	public void updateMin(){
		StackNode<Integer> current = this.top;
		this.min = current.value;

		while(current != null){
			if(current.value < this.min) this.min = current.value;

			current = current.prev;
		}
	}
}
