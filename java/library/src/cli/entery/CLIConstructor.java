package cli.entery;

import java.util.Scanner;

public interface CLIConstructor<Entity> {
    Entity constructFromCLI(Scanner sc, int id);
}
