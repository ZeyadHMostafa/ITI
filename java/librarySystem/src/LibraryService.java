import java.util.ArrayList;
import java.util.List;

import interfaces.ExtensiblePeriodInterface;
import models.Approver;
import models.User;
import models.books.Book;
import notification.Notifier;

public class LibraryService {
    private Approver<Integer> borrowApproverChain;
    private LibraryService instance;
    private List<Book> books = new ArrayList<>();

    LibraryService(){
        // Q.1: I'm pretty sure that's how we enforce a singleton pattern in Java
        if (instance == null) {
            instance = this;
        } else {
            throw new RuntimeException("Only one instance of LibraryService is allowed."); 
        }

        // Q.5&9: Setting up the chain of responsibility for borrowing books based on the number of days
        Approver<Integer> librarian = new Approver<>(request -> request <= 7, "Librarian");
        Approver<Integer> manager = new Approver<>(request -> request <= 10, "Manager");
        Approver<Integer> director = new Approver<>(request -> request <= 14, "Director");

        librarian.setNextApprover(manager);
        manager.setNextApprover(director);
        borrowApproverChain = librarian;
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public Book findBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equalsIgnoreCase(title)) {
                return book;
            }
        }
        return null;
    }

    public void borrowBook(String title, User user, int days) {
        Book book = findBook(title);
        if (book == null) {
            System.out.println("Book not found.");
            return;
        }
        
        if (! book.isAvailable()) {
            System.out.println("Book is currently not available.");
            if (book.getBorrowTracker() != null) {
                new Notifier(user, book.getBorrowTracker());
            }
            return;
        }

        if (!borrowApproverChain.approve(days)) {
            System.out.println("Borrowing request for " + days + " days could not approved.");
            return;
        }

        try {
            book.borrowBook(user, days);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public void returnBook(String title) {
        Book book = findBook(title);
        if (book == null) {
            System.out.println("Book not found.");
            return;
        }

        if (book.isAvailable()) {
            System.out.println("Book is already available.");
            return;
        }

        book.returnBook();
    }

    public void extendBorrowing(String title) {
        Book book = findBook(title);
        if (book == null) {
            System.out.println("Book not found.");
            return;
        }

        if (book.isAvailable()) {
            System.out.println("Book is currently available. No need to extend borrowing.");
            return;
        }

        if (book instanceof ExtensiblePeriodInterface) {
            ((ExtensiblePeriodInterface) book).extendPeriod();
         } else {
            System.out.println("This book does not support extending the borrowing period.");
            return;
        }
    }
}