package notification;

import java.util.ArrayList;
import java.util.List;

import interfaces.Observer;
import interfaces.Subject;
import models.Borrowal;

public class BorrowalTracker implements Subject<String>{
	private List<Observer<String>> observers = new ArrayList<>();
	private Borrowal borrowal;

	public void setBorrowal(Borrowal borrowal) {
		this.borrowal = borrowal;
	}
	public Borrowal getBorrowal() {
		return this.borrowal;
	}

	public void deleteBorrowal() {
		notifyObservers();
		this.borrowal = null;
	}

	@Override
	public void register(Observer<String> obj) { observers.add(obj); }

	@Override
	public void unregister(Observer<String> obj) { observers.remove(obj); }

	@Override
	public void notifyObservers() {
		for (Observer<String> obj : observers) {
			obj.update(borrowal.getBookTitle());
		}
	}
}
