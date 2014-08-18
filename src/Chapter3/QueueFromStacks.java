package Chapter3;

public class QueueFromStacks {

	public Stack s1;
	public Stack s2;

	public QueueFromStacks(){
		this.s1 = new Stack();
		this.s2 = new Stack();
	}

	/**
	 * Append a value to the end of the queue
	 * @param value the value to append to the queue
	 */
	public void append(int value){
		if(s1.isEmpty() && s2.isEmpty()){
			s1.push(value);
		}else{
			if(s1.size() > 0){
				s2.push(value);
			}
		}
	}

	/**
	 * Push all the elements in stack s2 onto stack s1
	 * The elements in s1 will be in correct order to remove from the queue
	 */
	public void switchStacks(){
		if(s1.isEmpty() && s2.isEmpty()){
			throw new NullPointerException();
		}else{
			if(s1.isEmpty() && !s2.isEmpty()){

				StackNode<Integer> current = s2.top;

				while(current != null){
					s1.push(current.value);
					current = current.prev;
					s2.pop();
				}
			}
		}
	}


	/**
	 * check the first element on the queue
	 */
	public int peek(){
		switchStacks();
		return s1.top.value;
	}

	/**
	 * remove the first element from the queue
	 * @return the first element on the queue
	 */
	public int remove(){
		switchStacks();
		return s1.pop();
	}
	
	/**
	 * checks if the queue is empty
	 * @return true if it is empty, false otherwise
	 */
	public boolean isEmpty(){
		return s1.isEmpty() && s2.isEmpty();
	}
}
