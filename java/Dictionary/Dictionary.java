import java.util.TreeMap;
import java.util.TreeSet;

class Dictionary {
	TreeMap<Character, TreeSet<String>> data;
	Dictionary(){
		data = new TreeMap<>();
	}
	
	void add(String word){
		word = word.toLowerCase();
		char key = word.charAt(0);
		if (!data.containsKey(key)){
			//key doesn't exist, add new value
			data.put(key, new TreeSet<String>());
		}
		// add word to list
		data.get(key).add(word);
	}
	
	String printSection(char key){
		if (!data.containsKey(key)) return "No Values";
		
		StringBuffer page = new StringBuffer();
		page.append("Section: "+key +"\n");
		data.get(key).forEach((word)->page.append(word+"\n"));
		return page.toString();
	}
	
	String printDictionary(){
		StringBuffer page = new StringBuffer();
		data.forEach((k,v)->page.append(printSection(k)+"\n"));
		return page.toString();
	}
}