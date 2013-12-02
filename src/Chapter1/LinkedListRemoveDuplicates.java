package Chapter1;

public class LinkedListRemoveDuplicates<T> {
	LinkedList<T> list;
	T[] buffer;

	public LinkedListRemoveDuplicates(LinkedList<T> list){
		this.list = list;
		this.buffer = (T[])(new Object[10]);
	}

	public LinkedList<T> remove(){

		if(this.list.isEmpty()){
			throw new NullPointerException();
		}else{
			MySet os = new MySet();
			T [] set = (T[]) os.populateMySet(this.list);
			LinkedList<T> res = new LinkedList<T>();
			
			for(T elem : set){
				res.append((T) elem);
			}
			
			return res;
		}
	}

	public void prettyPrint(LinkedList<T> list){
		Node<T> head = list.getHead();

		while(head.next != null){
			System.out.print(head.value + " -> ");
			head = head.next;
		}
		System.out.println(" //");
	}
}
