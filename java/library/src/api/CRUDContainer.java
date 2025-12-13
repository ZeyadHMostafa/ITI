package api;

import java.util.Set;
import java.util.TreeMap;

import utl.exceptions.ItemAlreadyExistsException;
import utl.exceptions.ItemNotFoundException;
import utl.interfaces.Identifiable;

public class CRUDContainer <Entity extends Identifiable>{
    private TreeMap<Integer,Entity> entities = new TreeMap<>();

    public void add(Entity entity) throws ItemAlreadyExistsException{
        if (entities.containsKey(entity.getId())){
        throw new ItemAlreadyExistsException();
        }
        entities.put(entity.getId(), entity);
    }

    public void update(Entity entity) throws ItemNotFoundException{
        if (!entities.containsKey(entity.getId())){
        throw new ItemNotFoundException();
        }

        entities.put(entity.getId(), entity);
    }

    public Entity get(int id) throws ItemNotFoundException{
        if (!entities.containsKey(id)){
        throw new ItemNotFoundException();
        }

        return entities.get(id);
    }

    public Entity delete(int id) throws ItemNotFoundException{
        if (!entities.containsKey(id)){
        throw new ItemNotFoundException();
        }

        return entities.remove(id);
    }

    public Set<Integer> getAllAvailableIds(){
        return entities.keySet();
    }

    public void display(int id) throws ItemNotFoundException{
        if (!entities.containsKey(id)){
        throw new ItemNotFoundException();
        }

        System.out.println(entities.get(id));
    }

}

