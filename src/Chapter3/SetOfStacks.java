package Chapter3;

public class SetOfStacks<T> {

	private int threshold;
	private int count;
	
	public Stack stack;
	
	public SetOfStacks(int threshold){
		this.threshold = threshold;
		this.count = 0;
		this.stack = new Stack();
	}
	
	
	/**
	 * Removes the element on the top of the set of stacks
	 * @return the element on the top of the set of stacks
	 */
	public int pop(){
		if(this.stack.isEmpty()){
			throw new NullPointerException();
		}else{
			if(this.count % this.threshold == 0){
				StackNode node = this.stack.top;
				StackNode temp = this.stack.top.prev;
				
				node.prev = null;
				temp.next = null;
				this.stack.top = temp;
				this.count--;
			}else{
				this.count--;
				return this.stack.pop();
			}
			
			
			return this.stack.top.value;
		}
	}
	
	/**
	 * pushes a new value to the top of the set of stacks
	 * @param value the value to push on to the top of the set of stacks
	 */
	public void push(int value){
		
		if(count % this.threshold != 0 || count == 0){
			this.stack.push(value);
		}else{
			Stack newStack = new Stack();
			newStack.push(value);
			
			this.stack.top.next = newStack.top;
			newStack.top.prev = this.stack.top;
			this.stack.top = newStack.top;
		}
		this.count++;
	}
}
