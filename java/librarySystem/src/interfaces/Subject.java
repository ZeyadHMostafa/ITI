package interfaces;

public interface Subject<Payload> {
	void register(Observer<Payload> obj);
	void unregister(Observer<Payload> obj);
	void notifyObservers();
}
