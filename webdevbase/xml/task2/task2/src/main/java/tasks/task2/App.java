package tasks.task2;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.List;

import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;
import jakarta.json.*;
import com.google.gson.Gson;

/**
 * Hello world!
 */

class User {
	public String name;
	public int id;
	public User(String name,int id){
		this.name = name;
		this.id = id;
	}

	@Override
    public String toString() {
        return "User{name='" + name + "', id=" + id + '}';
    }
}


public final class App {
	private App() {
	}

	public static void gsonUser(){
		// 1. Create a Gson instance
		Gson gson = new Gson();

		// 2. Serialize Java object to JSON string
		User objToSerialize = new User("Gson", 2);
		String jsonString = gson.toJson(objToSerialize);
		System.out.println("Gson Serialized JSON: " + jsonString);

		// 3. Deserialize JSON string to Java object
		User objFromJson = gson.fromJson(jsonString, User.class);
		System.out.println("Gson Deserialized Object: " + objFromJson);
	}

	public static void test_builder(){
		// test builder to convert array to list (proving both work)
		// no that that implies it workds for object by default
		User[] users = {new User("Jonathon",5),new User("Rana",12)};
		Jsonb jsonb = JsonbBuilder.create();
		String result = jsonb.toJson(users);
		System.out.println(result);
		List<User> userList = jsonb.fromJson(result, ArrayList.class);
		// if no error occurs then it works!
	}

	public static void readJson(String path) throws FileNotFoundException{
		File file = new File(path);
		JsonReader jsonReader = Json.createReader(new FileInputStream(file));
		JsonArray json = jsonReader.readArray();
		json.forEach(
			(val)->{
				JsonObject user = val.asJsonObject();
				String name = user.getString("name");
				int id = user.getInt("id");
				System.out.println(String.format("name:%s, id:%d",name, id));
			}
		);
	}
	public static void writeJson(String path) throws FileNotFoundException{
		File file = new File(path);
		JsonWriter jsonWriter = Json.createWriter(new FileOutputStream(file));
		JsonArrayBuilder json = Json.createArrayBuilder();
		User[] users = {new User("Jonathon",5),new User("Rana",12)};
		for (User user:users){
			json.add(
				Json.createObjectBuilder()
				.add("name", user.name)
				.add("id", user.id)
			);
		}
		JsonArray model = json.build();
		jsonWriter.writeArray(model);
			
	}

	/**
	 * @param args The arguments of the program.
	 */
	public static void main(String[] args) {
		System.out.println("--------------------------------------------------");
		try {
			readJson("doc1.json");
		} catch (Exception e) {
			System.out.println();
			System.out.println(e);
			System.out.println("");
			System.out.println("Note that I'm assuming you run the project from the same folder containing the xml");
			System.out.println("If you see this message that is likely because you did something else");

		}
		System.out.println("--------------------------------------------------");
		try {
			writeJson("doc2.json");
			System.out.println("succesfully wrote to doc2.json");
		} catch (Exception e) {
			System.out.println();
			System.out.println(e);
			System.out.println("");
			System.out.println("Note that I'm assuming you run the project from the same folder containing the xml");
			System.out.println("If you see this message that is likely because you did something else");

		}
		test_builder();
		gsonUser();
		
	}
}
