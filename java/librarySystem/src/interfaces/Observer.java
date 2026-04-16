package interfaces;

public interface Observer<Payload> {
	void update(Payload payload);
}
