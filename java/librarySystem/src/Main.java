import construction.BookBuilder;
import models.User;
import models.books.Book;

public class Main {
    public static void main(String[] args) {
        LibraryService AlexLibrary = new LibraryService();// Singleton
        
        AlexLibrary.addBook(
            new Book(
                "Harry Potter",
                "J.K. Rowling",
                2000,
                true
            )
        );

        AlexLibrary.addBook(
            new Book(
                "Lord of the Rings",
                "J.R.R. Tolkein",
                1954,
                true
            )
        );

        AlexLibrary.addBook(
            new BookBuilder()
                .setTitle("Another Book")
                .setAuthorName("J.R.R. Tolkein")
                .setYear(1954)
                .setAvailable(true)
                .setType("premium")
                .build()
        );

        AlexLibrary.addBook(
            new BookBuilder()
                .setTitle("Rings of the Lord")
                .setAuthorName("J.R.R. Tolkein")
                .setYear(1954)
                .setAvailable(true)
                .setType("ebook")
                .build()
        );

        User user1 = new User("John",true);
        User user2 = new User("Lisa",false);
        
        System.out.println("1.");
        AlexLibrary.borrowBook("Rings of the Lord", user2, 3);
        System.out.println();

        System.out.println("2.");
        AlexLibrary.borrowBook("Rings of the Lord", user1, 3);
        System.out.println();
        
        System.out.println("3.");
        AlexLibrary.borrowBook("Rings of the Lord", user2, 3);
        System.out.println();
        
        System.out.println("4.");
        AlexLibrary.returnBook("Rings of the Lord");
        System.out.println();
        
        System.out.println("5.");
        AlexLibrary.borrowBook("Another Book", user1, 14);
        System.out.println();
        
        System.out.println("6.");
        AlexLibrary.extendBorrowing("Another Book");
        System.out.println();
        
        System.out.println("7.");
        AlexLibrary.extendBorrowing("Another Book");
        System.out.println();

    }
}
