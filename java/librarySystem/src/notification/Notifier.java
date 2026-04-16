package notification;

import interfaces.Observer;
import models.User;

public class Notifier implements Observer<String> {
	private User user;
	public Notifier(User user, BorrowalTracker tracker) {
		
		if (tracker.getBorrowal() == null) {
			System.out.println("The book is currently available. No need to wait.");
			return;
		}

		System.out.println(user.getName() + " is waiting for " + tracker.getBorrowal().getBookTitle() + " to be available.");
		this.user = user;
		tracker.register(this);
	}

	@Override
	public void update(String title) {
		System.out.println("The book " + title + " that " + user.getName() + " was looking for is now available.");
	}
	
}
