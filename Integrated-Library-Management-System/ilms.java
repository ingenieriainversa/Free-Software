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
    public boolean getOpen(){return open;}
}
