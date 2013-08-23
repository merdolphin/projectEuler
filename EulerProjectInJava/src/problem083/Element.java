package problem083;

public final class Element implements Comparable <Element>{

	int rowidx;
	int colidx;
	int value;
	
	public Element(int rowidx, int colidx, int value){
		this.rowidx = rowidx;
		this.colidx = colidx;
		this.value = value;
		
	}
		
	public int getRowidx(){
		return rowidx;
	}
	
	public int getColidx(){
		return colidx;
	}
	
	public int getValue(){
		return value;
	}
	
	public int setRowidx(int id){
		return this.rowidx = id;
	}
	
	public int setColidx(int id){
		return this.colidx = id;
	}
	
	public int setValue(int v){
		return this.value = v;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + colidx;
		result = prime * result + rowidx;
		result = prime * result + value;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (getClass() != obj.getClass()) {
			return false;
		}
		Element other = (Element) obj;
		if (colidx != other.colidx) {
			return false;
		}
		if (rowidx != other.rowidx) {
			return false;
		}
		if (value != other.value) {
			return false;
		}
		return true;
	}
	
	@Override
	public String toString() {
		return "(" + rowidx + "," + colidx + "), "
				+ value ;
	}

	@Override
	public int compareTo(Element e) {
		
		return this.value-e.value;
	}
		

}
