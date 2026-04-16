package models.books;

import models.User;

public class PhysicalBook extends Book{

    public PhysicalBook(String title, String AuthorName, int Year, boolean isAvailable) {
        super(title, AuthorName, Year, isAvailable);
    }

    @Override
    public void borrowBook(User user, int days) throws Exception  {
        super.borrowBook(user, days);
        System.out.println("Physical Book Functionality");
    }
}
