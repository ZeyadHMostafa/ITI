package models.books;

import interfaces.ExtensiblePeriodInterface;
import models.Borrowal;
import models.User;
import notification.BorrowalTracker;

public class PremiumBook extends Book implements ExtensiblePeriodInterface{

    private boolean extentionUsed = false;

    public PremiumBook(String title, String AuthorName, int Year, boolean isAvailable) {
        super(title, AuthorName, Year, isAvailable);
    }

    @Override
    public void extendPeriod() {
        if (!extentionUsed) {
            extentionUsed = true;
            BorrowalTracker borrowTracker = super.getBorrowTracker();
            Borrowal oldBorrowal = borrowTracker.getBorrowal();
            borrowTracker.setBorrowal(
                new Borrowal(
                    oldBorrowal.getApprovedDays() + 10,
                    oldBorrowal.getCurrentBorrower(),
                    oldBorrowal.getCreationDate(),
                    super.getTitle()
                )
            );
            System.out.println("Premium book period extended by 10 days.");
        } else {
            System.out.println("Premium book extension already used.");
        }
    }

    @Override
    public void borrowBook(User user, int days) throws Exception {
        super.borrowBook(user, days);
        System.out.println("Premium Book Functionality");
    }

}
