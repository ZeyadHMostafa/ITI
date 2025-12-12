package menu;

import java.util.Scanner;

import util.CRUDController;

public class CRUDMenu{
    protected String title;
    protected String entityName;
    private String mainMeuString;
    private CRUDController controller;

    CRUDMenu(CRUDController controller, String title, String entityName){
        this.title = title;
        this.entityName = entityName;
        
        mainMeuString = title+":"+
        "\n1) Create "+entityName+
        "\n2) Review "+entityName+
        "\n3) Update "+entityName+
        "\n4) Delete "+entityName+
        "\n5) Search "+entityName+
        "\n6) Return"+
        "\n";
        this.controller = controller;
    }

    void mainView(Scanner sc){
        while (true){
            System.out.print(mainMeuString);
            String choice = sc.nextLine();
            String input;

            if (choice.matches("[1234]")){
                System.out.println("Please enter "+entityName+" ID:");
                input = sc.nextLine();
                if (!input.matches("^[0-9]+$")){
                    System.out.println("<!> please enter a proper ID");
                    continue;
                }
            } else if (choice.equals("5")){
                System.out.println("Please enter Search regex:");
                input = sc.nextLine();
                try {
                    controller.search(input);   
                } catch (IllegalArgumentException e) {
                    System.out.println(e.getMessage());
                }
            } else if (choice.equals("6")){
                return;
            } else {
                System.out.println("please pick a suitable option");
                continue;
            }
            
            try {
                switch(choice){
                    case "1":
                        controller.create(sc,Integer.parseInt(input));
                        break;
                    case "2":
                        controller.review(Integer.parseInt(input));
                        break;
                    case "3":
                        controller.update(sc,Integer.parseInt(input));
                        break;
                    case "4":
                        controller.delete(Integer.parseInt(input));
                        break;
                }       
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());                
            }
        }

    }
}
