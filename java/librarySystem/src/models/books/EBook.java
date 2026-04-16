package models.books;

import models.User;

public class EBook extends Book{

    public EBook(String title, String AuthorName, int Year, boolean isAvailable) {
        super(title, AuthorName, Year, isAvailable);
    }

    @Override
    public void borrowBook(User user, int days) throws Exception {
        if (!user.isPremium()){
            throw new Exception("Request Rejected Only premium users can borrow E-Books.");
        }
        
        super.borrowBook(user, days);
        System.out.println("E-Book Functionality");
    }
}
