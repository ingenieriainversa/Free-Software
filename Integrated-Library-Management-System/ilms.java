import java.util.ArrayList;

public class Library
{
    private String name;
    private String address;
    private int numEmployees;
    private boolean open;
    private ArrayList<String> users;
    private ArrayList<String> items;

    public Library(String name, String address, int numEmployees)
    {
        this.name = name;
        this.address = address;
        this.numEmployees = numEmployees;
        this.open = open;
        users = new ArrayList<String>();
        items = new ArrayList<String>();
    }
    
    public String getName(){return name;}
    public String getAddress(){return address;}
    public int getNumEmployees(){return numEmployees;}
    public int getNumUsers(){return users.size();}
    public int getNumItems(){return items.size();}
    public boolean getOpen(){return open;}
    
    public void listUser(int index)
    {
        if(index >= 0 && index < users.size()) {
            String user = users.get(index);
            System.out.println(user);
        }
    }
    
    public void listAllUsers()
    {
        for(String user : users) {
            System.out.println(user);
        }
    }
    
    public void listUserMatching(String searchString)
    {
        for(String user : users) {
            if(user.contains(searchString)) {
                System.out.println(user);
            }
        }
    }
    
    public void removeUser(int index)
    {
        if(index >= 0 && index < users.size()) {
            users.remove(index);
        }
    }
    
    public void listItem(int index)
    {
        if(index >= 0 && index < items.size()) {
            String item = items.get(index);
            System.out.println(item);
        }
    }
    
    public void listAllItems()
    {
        for(String item : items) {
            System.out.println(item);
        }
    }
    
    public void listItemMatching(String searchString)
    {
        for(String item : items) {
            if(item.contains(searchString)) {
                System.out.println(item);
            }
        }
    }
    
    public void removeItem(int index)
    {
        if(index >= 0 && index < items.size()) {
            items.remove(index);
        }
    }
}
