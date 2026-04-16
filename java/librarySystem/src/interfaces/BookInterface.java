package interfaces;

import models.User;

public interface BookInterface {
     void borrowBook(User user, int days) throws Exception;
     void returnBook() ;
}
