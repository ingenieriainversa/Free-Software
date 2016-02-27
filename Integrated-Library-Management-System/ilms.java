/*
 * Integrated Library Management System v0.01
 * ilms.java
 * Copyleft - 2014  Javier Dominguez Gomez
 * Written by Javier Dominguez Gomez <jdg@member.fsf.org>
 * GnuPG Key: 6ECD1616
 * Madrid, Spain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
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
