package models.books;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

import interfaces.BookInterface;
import models.User;
import notification.BorrowalTracker;
import models.Borrowal;

public class Book implements BookInterface{
    private String title;
    private String AuthorName;
    private int Year;
    
    private boolean isAvailable;
    private BorrowalTracker borrowTracker;
    
    public Book(String title, String AuthorName, int Year, boolean isAvailable) {
        this.title = title;
        this.AuthorName = AuthorName;
        this.Year = Year;
        this.isAvailable = isAvailable;
        this.borrowTracker = new BorrowalTracker();
    }

    public BorrowalTracker getBorrowTracker() {
        return borrowTracker;
    }
    
    public String getAuthorName() {
        return AuthorName;
    }

    public int getYear() {
        return Year;
    }
    
    public boolean isAvailable() {
        return isAvailable;
    }
    
    public String getTitle() {
        return title;
    }

    public void borrowBook(User user, int days) throws Exception {
        isAvailable = false;
        borrowTracker.setBorrowal(new Borrowal(days, user, LocalDate.now(), title));
        System.out.println(user.getName()+" has borrowed "+title);
    }

    public void returnBook() {
        isAvailable = true;
        Borrowal borrowal = borrowTracker.getBorrowal();
        long daysBorrowed = ChronoUnit.DAYS.between(borrowal.getCreationDate(), LocalDate.now());
        if (daysBorrowed > borrowal.getApprovedDays()) {
            System.out.println("Book is returned late. Please pay the fine.");
        }
        System.out.println(title + " has been returned");
        borrowTracker.deleteBorrowal();
    }


}
