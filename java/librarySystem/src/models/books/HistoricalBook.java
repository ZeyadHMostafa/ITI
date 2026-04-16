package models.books;

import models.User;

public class HistoricalBook extends Book{

    public HistoricalBook(String title, String AuthorName, int Year, boolean isAvailable) {
        super(title, AuthorName, Year, isAvailable);
    }

    @Override
    public void borrowBook(User user, int days) throws Exception {
        super.borrowBook(user, days);
        System.out.println("Historical Book Functionality");
    }
}
