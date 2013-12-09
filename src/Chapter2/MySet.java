package Chapter2;

import java.util.Iterator;

public class MySet<T> implements Iterable<T>{

	private T[] mySet;
	private final int DEFAULTLENGTH = 100;
	private int length;
	private int size;

	public MySet(){
		this.length = DEFAULTLENGTH;
		this.size = 0;
		this.mySet = (T[]) new Object[length];
	}

	public T[] populateMySet(LinkedList<T> list){
		int i = 0;
		if(list == null){
			throw new NullPointerException();
		}else{
			while(!list.isEmpty()){
				int j = 0;
				boolean unique = true;

				if(i < length/2){
					T dequedElement = list.dequeue();

					if(i == 0){
						this.mySet[i++] = dequedElement;
					}else{
						j = i - 1;

						while(j >= 0){
							if(this.mySet[j] != dequedElement){
								j--;
							}else{
								unique = false;
								break;
							}
						}

						if(unique){
							this.mySet[i++] = dequedElement;
							this.size++;
						}
					}
				}else{
					resize();				
				}
			}
		}
		return this.mySet;
	}

	public LinkedList<T> toOrderedSet(){
		LinkedList<T> list = new LinkedList<T>();
		
		for(T value : this){
			list.append(value);
		}
		return list;
	}

	public void resize(){
		length = length * 2; 
		T[] setCopy = (T []) new Object[length];

		for(int i = 0; i < this.mySet.length ; i++){
			setCopy[i] = this.mySet[i];
		}
		this.mySet = setCopy;
	}


	@Override
	public Iterator<T> iterator() {
		return new MyIterator();
	}


	private class MyIterator implements Iterator<T>{
		int arrayIndex = 0;

		@Override
		public boolean hasNext() {
			return arrayIndex < size;
		}

		@Override
		public T next() {
			return mySet[arrayIndex++];
		}

		@Override
		public void remove() {
			throw new UnsupportedOperationException();
		}

	}

}
