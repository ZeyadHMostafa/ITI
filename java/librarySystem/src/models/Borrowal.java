package models;

import java.time.LocalDate;

public class Borrowal {
	private int approvedDays;
	private User currentBorrower;
	private LocalDate creationDate;
	private String bookTitle;

	public Borrowal(int days, User user, LocalDate creationDate, String title) {
		this.approvedDays = days;
		this.currentBorrower = user;
		this.creationDate = creationDate;
		this.bookTitle = title;
	}

	public String getBookTitle() {
		return bookTitle;
	}
	public int getApprovedDays() {
		return approvedDays;
	}
	public User getCurrentBorrower() {
		return currentBorrower;
	}
	public LocalDate getCreationDate() {
		return creationDate;
	}
}
