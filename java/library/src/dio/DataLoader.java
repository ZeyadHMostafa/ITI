package dio;

import api.Library;
import obj.clients.Client;
import obj.libraryitems.Book;
import obj.libraryitems.Magazine;

public class DataLoader {
    static public void addFakeData(Library library){
        try {
            library.getClientContainer().add(new Client(100, "Mohammed Esmat" , "Mohammed@Company.com"));
            library.getClientContainer().add(new Client(200, "Kareem Mamdooh" , "Kareem@Company.com"));
            library.getClientContainer().add(new Client(300, "Farook El-Deeb" , "Farook@Company.com"));

            library.getItemContainer().add(new Book(50,"Book of Bananas",5));
            library.getItemContainer().add(new Book(150,"Book of Melons",2));
            library.getItemContainer().add(new Magazine(250,"Rare Magazine",1));

            library.borrowItem(100, 50);
            library.borrowItem(100, 150);
            library.borrowItem(200, 150);

        } catch (Exception e) {
            // no exception should ever happen
            e.printStackTrace();
        }
    }
}
