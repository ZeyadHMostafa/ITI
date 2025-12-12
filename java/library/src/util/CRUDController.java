package util;

import java.util.Scanner;


public interface CRUDController {
    void create(Scanner sc, int id) throws IllegalArgumentException;
    void review(int id) throws IllegalArgumentException;
    void update(Scanner sc, int id) throws IllegalArgumentException;
    void delete(int id) throws IllegalArgumentException;
    void search(String regex) throws IllegalArgumentException;
}
