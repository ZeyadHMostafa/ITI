package util;

import clients.Client;
import library.entities.Book;
import library.entities.Library;
import library.entities.Magazine;

public class FakeData {
    static public void addFakeData(Library library){
        try {
            library.addClient(new Client(100, "Mohammed Esmat" , "Mohammed@Company.com"));
            library.addClient(new Client(200, "Kareem Mamdooh" , "Kareem@Company.com"));
            library.addClient(new Client(300, "Farook El-Deeb" , "Farook@Company.com"));

            library.addItem(new Book(50,"Book of Bananas",5));
            library.addItem(new Book(150,"Book of Melons",2));
            library.addItem(new Magazine(250,"Rare Magazine",1));

            library.borrowItem(100, 50);
            library.borrowItem(100, 150);
            library.borrowItem(200, 150);

        } catch (Exception e) {
            // no exception should ever happen
            e.printStackTrace();
        }
    }
}
