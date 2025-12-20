package cli.menu;

import java.util.ArrayList;
import java.util.Scanner;

public class ChoiceMenu {
    protected class Choice {
        protected String text;
        protected Runnable func;
        Choice(String text, Runnable func){
            this.text = text;
            this.func = func;
        }
    }

    protected ArrayList<Choice> options;
    protected Scanner sc;
    private String title;
    private String optionString;

    ChoiceMenu(String title, Scanner sc){
        this.sc = sc;
        this.title = title;
        this.options = new ArrayList<>();
    }
    
    protected void updateOptionString(){
        StringBuffer optionString = new StringBuffer();
        optionString.append("\n-----------------------------------\n");
        optionString.append(title+":\n");
        optionString.append("0) Exit\n");
        for (int i=0; i<options.size(); i++){
            optionString.append((i+1)+") "+options.get(i).text+"\n");
        }
        this.optionString = optionString.toString();
    }

    public void runMenu(){
        while (true){
            String input;
            int choice;
            System.out.print(optionString);
            input = sc.nextLine();
            if (!input.matches("^[0-9]*$")){
                System.out.println("invalid input");
                continue;
            }else{
                choice = Integer.parseInt(input);
                if (choice<0||choice>options.size()){
                    System.out.println("invalid input");
                    continue;
                }
            }
            if (choice == 0) return;
            try {
                options.get(choice-1).func.run();   
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

