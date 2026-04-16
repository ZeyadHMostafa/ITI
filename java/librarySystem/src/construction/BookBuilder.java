package construction;

import models.books.*;

// Q.2: factory method pattern for various book types
public class BookBuilder {
	private String title;
	private String AuthorName;
	private int Year;
	private boolean isAvailable;
	private String type;

	public void fromJson(String json) {
		// Q.7: I didn't want to worry about bundling Java libraries for now
		// I would have used something like Jackson or Gson
		// to parse the JSON string into a Book object:

		// JSONObject jsonObject = new JSONObject(json);
		// this.title = jsonObject.getString("title");
		// this.AuthorName = jsonObject.getString("authorName");
		// this.Year = jsonObject.getInt("year");
		// this.isAvailable = jsonObject.getBoolean("isAvailable");
		// this.type = jsonObject.getString("type");
	}

	public BookBuilder setTitle(String title) {
		this.title = title;
		return this;
	}

	public BookBuilder setAuthorName(String AuthorName) {
		this.AuthorName = AuthorName;
		return this;
	}

	public BookBuilder setYear(int Year) {
		this.Year = Year;
		return this;
	}

	public BookBuilder setAvailable(boolean isAvailable) {
		this.isAvailable = isAvailable;
		return this;
	}

	public BookBuilder setType(String type) {
		this.type = type;
		return this;
	}

	public Book build() {
		switch (type.toLowerCase()) {
			case "ebook":
				return new EBook(title, AuthorName, Year, isAvailable);
			case "historical":
				return new HistoricalBook(title, AuthorName, Year, isAvailable);
			case "physical":
				return new PhysicalBook(title, AuthorName, Year, isAvailable);
			case "premium":
				return new PremiumBook(title, AuthorName, Year, isAvailable);
			default:
				throw new IllegalArgumentException("Invalid book type: " + type);
		}
	}
}